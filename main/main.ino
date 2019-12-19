#include "HX711.h"
#include <EEPROM.h>


#define FANATEC_CSL
//#define LOGITECH_G2X


#define DOUT_PIN 2
#define SCK_PIN 3
#define PWM_OUTPUT_PIN 10
#define EEPROM_ADR 0
#define PRESS_DETECT_THRESHOLD 30000    // CHANGE IN FORCE VALUE FROM STRAIN GAUGE TO DETECT "PEDAL PRESSED" DURING BOOT CALIBRATION
#define DEADZONE 5                      // MAINLY TO REMOVE NOISE ON SIGNAL WHEN PEDAL IS AT REST


HX711 scale;
long zero_val;
long max_val = 0;


void setup() {
  Serial.begin(115200);
  TCCR1B = TCCR1B & 0b11111000 | 1;     // RAISE PWM OUTPUT FREQUENCY ON ARDUINO NANO. TCCR0B = pin 5 and 6.
  scale.begin(DOUT_PIN, SCK_PIN);
  zero_val = scale.read_average(10);
  EEPROM.get(EEPROM_ADR, max_val);
}

void loop() {

  static bool startup = true;
  static bool press_detect = false;
  int force;
  int output;

  unsigned long now = millis();
  long raw_input = scale.read();
  if (raw_input<zero_val) {
    zero_val = raw_input;
  }


  // DURING FIRST 10 SECONDS AFTER BOOT
  if ( now<10000 && startup==true ) {

    // PEDAL WAS PRESSED DOWN
    if (raw_input>zero_val+PRESS_DETECT_THRESHOLD) {
      Serial.print("Pedal press detected. ");
      if (raw_input>max_val || press_detect==false) {
        press_detect = true;
        max_val = raw_input; 
        Serial.print("New max_val: ");
        Serial.print(max_val);
      }
      Serial.println();
    }
  }

  // ONCE, EXACTLY 10 SECONDS AFTER BOOT
  if ( now>10000 && startup==true ) {
    startup = false;

    // ONLY UPDATE EEPROM IF THE PEDAL WAS PUSHED DURING STARTUP PERIOD
    if(press_detect) { 
      Serial.print("Recalibration DONE. Saving new max_val:\t");
      Serial.println(max_val);
      EEPROM.put(EEPROM_ADR, max_val);
    }
    else {
      Serial.println("Re-Calibration timed out. Keeping previous max_val");
    }
  }
 

  force = ((255+DEADZONE)*((raw_input-zero_val)/(float)(max_val-zero_val)))-DEADZONE;
  force = constrain(force,0,255); 

  output = force;
  #ifdef LOGITECH_G2X
    output = 255-force;
  #endif
  #ifdef FANATEC_CSL
    output = 58-(58*force/255);
  #endif
  analogWrite(PWM_OUTPUT_PIN, output);

  #define TIMER1 100
  static unsigned long timer1 = TIMER1;
  if (now - timer1 >= TIMER1) {
    timer1 = now;
    Serial.print(raw_input); 
    Serial.print("\t"); 
    Serial.print(force); 
    Serial.print("\t"); 
    Serial.print(5*output/(float)255); 
    Serial.println("V"); 
  }
}





////////////////////////////////////////////////////////

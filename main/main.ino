#include "HX711.h"

////////////////////////////////////////////////////////

// #define INVERT_ANALOG_OUTPUT          // If analog output voltage should be high for no braking force and low for full braking
#define DEBUG                            // Enables printout of strain gauge force values over USB
// #define OPTIONAL_FIXED_MAX -250000    // Disables auto calibration of max force value and uses this value instead (run serial monitor and DEBUG to see what values your strain gauge outputs)

////////////////////////////////////////////////////////

#define DOUT_PIN 2
#define SCK_PIN 3
#define ANALOG_PIN 10


HX711 scale;
long zero_val;
long max_val = 0;


void setup() {
  Serial.begin(115200);
  TCCR1B = TCCR1B & 0b11111000 | 1;     // RAISE PWM OUTPUT FREQUENCY ON ARDUINO NANO
  scale.begin(DOUT_PIN, SCK_PIN);
  zero_val = scale.read_average(10);    // ZERO FORCE CALIBRATION. DO NOT PUSH ON PEDAL WHEN BOOTING UP! 
}

void loop() {

  long raw_input = scale.read();
  int force;
  const int DIRECTION_DETECT_DEAD_ZONE = 30000;

  #ifdef OPTIONAL_FIXED_MAX
    max_val = OPTIONAL_FIXED_MAX;
  #else
    if(raw_input>zero_val+DIRECTION_DETECT_DEAD_ZONE && raw_input>max_val) { // STRAIN GAUGE IS MOUNTED SO MORE FORCE GENERATES MORE POSITIVE RAW VALUES
      max_val = raw_input; 
    }
    if(raw_input<zero_val-DIRECTION_DETECT_DEAD_ZONE && raw_input<max_val) { // STRAIN GAUGE IS MOUNTED SO MORE FORCE GENERATES MORE NEGATIVE RAW VALUES
      max_val = raw_input; 
    }
  #endif

  force = 255*((raw_input-zero_val)/(float)(max_val-zero_val));
  force = (int)((force-25)*1.25); // DEADZONE BOTH AT MAX AND MIN
  force = constrain(force,0,255); 
  #ifdef INVERT_ANALOG_OUTPUT
    force = 255-force;
  #endif
  analogWrite(ANALOG_PIN, force);

  #ifdef DEBUG
    Serial.print(raw_input); 
    Serial.print("\t"); 
    Serial.print(force); 
    Serial.println(); 
  #endif
}





////////////////////////////////////////////////////////

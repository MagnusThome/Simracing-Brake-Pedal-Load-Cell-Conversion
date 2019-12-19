# Simracing-Brake-Pedal-Load-Cell-Conversion

Mount a strain gauge in your simracing brake pedal. This kit will output an analog voltage that represents the force applied on the brake pedal. This voltage can be used instead of the voltage from the potentiometer used originally.  
  
# Startup - Self calibration  
  
Every time you apply power to the pedal it will be in self calibration mode for the first 10 seconds. In normal use you just leave the pedal alone, simply do not apply any pressure to it, during this startup 10 seconds. 
  
- Important: the very first time you use the pedal you must calibrate maximum pedal pressure, at least once. This is done during the 10 second startup calibration phase by applying the amount of maximum force onto the pedal that you want to equal 100% full braking. You can choose a lighter or stronger pressure, whatever max force you apply during this self calibration phase will then be stored as the pressure where the pedal will send 100% braking to your PC or console, it is stored on the board even when power is disconnected.  
  
- Changing the calibration, choosing another pressure to equal full braking is simply done exactly the same way as you did the first time you calibrated it. Simply put: If you ever apply pressure to the brake pedal during the 10 second startup phase, this applied pressure will be stored as the new level and will from there on be used.  
  
# Startup - Normal use  
  
Do not apply any pressure to the brake pedal during the first 10 seconds after power is applied. Previous max pedal pressure is stored on the board and reused.  
  
# Parts needed:  
  
- 20kg Strain Gauge with included HX711 board  
- Arduino Nano 5 Volt  
- Resistor 4.7 kOhm  
- Capacitor 100nF  
  
# Mounting the strain gauge  
  
You'll have to be a bit creative to mount the strain gauge in the pedal so the pedal pushes against it so it can detect the forces applied to it. It's not that sensitive how much force and at what angle the force is applied. Here below are two examples on how I've mounted it in a Logitech G25 pedal and on a Fanatec CSL pedal.  
  
Important: You DO need to have the strain gauge outputting higher values for higher pedal pressure. If you mount it backwards it'll output lower numbers for higher pressures and you'll get strange results. But this is easily solved by enabling "REVERSED_STRAIN_GAUGE" in the source code! 
  
The black "arm" part for the Logitech pedal that you can see in my pictures below was 3D-printed but you can of course make it out of a piece of wood or metal instead. I later redid this "arm" so that I had 5mm of soft rubber inserted between the pedal, arm and strain gauge. This enabled the pedal to move just a tiny bit initially when pressed down and then go stiff. To me this was closer to how a real car brake pedal feels. 

<img src=pics/fanatec0.jpg>  
  
<img src=pics/fanatec1.jpg>  
  
<img src=pics/fanatec2.jpg>  
  
<img src=pics/logipedal1.jpg>  
  
<img src=pics/logipedal2.jpg>  
  
<img src=pics/logipedal3.jpg>  
  
<img src=pics/logipedal4.jpg>  
  
<img src=pics/logipedal5.jpg>  
  
# Connecting everything  
  
First you need to move the 0 Ohm jumper on the HX711 board. This makes it update at 80Hz instead of only 10Hz.  
  
<img src=pics/HX711_jumper.jpg>  

Then connect the strain gauge to the HX711 board and the HX711 board to the Arduino Nano like this.  
  
<img src=pics/connections1.jpg> 

Finally connect the Arduino board to the pedal, substituting 5 volt power, ground and the analog output voltage to the potentiometers 5 volt, ground and "wiper" middle pin. DOUBLE check that the potentiometer actually has 5 volts and ground wired to it so these wires can drive the Arduino. Logitech pedals seem to have this, the G25 certainly does and also the Fanatec pedal I converted, but for other makes be sure to check.   
  
The analog output from the Arduino board should be connected through a 4,7 kOhm resistor to the wire that previously was connected to the potentiometer "wiper" middle pin. And additionally a 100nF capacitor should be connected from this wire to ground.  
  
<img src=pics/connections3.jpg> 
  
<img src=pics/connections2.jpg>  
  
<img src=pics/connections4.jpg>  




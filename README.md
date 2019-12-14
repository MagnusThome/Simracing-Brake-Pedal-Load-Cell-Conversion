# Simracing-Brake-Pedal-Load-Cell-Conversion

Mount a strain gauge in your simracing brake pedal. This kit will output an analog voltage that represents the force applied on the brake pedal. This voltage can be used instead of the voltage from the potentiometer used originally.
  
Parts needed:
- 20kg Strain Gauge with included HX711 board  
- Arduino Nano 5 Volt  
- Resistor 4.7 kOhm  
- Capacitor 100nF  
  
# Mounting the strain gauge  
  
You'll have to be a bit creative to mount the strain gauge in the pedal so the pedal pushes against it so it can detect the forces applied to it. It's not that sensitive how much force and at what angle the force is applied, here's an example on how I mounted it in a Logitech G25 pedal set. The black "arm" part was 3D-printed but you can of course make it out of a piece of wood or metal instead. I later rebuilt this "arm" so that i had a 5mm soft rubber inserted between the pedal, arm and strain gauge. This enabled the pedal to move just a tiny bit initially when pressed down and then go stiff. To me this was closer to how a real car brake pedal feeels. 

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

Finally connect the Arduino board to the pedal, substituting 5 volt power, ground and the analog output voltage to the potentiometers 5 volt, ground and "wiper" middle pin. DOUBLE check that the potentiometer actually has 5 volts and ground wired to it so these wires can drive the Arduino. Logitech pedals seem to have this, the G25 certainly does, but for other makes be sure to check. 

<img src=pics/connections2.jpg> 




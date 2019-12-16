# Simracing-Brake-Pedal-Load-Cell-Conversion

Mount a strain gauge in your simracing brake pedal. This kit will output an analog voltage that represents the force applied on the brake pedal. This voltage can be used instead of the voltage from the potentiometer used originally.  
  
# Self calibration  
  
When powering up the board it will presume no pressure is applied to the brake pedal and it will calibrate this state to 0% output level sent into your pedal's electronics. So make sure the pedal is "at rest" each time power is applied.  
  
Secondly, before driving make sure you press the pedal down once with the high force you want to be 100% braking. This force level will then be stored and will from then on be the force neccessary to generate 100% braking output level to your pedal's electronics. This force level will be saved as long as the unit is powered on.  
  
There is a downside to this max force level self calibration that can be removed by setting the max force value to a forever fixed value in the source code (it's clearly commented and easy to find in the code). The downside is that if you just press with a smaller force first and then drive away, this lower force level will be used for 100% braking. But if you later during driving press much harder on the brake pedal the force for 100% braking will re-calibrate to this higher level of force equaling 100% braking. This is not a problem for most, if you usually set 100% braking to high force level. But if you want 100% braking to be at a lower force level it is easy to later mistakenly press much harder, for example during racing, and re-calibrate. In that case I suggest you hard code the max braking force value in the source code.  
  
# Parts needed:  
- 20kg Strain Gauge with included HX711 board  
- Arduino Nano 5 Volt  
- Resistor 4.7 kOhm  
- Capacitor 100nF  
  
# Mounting the strain gauge  
  
You'll have to be a bit creative to mount the strain gauge in the pedal so the pedal pushes against it so it can detect the forces applied to it. It's not that sensitive how much force and at what angle the force is applied. Here's an example on how I mounted it in a Logitech G25 pedal set. The black "arm" part was 3D-printed but you can of course make it out of a piece of wood or metal instead. I later redid this "arm" so that I had 5mm of soft rubber inserted between the pedal, arm and strain gauge. This enabled the pedal to move just a tiny bit initially when pressed down and then go stiff. To me this was closer to how a real car brake pedal feeels. 

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
  
The analog output from the Arduino board should be connected through a 4,7 kOhm resistor to the wire that previously was connected to the potentiometer "wiper" middle pin. And additionally a 100nF capacitor should be connected from this wire to ground.  
  
<img src=pics/connections3.jpg> 
  
<img src=pics/connections2.jpg>  
  
<img src=pics/connections3.jpg>  




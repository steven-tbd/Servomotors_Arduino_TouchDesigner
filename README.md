# Servo-Motors_Arduino_TouchDesigner
control multiple servo motors with TouchDesigner and Arduino

<h3>HARDWARE AND SOFTWARE:</h3>
<ul>
	<li><a href="https://www.youtube.com/watch?v=91rLXVMb0h8" target="_blank" rel="noopener">Arduino</a></li>
        <li><a href="https://www.youtube.com/watch?v=mQK3Scp3Qls" target="_blank" rel="noopener">PCA9685 breakout board</a> (up to 62 PCA9685 boards can be chained together to control up to 992 outputs)</li>
	<li>Servos</li>
	<li>Leap Motion (any sensor or input will work)</li>
	<li><a href="https://derivative.ca/UserGuide/Arduino" target="_blank" rel="noopener">TouchDesigner</a></li>	
</ul>

<br>
<h3>ARDUINO</h3>
<p>Include the Wire library and the library for the PCA9685 board. Define the pulse width and frequency for your motors. Using the pwm.setPWM(), create a function to send a position to all of your motors.</p>

<p>Copy and paste the code from the TouchDesigner User Guide Arduino page from under the subheading ‘Receiving Data on the Arduino’. Edit the ‘if’ statement to create a variable for the servo position to receive from TouchDesigner.</p>

<br>
<h3>TOUCHDESIGNER</h3>
<p>Use a CHOP Execute DAT to send information through the SerialDAT to the Arduino. Make sure that the values you send to the Arduino fall between the minimum and maximum pulse width of your servo motors.</p>

-----
https://stevenmbenton.com/control-multiple-servos-with-touchdesigner/

//PCA9685 servo control

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       650
#define MAX_PULSE_WIDTH       2500
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//setup serial buffer
char buffer[16];   //maximum expected length 
int len = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Listening, Baud:9600"); 
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
}

void moveMotor(int servo, float position)
{
  int pulse_width;
  pulse_width = int(position / 1000000 * FREQUENCY * 4096);
  pwm.setPWM(servo, 0, pulse_width);

}

void moveAll(float position)
{
  moveMotor(0, position);
  moveMotor(1, position);
  moveMotor(2, position);
  moveMotor(3, position);
  moveMotor(4, position);
  moveMotor(5, position);  
  moveMotor(6, position);
  moveMotor(7, position);
  moveMotor(8, position);    
}

void loop()
{
    if (Serial.available() > 0) 
    {
        int incomingByte = Serial.read();
        buffer[len++] = incomingByte;
        if (len >= 16)
        {
            len = 0;
        }
        if (incomingByte == '\n')
        {
            int position;
            int n = sscanf(buffer, "%d", &position);
            if (n == 1)
            {              
                Serial.println(position);
                moveAll(position);    
            }
            else
            {
                 Serial.println("failure");
            }
            len = 0; 
        }
    }
}

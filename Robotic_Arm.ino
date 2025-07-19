/*
🔧 Hardware Components
Component	Quantity
Arduino Uno/Nano	1
Servo Motor (SG90/MG90S)	3
Joystick Module	2
Breadboard	1
Jumper Wires (M–M, F–M)	As needed
External 5V Power Supply (Recommended)	1

🪛 Connection Steps
🕹️ Joystick Modules
Each joystick has:

X-axis: Outputs analog voltage (connect to analog pin)

Y-axis: Outputs analog voltage (connect to analog pin)

VCC: +5V

GND: Ground

(Optional SW pin): Not used in this code

Joystick 1 (Controls Servo 1 & 2)
VCC → Arduino 5V

GND → Arduino GND

X-axis → Arduino A0

Y-axis → Arduino A1

Joystick 2 (Controls Servo 3)
VCC → Arduino 5V

GND → Arduino GND

X-axis → Arduino A2

Y-axis → Not used

⚙️ Servo Motors
Servo 1 (s1)
Signal (Yellow) → Arduino pin 3

VCC (Red) → External 5V

GND (Brown) → External GND (shared with Arduino)

Servo 2 (s2)
Signal → Arduino pin 4

VCC → External 5V

GND → External GND

Servo 3 (s3)
Signal → Arduino pin 5

VCC → External 5V

GND → External GND

⚠️ Important: Never power 3 servos directly from Arduino 5V. Use an external 5V 
supply (e.g., 5V adapter or battery with common GND).*/

#include <Servo.h>

int x_pin1 = A0;
int y_pin1 = A1;

int x_pin2 = A2;
int pos1, pos2, pos3 = 0;

Servo s1;
Servo s2;
Servo s3;

void setup() 
{
 Serial.begin (9600);
 pinMode (A0, INPUT);
 pinMode (A1, INPUT);
 pinMode (A2, INPUT);

 s1.attach (3);
 s1.write (pos1);

 s2.attach (4);
 s2.write (pos2);

 s3.attach (5);
 s3.write (pos3);
}

void loop()
{
 int x_data1 = analogRead (A0);
 int y_data1 = analogRead (A1);
 int x_data2 = analogRead (A2);

 Serial.print ("x_data1:");
 Serial.print (x_data1);
 Serial.print ("\t");
 Serial.print ("y_data1:");
 Serial.print (y_data1);
 Serial.print ("\t");
 Serial.print ("x_data2:");
 Serial.print (x_data2);
 delay (20);

 if (x_data1 >= 550)
{
  if (pos1 <= 180)
 {
  pos1 = pos1 + 3;
  s1.write (pos1);
 }
}
else if (x_data1 <=450)
{
  if (pos1 >= 0)
  {
    pos1 = pos1 - 3;
    s1.write (pos1);
  }
}

 if (y_data1 >= 550)
{
  if (pos2 <= 180)
 {
  pos2 = pos2 + 5;
  s2.write (pos2);
 }
}
else if (y_data1 <=450)
{
  if (pos2 >= 0)
  {
    pos2 = pos2 - 5;
    s2.write (pos2);
  }
}

 if (x_data2 >= 550)
{
  if (pos3 <= 180)
 {
  pos3 = pos3 + 5;
  s3.write (pos3);
 }
}
else if (x_data2 <=450)
{
  if (pos3 >= 0)
  {
    pos3 = pos3 - 5;
    s3.write (pos3);
  }
}
}

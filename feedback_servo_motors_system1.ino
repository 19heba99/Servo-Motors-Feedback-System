#include <Servo.h>
#include <EEPROM.h>

Servo m1;
Servo m2;

int A = 3; // pin of the 1st servo on arduino
int B = 4; // pin of the 2nd servo on arduino
int C = A1; // pin of potentiometer on aduino (the potentiometer is a simulation of the first servo motor moving by hand)
int index = 0; // every read value from the ptentiometer will be saved at index zero of the EEPROM library
int indexValue; // to read the value saved at the selected index of EEPROM library
int x, y; // x to read the actual value of ptentiometer (0-1023) and y to convert it into servo range (0-180)

  void setup()
    
{
    
    // connecting pins
    
    pinMode(C, INPUT); 
    m1.attach(A);
    m2.attach(B);
    m2.write(0);
    m1.write(0);  

 }
   

void loop()
  
{
   x = analogRead(C);
   y = map(x,0,1023,0,180); 
   EEPROM.put(index, y); // put function is used to write a value of an integer  (needs 2 bytes rather than only 1 as in write function) in the EEPROM library index 
   EEPROM.get(index, indexValue); // get function is used to read a value of an integer  (needs 2 bytes rather than only 1 witch as in read function) from the EEPROM library index and name it
  
  // according to the movement of first motor the second will move at the same time
  // the second motor in real robot hand will be setted on an opisite direction to move the 2nd hand in an opisite way from the first one
   m1.write(indexValue); 
   m2.write(indexValue);
   delay(10); 
}


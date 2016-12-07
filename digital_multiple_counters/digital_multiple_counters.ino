#include <Ping.h>
#include <NewPing.h>
#include <TimerOne.h>
#include <TimerThree.h>

//Ping ping = Ping(15);  // Ping signal on pin 15

const int numReadings = 10;

int pwmPins [4] = { 9, 10, 12, 14};
//vector<Ping> myPings;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void pinger(vector<Ping> myPings,i)
{
  ping.fire();
  
    // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    if ((ping.inches()<=60)and(ping.inches()>=0))
    {
      readings[readIndex] = ping.inches();
    }
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex = readIndex + 1;
  
    // if we're at the end of the array...
    if (readIndex >= numReadings) {
      // ...wrap around to the beginning:
      readIndex = 0;
    }
  
    // calculate the average:
    average = total / numReadings;
    // send it to the computer as ASCII digits
  
    
    //Serial.println(1000-950*average/50);
    delay(1);        // delay in between reads for stability
}
void setup() 
{
  Timer1.initialize(1000);
  for (int i=0; i<4; i++)
  {
    myPings.pushback(Ping(i));
  }
  Timer1.start();
  Timer1.pwm(14,1000);
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop()
{
  
    for (int i=0; i<4; i++)
    {
      pinger(myPings,i);
    }
    
  
    Timer1.setPwmDuty(14,500-495*average/50);
   
  
}


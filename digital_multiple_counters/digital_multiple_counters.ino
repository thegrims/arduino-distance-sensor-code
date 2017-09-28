#include <Ping.h>
#include <NewPing.h>
#include <TimerOne.h>
#include <TimerThree.h>


const int numReadings = 10;

int pwmPins [4] = { 9, 10, 12, 14};


int readings[numReadings];      // ping readings buffer from the analog input. I chose a buffer 10 long 
                                // and averaged it to create a moving average and smooth the data 

int readIndex = 0;              // index of the current reading
int total = 0;                  // running total of the most recent 10 ping values
int average = 0;                // average

void pinger(vector<Ping> myPings,i) {
    ping.fire();
    // subtract the last reading:
    total = total - readings[readIndex];
    // read from the sensor:
    if ((ping.inches()<=60)and(ping.inches()>=0)) {
      readings[readIndex] = ping.inches();
    }
    // add the reading to the total:
    total = total + readings[readIndex];
    // advance to the next position in the array:
    readIndex += 1;
  
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
void setup() {
  Timer1.initialize(1000);
  // gets ping values from all 4 distance sensors
  for (int i=0; i<4; i++) {
    myPings.pushback(Ping(i));
  }
  Timer1.start();
  Timer1.pwm(14,1000);
  
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
    for (int i=0; i<4; i++) {
      pinger(myPings,i);
    }
    Timer1.setPwmDuty(14,500-495*average/50);
}


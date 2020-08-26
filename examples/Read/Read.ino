#include "HT1382.h"
HTClock rtc;

void setup() {
  Serial.begin(115200);  // start serial for output
   Serial.println("Start .."); 
  delay(20);
}

void loop() {
  Serial.println("Time :"+String(rtc.hour())+":"+String(rtc.minute())+":"+String(rtc.second()));
   Serial.println("Date :"+String(rtc.year())+"/"+String(rtc.month())+"/"+String(rtc.day()));
delay(1000);


}

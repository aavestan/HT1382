#include "HT1382.h"
HTClock rtc;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);  // start serial for output
   Serial.println("Start ..");
   Serial.println("Seting Clock");
//set(const uint8_t second, const uint8_t minute, const uint8_t hour, const uint8_t dayOfWeek, const uint8_t dayOfMonth, const uint8_t month, const uint8_t year)    
rtc.set(0,22,15,5,27,8,20);
}

void loop() {
   Serial.println("Time :"+String(rtc.hour())+":"+String(rtc.minute())+":"+String(rtc.second()));
   Serial.println("Date :"+String(rtc.year())+"/"+String(rtc.month())+"/"+String(rtc.day()));
   delay(1000);

}

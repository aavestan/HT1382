#include <Wire.h>
#include "HT1382.h"
uint8_t HTRead(uint8_t address){
   Wire.beginTransmission(0x68);
    Wire.write(address); 
  Wire.endTransmission();
      HT1382_YIELD

  Wire.requestFrom(0x68,1 );    // request 6 bytes from slave device #8
char c;
  while (Wire.available()) { // slave may send less than requested
    c = Wire.read(); // receive a byte as character
  }
 HT1382_YIELD
if(address==2) c = c & 0B01111111;
return bcdToDec(c);
}
  
HTClock::HTClock() { }

uint8_t HTClock::second() {
  return HTRead(0);
}
uint8_t HTClock::minute() {
  return HTRead(1);
}
uint8_t HTClock::hour() {
  return HTRead(2);
}
uint8_t HTClock::day() {
  return HTRead(3);
}
uint8_t HTClock::month() {
  return HTRead(4);
}
uint8_t HTClock::dayOfWeek() {
  return HTRead(5);
}
uint8_t HTClock::year() {
  return HTRead(6);
}


void  HTClock::set(const uint8_t second, const uint8_t minute, const uint8_t hour, const uint8_t dayOfWeek, const uint8_t dayOfMonth, const uint8_t month, const uint8_t year) {
   HT1382_YIELD
    Wire.beginTransmission(0x68);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(second)); // set seconds
  Wire.write(decToBcd(minute)); // set minutes
  Wire.write(0B10000000 |decToBcd(hour)); // set hours
  Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.write(decToBcd(0)); // set seconds

  Wire.endTransmission();
 HT1382_YIELD
}
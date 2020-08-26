/*
 
 */
 
#ifndef HT1382

#if ARDUINO_ARCH_ESP8266
		/**
		 * \brief ESP8266, yield to don't block ESP functionality.
		 *
		 * When this library is used in other MCUs this is simply removed by the preprocessor
		 */
		#define HT1382_YIELD yield();
	#else
		#if ARDUINO_ARCH_ESP32
		/**
		 * \brief ESP32, yield to don't block ESP functionality.
		 *
		 * When this library is used in other MCUs this is simply removed by the preprocessor
		 */
			#define HT1382_YIELD yield();
		#else
			#define HT1382_YIELD
		#endif
	#endif





#define decToBcd(val) ((uint8_t) ((val / 10 * 16) + (val % 10)))
#define bcdToDec(val) ((uint8_t) ((val / 16 * 10) + (val % 16)))
class HTClock {
    public:
      /******* Constructors *******/
      HTClock();

      /******* RTC functions ********/
//      void refresh();
      uint8_t second();
      uint8_t minute();
      uint8_t hour();
      uint8_t day();
      uint8_t month();
      uint8_t year();
      uint8_t dayOfWeek();
//      int16_t temp();
      void set(const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t);

//      void set_rtc_address(const int);
//      void set_model(const uint8_t);
 //     uint8_t model();

      /******* Power ********/
//      bool lostPower();
//      void lostPowerClear();
//      bool enableBattery(); // Only DS3231 and DS3232.
  //    bool disableBattery();


      /******** Alarms ************/
//      bool alarmSet(const uint8_t, const uint8_t, const uint8_t, const uint8_t, const uint8_t); // Seconds will be ignored on Alarm 2
//      bool alarmDisable(const uint8_t);
//      bool alarmClearFlag(const uint8_t);
 //     uint8_t alarmMode(const uint8_t);
//      uint8_t alarmSecond(const uint8_t);
  //    uint8_t alarmMinute(const uint8_t);
//      uint8_t alarmHour(const uint8_t);
//      uint8_t alarmDayDow(const uint8_t);

      /*********** SQWG ************/
//      uint8_t sqwgMode();
//      bool sqwgSetMode(const uint8_t);


/*
    private:
byte HTRead(byte address);

      // Address
      int _rtc_address = URTCLIB_ADDRESS;
      // RTC rad data
      uint8_t _second = 0;
      uint8_t _minute = 0;
      uint8_t _hour = 0;
      uint8_t _day = 0;
      uint8_t _month = 0;
      uint8_t _year = 0;
      uint8_t _dayOfWeek = 0;
*/
  };

#endif
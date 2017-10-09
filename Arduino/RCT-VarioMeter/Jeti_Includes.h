// For example #include <Sensor_Library.h>
#include <EEPROM.h>
#include <stdlib.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

// Set sensor-type based on saved setting - If not saved default to BMP280

#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp280;
#include <Adafruit_BME280.h>
Adafruit_BME280 bme280;
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp085;

/*int type = EEPROM.read(1);
  #define SENSOR_TYPE type

  #if SENSOR_TYPE == 0
  int senType = 0;
  #include <Adafruit_BMP280.h>
  Adafruit_BMP280 bmp;
  #elif SENSOR_TYPE == 1
  int senType = 1;
  #include <Adafruit_BME280.h>
  Adafruit_BME280 bmp;
  #elif SENSOR_TYPE == 2
  int senType = 2;
  #include <Adafruit_BMP085.h>
  Adafruit_BMP085 bmp;
  #elif SENSOR_TYPE > 2
  int senType = 0;
  #include <Adafruit_BMP280.h>
  Adafruit_BMP280 bmp;
  #endif*/

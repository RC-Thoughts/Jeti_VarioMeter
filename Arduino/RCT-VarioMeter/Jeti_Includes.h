// For example #include <Sensor_Library.h>
#include <EEPROM.h>
#include <stdlib.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>

// Libraries for different sensor-modules
#include <Adafruit_BMP280.h>
#include <Adafruit_BME280.h>
#include <Adafruit_BMP085.h>
#include <MS5611.h>
#include <LPS.h>
Adafruit_BMP280 bmp280;
Adafruit_BME280 bme280;
Adafruit_BMP085 bmp085;
MS5611 ms5611;
LPS lps;

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


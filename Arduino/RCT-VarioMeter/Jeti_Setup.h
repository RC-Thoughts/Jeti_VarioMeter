// Stuff that needs to be inside void setup()

// Sensor Name, Serial speed is 9900 for Pro Mini 3.3V due software serial
JB.Init(F("RCT Vario"), JETI_RX, 9900);

// identify sensor
if (bmp085.begin()) {
  pressureSensor.type = BMP085_BMP180;
} else if (bmp280.begin(0x77)) {
  pressureSensor.type = BMP280;
} else if (bmp280.begin(0x76)) {
  pressureSensor.type = BMP280;
} else if (bme280.begin(0x77)) {
  pressureSensor.type = BME280;
} else if (bme280.begin(0x76)) {
  pressureSensor.type = BME280;
} else if (lps.init()) {
  Wire.begin();
  lps.enableDefault();
  pressureSensor.type = LPS;
} else {
  Wire.beginTransmission(MS5611_ADDRESS); // if no Bosch sensor, check if return an ACK on MS5611 address
  if (Wire.endTransmission() == 0) {
    ms5611.begin(MS5611_ULTRA_HIGH_RES);
    pressureSensor.type = MS5611;
  }
}

// If first start of sensor store default values and restart
if (EEPROM.read(10) != 1) {
  switch (pressureSensor.type) {
    case BMP085_BMP180 : {
        pressureSensor.filterX = BMP085_FILTER_X;
        pressureSensor.filterY = BMP085_FILTER_Y;
        pressureSensor.deadzone = BMP085_DEADZONE;
        break;
      }
    case BMP280 : {
        pressureSensor.filterX = BMx280_FILTER_X;
        pressureSensor.filterY = BMx280_FILTER_Y;
        pressureSensor.deadzone = BMx280_DEADZONE;
        break;
      }
    case BME280 : {
        pressureSensor.filterX = BMx280_FILTER_X;
        pressureSensor.filterY = BMx280_FILTER_Y;
        pressureSensor.deadzone = BMx280_DEADZONE;
        break;
      }
    case MS5611 : {
        pressureSensor.filterX = MS5611_FILTER_X;
        pressureSensor.filterY = MS5611_FILTER_Y;
        pressureSensor.deadzone = MS5611_DEADZONE;
        break;
      }
    case LPS : {
        pressureSensor.filterX = LPS_FILTER_X;
        pressureSensor.filterY = LPS_FILTER_Y;
        pressureSensor.deadzone = LPS_DEADZONE;
        break;
      }
  }
  EEPROM.write(0, EU); // Default to EU units
  EEPROM.write(1, false); // Enable raw Vario-value
  EEPROM.write(2, int(pressureSensor.deadzone)); // Set default deadzone
  EEPROM.write(3, int(pressureSensor.filterX * 100)); // Set default FilterX
  EEPROM.write(4, int(pressureSensor.filterY * 100)); // Set default FilterY
  EEPROM.write(10, true); // Set First init to done
  for (int i = 0; i <= 4; i++) { // Blink on-board LED five times
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

//read values from EEprom
units = EEPROM.read(0); // EU/US units?
viewRawVario = EEPROM.read(1); // Raw Vario value used?
tempViewRawVario = viewRawVario;
pressureSensor.deadzone = EEPROM.read(2); // Deadzone?
pressureSensor.filterX = (float)EEPROM.read(3) / 100; // Filter X?
pressureSensor.filterY = (float)EEPROM.read(4) / 100; // Filter Y?

// Define Jeti Sensor value name & unit & variable & precision (decimals)
// JB.setValue30(JB.addData(F("NAME"), F("UNIT")), &VARIABLE, DEC);
//
// Sensor-value ranges:
// JB.setValue6 =   -31 to 31               (Variable is uint8_t)
// JB.setValue14 =  -8191 to 8191           (Variable is int)
// JB.setValue30 =  -536870911 to 536870911 (Variable is long)

if (units == EU) {
  JB.setValue30(JB.addData(F("Rel. Altit"), F("m")), &uRelAltitude, 1);
  JB.setValue30(JB.addData(F("Altitude"), F("m")), &uAbsAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("m/s")), &uVario, 2);
  JB.setValue30(JB.addData(F("Pressure"), F("hPa")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x43")), &uTemperature, 1);
  if (viewRawVario) {
    JB.setValue30(JB.addData(F("Vario Raw"), F("m/s")), &uRawVario, 2);
  }
} else {
  JB.setValue30(JB.addData(F("Rel. Altit"), F("ft")), &uRelAltitude, 1);
  JB.setValue30(JB.addData(F("Altitude"), F("ft")), &uAbsAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("ft/s")), &uVario, 2);
  JB.setValue30(JB.addData(F("Pressure"), F("inHG")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x46")), &uTemperature, 1);
  if (viewRawVario) {
    JB.setValue30(JB.addData(F("Vario Raw"), F("ft/s")), &uRawVario, 2);
  }
}

// If we have BME280 add humidity sensor
if (pressureSensor.type == BME280) {
  JB.setValue30(JB.addData(F("Humidity"), F("%rH")), &uHumidity, 1);
}

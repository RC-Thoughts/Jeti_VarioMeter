// Stuff that needs to be inside void setup()

// Sensor Name, Serial speed is 10240 for Pro Mini 3.3V due software serial
JB.Init(F("RCT Vario"), JETI_RX, 10240);

// If first start of sensor store default values and restart
initDone = EEPROM.read(10);
if (initDone != 1) {
  EEPROM.write(0, 0); // Default to EU units
  EEPROM.write(1, 0); // Default to BMP280 sensor
  EEPROM.write(2, 3); // Default to Deadzone 3
  EEPROM.write(3, 88); // Default to FilterX 0.88
  EEPROM.write(4, 15); // Default to FilterY 0.15
  EEPROM.write(10, 1); // Set First init to done
  for (int i = 0; i <= 4; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

// Read EU/US
units = EEPROM.read(0);
if (units < 0 or units > 1) {
  units = 0;
}

// Read sensor type
senStore = EEPROM.read(1);
if (senStore < 0 or senStore > 3) {
  senStore = 0;
}
senType = senStore;

// Read Deadzone and set to default 3 if not set
DEADZONE_UP = EEPROM.read(2);
if (DEADZONE_UP < 0 or DEADZONE_UP > 5) {
  DEADZONE_UP = 3;
}
DEADZONE_DOWN = (DEADZONE_UP * -1);

// Read Filter X and set to default 0.88 if not set
FilterX = EEPROM.read(3);
if (FilterX <= 0 or FilterX >= 100) {
  FilterX = 88;
}
FILTER_X = (float)FilterX / 100;

// Read Filter Y and set to default 0.15 if not set
FilterY = EEPROM.read(4);
if (FilterY <= 0 or FilterY >= 100) {
  FilterY = 15;
}
FILTER_Y = (float)FilterY / 100;

// Define Jeti Sensor value name & unit & variable & precision (decimals)
// JB.setValue30(JB.addData(F("NAME"), F("UNIT")), &VARIABLE, DEC);
//
// Sensor-value ranges:
// JB.setValue6 =   -31 to 31               (Variable is uint8_t)
// JB.setValue14 =  -8191 to 8191           (Variable is int)
// JB.setValue30 =  -536870911 to 536870911 (Variable is long)

if (units == 0) {
  JB.setValue30(JB.addData(F("Rel. Altit"), F("m")), &uAltitude, 1);
  JB.setValue30(JB.addData(F("Altitude"), F("m")), &uAbsAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("m/s")), &uVario, 2);
  JB.setValue30(JB.addData(F("Pressure"), F("hPa")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x43")), &uTemperature, 1);
} else {
  JB.setValue30(JB.addData(F("Rel. Altit"), F("ft")), &uAltitude, 1);
  JB.setValue30(JB.addData(F("Altitude"), F("ft")), &uAbsAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("ft/s")), &uVario, 2);
  JB.setValue30(JB.addData(F("Pressure"), F("inHG")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x46")), &uTemperature, 1);
}

// If we have BME280 add humidity sensor
if (senType == 1) {
  JB.setValue30(JB.addData(F("Humidity"), F("%rH")), &uHumidity, 1);
}

// Start using correct sensor-library based on used sensor type
if (senType == 0) {
  bmp280.begin(); // Start BMP280
} else if (senType == 1) {
  bme280.begin(); // Start BME280
} else if (senType <= 3) {
  bmp085.begin(); // Start BMP085 or BMP180
}

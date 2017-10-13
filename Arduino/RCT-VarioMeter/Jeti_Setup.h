// Stuff that needs to be inside void setup()

// Sensor Name, Serial speed is 10240 for Pro Mini 3.3V due software serial
JB.Init(F("RCT Vario"), JETI_RX, 9900);

// Read EU/US
units = EEPROM.read(0);
if (units < 0 or units > 1) {
  units = 0;
}

// Read sensor type
senStore = EEPROM.read(1);
if (senStore < 0 or senStore > 2) {
  senStore = 0;
}
senType = senStore;

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
  bmp280.begin();
} else if (senType == 1) {
  bme280.begin();
} else if (senType == 2) {
  bmp085.begin();
} else {
  bmp280.begin();
}


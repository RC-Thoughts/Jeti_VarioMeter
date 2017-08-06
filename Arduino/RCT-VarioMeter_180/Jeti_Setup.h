//
// Stuff that needs to be inside void setup()
//

// Sensor Name
// Serial speed is 10240 for Pro Mini 3.3V due software serial
JB.Init(F("RCT Vario"), JETI_RX, 9900);

// Read EU/US
units = EEPROM.read(0);
if (units == 255 or units == 254) {
  units = 0;
}

// Define Jeti Sensor value name & unit & variable & precision (decimals)
// JB.setValue30(JB.addData(F("NAME"), F("UNIT")), &VARIABLE, DEC);
//
// Sensor-value ranges:
// JB.setValue6 =   -31 to 31               (Variable is uint8_t)
// JB.setValue14 =  -8191 to 8191           (Variable is int)
// JB.setValue30 =  -536870911 to 536870911 (Variable is long)

if (units == 0) {
  JB.setValue30(JB.addData(F("Altitude"), F("m")), &uAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("m/s")), &uVario, 1);
  JB.setValue30(JB.addData(F("Pressure"), F("hpa")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x43")), &uTemperature, 2);
} else {
  JB.setValue30(JB.addData(F("Altitude"), F("ft")), &uAltitude, 0);
  JB.setValue30(JB.addData(F("Vario"), F("ft/s")), &uVario, 1);
  JB.setValue30(JB.addData(F("Pressure"), F("inHG")), &uPressure, 2);
  JB.setValue30(JB.addData(F("Temperature"), F("\xB0\x46")), &uTemperature, 2);
}

bmp.begin();

// Build Jetibox screens

switch (current_screen)
{
case aboutScreen : {
    JB.JetiBox_P(ABOUT_1, ABOUT_2);
    break;
  }
case viewCurAltVario : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    // Line 1 - Altitude
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uRelAltitude / 10), 1);

    // Get length of value
    int charLength;
    size_t strlen(const char *temp);
    charLength = strlen(temp);

    // Set spacing for m / ft
    if (units == 0) {
      strcat_P((char*)&msg_line1, (const char*)F("Alt: "));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("Alt:"));
    }
    if (uRelAltitude >= 0) {
      if (charLength == 3) {
        strcat_P((char*)&msg_line1, (const char*)F("    "));
      } else if (charLength == 4) {
        strcat_P((char*)&msg_line1, (const char*)F("   "));
      } else if (charLength == 5) {
        strcat_P((char*)&msg_line1, (const char*)F("  "));
      } else if (charLength == 5) {
        strcat_P((char*)&msg_line1, (const char*)F(" "));
      } else {
        strcat_P((char*)&msg_line1, (const char*)F(""));
      }
    } else {
      if (charLength == 4) {
        strcat_P((char*)&msg_line1, (const char*)F("   "));
      } else if (charLength == 5) {
        strcat_P((char*)&msg_line1, (const char*)F("  "));
      } else if (charLength == 6) {
        strcat_P((char*)&msg_line1, (const char*)F(" "));
      } else {
        strcat_P((char*)&msg_line1, (const char*)F(""));
      }
    }
    strcat((char*)&msg_line1, (char*)&temp);
    if (units == 0) {
      strcat_P((char*)&msg_line1, (const char*)F("m"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("ft"));
    }

    // Line 2 - Vario
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uVario / 100), 2);

    // Get length of value
    charLength = 0;
    size_t strlen(const char *temp);
    charLength = strlen(temp);

    // Set spacing for m / ft
    if (units == 0) {
      strcat_P((char*)&msg_line2, (const char*)F("Var: "));
    } else {
      strcat_P((char*)&msg_line2, (const char*)F("Var:"));
    }

    if (uVario >= 0) {
      if (charLength == 3) {
        strcat_P((char*)&msg_line2, (const char*)F("     "));
      } else if (charLength == 4) {
        strcat_P((char*)&msg_line2, (const char*)F("    "));
      } else if (charLength == 5) {
        strcat_P((char*)&msg_line2, (const char*)F("   "));
      } else {
        strcat_P((char*)&msg_line2, (const char*)F("  "));
      }
    } else {
      if (charLength == 4) {
        strcat_P((char*)&msg_line2, (const char*)F("    "));
      } else if (charLength == 5) {
        strcat_P((char*)&msg_line2, (const char*)F("   "));
      } else if (charLength == 6) {
        strcat_P((char*)&msg_line2, (const char*)F("  "));
      } else {
        strcat_P((char*)&msg_line2, (const char*)F(" "));
      }
    }
    strcat((char*)&msg_line2, (char*)&temp);
    if (units == 0) {
      strcat_P((char*)&msg_line2, (const char*)F("m/s"));
    } else {
      strcat_P((char*)&msg_line2, (const char*)F("ft/s"));
    }

    // Create line
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case viewCurTempPres: {
    msg_line1[0] = 0; msg_line2[0] = 0;
    // Line 1
    strcat_P((char*)&msg_line1, (const char*)F("Temp: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uTemperature / 10), 1);
    strcat((char*)&msg_line1, (char*)&temp);
    if (units == US) {
      strcat_P((char*)&msg_line1, (const char*)F("\xB0\x46"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("\xB0\x43"));
    }
    // Line 2
    strcat_P((char*)&msg_line2, (const char*)F("Pres: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uPressure / 100), 1);
    strcat((char*)&msg_line2, (char*)&temp);
    if (units == US) {
      strcat_P((char*)&msg_line2, (const char*)F("inHG"));
    } else {
      strcat_P((char*)&msg_line2, (const char*)F("hPa"));
    }
    // Create line
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case resetAltitude : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    //strcat_P((char*)&msg_line1, (const char*)F("Altitude Reset"));
    //strcat_P((char*)&msg_line2, (const char*)F("Reset Dn Next >"));
    strcat_P((char*)&msg_line1, (const char*)F("Altitude Reset?"));
    strcat_P((char*)&msg_line2, (const char*)F("Press: Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setFilterX : {
    // Filter X
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Filter X: "));
    temp[0] = 0;
    floatToString((char*)&temp, (pressureSensor.filterX), 2);
    strcat((char*)&msg_line1, (char*)&temp);
    strcat_P((char*)&msg_line2, (const char*)F("Change: Up/Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setFilterY : {
    // Filter Y
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Filter Y: "));
    temp[0] = 0;
    floatToString((char*)&temp, (pressureSensor.filterY), 2);
    strcat((char*)&msg_line1, (char*)&temp);
    strcat_P((char*)&msg_line2, (const char*)F("Change: Up/Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setDeadzone : {
    // Deadzone
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Deadzone: "));
    temp[0] = 0;
    floatToString((char*)&temp, (pressureSensor.deadzone), 0);
    strcat((char*)&msg_line1, (char*)&temp);
    strcat_P((char*)&msg_line2, (const char*)F("Change: Up/Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case detectedSensor : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Detected Sensor:"));
    switch (pressureSensor.type) {
      case unknown : {
          strcat_P((char*)&msg_line2, (const char*)F("Not Detected!"));
          break;
        }
      case BMP085_BMP180 : {
          strcat_P((char*)&msg_line2, (const char*)F("Found BMP085/180"));
          break;
        }
      case BMP280 : {
          strcat_P((char*)&msg_line2, (const char*)F("Found BMP280"));
          break;
        }
      case BME280 : {
          strcat_P((char*)&msg_line2, (const char*)F("Found BME280"));
          break;
        }
      case MS5611 : {
          strcat_P((char*)&msg_line2, (const char*)F("Found MS5611"));
          break;
        }
      case LPS : {
          strcat_P((char*)&msg_line2, (const char*)F("Found LPS"));
          break;
        }
    }
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setUnits : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Units: "));
    if (units == US) {
      strcat_P((char*)&msg_line1, (const char*)F("\x55\x53\x28\x66\x74\x2C\xDF\x46\x29"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("\x45\x55\x28\x6D\x2C\xDF\x43\x29"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Change: Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setRawVario : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Raw Vario: "));
    if (tempViewRawVario) {
      strcat_P((char*)&msg_line1, (const char*)F("On"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("Off"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Change: Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case saveSettings : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Save and Restart"));
    strcat_P((char*)&msg_line2, (const char*)F("Save: Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case defaultSettings : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Reset Defaults"));
    strcat_P((char*)&msg_line2, (const char*)F("Reset: Down"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
}

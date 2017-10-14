// Build Jetibox screens

switch (current_screen)
{
case aboutScreen : {
    JB.JetiBox_P(ABOUT_1, ABOUT_2);
    break;
  }
case viewCurAltitude : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    // Line 1
    strcat_P((char*)&msg_line1, (const char*)F("Altit: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uRelAltitude / 10), 1);
    strcat((char*)&msg_line1, (char*)&temp);
    if (units == 1) {
      strcat_P((char*)&msg_line1, (const char*)F("ft"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("m"));
    }
    // Line 2
    strcat_P((char*)&msg_line2, (const char*)F("Vario: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uVario / 100), 2);
    strcat((char*)&msg_line2, (char*)&temp);
    if (units == 1) {
      strcat_P((char*)&msg_line2, (const char*)F("ft/s"));
    } else {
      strcat_P((char*)&msg_line2, (const char*)F("m/s"));
    }
    // Create line
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case viewCurTemperature : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    // Line 1
    strcat_P((char*)&msg_line1, (const char*)F("Temp: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uTemperature / 10), 1);
    strcat((char*)&msg_line1, (char*)&temp);
    if (units == 1) {
      strcat_P((char*)&msg_line1, (const char*)F("\xB0\x46"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("\xB0\x43"));
    }
    // Line 2
    strcat_P((char*)&msg_line2, (const char*)F("Pres: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uPressure / 100), 1);
    strcat((char*)&msg_line2, (char*)&temp);
    if (units == 1) {
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
    strcat_P((char*)&msg_line1, (const char*)F("Altitude Reset"));
    strcat_P((char*)&msg_line2, (const char*)F("Press DN"));
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
    strcat_P((char*)&msg_line2, (const char*)F("Chg UpDn Next >"));
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
    strcat_P((char*)&msg_line2, (const char*)F("Chg UpDn Next >"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setDeadzone : {
    // Deadzone
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Deadzone cm: "));
    temp[0] = 0;
    floatToString((char*)&temp, (pressureSensor.deadzone), 0);
    strcat((char*)&msg_line1, (char*)&temp);
    strcat_P((char*)&msg_line2, (const char*)F("Chg UpDn Next >"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setUnits : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Units:  "));
    if (units == US) {
      strcat_P((char*)&msg_line1, (const char*)F("US"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("EU"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Chg DN Next >"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case detectedSensor : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("detected Sensor: "));
    switch (pressureSensor.type){
      case unknown : {
        strcat_P((char*)&msg_line2, (const char*)F("not available"));
        break;
      }
      case BMP085_BMP180 : {
        strcat_P((char*)&msg_line2, (const char*)F("BMP085/BMP180"));
        break;
      }
      case BMP280 : {
        strcat_P((char*)&msg_line2, (const char*)F("BMP280"));
        break;
      }
      case BME280 : {
        strcat_P((char*)&msg_line2, (const char*)F("BME280"));
        break;
      }
      case MS5611 : {
        strcat_P((char*)&msg_line2, (const char*)F("MS5611"));
        break;
      }
    }
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case setRawVario : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("raw Vario: "));
    if (tempJBviewRawVario) {
      strcat_P((char*)&msg_line1, (const char*)F("ON"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("OFF"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Chg DN Next >"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case saveSettings : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Save and restart"));
    strcat_P((char*)&msg_line2, (const char*)F("Press: DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case defaultSettings : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("default settings"));
    strcat_P((char*)&msg_line2, (const char*)F("Press: DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
}

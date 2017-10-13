// Build Jetibox screens

switch (current_screen)
{
case 0 : {
    JB.JetiBox_P(ABOUT_1, ABOUT_2);
    break;
  }
case 1 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    // Line 1
    strcat_P((char*)&msg_line1, (const char*)F("Altit: "));
    temp[0] = 0;
    floatToString((char*)&temp, ((float)uAltitude / 10), 1);
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
case 2 : {
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
case 3 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Altitude Reset"));
    strcat_P((char*)&msg_line2, (const char*)F("Press DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case 4 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Units:  "));
    if (units == 1) {
      strcat_P((char*)&msg_line1, (const char*)F("US"));
    } else {
      strcat_P((char*)&msg_line1, (const char*)F("EU"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Change: DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case 5 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Sensor: "));
    if (senStore == 0) {
      strcat_P((char*)&msg_line1, (const char*)F("BMP280"));
    }
    if (senStore == 1) {
      strcat_P((char*)&msg_line1, (const char*)F("BME280"));
    }
    if (senStore == 2) {
      strcat_P((char*)&msg_line1, (const char*)F("BMP085"));
    }
    strcat_P((char*)&msg_line2, (const char*)F("Change: DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case 6 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Save and restart"));
    strcat_P((char*)&msg_line2, (const char*)F("Press: UP & DN"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
case 7 : {
    msg_line1[0] = 0; msg_line2[0] = 0;
    strcat_P((char*)&msg_line1, (const char*)F("Altitude reset"));
    strcat_P((char*)&msg_line2, (const char*)F("Press < to exit"));
    JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
    break;
  }
  JB.JetiBox((char*)&msg_line1, (char*)&msg_line2);
}

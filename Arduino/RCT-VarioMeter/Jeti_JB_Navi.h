// Jetibox navigation and button actions

// Button codes
// 224  RIGHT
// 112  LEFT
// 208  UP
// 176  DOWN
// 144  UP & DOWN
// 96   LEFT & RIGHT

int read = delayTR (GETCHAR_TIMEOUT_ms);
if ( (read != 240 ) && (read != 0) )
{
  switch (read)
  {
    case 224 : // RIGHT
      if (current_screen < MAX_SCREEN) {
        current_screen++;
      } else {
        current_screen = 0;
      }
      break;
    case 112 : // LEFT
      if (current_screen > 1) {
        current_screen--;
      } else {
        current_screen = MAX_SCREEN;
      }
      break;
    case 208 : // UP
      if (current_screen == setFilterX) {
        if (pressureSensor.filterX < 0.98) {
          pressureSensor.filterX += 0.01;
        }
      }
      if (current_screen == setFilterY) {
        if (pressureSensor.filterY < 0.98) {
          pressureSensor.filterY += 0.01;
        }
      }
      if (current_screen == setDeadzone) {
        if (pressureSensor.deadzone < 100) {
          pressureSensor.deadzone++;
        }
      }
      break;
    case 176 : // DOWN
      if (current_screen == resetAltitude) {
        startAltitude = curAltitude;
        current_screen = 1;
      }
      if (current_screen == setFilterX) {
        if (pressureSensor.filterX > 0.01) {
          pressureSensor.filterX -= 0.01;
        }
      }
      if (current_screen == setFilterY) {
        if (pressureSensor.filterY > 0.01) {
          pressureSensor.filterY -= 0.01;
        }
      }
      if (current_screen == setDeadzone) {
        if (pressureSensor.deadzone > 0) {
          pressureSensor.deadzone--;
        }
      }
      if (current_screen == setUnits) {
        if (units == EU) {
          units = US;
        } else {
          units = EU;
        }
      }
      if (current_screen == setRawVario) {
        tempViewRawVario = !tempViewRawVario;
      }
      if (current_screen == saveSettings) {
        EEPROM.write(0, units);
        EEPROM.write(1, tempViewRawVario);
        EEPROM.write(2, int(pressureSensor.deadzone));
        EEPROM.write(3, int(pressureSensor.filterX * 100));
        EEPROM.write(4, int(pressureSensor.filterY * 100));
        delay(100);
        resetFunc();
      }
      if (current_screen == defaultSettings) {
        EEPROM.write(10, 0);
        delay(100);
        resetFunc();
      }
      break;
    case 144 : // UP+DOWN
      if (current_screen == setFilterX) {
        if (pressureSensor.filterX < 0.99) {
          pressureSensor.filterX += 0.10;
        }
      }
      if (current_screen == setFilterY) {
        if (pressureSensor.filterY < 0.99) {
          pressureSensor.filterY += 0.10;
        }
      }
      if (current_screen == setDeadzone) {
        if (pressureSensor.deadzone < 100) {
          pressureSensor.deadzone += 10;
        }
      }
      break;
    case 96 : // LEFT+RIGHT
      if (current_screen == setFilterX) {
        pressureSensor.filterX = 0.01;
      }
      if (current_screen == setFilterY) {
        pressureSensor.filterY = 0.01;
      }
      if (current_screen == setDeadzone) {
        pressureSensor.deadzone = 0;
      }
      break;
  }
}

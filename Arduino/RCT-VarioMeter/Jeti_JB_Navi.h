// Jetibox navigation and button actions

// Button codes
// 224  RIGHT
// 112  LEFT
// 208  UP
// 176  DOWN
// 144  UP & DOWN
// 9    LEFT & RIGHT

int read = delayTR (GETCHAR_TIMEOUT_ms);
if ( (read != 240 ) && (read != 0) )
{
  switch (read)
  {
    case 224 : // RIGHT
      if (current_screen != MAX_SCREEN)
      {
        if (current_screen == 9) {
          EEPROM.write(0, units);
          EEPROM.write(1, senStore);
          EEPROM.write(2, DEADZONE_UP);
          EEPROM.write(3, FilterX);
          EEPROM.write(4, FilterY);
          delay(100);
          resetFunc();
        }
        if (current_screen == 10) {
          current_screen = 0;
        }
        current_screen++;
      }
      break;
    case 112 : // LEFT
      if (current_screen == 10) {
        current_screen = 1;
      }
      if (current_screen != 0) {
        current_screen--;
      }
      break;
    case 208 : // UP
      if (current_screen == 4) {
        FilterX++;
        if (FilterX == 100) {
          FilterX = 1;
        }
        FILTER_X = (float)FilterX / 100;
        current_screen = 4;
      }
      if (current_screen == 5) {
        FilterY++;
        if (FilterY == 100) {
          FilterY = 1;
        }
        FILTER_Y = (float)FilterY / 100;
        current_screen = 5;
      }
      if (current_screen == 6) {
        if (DEADZONE_UP < 5) {
          DEADZONE_UP++;
        } else if (DEADZONE_UP == 5) {
          DEADZONE_UP = 0;
        }
        DEADZONE_DOWN = (DEADZONE_UP * -1);
        current_screen = 6;
      }
      break;
    case 176 : // DOWN
      if (current_screen == 3) {
        startAltitude = curAltitude;
        current_screen = 10;
      }
      if (current_screen == 4) {
        FilterX--;
        if (FilterX <= 0) {
          FilterX = 1;
        }
        FILTER_X = (float)FilterX / 100;
        current_screen = 4;
      }
      if (current_screen == 5) {
        FilterY--;
        if (FilterY <= 0) {
          FilterY = 1;
        }
        FILTER_Y = (float)FilterY / 100;
        current_screen = 5;
      }
      if (current_screen == 6) {
        if (DEADZONE_UP > 0) {
          DEADZONE_UP--;
          current_screen = 6;
        } else if (DEADZONE_UP == 0) {
          DEADZONE_UP = 5;
        }
        DEADZONE_DOWN = (DEADZONE_UP * -1);
        current_screen = 6;
      }
      if (current_screen == 7) {
        if (units == 0) {
          units = 1;
        } else {
          units = 0;
        }
        current_screen = 7;
      }
      if (current_screen == 8) {
        if (senStore == 0) {
          senStore = 1;
        } else if (senStore == 1) {
          senStore = 2;
        } else if (senStore == 2) {
          senStore = 3;
        } else if (senStore == 3) {
          senStore = 0;
        }
        current_screen = 8;
      }
      break;
    case 144 : // UP+DOWN
      if (current_screen == 4) {
        FilterX = FilterX + 10;
        if (FilterX > 99) {
          FilterX = 99;
        }
        FILTER_X = (float)FilterX / 100;
        current_screen = 4;
      }
      if (current_screen == 5) {
        FilterY = FilterY + 10;
        if (FilterY > 99) {
          FilterY = 99;
        }
        FILTER_Y = (float)FilterY / 100;
        current_screen = 5;
      }
      break;
    case 96 : // LEFT+RIGHT
      if (current_screen == 4) {
        FilterX = 1;
        FILTER_X = (float)FilterX / 100;
        current_screen = 4;
      }
      if (current_screen == 5) {
        FilterY = 1;
        FILTER_Y = (float)FilterY / 100;
        current_screen = 5;
      }
      break;
  }
}

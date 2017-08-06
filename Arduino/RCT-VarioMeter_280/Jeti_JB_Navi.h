//
// Jetibox navigation and button actions
//

// Button codes
// 224  RIGHT
// 112  LEFT
// 208  UP
// 176  DOWN
// 144  UP & DOWN
// 9    LEFT & RIGHT
//
int read = delayTR (GETCHAR_TIMEOUT_ms);
if ( (read != 240 ) && (read != 0) )
{
  switch (read)
  {
    case 224 : // RIGHT
      if (current_screen != MAX_SCREEN)
      {
        current_screen++;
        if (current_screen == 6) {
          current_screen = 0;
        }
      }
      break;
    case 112 : // LEFT
      if (current_screen == 6) {
        current_screen = 1;
      }
      if (current_screen != 0) {
        current_screen--;
      }
      break;
    case 208 : // UP
      break;
    case 176 : // DOWN
      if (current_screen == 3) {
        startAltitude = average_altitude;
        current_screen = 6;
      }
      if (current_screen == 4) {
        if (units == 0) {
          units = 1;
        } else {
          units = 0;
        }
        current_screen = 4;
      }
      break;
    case 144 : // UP+DOWN
      if (current_screen == 4) {
        EEPROM.write(0, units);
        resetFunc();
      }
      break;
    case 96 : // LEFT+RIGHT
      break;
  }
}

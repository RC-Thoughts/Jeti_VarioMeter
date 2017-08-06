/*
   -----------------------------------------------------------
                   Jeti Variometer v 1.0
   -----------------------------------------------------------

    Tero Salminen RC-Thoughts.com (c) 2017 www.rc-thoughts.com

   -----------------------------------------------------------

    Simple Variometer sensor - Vertical speed in m/s or ft/s

    Includes
    - Altitude
    - Temperatue
    - Pressure
    - Vario

     Localization selectable vith Jetibox by user to EU / US:
     - Altitude     m / ft
     - Temperature  C / F
     - Pressure     hPa / inHG
     - Vario        m/s / ft/s

    Big thanks to scimart for testing with test-environment!
   -----------------------------------------------------------
    Shared under MIT-license by Tero Salminen (c) 2017
   -----------------------------------------------------------
*/

#if defined(__AVR_ATmega328P__)
#ifdef HardwareSerial_h
# error Must include disableserial.h before the Arduino serial driver is defined.
#endif
#define HardwareSerial_h
#endif
#include <Arduino.h>
#include "SoftwareSerialO2.h"
#include "JETI_EX_SENSOR_2.h"
#include "Jeti_Includes.h"

#define GETCHAR_TIMEOUT_ms 100

#ifndef JETI_RX
#define JETI_RX 3 // Pin for Jeti signal
#endif

#define MAX_CONFIG 4
#define COND_LES_EQUAL 1
#define COND_MORE_EQUAL 2

JETI_Box_class JB;

// ID number for sensor (Needs to be unique for all sensors in model)
const unsigned char Jeti_SensorID3 = 0x02;

#include "Jeti_Init.h"

uint8_t frame[10];
short cmpt = 0;
short value = 27;

// Jetibox settings
int current_screen = 0;
int current_config = 0;
int last_screen = 1;

char * floatToString(char * outstr, float value, int places, int minwidth = 0) {
  int digit;
  float tens = 0.1;
  int tenscount = 0;
  int i;
  float tempfloat = value;
  int c = 0;
  int charcount = 1;
  int extra = 0;
  float d = 0.5;
  if (value < 0)
    d *= -1.0;
  for (i = 0; i < places; i++)
    d /= 10.0;
  tempfloat +=  d;
  if (value < 0)
    tempfloat *= -1.0;
  while ((tens * 10.0) <= tempfloat) {
    tens *= 10.0;
    tenscount += 1;
  }
  if (tenscount > 0)
    charcount += tenscount;
  else
    charcount += 1;
  if (value < 0)
    charcount += 1;
  charcount += 1 + places;
  minwidth += 1;
  if (minwidth > charcount) {
    extra = minwidth - charcount;
    charcount = minwidth;
  }
  if (value < 0)
    outstr[c++] = '-';
  if (tenscount == 0)
    outstr[c++] = '0';
  for (i = 0; i < tenscount; i++) {
    digit = (int) (tempfloat / tens);
    itoa(digit, &outstr[c++], 10);
    tempfloat = tempfloat - ((float)digit * tens);
    tens /= 10.0;
  }
  if (places > 0)
    outstr[c++] = '.';
  for (i = 0; i < places; i++) {
    tempfloat *= 10.0;
    digit = (int) tempfloat;
    itoa(digit, &outstr[c++], 10);
    tempfloat = tempfloat - (float) digit;
  }
  if (extra > 0 ) {
    for (int i = 0; i < extra; i++) {
      outstr[c++] = ' ';
    }
  }
  outstr[c++] = '\0';
  return outstr;
}

// Worker to check for Jetibox button
int delayTR(int _delay)
{
  int read = 0;
  unsigned long wait_till = millis() + _delay;
  while ( millis() <  wait_till )
  {
    if (JetiSerial.available() > 0 )
    {
      read = JB.readbuttons();
      if (read != 240 && read != 0)
      {
        break;
      }
    }
  }
  return read;
}

void setup()
{
  pinMode(13, OUTPUT);      // LED
  digitalWrite(13, HIGH);   // LED

  pinMode(JETI_RX, OUTPUT); // Jeti PIN
  digitalWrite(JETI_RX, LOW);

  last_screen = current_screen;

  JB.JetiBox_P(ABOUT_1, ABOUT_2);

#include "Jeti_Setup.h"

  JB.SendFrame();
  digitalWrite(13, LOW); // LED
}

void process_screens()
{
  char msg_line1[LCDMaxPos / 2];
  char msg_line2[LCDMaxPos / 2];
  char temp[LCDMaxPos / 2];

  if (last_screen != current_screen)
  {
    last_screen = current_screen;
  }

#include "Jeti_JB_Screens.h"
}

#include "Jeti_Functions.h"

void loop()
{
#include "Jeti_Runtime.h"

  // Jeti Stuff
  if (current_screen != MAX_SCREEN)
    current_config = 0; //zero 5th screen

  process_screens();

  JB.txMode();
  JB.SendFrame();
  JB.rxMode();

#include "Jeti_JB_Navi.h"
}

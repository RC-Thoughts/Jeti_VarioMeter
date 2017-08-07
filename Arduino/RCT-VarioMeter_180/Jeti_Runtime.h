//
// This is the main loop where the work is done
//

curAltitude = bmp.readAltitude(); // In Meter
uTemperature = bmp.readTemperature() * 100; // In CelsiuS
uPressure = bmp.readPressure(); // In Pascal (100 Pa = 1 hPa = 1 mbar)

AltFilter.Filter(curAltitude);

float time = millis();
float vario = 0;
float N1 = 0;
float N2 = 0;
float N3 = 0;
float D1 = 0;
float D2 = 0;

average_altitude = AltFilter.Current();

for (int cc = 1; cc <= maxsamples; cc++) {
  alt[(cc - 1)] = alt[cc];
  tim[(cc - 1)] = tim[cc];
};
alt[maxsamples] = AltFilter.Current() * 10;
tim[maxsamples] = time;
float stime = tim[maxsamples - samples];

for (int cc = (maxsamples - samples); cc < maxsamples; cc++) {
  N1 += (tim[cc] - stime) * alt[cc];
  N2 += (tim[cc] - stime);
  N3 += (alt[cc]);
  D1 += (tim[cc] - stime) * (tim[cc] - stime);
  D2 += (tim[cc] - stime);
};

vario = 1000 * ((samples * N1) - N2 * N3) / (samples * D1 - D2 * D2);
VarFilter.Filter(vario);
uVario = vario;

uAltitude = average_altitude - startAltitude;
uAbsAltitude = average_altitude;

if (uLoopCount == 20) {
  startAltitude = average_altitude;
}

if (uLoopCount < 40) {
  uLoopCount++;
  uAltitude = 0;
  uAbsAltitude = 0;
  uVario = 0;
}

// EU to US conversions
// ft/s = m/s / 0.3048
// inHG = hPa * 0,029529983071445
// ft = m / 0.3048
if (units == 1) {
  uAltitude = uAltitude / 0.3048;
  uAbsAltitude = uAbsAltitude / 0.3048;
  uVario = uVario / 0.3048;
  uPressure = uPressure * 0.029529983071445;
  uTemperature = uTemperature * 1.8 + 32;
}

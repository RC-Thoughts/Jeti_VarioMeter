// This is the main loop where the work is done

// Read sensormodule values
if (pressureSensor.type == BMP085_BMP180) {
  curAltitude = bmp085.readAltitude(101325) * 100; // In Centimeter
  uTemperature = bmp085.readTemperature() * 10; // In Celsius ( x10 for one decimal)
  uPressure = bmp085.readPressure(); // In Pascal (100 Pa = 1 hPa = 1 mbar)
}else if (pressureSensor.type == BMP280) {
  curAltitude = bmp280.readAltitude(1013.25) * 100; // In Centimeter
  uTemperature = bmp280.readTemperature() * 10; // In Celsius ( x10 for one decimal)
  uPressure = bmp280.readPressure(); // In Pascal (100 Pa = 1 hPa = 1 mbar)
}else if (pressureSensor.type == BME280) {
  curAltitude = bme280.readAltitude(1013.25) * 100; // In Centimeter
  uTemperature = bme280.readTemperature() * 10; // In Celsius ( x10 for one decimal)
  uPressure = bme280.readPressure(); // In Pascal (100 Pa = 1 hPa = 1 mbar)
  uHumidity = bme280.readHumidity() * 10; // In %rH
}

// Set start-altitude in sensor-start
if (uLoopCount == 9) {
  startAltitude = curAltitude;
  lastVariofilter = 0;
}

// Vario calculation
uVario = (curAltitude - lastAltitude) * (1000 / float(millis() - lastTime));
uRawVario = uVario;
lastTime = millis();
lastAltitude = curAltitude;

// Vario Filter
float fX;
float fY = uVario;
fX = pressureSensor.filterX * lastVariofilter;
fY = pressureSensor.filterY * fY;
lastVariofilter = fX + fY;
uVario = lastVariofilter;

// Dead zone filter
if (uVario > pressureSensor.deadzone) {
  uVario -= pressureSensor.deadzone;
}
else if (uVario < (pressureSensor.deadzone* -1)) {
  uVario -= (pressureSensor.deadzone* -1);
}
else {
  uVario = 0;
}

// Altitude
uRelAltitude = (curAltitude - startAltitude) / 10;
uAbsAltitude = curAltitude / 100;

if (uLoopCount < 10) {
  uLoopCount++;
  uVario = 0;
  uRelAltitude = 0;
  uAbsAltitude = 0;
}

// EU to US conversions
// ft/s = m/s / 0.3048
// inHG = hPa * 0,029529983071445
// ft = m / 0.3048
if (units == US) {
  uRelAltitude = uRelAltitude / 0.3048;
  uAbsAltitude = uAbsAltitude / 0.3048;
  uVario = uVario / 0.3048;
  uRawVario = uRawVario / 0.3048;
  uPressure = uPressure * 0.029529983071445;
  uTemperature = uTemperature * 1.8 + 32;
}

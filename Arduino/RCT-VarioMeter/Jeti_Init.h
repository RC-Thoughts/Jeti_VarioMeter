// Stuff done in initialisation of sketch

// Jetibox Start Screen
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F(" Variometer 1.4")

// Max screens in jetibox (navigating over this goes to start)
#define MAX_SCREEN 11

// Jetibox screens, names and order
enum screenViews {
  aboutScreen,
  viewCurAltVario,
  viewCurTempPres,
  resetAltitude,
  setFilterX,
  setFilterY,
  setDeadzone,
  detectedSensor,
  setUnits,
  setRawVario,
  saveSettings,
  defaultSettings
};

// ID number for sensor (Needs to be unique for all sensors in model 0xA400 – 0xA41F)
const unsigned char Jeti_SensorID3 = 0x02;
const unsigned char Jeti_SensorID4 = 0x08;

// Sensors
int uLoopCount = 0;
long uRelAltitude = 0;
long uAbsAltitude = 0;
long uPressure = 0;
long uTemperature = 0;
long uVario = 0;
long uRawVario = 0;
double lastVariofilter = 0;
long curAltitude = 0;
long lastAltitude = 0;
unsigned long lastTime = 0;
long startAltitude = 0;
long uHumidity = 0;
bool viewRawVario;
bool tempViewRawVario;

// EU/US Units
enum unitType {EU, US};
unitType units = EU;

// Sensor type
enum senType {
  unknown,
  BMP085_BMP180,
  BMP280,
  BME280,
  MS5611,
  LPS
};

struct {
  senType type = unknown;
  float filterX = 0.5;
  float filterY = 0.5;
  long deadzone = 0;
} pressureSensor;

// Vario lowpass filter and
// dead zone filter in centimeter (Even if you use US-units!)

// BMP085/BMP180
#define BMP085_FILTER_X 0.5
#define BMP085_FILTER_Y 0.5
#define BMP085_DEADZONE 0

// BMP280/BME280
#define BMx280_FILTER_X 0.88
#define BMx280_FILTER_Y 0.15
#define BMx280_DEADZONE 3

// MS5611
#define MS5611_FILTER_X 0.5
#define MS5611_FILTER_Y 0.5
#define MS5611_DEADZONE 0

// LPS (LPS311)
#define LPS_FILTER_X 0.5
#define LPS_FILTER_Y 0.5
#define LPS_DEADZONE 0

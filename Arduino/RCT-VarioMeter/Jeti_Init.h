// Stuff done in initialisation of sketch

// Jetibox Start Screen
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F("   Variometer")

// Max screens in jetibox (navigating over this goes to start)
#define MAX_SCREEN 6

// ID number for sensor (Needs to be unique for all sensors in model)
const unsigned char Jeti_SensorID3 = 0x02;
const unsigned char Jeti_SensorID4 = 0x08;

// Sensors
int uLoopCount = 0;
long uAltitude = 0;
long uAbsAltitude = 0;
long uPressure = 0;
long uTemperature = 0;
long uVario = 0;
double lastVariofilter = 0;
long curAltitude = 0;
long lastAltitude = 0;
unsigned long lastTime = 0;
long startAltitude = 0;
//#if SENSOR_TYPE == 1
  long uHumidity = 0;
//#endif

// EU/US Units
int units = 0;

// Sensor type
int senType = 0;
int senStore = 0;

// Vario lowpass filter
#define FILTER_X 0.88
#define FILTER_Y 0.15

// Vario dead zone filter in centimeter (Even if you use US-units!)
#define DEADZONE_UP 5
#define DEADZONE_DOWN -5

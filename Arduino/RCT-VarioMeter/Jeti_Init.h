// Stuff done in initialisation of sketch

// Jetibox Start Screen
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F(" Variometer 1.3")

// Max screens in jetibox (navigating over this goes to start)
#define MAX_SCREEN 10

// ID number for sensor (Needs to be unique for all sensors in model 0xA400 – 0xA41F)
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
long uHumidity = 0;

// Init done?
int initDone;

// EU/US Units
int units = 0;

// Sensor type
int senStore = 0;
int senType = 0;

// Vario lowpass filter
int FilterX = 88;
int FilterY = 15;
float FILTER_X;
float FILTER_Y;

// Vario dead zone filter in centimeter (Even if you use US-units!)
int DEADZONE_UP = 3;
int DEADZONE_DOWN = -3;

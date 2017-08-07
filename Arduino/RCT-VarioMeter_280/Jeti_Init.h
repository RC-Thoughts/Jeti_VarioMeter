//
// Stuff done in initialisation of sketch
//

// Jetibox Start Screen
//
#define ABOUT_1 F(" RCT Jeti Tools")
#define ABOUT_2 F("   Variometer")

//
// Max screens in jetibox (navigating over this goes to start)
//
#define MAX_SCREEN 5

//
// Sensor ID (0x02) - Needs to be unique in a model
//
const unsigned char Jeti_SensorID4 = 0x08;

//
// Sensor variables & other init-stuff nede
//

// Sensors
int uLoopCount = 0;
long uAltitude = 0;
long uAbsAltitude = 0;
long uPressure = 0;
long uTemperature = 0;
long uVario = 0;
long curAltitude = 0;
long startAltitude = 0;

// EU/US Units
int units = 0;

// Filter
ExponentialFilter<long> AltFilter(50, 0);
ExponentialFilter<long> VarFilter(80, 0);

// Vario
#define sample_count 2
long average_altitude = 0;
int samples = 10;
int maxsamples = 13;
float alt[51];
float tim[51];
static long k[sample_count];

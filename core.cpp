
//btw the accelerometer is called the ADXL345
//accelerometer uses xzy not xyz
#include <math.h>

//#include <Adafruit_Sensor.h> 
#include <Wire.h>
#include <ADXL345.h>


//#include <stdlib.h>

ADXL345 accel(ADXL345_STD);

struct Accel3 {
float x{0.0};
float z{0.0};
float y{0.0};

// vectors for acceleration



  String toString() {
        return "acceleration: " + String(x) + ", " + String(z) + ", " + String(y); //for outputting data
    }



    Accel3(float _x = 0.0, float _z = 0.0, float _y = 0.0)  // Constructor
        : x(_x), z(_z), y(_y) {}

};


//this will be the highest acceleration recorded

void SetupSensor()
{
 //  Wire.begin();

  byte deviceID = accel.readDeviceID();
  if (deviceID != 0) {
    Serial.print("0x");
    Serial.print(deviceID, HEX);
    Serial.println("");
  } else {
    Serial.println("read device id: failed");
    while(1) {
      delay(100);
    }
  }

  // Data Rate
  // - ADXL345_RATE_3200HZ: 3200 Hz
  // - ADXL345_RATE_1600HZ: 1600 Hz
  // - ADXL345_RATE_800HZ:  800 Hz
  // - ADXL345_RATE_400HZ:  400 Hz
  // - ADXL345_RATE_200HZ:  200 Hz
  // - ADXL345_RATE_100HZ:  100 Hz
  // - ADXL345_RATE_50HZ:   50 Hz
  // - ADXL345_RATE_25HZ:   25 Hz
  // - ...
  if (!accel.writeRate(ADXL345_RATE_200HZ)) {
    Serial.println("write rate: failed / setup stopped");
    while(1) {
      delay(100);
    }
  }

  // Data Range
  // - ADXL345_RANGE_2G: +-2 g
  // - ADXL345_RANGE_4G: +-4 g
  // - ADXL345_RANGE_8G: +-8 g
  // - ADXL345_RANGE_16G: +-16 g
  if (!accel.writeRange(ADXL345_RANGE_16G)) {
    Serial.println("write range: failed / setup stopped");
    while(1) {
      delay(100);
    }
  }

  if (!accel.start()) {
    Serial.println("start: failed / setup stopped");
    while(1) {
      delay(100);
    }
  }
}


float accelMag(float x, float z, float y)
{
return sqrt((x*x)+(z*z)+(y*y));
}
// this is for magnitude 

struct Accel3 HighestAccel(0.0, 0.0, 0.0);
//struct Accel3 AccelAverage(0.0, 0.0, 0.0);
//int Iters = 0; 
 // keep the average as the pure sum and increase the iteration counter to make it divide into an accurate average without weird arduino linked lists


void CategorizeData(float X, float Z, float Y)
{
if (accelMag(HighestAccel.x, HighestAccel.z, HighestAccel.y) <= accelMag(X, Z, Y))
{
HighestAccel.x = X;
HighestAccel.z = Z;
HighestAccel.y = Y;
//Iters += 1
}
}

//Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
void setup() {

 
 
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Serial.println(); // arduino likes to put a bunch of weird characters in the beginning of serial monitor

  SetupSensor();

/*
   if(!accel.begin())
   {
      Serial.println("No valid sensor found - waiting");
      while(1);
   }
*/
  Serial.println(HighestAccel.toString());
  Serial.println(accelMag(HighestAccel.x, HighestAccel.z, HighestAccel.y));
//Serial.print();
}


void loop() {
  // put your main code here, to run repeatedly:
/*
 sensors_event_t event; 
  accel.getEvent(&event);

  CategorizeData(event.acceleration.x, event.acceleration.z, event.acceleration.y)

   Serial.println(HighestAccel.toString());
  delay(150)
*/
 if (accel.update()) {
    Serial.print(accel.getX());
    Serial.print(",");
    Serial.print(accel.getY());
    Serial.print(",");
    Serial.print(accel.getZ());
    Serial.println("");
  } else {
    Serial.println("update failed");
    while(1) {
      delay(100);
    }
  }
  delay(300);

}

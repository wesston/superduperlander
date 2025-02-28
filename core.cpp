//btw the accelerometer is called the ADXL345
//accelerometer uses xzy not xyz
#include <math.h>

#include <Wire.h>
#include <Adafruit_Sensor.h> 
#include <Adafruit_ADXL345_U.h>


//#include <stdlib.h>

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


float accelMag(x, z, y)
{
return sqrt((Acceleration.x*Acceleration.x)+(Acceleration.z*Acceleration.z)+(Acceleration.y*Acceleration.y));
}
// this is for magnitude 

struct Accel3 HighestAccel(0.0, 0.0, 0.0);
//struct Accel3 AccelAverage(0.0, 0.0, 0.0);
//int Iters = 0; 
 // keep the average as the pure sum and increase the iteration counter to make it divide into an accurate average without weird arduino linked lists


void CategorizeData(float X, float Z, float Y)
{
if (accelMag(HighestAccel.X, HighestAccel.z, HighestAccel.y) <= accelMag(X, Z, Y))
{
HighestAccel.x = X
HighestAccel.z = Z
HighestAccel.Y = Y
//Iters += 1
}
}

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
void setup() {

 
 
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(); // arduino likes to put a bunch of weird characters in the beginning of serial monitor

   if(!accel.begin())
   {
      Serial.println("No valid sensor found - waiting");
      while(1);
   }

  Serial.println(HighestAccel.toString());
  Serial.println(accelMag(HighestAccel));
//Serial.print();
}


void loop() {
  // put your main code here, to run repeatedly:

 sensors_event_t event; 
  accel.getEvent(&event);

  CategorizeData(event.acceleration.x, event.acceleration.z, event.acceleration.y)

   Serial.println(HighestAccel.toString());
  delay(150)

}

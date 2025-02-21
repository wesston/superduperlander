
#include <math.h>
#include <EasyStringStream.h>
#include <stdlib.h>
#include <floatToString.h>
struct Accel3 {
float x;
float y;
float z;
};

volatile struct Accel3 HighestAccel = {0.0, 0.0, 0.0};

float averageAccelMag(Accel3 Acceleration)
{
return (abs(Acceleration.x) + abs(Acceleration.y) + abs(Acceleration.z))/3;
}

String AccelDataReturn(Accel3 Acceleration) {
  char AccelX[7];
  char AccelY[7];
  char AccelZ[7];
  floatToString(Acceleration.x, AccelX, sizeof(AccelX), 3);
   floatToString(Acceleration.y, AccelY, sizeof(AccelY), 3);
    floatToString(Acceleration.z, AccelZ, sizeof(AccelZ), 3);
return ("x: " <<  AccelX << " y: " << AccelY << " z: " << AccelZ);
}

void setup() {
  // put your setup code here, to run once:
Serial.print(AccelDataRetunr(HighestAccel));
}

void loop() {
  // put your main code here, to run repeatedly:

}

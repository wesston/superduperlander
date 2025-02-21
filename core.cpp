
#include <math.h>

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

return ("x: " <<  Acceleration.x << " y: " << Acceleration.y << " z: " << Acceleration.z);
}

void setup() {
  // put your setup code here, to run once:
Serial.print(AccelDataRetunr(HighestAccel));
}

void loop() {
  // put your main code here, to run repeatedly:

}

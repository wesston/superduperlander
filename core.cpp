
#include <math.h>
#include <EasyStringStream.h>
//#include <stdlib.h>

struct Accel3 {
float x{0.0};
float y{0.0};
float z{0.0};
// vectors for acceleration

void AccelDataReturn() 
{
Serial.print("acceleration: ");
Serial.print(x);
Serial.print(", ");
Serial.print(y);
Serial.print(", ");
Serial.println(z);
}
//output accel - no idea how to tostring in cpp
//if you know lmk please
};
struct Accel3 HighestAccel = {0.0, 0.0, 0.0};

struct 
//this will be the highest acceleration recorded


float accelMag(Accel3 Acceleration)
{
return sqrt((Acceleration.x*Acceleration.x)+(Acceleration.y*Acceleration.y)+(Acceleration.z*Acceleration.z));
}
// this is for magnitude 


void AccelDataReturn(Accel3 Acceleration);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
HighestAccel.AccelDataReturn();
Serial.println(accelMag(HighestAccel));
//Serial.print();
}


void loop() {
  // put your main code here, to run repeatedly:

}



//btw the accelerometer is called the ADXL345
//accelerometer uses xzy not xyz
#include <math.h>

//#include <Adafruit_Sensor.h> 
#include <Wire.h>

#include <Adafruit_ADXL345_U.h>

//#include <stdlib.h>

//ADXL345 accel(ADXL345_STD);

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

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
void displaySensorDetails(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

void displayDataRate(void)
{
  Serial.print  ("Data Rate:    "); 
  
  switch(accel.getDataRate())
  {
    case ADXL345_DATARATE_3200_HZ:
      Serial.print  ("3200 "); 
      break;
    case ADXL345_DATARATE_1600_HZ:
      Serial.print  ("1600 "); 
      break;
    case ADXL345_DATARATE_800_HZ:
      Serial.print  ("800 "); 
      break;
    case ADXL345_DATARATE_400_HZ:
      Serial.print  ("400 "); 
      break;
    case ADXL345_DATARATE_200_HZ:
      Serial.print  ("200 "); 
      break;
    case ADXL345_DATARATE_100_HZ:
      Serial.print  ("100 "); 
      break;
    case ADXL345_DATARATE_50_HZ:
      Serial.print  ("50 "); 
      break;
    case ADXL345_DATARATE_25_HZ:
      Serial.print  ("25 "); 
      break;
    case ADXL345_DATARATE_12_5_HZ:
      Serial.print  ("12.5 "); 
      break;
    case ADXL345_DATARATE_6_25HZ:
      Serial.print  ("6.25 "); 
      break;
    case ADXL345_DATARATE_3_13_HZ:
      Serial.print  ("3.13 "); 
      break;
    case ADXL345_DATARATE_1_56_HZ:
      Serial.print  ("1.56 "); 
      break;
    case ADXL345_DATARATE_0_78_HZ:
      Serial.print  ("0.78 "); 
      break;
    case ADXL345_DATARATE_0_39_HZ:
      Serial.print  ("0.39 "); 
      break;
    case ADXL345_DATARATE_0_20_HZ:
      Serial.print  ("0.20 "); 
      break;
    case ADXL345_DATARATE_0_10_HZ:
      Serial.print  ("0.10 "); 
      break;
    default:
      Serial.print  ("???? "); 
      break;
  }  
  Serial.println(" Hz");  
}

void displayRange(void)
{
  Serial.print  ("Range:         +/- "); 
  
  switch(accel.getRange())
  {
    case ADXL345_RANGE_16_G:
      Serial.print  ("16 "); 
      break;
    case ADXL345_RANGE_8_G:
      Serial.print  ("8 "); 
      break;
    case ADXL345_RANGE_4_G:
      Serial.print  ("4 "); 
      break;
    case ADXL345_RANGE_2_G:
      Serial.print  ("2 "); 
      break;
    default:
      Serial.print  ("?? "); 
      break;
  }  
  Serial.println(" g");  
}


//this will be the highest acceleration recorded



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


   if(!accel.begin())
   {
      Serial.println("No valid sensor found - failed");
      while(1);
   }

 accel.setRange(ADXL345_RANGE_16_G);

 displaySensorDetails();
  
  /* Display additional settings (outside the scope of sensor_t) */
  displayDataRate();
  displayRange();

  Serial.println(HighestAccel.toString());
  Serial.println(accelMag(HighestAccel.x, HighestAccel.z, HighestAccel.y));
//Serial.print();
}


void loop() {
  // put your main code here, to run repeatedly:

 sensors_event_t event; 
  accel.getEvent(&event);

  CategorizeData(event.acceleration.x, event.acceleration.z, event.acceleration.y);

   Serial.println(HighestAccel.toString());
  delay(300);

}

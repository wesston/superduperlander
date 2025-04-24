
//btw the accelerometer is called the ADXL345
//accelerometer uses xzy not xyz
#include <math.h>

//#include <Adafruit_Sensor.h> 
#include <Wire.h>

#include <Adafruit_ADXL345_U.h>

#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//#include <stdlib.h>

//ADXL345 accel(ADXL345_STD);

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

struct Accel3 {
float x{0.0};
float z{0.0};
float y{0.0};


// vectors for acceleration



  String toString() {
        return "acceleration: \n " + String(x) + ", " + String(z) + ", " + String(y); //for outputting data
    }



    Accel3(float _x = 0.0, float _z = 0.0, float _y = 0.0)  // Constructor
        : x(_x), z(_z), y(_y) {}

};



// 'Aqualog55', 128x32px
const unsigned char bitmap_Aqualogo [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x18, 0x42, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x03, 0xc0, 0x3f, 0x03, 0xc1, 0x83, 0xc0, 0x00, 0x00, 0xc2, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xc0, 0xff, 0xc3, 0xc3, 0x87, 0xc0, 0x00, 0xff, 0xf5, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xe0, 0xe1, 0xe3, 0xc3, 0x87, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x07, 0xe1, 0xc0, 0xe3, 0xc3, 0x87, 0xe0, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0f, 0xe3, 0xc0, 0x73, 0xc3, 0x8f, 0xe0, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0d, 0xe3, 0x80, 0x73, 0xc3, 0x8d, 0xe0, 0x03, 0xf8, 0x7f, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x0c, 0xf3, 0x80, 0x73, 0xc3, 0x9c, 0xe0, 0x01, 0xdf, 0xff, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1c, 0xf3, 0x80, 0x73, 0xc3, 0x9c, 0xf0, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x18, 0xf3, 0x80, 0x73, 0xc3, 0x98, 0xf0, 0x03, 0xff, 0xdf, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0xfb, 0xde, 0x73, 0xc3, 0xbf, 0xf0, 0x00, 0x7e, 0x43, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x38, 0x79, 0xdf, 0xf1, 0xc3, 0xbf, 0xf8, 0x01, 0xf3, 0xfe, 0x30, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x30, 0x79, 0xef, 0xe1, 0xe3, 0x30, 0x78, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x70, 0x78, 0xff, 0xc1, 0xff, 0x70, 0x78, 0x01, 0x00, 0x1e, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x70, 0x3c, 0x7f, 0x80, 0xfe, 0x60, 0x38, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x18, 0x0b, 0xc0, 0x38, 0x60, 0x38, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x78, 0x42, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xfc, 0x66, 0x30, 0xfc, 0xcc, 0x7e, 0x3e, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xc0, 0x66, 0x30, 0x30, 0xcc, 0x7e, 0x3c, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xfc, 0x7e, 0x3e, 0x30, 0xfc, 0x7c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x78, 0x3c, 0x3e, 0x20, 0xf8, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x0f, 0x08, 0x01, 0xc0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x1f, 0x88, 0xc7, 0xf1, 0xf8, 0xc0, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x18, 0x0f, 0xc6, 0x31, 0x18, 0xc0, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x3f, 0x1f, 0x88, 0xc7, 0xf1, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x1e, 0x0f, 0x08, 0x43, 0xe1, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
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
  display.println("Accel Sensor Found");
  display.display();
  delay(1500);
}

void StringOut(String toDisplay)
{
   display.println(toDisplay);
         display.display();
}
/*
void displayDataRate(void)
{
  Serial.print  ("Data Rate:    "); 
  switch(accel.getDataRate())
  {
    case ADXL345_DATARATE_3200_HZ:
      Serial.print  ("3200 "); 
        StringOut("Data Rate: 3200");
    
      break;
    case ADXL345_DATARATE_1600_HZ:
      Serial.print  ("1600 "); 
        StringOut("Data Rate: 1600");
    
      break;
    case ADXL345_DATARATE_800_HZ:
      Serial.print  ("800 "); 
       StringOut("Data Rate: 800");
 
      break;
    case ADXL345_DATARATE_400_HZ:
      Serial.print  ("400 "); 
       StringOut("Data Rate: 400");
  
      break;
    case ADXL345_DATARATE_200_HZ:
      Serial.print  ("200 "); 
       StringOut("Data Rate: 200");
      
      break;
    case ADXL345_DATARATE_100_HZ:
      Serial.print  ("100 "); 
       StringOut("Data Rate: 100");
    
      break;
    case ADXL345_DATARATE_50_HZ:
      Serial.print  ("50 "); 
       StringOut("Data Rate: 50");
    
      break;
    case ADXL345_DATARATE_25_HZ:
      Serial.print  ("25 "); 
       StringOut("Data Rate: 25");
       
      break;
    case ADXL345_DATARATE_12_5_HZ:
      Serial.print  ("12.5 "); 
       StringOut("Data Rate: 12.5");
      
      break;
    case ADXL345_DATARATE_6_25HZ:
      Serial.print  ("6.25 "); 
        StringOut("Data Rate: 6.25");
     
      break;
    case ADXL345_DATARATE_3_13_HZ:
      Serial.print  ("3.13 "); 
       StringOut("Data Rate: 3.13");
      
      break;
    case ADXL345_DATARATE_1_56_HZ:
      Serial.print  ("1.56 "); 
       StringOut("Data Rate: 1.56");
      
      break;
    case ADXL345_DATARATE_0_78_HZ:
      Serial.print  ("0.78 "); 
       StringOut("Data Rate: 0.78");
      
      break;
    case ADXL345_DATARATE_0_39_HZ:
      Serial.print  ("0.39 "); 
       StringOut("Data Rate: 0.39");
      
      break;
    case ADXL345_DATARATE_0_20_HZ:
      Serial.print  ("0.20 "); 
      StringOut("Data Rate: 0.20");
        
      break;
    case ADXL345_DATARATE_0_10_HZ:
      Serial.print  ("0.10 "); 
       StringOut("Data Rate: 0.10");
      
      break;
    default:
      Serial.print  ("???? "); 
      StringOut("Data Rate: unknown");
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
       StringOut("Range: +/-16g");
     
      break;
    case ADXL345_RANGE_8_G:
      Serial.print  ("8 "); 
       StringOut("Range: +/-8g");
     
      break;
    case ADXL345_RANGE_4_G:
      Serial.print  ("4 "); 
         StringOut("Range: +/-4g");
        
      break;
    case ADXL345_RANGE_2_G:
      Serial.print  ("2 "); 
      StringOut("Range: +/-2g");
        
      break;
    default:
      Serial.print  ("?? "); 
      StringOut("Range: unkown");
       
      break;
  }  
  Serial.println(" g");  
  //display.display();
}
*/

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

void clearReset()
{
   display.clearDisplay();
 display.setCursor(0, 0);
}

//Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();
void setup() {

 
 
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Serial.println(); // arduino likes to put a bunch of weird characters in the beginning of serial monitor


if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

    clearReset();

display.drawBitmap(0, 0, bitmap_Aqualogo, 128, 32, WHITE);

  // Update the display
  display.setTextColor(WHITE);
  display.display();
  delay(2000);

    clearReset();

  display.setTextSize(2);
  display.println("diagnostic time :)");
  display.display();
delay(3500);
  clearReset();
   display.setTextSize(1);
   /*
   if(!accel.begin())
   {
      Serial.println("No valid sensor found - failed");
       display.println("No valid sensor found - check the pin connections!");
        display.display();
      while(1);
   }
 */

 accel.setRange(ADXL345_RANGE_16_G);

 displaySensorDetails();

   clearReset();

  delay(2500);
 
  /* Display additional settings (outside the scope of sensor_t) */
  /*
  displayDataRate();
  delay(3000);

    clearReset();

  displayRange();
  delay(3000);

   clearReset();
*/
  display.println("diagnostics done..\n happy dropping!");
   display.display();
  delay(4500);
   clearReset();
  Serial.println(HighestAccel.toString());
  Serial.println(accelMag(HighestAccel.x, HighestAccel.z, HighestAccel.y));
  display.println("remember to reset \n between trials");
 display.display();
  delay(4500);
   clearReset();
    StringOut(HighestAccel.toString());
//Serial.print();
}


void loop() {
  // put your main code here, to run repeatedly:

 sensors_event_t event; 
  accel.getEvent(&event);

  CategorizeData(event.acceleration.x, event.acceleration.z, event.acceleration.y);

  // Serial.println(HighestAccel.toString());

     clearReset();

   //display.println();
   StringOut(HighestAccel.toString());
    
  delay(300);

}

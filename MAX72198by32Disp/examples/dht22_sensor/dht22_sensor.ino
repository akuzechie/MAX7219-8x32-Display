//-----------------------------------------------
// DHT22 Temp & Humidity on MAX7219 8x32 Display
// using MAX72198by32Disp.h Library
// by: Anas Kuzechie
//-----------------------------------------------
#include <DHT.h>
#include <MAX72198by32Disp.h>
#include "MAX7219_Letters.h"
//------------------------------
DHT dht(5, DHT22);
MAX72198by32Disp disp(2, 3, 4);
//------------------------------
float temp; int humidity;
int temp_LSD, temp_MSD, temp_fraction, hum_LSD, hum_MSD;
unsigned long millisCapture = millis(), myDelay = 15000;
//========================================================
void setup()
{
  dht.begin();
  disp.Initialize(0);
  //-------------------------
  disp.Clear(); delay(1000);
  //-------------------------
  disp.Letter(1, D);
  disp.Letter(2, H);
  disp.Letter(3, T);
  disp.Letter(4, d22);
  //-------------------------
  delay(2000); disp.Clear();
}
//========================================================
void loop()
{
  delay(2000);
  //-------------------------------------
  temp = dht.readTemperature();
  temp_MSD = int(temp)/10;
  temp_LSD = int(temp)%10;
  temp_fraction = (temp - int(temp))*10;
  //-------------------------------------
  disp.Number  (1, temp_MSD);
  disp.Numberdp(2, temp_LSD);
  disp.Number  (3, temp_fraction);
  disp.Letter  (4, dc);
  //--------------------------------------
  if(millis() - millisCapture > myDelay)
  {
    disp.Clear(); delay(1000);
    //----------------------------
    humidity = dht.readHumidity();
    hum_MSD = humidity/10;
    hum_LSD = humidity%10;
    //----------------------------
    disp.Letter(1, H);
    disp.Number(2, hum_MSD);
    disp.Number(3, hum_LSD);
    disp.Symbol(4, '%');
    //----------------------------
    delay(3000); disp.Clear();
    millisCapture = millis();
  }
}
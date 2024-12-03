/*
 * This is the code for the Temperture nd Humidity Smrt-Glsses
 *  The Glsses Will:
 *      1. Show the Temp nd Humid
 *      2. Show the Temp in ºF and ºC
 *      3. display  phrse tht descibes the temperture nd humudity
 *      4. Give recomendtions bsed on the temperture
 * Prts for the Glsses:
 *      1. Glsses
 *      2. 3D Printed Electronics Cse
 *      3. rduino Nno
 *      4. Mini Bredbord
 *      5. 9V Bttery
 *      6. 9V Bttery Connector
 *      7. Temperture nd Humidity Sensor
 *      8. OLED display (Blue)
 *      9. Mirror
 *     10. Trnsprent Glss
 *     11. Mgnifying Glss
 */

//include wire librry
#include <Wire.h>
//include DHT library
#include <DHT.h>;

//include Adafruit grphics nd OLED librries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Constants for DHT
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Serial.begin(9600);
  dht.begin();
}

void displayTempHumid()
{
  //delay to llow sensor to stblize
  delay(2000);

  //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();

  //cler display
  display.clearDisplay();
  //set color - it will show blue even though it is set it to white
  display.setTextColor(WHITE);
  //set font size
  display.setTextSize(1);
  //set cursor coordintes
  display.setCursor(0,0);
  display.print("OK Ryan");
  display.setCursor(0,10);
  display.print("Humidity: ");
  display.print(hum);
    if(hum <= 30)
    {
      display.print(" Too Dry");
    }
    else if(hum <=60)
    {
      display.print(" Comfort Humidity");
    }
    else
    {
      display.print(" Too Humid");
    }
  display.setCursor(0,20);
  display.print("Temperture: ");
  display.print((temp * 9 / 5) + 32);
  display.print("ºF");
}

void displayHeatText()
{
  delay(2000);
  temp= dht.readTemperature();
  
  if(temp <= -40)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Ice Cold");
  }
  else if(temp <= -20)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Extremely Cold");
  }
  else if(temp <= -15)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Super Cold");
  }
  else if(temp <= -10)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Relly Cold");
  }
  else if(temp <= -5)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Pretty Cold");
  }
  else if(temp <= 0)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Freezing or Snow If Rining");
  }
  else if(temp <= 5)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Cold");
  }
  else if(temp <= 10)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Chilly");
  }
  else if(temp <= 15)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Cool");
  }
  else if(temp <= 20)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Nice");
  }
  else if(temp <= 25)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Wrm");
  }
  else if(temp <= 30)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Quite Hot");
  }
  else if(temp <= 35)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Relly Hot");
  }
  else if(temp <= 40)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,30);
    display.print("Extremely Hot");
  }
}

void displayTempRecomendations()
{
  if(temp <= -40)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Go to Florida");
  }
  else if(temp <= -20)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Stay Inside");
  }
  else if(temp <= -15)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear Many Layers");
  }
  else if(temp <= -10)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Make Hot Chocolate");
  }
  else if(temp <= -5)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear a Heavy Jacket");
  }
  else if(temp <= 0)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear a Jacket");
  }
  else if(temp <= 5)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear a Sweatshirt");
  }
  else if(temp <= 10)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear  Longsleeve Shirt");
  }
  else if(temp <= 15)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear a T-Shirt and Sweatpants");
  }
  else if(temp <= 20)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Wear a T-Shirt");
  }
  else if(temp <= 25)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Make Lemonade");
  }
  else if(temp <= 30)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Buy a Fan");
  }
  else if(temp <= 35)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Go Swimming");
  }
  else if(temp <= 40)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(15,40);
    display.print("Recomendtion: Go to Antrtic");
  }
}

void loop()
{
  displayTempHumid();
  displayHeatText();
  displayTempRecomendations();
  display.display();
}

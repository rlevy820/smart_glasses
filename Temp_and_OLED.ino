int i = 80;

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

//int hum;  //Stores humidity value
float temp; //Stores temperature value

float pressLength = 0;

int button = 2;

int photo = A3;
int photoValue = 0;
int LED = 12;

void Temp()
{
  //delay to llow sensor to stblize
  delay(400);

  //Read data and store it to variables hum and temp
    //hum = dht.readHumidity(); //un-comment to sense humidity
    temp = dht.readTemperature();

  //cler display
  display.clearDisplay();
  //set color - it will show blue even though it is set it to white
  display.setTextColor(WHITE);
  //set font size
  display.setTextSize(1);
  //set cursor coordintes
  display.setCursor(0,0);//0,0
  display.print("Temperature: ");
  display.print(((temp * 9 / 5) + 32), 1);
  display.print(" F");
  display.setCursor(80,10);//80,10
  display.print(temp, 1);
  display.print(" C");
}

void TempAddOns()
{
  if(temp <= -20)
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Ice Cold");
    display.setCursor(0,20);
    display.print("Go Somewhere Warm");
  }
  else if(temp > -20 && temp <= 1)//-4 to 33
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Really Cold");
    display.setCursor(0,20);
    display.print("Stay Inside");
  }
  else if(temp > 1 && temp <= 10)//33 to 60
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Quite Cold");
    display.setCursor(0,20);
    display.print("Make Hot Chocolate");
  }
  else if(temp > 10 && temp <= 16)//50 to 60
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Pretty Cold");
    display.setCursor(0,20);
    display.print("Wear a Sweatshirt");
  }
  else if(temp > 16 && temp <= 20)//60 to 68
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Kind Of Cold");
    display.setCursor(0,20);
    display.print("Wear Longsleeve Shirt");
  }
  else if(temp > 20 && temp <= 23)//68 to 73
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Nice");
    display.setCursor(0,20);
    display.print("Take a Nap");
  }
  else if(temp > 23 && temp <= 27)//75 to 80
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    
    display.setCursor(0,10);
    display.print("Pretty Hot");
    display.setCursor(0,20);
    display.print("Turn Down the Heat");
  }
  else if(temp > 27 && temp <= 32)//82 to 89
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    
    display.setCursor(0,10);
    display.print("Quite Hot");
    display.setCursor(0,20);
    display.print("Wear a Tank-Top");
  }
  else if(temp > 32 && temp <= 37)//91 to 98
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Really Hot");
    display.setCursor(0,20);
    display.print("Go Swimming");
  }
  else if(temp > 37)//100 and up
  {
    display.setTextColor(WHITE);
    display.setTextSize(1);
    display.setCursor(0,10);
    display.print("Awfully Hot");
    display.setCursor(0,20);
    display.print("Go Someplace Cold");
  }
}

void setup()
{
  Wire.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Serial.begin(9600);
  dht.begin();

  pinMode(button, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(photo, INPUT);

  Serial.begin(9600);
}

void loop()
{
   Temp();
   TempAddOns();
   display.display();
     
   photoValue = analogRead(photo);
   Serial.println(photoValue);
   delay(500);

   digitalWrite(LED, HIGH);
}

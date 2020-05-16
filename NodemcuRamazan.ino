#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "DHT.h"

const char *ssid =  "SSID";     // Buraya modem bilgilerinizi yazıyorsunu büyük küçük harfe duyarlıdır
const char *pass =  "PAROLA";

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

WiFiClient client;



#define DHTTYPE DHT11   // DHT 11
uint8_t DHTPin = D4; 
DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;

void setup()
{
      pinMode(DHTPin, INPUT);
      dht.begin(); 
      lcd.begin();
      lcd.print("BASLATILIYOR");
      lcd.backlight();
      Serial.begin(9600);

      Serial.println("Connecting to ");
      Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());
}

void loop()
{

  Temperature = dht.readTemperature(); // Gets the values of the temperature
  Humidity = dht.readHumidity(); // Gets the values of the humidity

if (WiFi.status() == WL_CONNECTED) {
  HTTPClient httpsaat;
  String saat = "http://siteadi.com/nodemcu.php";
  httpsaat.begin(saat);
  int httpCode = httpsaat.GET();   

  HTTPClient httpdata;
  String data = "http://siteadi.com/nodemcu.php?v=1";
  httpdata.begin(data); 
  int httpCodem = httpdata.GET();   

   HTTPClient httpiftar;
  String dataiftar = "http://siteadi.com/nodemcu.php?v=2";
  httpiftar.begin(dataiftar); 
  int httpCodeiftar = httpiftar.GET();   

  if (httpCode == 200) {
    
    String payload = httpsaat.getString();   //Get the request response payload
    String responseSaat = (payload.c_str());

    String payloaddata = httpdata.getString();   //Get the request response payload
    String responseData = (payloaddata.c_str());

    String payloadiftar = httpiftar.getString();   //Get the request response payload
    String responseiftar = (payloadiftar.c_str());
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(responseSaat);
    
    lcd.setCursor(0, 1);
    lcd.print(Temperature);
    lcd.print("C NEM: ");
    lcd.print(Humidity);

     delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(responseData);
    lcd.setCursor(0, 1);
    lcd.print(responseiftar);

    Serial.println(responseData);
  
  delay(3000);
  }else{
      lcd.print("SERVER HATASI");
      delay(5000);
      lcd.clear();
    }
  
}else{
  lcd.print("Baglanamadi...");
  delay(5000);
  lcd.clear();
  }
  
}

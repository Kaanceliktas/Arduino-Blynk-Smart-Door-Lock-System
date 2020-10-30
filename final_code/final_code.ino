#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

char auth[] = "Code that you will take from Blynk App";

char ssid[] = "Wi-Fi Name";
char pass[] = "Wi-Fi Password";

LiquidCrystal_I2C lcd(Adress of lcd Screen);

Servo servo;


BLYNK_WRITE(V1)
{
  lcd.setCursor(0, 0); 
   lcd.print("Welcome To Home");    
  lcd.setCursor(0, 1); 
   lcd.print("Please Use App"); 

  servo.write(param.asInt());
}
BLYNK_WRITE(V2)
{
  lcd.setCursor(0, 0); 
   lcd.print("Welcome To Home");    
  lcd.setCursor(0, 1); 
   lcd.print("Door is Opened");  
  servo.write(70);
}
BLYNK_WRITE(V3)
{
    lcd.setCursor(0, 0); 
   lcd.print("Good Bye !!");    
  lcd.setCursor(0, 1); 
   lcd.print("Door is Closed"); 
  servo.write(0);
}

void setup()
{

lcd.begin(16,2);    
 lcd.init();          
 lcd.backlight();     
 
  
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo.attach(D4);  
}

void loop()
{
  Blynk.run();
}

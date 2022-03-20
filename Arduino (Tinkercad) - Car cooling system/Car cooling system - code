#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>
#define PINNeo 9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PINNeo, NEO_GRB + NEO_KHZ800);

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int tempSensorPin=A0;
int ledPin=10;
int motorPin=11;
int switchPin=8;
int fanspeed=0;
int speakerPin=13;
double temperature;
int neoLednr, prev_neoLednr = 0;

void setup()
{
  pinMode(tempSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  
  lcd.begin(16,2);
  Serial.begin(9600);
  strip.begin();
  strip.show();
}

void loop()
{
  temperature=analogRead(tempSensorPin);
  temperature=map(temperature, 20, 358, 50, 130);
  neoLednr=map(temperature, 50, 130, 1, 12);
  
  if(digitalRead(switchPin)==HIGH)    // contact ON
  {
  	if(neoLednr != prev_neoLednr)
  	{
    	if(temperature<60)
    	{
     	   switch_led(strip.Color(0, 0, 0), 0, 12);
      	 switch_led(strip.Color(0, 0, 255), 50, neoLednr);  // Led albastru pt temp<60
      	 prev_neoLednr=neoLednr;
      	 delay(500);
    	}
    		else
        	{
         	 switch_led(strip.Color(0, 0, 0), 0, 12);
         	 switch_led(strip.Color(255, 0, 0), 50, neoLednr);  // Led rosu pt temp>=60
         	 prev_neoLednr=neoLednr;
         	 delay(500);
        	}
  
  	}
  	  Serial.println(temperature);
  
  	if(temperature<60)
  	{
    	lcd.clear();
    	lcd.setCursor(0,0);
    	lcd.print("Temp: ");
    	lcd.setCursor(8,0);
    	lcd.print(temperature); // afisare temp
    	lcd.print("C");
    	lcd.setCursor(1,1);
  		lcd.print("Do not rev!"); // Afisare avertizare
    	delay(1000);
      
    	fanspeed=0;
    	analogWrite(motorPin,fanspeed);  // Fan oprit
  	}
    
    if(temperature>=60 && temperature<=100)
    {
      	fanspeed=0;
      	analogWrite(motorPin,fanspeed);  // Fan oprit
    }
    
  	if(temperature>=60 && temperature<=120)
  	{
    	lcd.clear();
    	lcd.setCursor(0,0);
    	lcd.print("Temp: ");
    	lcd.setCursor(8,0);
    	lcd.print(temperature);  // Afisare temp
    	lcd.print("C");
    	delay(1000);
  	}
    
  	if(temperature>=100 && temperature<=120)
  	{	
    	fanspeed=80;
    	analogWrite(motorPin,fanspeed); // Fan ON 50%
    	delay(1000);
  	}
    
  	if(temperature>120)
  	{
    	lcd.clear();
    	lcd.setCursor(0,0);
    	lcd.print("Temp: ");
    	lcd.setCursor(8,0);
    	lcd.print(temperature);  // Afisare tmp
    	lcd.print("C");
    	lcd.setCursor(0,1);
    	lcd.print("STOP Overheating");  // Afisare avertizare
    
    	for (int i=0; i<=255; i+=5)
    	{
      		analogWrite(ledPin,i);  //PWM crescator pt led avertizare
      		delay(30);
    	}
    	for (int i=255; i>=0; i-=5)
    	{
      		analogWrite(ledPin,i);  //PWM descrescator pt led avertizare
      		delay(30);
    	}
      
    	fanspeed=160;
    	analogWrite(motorPin,fanspeed);  // Fan ON Max speed
    	//tone(13,200,100);  // Avertizare sonora
    	delay(1000);
  	} 
  }
  
  if(digitalRead(switchPin)==LOW) //Contact OFF
  {
    switch_led(strip.Color(0, 0, 0), 10, 12); //Led OFF
    delay(500);
    
    lcd.clear();  //LCD Off
    
    fanspeed=0;
    analogWrite(motorPin,fanspeed); // Fan OFF
  }
    
}

void switch_led(uint32_t color, int time, int led_num)
{
  for(uint16_t i=0; i<led_num; i++)
  {
    strip.setPixelColor(i, color);
    strip.show();
    delay(time);
  }
}

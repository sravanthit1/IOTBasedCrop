#include <LiquidCrystal.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2	 // pin Neopixel is attached to
#define NUMPIXELS 1 // number of neopixels in strip
#define SENSOR A0		//input pin for Potentiometer

#define dryThreshold 50 //below this value, begin alerting dry, turn red;
#define wetThreshold 200 //above this value, begin alerting wet,turn blue;
#define thresholdCenter (dryThreshold + wetThreshold)/2 //Brightest Green point
#define crossFade 20 //how much blue and red should fade in to green

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 100;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

int sensorValue  = 0;
int transitionValue = 0;

LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  pixels.begin();
  pinMode(SENSOR,INPUT);
  lcd.begin(16, 2);
  Serial.begin(115200);
}

void loop() {
  sensorValue = analogRead(SENSOR);
  transitionValue = map(sensorValue,0,1023,0,255);
  setColor();
  pixels.setPixelColor(0,redColor,greenColor,blueColor);
  pixels.show();

  int value = analogRead(A0);
  Serial.println(value);
  if (value <= 164) {
    lcd.setCursor(0, 0);
    lcd.print("  Dry Weather   ");
    Serial.println("Dry Weather");
    lcd.setCursor(0, 1);
    lcd.print("    No Rain    ");
   }
  if ((value > 165) && (value <= 327)) {
    Serial.println("Heavy Mist ");
    lcd.setCursor(0, 0);
    lcd.print("      ");
    lcd.setCursor(0, 1);
    lcd.print("   Heavy Mist   ");
   }
  if ((value > 328) && (value <= 511)) {
    Serial.println("    Drizzle   ");
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("   Drizzle   ");
  }
  if ((value > 512) && (value <= 700)) {
    Serial.println("Average Rainfall");
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Average Rainfall ");
  }
  if ((value > 700) && (value <= 800)) {
    Serial.println("Heavy Rain");
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("   Heavy Rain   ");
  }
  if (value > 800) {
    Serial.println("Extreme Rain");
    lcd.setCursor(0, 0);
    lcd.print("     Very       ");
    lcd.setCursor(0, 1);
    lcd.print("  Extreme Rain    ");
   }
  
  delay(100);
}

void setColor(){

  
  redColor = ((transitionValue <= dryThreshold + crossFade) && (transitionValue >= 0 ))? map(transitionValue,0,dryThreshold + crossFade,255,0) : 0;
  blueColor = (transitionValue >= wetThreshold - crossFade && transitionValue <= 255)? map(transitionValue,wetThreshold - crossFade,255,0,255):0; 

  if(transitionValue >= dryThreshold && transitionValue <= thresholdCenter)
  {
    greenColor = map(transitionValue,dryThreshold,thresholdCenter,0,255);
  }
  else if(transitionValue > thresholdCenter && transitionValue < wetThreshold)
  {
    greenColor = map(transitionValue,dryThreshold,thresholdCenter,255,0);
  }
  else{
    greenColor = 0;
  }
                   
}




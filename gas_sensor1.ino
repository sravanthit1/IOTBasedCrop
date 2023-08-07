#include <Adafruit_NeoPixel.h>
#define PIN 5
#define LED_COUNT 12

int Ledjes = 5;
int Uit = 9; 					// Digital pin 8 will be called 'pin8'
int COfunctie = 10;
int Geluid = 12;
int gasSensorA = A5;			// Analog pin 0 will be called 'sensor'
int Rval;
int Gval;
int Bval;
int sensorValue = 0;        // Set the initial sensorValue to 0
int outputValue = 0;        // Eventual modified pot output signal

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);


// The setup routine runs once when you press reset
void setup() {
  Serial.begin(9600);		// Initialize serial communication at 9600 bits per second
  leds.begin();
  leds.show();
  pinMode (gasSensorA, INPUT);
  pinMode (9, INPUT);
  pinMode (10, INPUT);
  pinMode (11, INPUT);
  pinMode (12, OUTPUT);
}

// The loop routine runs over and over again forever
void loop() 
{
  	sensorValue = analogRead(gasSensorA);		// Read the input on analog pin 0 (named 'sensor') 
  	Serial.println(sensorValue, DEC);			// Print out the value you read  
  		if (sensorValue > 700) 					// If sensorValue is greater than 800
  		{				
    	(Ledjes, HIGH);							// Activate digital output pin 5 - the LED will light up
    	leds.setPixelColor(0, 255, 255, 254);
		leds.setPixelColor(1, 255, 255, 254);
 		leds.setPixelColor(2, 255, 0, 0);
 		leds.setPixelColor(3, 255, 0, 0);
 		leds.setPixelColor(4, 255, 0, 0);
    	leds.setPixelColor(5, 255, 0, 0);
		leds.setPixelColor(6, 255, 0, 0);
 		leds.setPixelColor(7, 255, 0, 0);
 		leds.setPixelColor(8, 255, 0, 0);
 		leds.setPixelColor(9, 255, 0, 0);
    	leds.setPixelColor(10, 255, 255, 254);
		leds.setPixelColor(11, 255, 255, 254);
    	leds.show();
    	tone(13, 1500);
    	delay(500);
    	leds.setPixelColor(0, 255, 0, 0);
		leds.setPixelColor(1, 255, 0, 0);
 		leds.setPixelColor(2, 255, 0, 0);
 		leds.setPixelColor(3, 255, 0, 0);
 		leds.setPixelColor(4, 255, 0, 0);
    	leds.setPixelColor(5, 255, 0, 0);
		leds.setPixelColor(6, 255, 0, 0);
 		leds.setPixelColor(7, 255, 0, 0);
 		leds.setPixelColor(8, 255, 0, 0);
 		leds.setPixelColor(9, 255, 0, 0);
    	leds.setPixelColor(10, 255, 0, 0);
		leds.setPixelColor(11, 255, 0, 0);
    	leds.show();
    	noTone (13);
    	delay(500);
 		}
  		else 	
        {
    	(Ledjes, LOW);			// Deactivate digital output pin 5 - the LED will not light up
    	leds.setPixelColor(0, 0, 255, 0);
		leds.setPixelColor(1, 0, 255, 0);
 		leds.setPixelColor(2, 0, 255, 0);
 		leds.setPixelColor(3, 0, 255, 0);
 		leds.setPixelColor(4, 0, 255, 0);
    	leds.setPixelColor(5, 0, 255, 0);
		leds.setPixelColor(6, 0, 255, 0);
 		leds.setPixelColor(7, 0, 255, 0);
 		leds.setPixelColor(8, 0, 255, 0);
 		leds.setPixelColor(9, 0, 255, 0);
    	leds.setPixelColor(10, 0, 255, 0);
		leds.setPixelColor(11, 0, 255, 0);
  		leds.show();
  		}
}

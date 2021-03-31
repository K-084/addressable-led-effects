/**
 *
 * @author Shafiqur Khan
 * @version 1.0
 * @since -03/15/2021-
 * 
 * 
 */

#include <Adafruit_NeoPixel.h>

#define PIN1 2
#define PIN2 3
const int numPixels1 = 240;
const int numPixels2 = 240;
Adafruit_NeoPixel strip1;
Adafruit_NeoPixel strip2;

int countPixel = 0;
int countVal = 0;
byte r = 0;
byte g = 0;
byte b = 0;
byte w = 0;
int p = 0;
bool isOn = false;
byte command = 0;
bool isCommand = false;

void setup()
{
  strip1 = Adafruit_NeoPixel(numPixels1, PIN1, NEO_GRBW + NEO_KHZ800);
  delay(100);
  strip2 = Adafruit_NeoPixel(numPixels2, PIN2, NEO_GRBW + NEO_KHZ800);
  delay(100);
  // start serial port and wait for port to open:
  Serial.begin(115200);
  Serial1.begin(115200);
  strip1.setBrightness(255);
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.setBrightness(255);
  strip2.begin();
  strip2.show(); // Initialize all pixels to 'off'
}

void loop()
{ 
  if (Serial1.available()>0)
  {
    int value = Serial1.read();
    if(value == 255 && command == 0)
    {
      isCommand = true;
    }
    else if(isCommand && command == 0)
    {
      command = value;
    }
    else
    {
      handleCommand(command, value);
    }
  }
}
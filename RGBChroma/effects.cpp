

void fadeIn()
{
  isOn = true;
  for(int j = 0; j<=51; j++)
  {
    for(int i = 0; i<numPixels1; i++)
    {
      strip1.setPixelColor(i, 0, 0, 0, 5*j);
      strip2.setPixelColor(i, 0, 0, 0, 5*j);
    }
    strip1.show();
    strip2.show();
    delay(15);
  }
}

void fadeOut()
{
  isOn = false;
  for(int j = 51; j>=0; j--)
  {
    for(int i = 0; i<numPixels1; i++)cxdswq1
    {
      strip1.setPixelColor(i, 0, 0, 0, 5*j);
      strip2.setPixelColor(i, 0, 0, 0, 5*j);
    }
    strip1.show();
    strip2.show();
    delay(15);
  }
}

void fire()
{
    int r = 255;
    int g = r-60;
    int b = 20;
    for(int x = 0; x <numPixels1; x++)
    {
    int flicker = random(0,150);
    int r1 = r-flicker;
    int g1 = g-flicker;
    int b1 = b-flicker;
    if(g1<0) g1=0;
    if(r1<0) r1=0;
    if(b1<0) b1=0;
    strip1.setPixelColor(x,r1,g1, b1,0);
    strip2.setPixelColor(x,r1,g1, b1,0);
    }
    strip1.show();
    strip2.show();
    delay(random(10,20));
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip1.numPixels(); i++) {
      strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
      strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
    }
    strip1.show();
    strip2.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void handleCommand(byte Command, byte Value)
{
  switch(Command)
  {
    //Toggle
    case 1:
      isCommand = false;
      command = 0;
      if(isOn)
      {
        fadeOut();
      }
      else
      {
        fadeIn();
      }
      break;
    //Turn on  
    case 2:
      isCommand = false;
      command = 0;
      fadeIn();
      break;
    //Turn off
    case 3:
      isCommand = false;
      command = 0;
      fadeOut();
      break;
  }
}

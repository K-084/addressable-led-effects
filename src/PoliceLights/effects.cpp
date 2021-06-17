#include Arduino.h

class effects {

  public:

    /**
    * Strobs from left to right
    * @param c
    * @param wait
    */
    void ArrowRight(uint32_t c, uint8_t wait) {
      for (int j = 0; j < 4; j++) { // The j<# determines how many cycles
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, c);
          strip.show();
          delay(wait);
        }
        
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
          strip.setPixelColor(i, 0);
        }
        
        strip.show();
        delay(wait);
      }
    }

    /**
    * Strobes from right to left
    * @param c
    * @param wait
    */
    void ArrowLeft(uint32_t c, uint8_t wait) {
      for (int j = 0; j < 4; j++) { // The j<# determines how many cycles
        for (uint16_t i = strip.numPixels(); i + 1 > 0 ; i--) {
          strip.setPixelColor(i, c);
          strip.show();
          delay(wait);
        }
        for (uint16_t i = strip.numPixels(); i + 1 > 0 ; i--) {
          strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);
      }
    }

    /**
    * Split the LEDs from midpoint
    * Turn on/off either half
    * @param c
    * @param wait
    */
    void WigWag(uint32_t c, uint8_t wait) {
      for (int j = 0; j < 10; j++) { // The j<# determines how many cycles
        for (int i = 0; i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, c);
        }
        for (int i = (strip.numPixels() / 2); i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);

        for (int i = 0; i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, 0);
        }
        for (int i = (strip.numPixels() / 2); i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, c);
        }
        strip.show();
        delay(wait);
      }
    }


    void WigWag2(uint32_t c, uint32_t c2, uint8_t wait) {
      for (int j = 0; j < 20; j++) { // The j<# determines how many cycles
        for (int i = 0; i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, c);
        }
        for (int i = (strip.numPixels() / 2); i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, 0);
        }
        strip.show();
        delay(wait);

        for (int i = 0; i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, 0);
        }
        for (int i = (strip.numPixels() / 2); i < strip.numPixels(); i = i + 1) {
          strip.setPixelColor(i, c2);
        }
        strip.show();
        delay(wait);
      }
    }

    void ClearLights() {
      for (int i = 0; i < strip.numPixels(); i = i + 1) {
        strip.setPixelColor(i, 0);    //turn every pixel off
      }
      strip.show();
    }

    void BlinkOuter(uint32_t c, uint8_t wait) {
      for (int j = 0; j < 10; j++) { // The j<# determines how many cycles
        strip.setPixelColor(strip.numPixels() - 1, c);
        strip.setPixelColor(0, c);
        strip.show();
        delay(wait);
        strip.setPixelColor(strip.numPixels() - 1, 0);
        strip.setPixelColor(0, 0);
        strip.show();
        delay(wait);
      }
    }

    void OnOuter(uint32_t c) {
      strip.setPixelColor(strip.numPixels() - 1, c);
      strip.setPixelColor(0, c);
      strip.show();
      delay(3000);
    }

}
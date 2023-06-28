/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/Documents/CTD_2023/Labs/Lab6/src/Lab6.ino"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 3 "/Users/admin/Documents/CTD_2023/Labs/Lab6/src/Lab6.ino"
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void graphicsTest();
void bitmapTest();

#define TEMP A5

void setup()
{
  display.setup();

  display.clearDisplay();
  display.display();
}

void loop()
{
  display.loop();
  uint64_t reading = analogRead(TEMP);
  double voltage = (reading * 3.3) / 4095.0;
  int temperature = (voltage - 0.5) * 10.0;
  int temp2 = temperature * (1.8) + 32;
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.printf("%u celcius", temperature);
  display.printf("%u fahrenheit", temp2);
  display.display();
}
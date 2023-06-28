#include "oled-wing-adafruit.h"

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
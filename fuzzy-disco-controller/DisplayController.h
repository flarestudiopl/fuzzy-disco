#include <Wire.h>
#include "SSD1306.h"

class DisplayController
{
  private:
  SSD1306 display;

  public:
  DisplayController(uint8_t address, uint8_t sda, uint8_t scl);
  void Initialize();
  void WriteToDisplay(String text);
};


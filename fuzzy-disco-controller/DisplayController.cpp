#include "DisplayController.h"

DisplayController::DisplayController(uint8_t address, uint8_t sda, uint8_t scl)
  : display(address, sda, scl)
{
}

void DisplayController::Initialize()
{
  display.init();
  display.setContrast(255);
  display.flipScreenVertically();
}

void DisplayController::WriteToDisplay(String text)
{
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawStringMaxWidth(0, 0, 128, text);
  display.display();
}


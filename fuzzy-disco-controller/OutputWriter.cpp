#include "OutputWriter.h"

OutputWriter::OutputWriter(uint16_t pixelCount, uint8_t outputPin)
  : strip(pixelCount, outputPin, NEO_GRB + NEO_KHZ800)
{
}

void OutputWriter::Initialize()
{
  strip.begin();
  strip.setBrightness(255);
  strip.show();
}

void OutputWriter::Write(uint8_t outputBuffer[], int bufferSize)
{
  int pixelNumber = 0;

  for (int i = 0; i < bufferSize; i += 3)
  {
    strip.setPixelColor(pixelNumber, (uint8_t)outputBuffer[i], (uint8_t)outputBuffer[i + 1], (uint8_t)outputBuffer[i + 2]);
    pixelNumber++;
  }

  strip.show();
}


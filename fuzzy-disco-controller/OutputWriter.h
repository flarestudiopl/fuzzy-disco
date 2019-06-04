#include <Adafruit_NeoPixel.h>

class OutputWriter
{
  private:
    Adafruit_NeoPixel strip;

  public:
    OutputWriter(uint16_t pixelCount, uint8_t outputPin);
    void Initialize();
    void Write(uint8_t outputBuffer[], int bufferSize);
};


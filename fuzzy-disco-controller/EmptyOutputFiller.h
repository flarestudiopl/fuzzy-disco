#include <stdint.h>

class EmptyOutputFiller
{
  private:
    unsigned long timeoutMilliseconds;
    uint8_t finalOutputState;
    unsigned long fadeInStepMilliseconds;
    unsigned long currentTime;
    unsigned long lastFrameSum;
    unsigned long lastNonEmptyFrameTime;
    unsigned long lastOutputStateChange;
    uint8_t currentOutputState;

  public:
    EmptyOutputFiller(unsigned long timeoutMilliseconds, unsigned long fadeInTimeMilliseconds, uint8_t finalOutputState);
    void Fill(bool newFrameArrived, uint8_t outputBuffer[], int bufferSize);
};


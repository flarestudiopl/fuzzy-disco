#include "EmptyOutputFiller.h"
#include <Arduino.h>

EmptyOutputFiller::EmptyOutputFiller(unsigned long timeoutMilliseconds, unsigned long fadeInTimeMilliseconds, uint8_t finalOutputState)
{
  this->timeoutMilliseconds = timeoutMilliseconds;
  this->fadeInStepMilliseconds = fadeInTimeMilliseconds / finalOutputState;
  this->finalOutputState = finalOutputState;
  this->lastNonEmptyFrameTime = 0;
  this->lastOutputStateChange = 0;
  this->currentOutputState = 0;
}

void EmptyOutputFiller::Fill(bool newFrameArrived, uint8_t outputBuffer[], int bufferSize)
{
  currentTime = millis();
  lastFrameSum = 0;

  if (newFrameArrived)
  {
    for (int i = 0; i < bufferSize; i++)
    {
      lastFrameSum += outputBuffer[i];
    }

    if (lastFrameSum > 0)
    {
      currentOutputState = 0;
      lastNonEmptyFrameTime = currentTime;
    }
  }

  if (currentTime - lastNonEmptyFrameTime > timeoutMilliseconds &&
      currentTime - lastOutputStateChange > fadeInStepMilliseconds)
  {
    if (currentOutputState <= finalOutputState)
    {
      currentOutputState++;
    }

    for (int i = 0; i < bufferSize; i++)
    {
      outputBuffer[i] = currentOutputState;
    }

    lastOutputStateChange = currentTime;
  }
}


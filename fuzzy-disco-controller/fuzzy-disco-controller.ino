#include "WifiManager.h"
#include "DisplayController.h"
#include "PacketReceiver.h"
#include "OutputWriter.h"

#define STRIP_LENGTH 147

WifiManager wifiManager;
DisplayController displayController(0x3c, 2, 14);
PacketReceiver packetReceiver;
OutputWriter outputWriter(STRIP_LENGTH, 4);

const int bufferSize = STRIP_LENGTH * 3;
uint8_t outputBuffer[bufferSize];

void setup()
{
  //Serial.begin(74880);
  //Serial.println("Setup start...");
  
  wifiManager.Initialize();
  displayController.Initialize();
  packetReceiver.Initialize();
  outputWriter.Initialize();

  // TODO
  displayController.WriteToDisplay(wifiManager.GetBaseIp().toString());
}

void loop()
{
  packetReceiver.Receive(outputBuffer, bufferSize);  
  outputWriter.Write(outputBuffer, bufferSize);
}

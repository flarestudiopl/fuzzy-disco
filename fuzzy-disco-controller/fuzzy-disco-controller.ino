#include "WifiManager.h"
#include "DisplayController.h"
#include "PacketReceiver.h"
#include "OutputWriter.h"

WifiManager wifiManager;
DisplayController displayController(0x3c, 2, 14);
PacketReceiver packetReceiver;

void setup()
{
  wifiManager.Initialize();
  displayController.Initialize();
  packetReceiver.Initialize();
  
  // TODO
  displayController.WriteToDisplay(wifiManager.GetBaseIp().toString());
}

void loop()
{
  packetReceiver.Receive();
}

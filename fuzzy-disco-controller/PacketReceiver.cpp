#include "PacketReceiver.h"

void PacketReceiver::Initialize()
{
  udp.begin(50000);
}

bool PacketReceiver::Receive(uint8_t outputBuffer[], int bufferSize)
{
  if (udp.parsePacket())
  {
    int opCode = udp.read();
    if (opCode == 0x02) {
      this->ProcessDirectWrite(outputBuffer, bufferSize);
    }

    return true;
  }

  return false;
}

void PacketReceiver::ProcessDirectWrite(uint8_t outputBuffer[], int bufferSize)
{
  int i = 0;

  while (udp.available() >= 3 &&
         i < bufferSize)
  {
    outputBuffer[i] = (uint8_t)udp.read();
    outputBuffer[i + 1] = (uint8_t)udp.read();
    outputBuffer[i + 2] = (uint8_t)udp.read();

    i += 3;
  }

  udp.flush();
}


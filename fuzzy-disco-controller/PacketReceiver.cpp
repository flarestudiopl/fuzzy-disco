#include "PacketReceiver.h"

void PacketReceiver::Initialize()
{
  udp.begin(50000);
}

void PacketReceiver::Receive()
{
  if(udp.parsePacket())
  {
    // TODO
  }
}


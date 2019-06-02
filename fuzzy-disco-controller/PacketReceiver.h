#include <WiFiUdp.h>

class PacketReceiver
{
  private:
  WiFiUDP udp;

  public:
  void Initialize();
  void Receive(); 
};


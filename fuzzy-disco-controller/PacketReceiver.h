#include <WiFiUdp.h>

class PacketReceiver
{
  private:
    WiFiUDP udp;
    void ProcessDirectWrite(uint8_t* outputBuffer, int bufferSize);

  public:
    void Initialize();
    bool Receive(uint8_t* outputBuffer, int bufferSize);
};


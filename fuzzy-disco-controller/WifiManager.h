#include <ESP8266WiFi.h>

class WifiManager
{
  private:
  bool softApMode = false;
  IPAddress baseIp;
  IPAddress fallbackIp;
  IPAddress fallbackGateway;
  IPAddress fallbackSubnet;
  
  public:
  WifiManager();
  void Initialize();
  bool IsSoftAp() const { return softApMode; }
  IPAddress GetBaseIp() const { return baseIp; }
};


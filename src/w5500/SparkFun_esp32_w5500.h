/****************************************************************************************************************************
  SparkFun_esp32_w5500.h
  
  For Ethernet shields using ESP32_W5500 (ESP32 + W5500)

  WebServer_ESP32_W5500 is a library for the ESP32 with Ethernet W5500 to run WebServer

  Based on and modified from ESP32-IDF https://github.com/espressif/esp-idf
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_W5500
  Modified by SparkFun
  Licensed under GPLv3 license

  Please see SparkFun_WebServer_ESP32_W5500.h for the version information
 *****************************************************************************************************************************/

#ifndef _ESP32_W5500_H_
#define _ESP32_W5500_H_

#include "WiFi.h"
#include "esp_system.h"
#include "esp_eth.h"
#include "driver/spi_master.h"

#include <hal/spi_types.h>

////////////////////////////////////////

static uint8_t W5500_Default_Mac[] = { 0xFE, 0xED, 0xDE, 0xAD, 0xBE, 0xEF };

////////////////////////////////////////

class ESP32_W5500
{
  private:
    bool initialized;
    bool staticIP;
    
    uint8_t mac_eth[6] = { 0xFE, 0xED, 0xDE, 0xAD, 0xBE, 0xEF };

  public:
    esp_eth_handle_t eth_handle;
    esp_eth_netif_glue_handle_t netif_glue_handle;
    esp_eth_phy_t *eth_phy;
    esp_eth_mac_t *eth_mac;
    esp_netif_t *eth_netif;
    spi_device_handle_t spi_handle;
    int spi_host;
    esp_eth_config_t eth_config;

    bool started;
    eth_link_t eth_link;
    static void eth_event_handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

    ESP32_W5500();
    ~ESP32_W5500();

    bool begin(int POCI, int PICO, int SCLK, int CS, int INT, int SPICLOCK_MHZ = 25, int SPIHOST = SPI3_HOST,
               uint8_t *W5500_Mac = W5500_Default_Mac);

    void end();

    bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = (uint32_t)0x00000000,
                IPAddress dns2 = (uint32_t)0x00000000);

    const char * getHostname();
    bool setHostname(const char * hostname);

    bool fullDuplex();
    bool linkUp();
    uint8_t linkSpeed();

    bool enableIpV6();
    IPv6Address localIPv6();

    IPAddress localIP();
    IPAddress subnetMask();
    IPAddress gatewayIP();
    IPAddress dnsIP(uint8_t dns_no = 0);

    IPAddress broadcastIP();
    IPAddress networkID();
    uint8_t subnetCIDR();

    uint8_t * macAddress(uint8_t* mac);
    String macAddress();

    friend class WiFiClient;
    friend class WiFiServer;
};

////////////////////////////////////////

extern ESP32_W5500 ETH;

////////////////////////////////////////

#endif /* _ESP32_W5500_H_ */

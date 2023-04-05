/****************************************************************************************************************************
  SparkFun_WebServer_ESP32_W5500_Impl.h
  
  For Ethernet shields using ESP32_W5500 (ESP32 + W5500)

  WebServer_ESP32_W5500 is a library for the ESP32 with Ethernet W5500 to run WebServer

  Based on and modified from ESP32-IDF https://github.com/espressif/esp-idf
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_W5500
  Modified by SparkFun
  Licensed under GPLv3 license

  Please see SparkFun_WebServer_ESP32_W5500.h for the version information
 *****************************************************************************************************************************/

#pragma once

#ifndef WEBSERVER_ESP32_W5500_IMPL_H
#define WEBSERVER_ESP32_W5500_IMPL_H

//////////////////////////////////////////////////////////////

bool ESP32_W5500_eth_connected = false;

//////////////////////////////////////////////////////////////

void ESP32_W5500_onEvent()
{
  WiFi.onEvent(ESP32_W5500_event);
}

//////////////////////////////////////////////////////////////

void ESP32_W5500_waitForConnect()
{
  while (!ESP32_W5500_eth_connected)
    delay(100);
}

//////////////////////////////////////////////////////////////

bool ESP32_W5500_isConnected()
{
  return ESP32_W5500_eth_connected;
}

//////////////////////////////////////////////////////////////

void ESP32_W5500_event(WiFiEvent_t event)
{
  switch (event)
  {
    case ARDUINO_EVENT_ETH_START:
      ET_LOG0(F("ETH Started"));
      //set eth hostname here
      ETH.setHostname("ESP32_W5500");
      break;

    case ARDUINO_EVENT_ETH_CONNECTED:
      ET_LOG0(F("ETH Connected"));
      break;

    case ARDUINO_EVENT_ETH_GOT_IP:
      if (!ESP32_W5500_eth_connected)
      {
        uint8_t macAddr[6] = { 0 };
        ETH.macAddress(macAddr);
        char macStr[18] = { 0 };
        sprintf(macStr, "%02X:%02X:%02X:%02X:%02X:%02X", macAddr[0], macAddr[1],
                macAddr[2], macAddr[3], macAddr[4], macAddr[5]);

        IPAddress localIP = ETH.localIP();
        char ipStr[18] = { 0 };
        sprintf(ipStr, "%d.%d.%d.%d", localIP[0], localIP[1], localIP[2], localIP[3]);

        ET_LOG3(F("ETH MAC: "), macStr, F(", IPv4: "), ipStr);

        if (ETH.fullDuplex())
        {
          ET_LOG0(F("FULL_DUPLEX"));
        }
        else
        {
          ET_LOG0(F("HALF_DUPLEX"));
        }

        ET_LOG1(String(ETH.linkSpeed()), F("Mbps"));

        ESP32_W5500_eth_connected = true;
      }

      break;

    case ARDUINO_EVENT_ETH_DISCONNECTED:
      ET_LOG0("ETH Disconnected");
      ESP32_W5500_eth_connected = false;
      break;

    case ARDUINO_EVENT_ETH_STOP:
      ET_LOG0("ETH Stopped");
      ESP32_W5500_eth_connected = false;
      break;

    default:
      break;
  }
}

//////////////////////////////////////////////////////////////

#endif    // WEBSERVER_ESP32_W5500_IMPL_H

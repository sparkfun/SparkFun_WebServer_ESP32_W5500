/****************************************************************************************************************************
  SparkFun_WebServer_ESP32_W5500.h

  For Ethernet shields using ESP32_W5500 (ESP32 + W5500)

  WebServer_ESP32_W5500 is a library for the ESP32 with Ethernet W5500 to run WebServer

  Based on and modified from ESP32-IDF https://github.com/espressif/esp-idf
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_W5500
  Modified by SparkFun
  Licensed under GPLv3 license

  Version: 1.5.5

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.5.1   K Hoang      29/11/2022 Initial coding for ESP32_W5500 (ESP32 + W5500). Sync with WebServer_WT32_ETH01 v1.5.1
  1.5.2   K Hoang      06/01/2023 Suppress compile error when using aggressive compile settings
  1.5.3   K Hoang      11/01/2023 Using `SPI_DMA_CH_AUTO` and built-in ESP32 MAC
  1.5.4   SparkFun     April 2023 Add the .end method. Change ET_LOG to use ESP32 log_d etc.
  1.5.5   SparkFun     April 2023 Implement fullDuplex, linkUp and linkSpeed
 *****************************************************************************************************************************/

#pragma once

#ifndef WEBSERVER_ESP32_W5500_H
#define WEBSERVER_ESP32_W5500_H

//////////////////////////////////////////////////////////////

#define USING_CORE_ESP32_CORE_V200_PLUS      true

#define WEBSERVER_ESP32_W5500_VERSION        "WebServer_ESP32_W5500 v1.5.4 for core v2.0.0+"

#define WEBSERVER_ESP32_W5500_VERSION_MAJOR  1
#define WEBSERVER_ESP32_W5500_VERSION_MINOR  5
#define WEBSERVER_ESP32_W5500_VERSION_PATCH  5

#define WEBSERVER_ESP32_W5500_VERSION_INT    1005005

//////////////////////////////////////////////////////////////

#include <Arduino.h>

#include "SparkFun_WebServer_ESP32_W5500_Debug.h"

//////////////////////////////////////////////////////////////

#include "w5500/SparkFun_esp32_w5500.h"

#include "SparkFun_WebServer_ESP32_W5500.hpp"
#include "SparkFun_WebServer_ESP32_W5500_Impl.h"

#endif    // WEBSERVER_ESP32_W5500_H

/****************************************************************************************************************************
  SparkFun_WebServer_ESP32_W5500_Debug.h
  
  For Ethernet shields using ESP32_W5500 (ESP32 + W5500)

  WebServer_ESP32_W5500 is a library for the ESP32 with Ethernet W5500 to run WebServer

  Based on and modified from ESP32-IDF https://github.com/espressif/esp-idf
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_W5500
  Modified by SparkFun
  Licensed under GPLv3 license

  Please see SparkFun_WebServer_ESP32_W5500.h for the version information
 *****************************************************************************************************************************/

#pragma once

#ifndef WEBSERVER_ESP32_W5500_DEBUG_H
#define WEBSERVER_ESP32_W5500_DEBUG_H

#include <Arduino.h>
#include <stdio.h>

///////////////////////////////////////

// Change _ETHERNET_WEBSERVER_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: WARN: errors and warnings
// 3: INFO: errors, warnings and informational (default)
// 4: DEBUG: errors, warnings, informational and debug
// 5: VERBOSE: everything

#ifndef _ETHERNET_WEBSERVER_LOGLEVEL_
  #define _ETHERNET_WEBSERVER_LOGLEVEL_ 0
#endif

///////////////////////////////////////

#define ET_LOGERROR0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 0) { log_e("%s", x); }
#define ET_LOGERROR1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 0) { log_e("%s%s", x, y); }
#define ET_LOGERROR2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 0) { log_e("%s%s%s", x, y, z); }
#define ET_LOGERROR3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 0) { log_e("%s%s%s%s", x, y, z, w); }

///////////////////////////////////////

#define ET_LOGWARN0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 1) { log_w("%s", x); }
#define ET_LOGWARN1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 1) { log_w("%s%s", x, y); }
#define ET_LOGWARN2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 1) { log_w("%s%s%s", x, y, z); }
#define ET_LOGWARN3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 1) { log_w("%s%s%s%s", x, y, z, w); }

///////////////////////////////////////

#define ET_LOGINFO0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 2) { log_i("%s", x); }
#define ET_LOGINFO1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 2) { log_i("%s%s", x, y); }
#define ET_LOGINFO2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 2) { log_i("%s%s%s", x, y, z); }
#define ET_LOGINFO3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 2) { log_i("%s%s%s%s", x, y, z, w); }

///////////////////////////////////////

#define ET_LOGDEBUG0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 3) { log_d("%s", x); }
#define ET_LOGDEBUG1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 3) { log_d("%s%s", x, y); }
#define ET_LOGDEBUG2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 3) { log_d("%s%s%s", x, y, z); }
#define ET_LOGDEBUG3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 3) { log_d("%s%s%s%s", x, y, z, w); }

///////////////////////////////////////

#define ET_LOG0(x)        if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 4) { log_v("%s", x); }
#define ET_LOG1(x,y)      if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 4) { log_v("%s%s", x, y); }
#define ET_LOG2(x,y,z)    if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 4) { log_v("%s%s%s", x, y, z); }
#define ET_LOG3(x,y,z,w)  if(_ETHERNET_WEBSERVER_LOGLEVEL_ > 4) { log_v("%s%s%s%s", x, y, z, w); }

///////////////////////////////////////

#endif    // WEBSERVER_ESP32_W5500_DEBUG_H



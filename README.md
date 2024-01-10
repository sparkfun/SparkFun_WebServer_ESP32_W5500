## SparkFun WebServer ESP32 W5500 Library

A remix of [Khoi Hoang's WebServer_ESP32_W5500](https://github.com/khoih-prog/WebServer_ESP32_W5500) (now archived).

Thank you Khoi.

This library adds the WIZnet W5500 as a physical Ethernet interface for the ESP32. The actual WebServer (HTTP(S)) methods are provided by WiFiServer and WiFiClient. Works great with me-no-dev's [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer).

**Note:**

This library uses the low-level TCP-IP, NETIF, SPI bus and interrupt service methods from the Espressif ESP-IDF. It can not co-exist with the SPI and interrupt methods from the Arduino core for ESP32.
They fight each other... If - like us - you are using this library in Arduino code, you need to structure your code carefully so nothing else attempts to configure or access SPI or interrupts while the WebServer is in use.

The ESP32_W5500 WebServer class makes changes to the ESP32 memory which are not cleared by a standard ```ESP.restart()```. Make sure you call the ```.end()``` method before restarting your code if you want to change over to Arduino Ethernet, SPI and interrupts. Please see [Example1](https://github.com/sparkfun/SparkFun_WebServer_ESP32_W5500/blob/main/examples/Example1_AsyncWebServer/Example1_AsyncWebServer.ino) for more details.

---

## License

- The library is licensed under [GPL-3.0-only](https://github.com/sparkfun/SparkFun_WebServer_ESP32_W5500/blob/main/LICENSE)

---

## Copyright

- Copyright (c) 2016- Hristo Gochkov

- Copyright (c) 2022- Khoi Hoang

- Copyright (c) 2023- SparkFun

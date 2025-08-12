# SCPI red pitaya library
[![Build Status](https://github.com/RedPitaya/SCPI-red-pitaya-arduino/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/RedPitaya/SCPI-red-pitaya-arduino/actions)

## Description

Arduino library for controlling Red Pitaya boards via SCPI server.
The library communicates over any Arduino [`Stream`](https://www.arduino.cc/reference/en/language/functions/communication/stream/),
so it works with transports such as `EthernetClient`, `WiFiClient`, or serial interfaces.

You can get acquainted with Red Pitaya products [here](https://redpitaya.com).
Information about SCPI server is located [here](https://redpitaya.readthedocs.io/en/latest/appsFeatures/remoteControl/scpi.html).

# Dependencies
 * [Red pitaya boards](https://redpitaya.com/stemlab-125-14/).
 * An Arduino `Stream` implementation (e.g. Ethernet, WiFi, or Serial) for communication with the SCPI server.

# Contributing

Contributions are welcome!  Not only you’ll encourage the development of the library, but you’ll also learn how to best use the library and probably some C++ too

## Documentation and doxygen
Documentation is produced by doxygen. Contributions should include documentation for any new code added.

Some examples of how to use doxygen can be found in these guide pages:

https://learn.adafruit.com/the-well-automated-arduino-library/doxygen

https://learn.adafruit.com/the-well-automated-arduino-library/doxygen-tips

MIT license, check license.txt for more information
All text above must be included in any redistribution

To install, use the Arduino Library Manager and search for "SCPI Red Pitaya" and install the library.

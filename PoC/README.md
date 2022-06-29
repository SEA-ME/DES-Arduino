# Arduino CAN Example

Simple CAN Bus examle based on two nodes.

**Node A** is based on an *Arduino Uno* and a *MCP2515* shield board with the *Arduino MCP2515 CAN interface library*.

**Node B** is based on a *SocketCAN* enabled device (eg. *PEAK-USB*) and uses *can-utils* tools.

Tested with Linux, Windows might require additional steps.

## Prerequisites

### PlatformIO

This project is based on PlatformIO. Installation guides for various operating systems can be found here:

[https://docs.platformio.org/en/latest/core/installation.html](https://docs.platformio.org/en/latest/core/installation.html) 

For a quickstart guide on PlatformIO, read the following (official) documentation:

[https://docs.platformio.org/en/latest/core/quickstart.html](https://docs.platformio.org/en/latest/core/quickstart.html)

### can-utils

Install can-utils with following command (example for apt):

	sudo apt-get install can-utils
	
### udev rules

The Arduino Uno device files will require root access for read and write access by default. To enable non-root users to access the device, add some custom udev rules as described in the following link:

[https://docs.platformio.org/en/latest//faq.html#platformio-udev-rules](https://docs.platformio.org/en/latest//faq.html#platformio-udev-rules) 
	

## Build & Upload

Build:

	pio run -e uno

Upload:

	pio run -e uno -t upload

At this point **Node A** is set up and starts to transmit CAN data periodically and waits for incoming data to arrive.
	
Clean (if required):

	pio run -t clean

## Setup socket CAN

To setup **Node B** with SocketCAN, run the following commands with root privileges.

Init can interface to a bitrate of 125 kBit/s:

	ip link set can0 type can bitrate 125000
	ip link set up can0
	
Show received CAN frames with one of following commands:

	candump can0
	cansniffer can0
	
Send can frames:

	cansend can0 123#0011
	

## References

* https://registry.platformio.org/libraries/autowp/autowp-mcp2515
* https://github.com/autowp/arduino-mcp2515
* https://elinux.org/CAN_Bus
* https://wiki.seeedstudio.com/CAN-BUS_Shield_V1.2/
* https://www.arduino.cc/reference/de/language/functions/external-interrupts/attachinterrupt/

# Arduino CAN Example

Simple CAN Bus examle based on two nodes.

**Node A** is based on an *Arduino Uno* and a *MCP2515* shield board with the *Arduino MCP2515 CAN interface library*.

**Node B** is based on a *SocketCAM* enabled device (eg. *PEAK-USB*) and uses *can-utils* tools.

Tested with Linux, Windows might require additional steps.

## Prerequisites

### Arduino IDE

Download the official Arduino IDE from https://www.arduino.cc/en/software and extract it to a known location (from here on referred as **<PATH_TO_ARDUINO\>**).

### can-utils

Install can-utils with following command (example for apt):

	sudo apt-get install can-utils
	
### udev rules

The Arduino Uno device files will require root access for read and write access by default. To enable non-root uses to access the device, place the rule file in the corresponding directory and retrigger the udev daemon:

	sudo cp resources/50-arduino.rules /etc/udev/rules.d
	sudo udevadm trigger
	
The Arduino Uno needs to be plugged out and back in again for the command to take effect.

## Build & Upload

Run CMake:

	cd arduino_can_example/
	mkdir build/
	cd build/
	cmake -DCMAKE_TOOLCHAIN_FILE=../external/Arduino-CMake-Toolchain/Arduino-toolchain.cmake -DARDUINO_INSTALL_PATH=<PATH_TO_ARDUINO> ..

Build:

	make

Upload:

	make upload-arduino_can_example -- SERIAL_PORT=/dev/ttyACM0

At this point **Node A** is set up and starts to transmit CAN data periodically and waits for incoming data to arrive.

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

* https://github.com/a9183756-gh/Arduino-CMake-Toolchain
* https://github.com/autowp/arduino-mcp2515
* https://elinux.org/CAN_Bus
* https://wiki.seeedstudio.com/CAN-BUS_Shield_V1.2/
* https://www.arduino.cc/reference/de/language/functions/external-interrupts/attachinterrupt/

## PoC provided by Torsten Wylegala (twyleg)
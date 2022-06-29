# Project 02: Arduino


## Description
Interfacing MCP2515 CAN BUS Module with Arduino


# Duration
40 hours / 1 week


# Skills
* General Electronics
* Electronics Circuits
* Programming
* In-Vehicle communication


# Attachments
* Attachment 1
* Attachment 2


# Forewords
Today any average car consists of around 60 to 100 sensor units in it for sensing and exchanging information. With car manufactures constantly making their car smarter with features like Autonomous driving, Airbag system, Tire Pressure monitoring, Cruise control system etc. this number is only expected to go high. Unlike other sensors, these sensors process critical information and hence the data from these sensors should be communicated using standard automotive communication protocols. For example, cruise control system data like speed, throttle position etc are vital values which are sent to Electronic Control Unit (ECU) to decide the acceleration level of the car, a miscommunication or loss of data here could lead to critical failures. Hence unlike standard communication protocols like UART, SPI or I2C, designers use reliable automobile communication protocols like LIN, CAN, FlexRay etc.


# Introduction
Out of all the available protocols CAN is more predominantly used and popular. You will also exchange data between two Arduinos using CAN communication. Sounds interesting right! So, let’s get started.


# Objectives
* Send humidity & temperature (DHT11) sensor data from Arduino Nano to Arduino Uno via CAN bus module MCP2515 (a high speed CAN transceiver).


# Common Instructions
Safety first! Electronics is a potentially dangerous hobby. Any circuit that works with 120 VAC power from an electrical outlet is especially dangerous and could potentially kill you. Here are some safety guidelines to keep you safe as you work:
* Never work on a circuit while power is applied.
* Do not connect power to a circuit until the circuit is finished and you have carefully checked your work.
* If you smell anything burning, immediately disconnect the power and examine your circuit to find out what went wrong.
* Keep your work area dry.
* Always wear safety goggles.
* Be careful around large capacitors; they can continue to hold voltage long after they are disconnected from power.
* Be especially careful when you solder because a hot soldering iron can easily burn you.
* Always work in a well-ventilated space.
* Have safety equipment such as a fire extinguisher, a first-aid kit, and a phone nearby.


# Mandatory part
* You must read humidity and temperature sensor data using Arduino Nano.
* You must transmit humidity and temperature sensor data over CAN.
* You must show humidity and temperature on some mini LCD display connected to Arduino Uno.
* You must show the working of your setup. (May be try playing with room temperature?)


# Bonus part
* Find a way to place the CAN Bus Module on your PiRacer. (Hint: 3D-Printer comes very handy to create customized parts)


# Submission & Peer evaluation
How to do peer evaluation

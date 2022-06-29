// Copyright (C) 2021 twyleg
#include "Arduino.h"

#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(10);
struct can_frame txCanFrame1;
struct can_frame txCanFrame2;


bool canInterruptTriggered = false;

void interruptHandler() {
	canInterruptTriggered = true;
}

void printCanFrame(struct can_frame& canFrame) {
	Serial.print("CAN frame: id=0x");
	Serial.print(canFrame.can_id, HEX);
	Serial.print(", len=");
	Serial.print(canFrame.can_dlc, HEX);
	Serial.print(", data=");

	for (int i = 0; i<canFrame.can_dlc; i++) {
		Serial.print(" 0x");
		Serial.print(canFrame.data[i], HEX);
		Serial.print(" ");
	}

	Serial.println();
}

void readCanFrames() {
	struct can_frame canFrame;
	uint8_t irq = mcp2515.getInterrupts();

	if (irq & MCP2515::CANINTF_RX0IF) {
		if (mcp2515.readMessage(MCP2515::RXB0, &canFrame) == MCP2515::ERROR_OK) {
			Serial.print("Received ");
			printCanFrame(canFrame);
		}
	}

	if (irq & MCP2515::CANINTF_RX1IF) {
		if (mcp2515.readMessage(MCP2515::RXB1, &canFrame) == MCP2515::ERROR_OK) {
			Serial.print("Received ");
			printCanFrame(canFrame);
		}
	}
}

void setup() {

	txCanFrame1.can_id  = 0x011;
	txCanFrame1.can_dlc = 1;
	txCanFrame1.data[0] = 0x00;

	txCanFrame2.can_id  = 0x010;
	txCanFrame2.can_dlc = 1;
	txCanFrame2.data[0] = 0x00;

	while (!Serial);
	Serial.begin(115200);
	SPI.begin();

	mcp2515.reset();
	mcp2515.setBitrate(CAN_125KBPS);
	mcp2515.setNormalMode();

	attachInterrupt(digitalPinToInterrupt(2), interruptHandler, FALLING);

	Serial.println("CAN Receiver/Transmitter started!");
}

void loop() {

	// Read
	if (canInterruptTriggered) {
		canInterruptTriggered = false;
		readCanFrames();
	}


	// Write
	static uint32_t lastTimestamp = millis();
	uint32_t now = millis();

	if (now - lastTimestamp > 500) {

		Serial.print("Transmit ");
		printCanFrame(txCanFrame1);
		Serial.print("Transmit ");
		printCanFrame(txCanFrame2);

		mcp2515.sendMessage(&txCanFrame1);
		mcp2515.sendMessage(&txCanFrame2);

		txCanFrame1.data[0]++;
		txCanFrame2.data[0]++;

		lastTimestamp = now;
	}
}


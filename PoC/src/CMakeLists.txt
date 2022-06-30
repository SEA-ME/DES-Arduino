cmake_minimum_required(VERSION 3.0.0)

add_executable(arduino_can_example
	main.cc
)

target_link_arduino_libraries(arduino_can_example
	PRIVATE core
	PRIVATE mcp2515
)

#
# A little hack to make IDEs aware of the arduino includes (not working properly at the moment)
#
target_include_directories(arduino_can_example
	PUBLIC ${ARDUINO_INSTALL_PATH}/hardware/tools/avr/avr/include/
	PUBLIC ${ARDUINO_INSTALL_PATH}/hardware/arduino/avr/cores/arduino/
	PUBLIC ${ARDUINO_INSTALL_PATH}/hardware/arduino/avr/cores/
)

target_enable_arduino_upload(arduino_can_example)

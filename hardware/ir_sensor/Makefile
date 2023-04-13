PROJ_NAME=ir_sensor

all:
	arduino-cli compile --fqbn arduino:avr:uno $(PROJ_NAME).ino

upload:
	arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno $(PROJ_NAME).ino

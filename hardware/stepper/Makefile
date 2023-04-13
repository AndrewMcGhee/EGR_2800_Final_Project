PROJ_NAME=stepper

all:
	arduino-cli compile --fqbn arduino:avr:uno $(PROJ_NAME).ino

upload:
	arduino-cli upload -p /dev/ttyACM* --fqbn arduino:avr:uno $(PROJ_NAME).ino

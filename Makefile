# Wrapper around PlatformIO (https://platformio.org).

all:
	pio run

flash:
	pio run -t upload

monitor:
	pio device monitor

clean:
	pio run -t clean

.PHONY: all flash monitor clean

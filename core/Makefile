FLAGS=-Wall -Wextra
CXXFLAGS=$(FLAGS) -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=103 -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/share/arduino/hardware/arduino/variants/standard/
CFLAGS=$(FLAGS) -g -Os -w -fno-exceptions -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=103 -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/share/arduino/hardware/arduino/variants/standard/
FILES=WString.o wiring_digital.o wiring.o wiring_analog.o WInterrupts.o Tone.o Print.o main.o HardwareSerial.o wiring_shift.o wiring_pulse.o Print.o WMath.o


all : $(FILES)
	avr-ar rcsv core.a *.o

%.o : /usr/share/arduino/hardware/arduino/cores/arduino/%.c
	avr-gcc $(CFLAGS) -c $< -o $@

%.o : /usr/share/arduino/hardware/arduino/cores/arduino/%.cpp
	avr-g++ $(CXXFLAGS) -c $< -o $@

clean :
	rm -vf *.o
	rm -vf *.a

OBJS=ppe.o bt.o dir.o
NAME=obj
FLAGS=-g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=103 -I /usr/share/arduino/hardware/arduino/cores/arduino/ -I /usr/share/arduino/hardware/arduino/variants/standard/ -I/usr/share/arduino/libraries/{EEPROM,Esplora,Ethernet,Firmata,GSM,LiquidCrystal,Robot_Control,Robot_Motor,SD,Servo,SoftwareSerial,SPI,Stepper,TFT,WiFi,Wire}
PORT=/dev/ttyUSB0
BAUDRATE=57600

$(NAME).hex : $(OBJS)
	cd core && touch tmp.o tmp.a
	cd core && make clean
	cd core && make
	avr-g++ -Os -Wl,--gc-sections -mmcu=atmega328p -o $(NAME).elf $^ ./core/core.a -L core -lm
	avr-objcopy -O ihex -R .eeprom $(NAME).elf $(NAME).hex

%.o : %.cpp
	avr-g++ $(FLAGS) -c $^ -o $@

transmit : $(NAME).hex
	avrdude -C /etc/avrdude.conf -v -p m328p -P $(PORT) -b$(BAUDRATE) -c arduino -U flash:w:$(NAME).hex

connect : transmit
	screen $(PORT) 9600

clean :
	cd core && touch tmp.o tmp.a
	cd core && make clean
	rm -vf $(NAME).o
	rm -vf $(NAME).elf
	rm -vf $(NAME).hex

.PHONY:clean connect transmit


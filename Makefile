

buttons.o : 
	avr-gcc buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  
	
buttons.exe :
	avr-gcc -mmcu=atmega328p buttons.o -o buttons
	
buttons.hex :
	avr-objcopy -O ihex -R .eeprom buttons buttons.hex
	
dump :
	avrdude -p atmega328p -P usb -c usbasp -U flash:w:buttons.hex
	
all :
		avr-gcc buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  
		avr-gcc -mmcu=atmega328p buttons.o -o buttons
		avr-objcopy -O ihex -R .eeprom buttons buttons.hex

	
clean :
	rm buttons.o 
	rm buttons.hex
	rm buttons
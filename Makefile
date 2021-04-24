

buttons.o : 
	avr-gcc buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  
	
buttons.exe :
	avr-gcc -mmcu=atmega328p buttons.o -o buttons
	
buttons.hex :
	avr-objcopy -O ihex -R .eeprom buttons buttons.hex
	
dump :
	avrdude -p atmega328p -P usb -c usbasp -U flash:w:buttons.hex
	
all :	
	# main file obj creation
	avr-gcc buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  
	# custom files obj creation	
	avr-gcc src/GPIO_DRIVER0.c -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lib.o
	# linking them here to get executable
	avr-gcc -mmcu=atmega328p buttons.o lib.o -o buttons
	# converting executable to inter hex format
	avr-objcopy -O ihex -R .eeprom buttons buttons.hex

	
clean :
	rm buttons.o 
	rm buttons.hex
	rm buttons
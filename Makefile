CC = avr-gcc
PROJECT_NAME = buttons
OUTPUT_NAME = buttons_op

buttons.o : 
	$(CC) buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  

lib.o :
	$(CC) src/GPIO_DRIVER0 -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lib.o 
	
buttons.exe :
	$(CC) -mmcu=atmega328p buttons.o -o $(OUTPUT_NAME)
	
buttons.hex :
	avr-objcopy -O ihex -R .eeprom buttons $(OUTPUT_NAME).hex
	
dump :
	avrdude -p atmega328p -P usb -c usbasp -U flash:w:$(OUTPUT_NAME).hex
	
all :	
	# main file obj creation
	$(CC) buttons.c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o buttons.o  
	# custom files obj creation	
	$(CC) src/GPIO_DRIVER0.c -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o lib.o
	# linking them here to get executable
	$(CC) -mmcu=atmega328p buttons.o lib.o -o $(OUTPUT_NAME)
	# converting executable to inter hex format
	avr-objcopy -O ihex -R .eeprom $(OUTPUT_NAME) $(OUTPUT_NAME).hex

	
clean :
	rm $(OUTPUT_NAME)
	rm buttons.o
	rm $(OUTPUT_NAME).hex
	rm lib.o
	

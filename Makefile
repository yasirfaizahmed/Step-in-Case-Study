CC = avr-gcc
PROJECT_NAME = main
OUTPUT_NAME = main_op

all :	
	# main file obj creation
	$(CC) $(PROJECT_NAME).c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $(PROJECT_NAME).o  
	# custom files obj creation	
	$(CC) src/GPIO_DRIVER0.c -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o GPIO.o
	$(CC) src/ADC_DRIVER0.c -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o ADC.o
	$(CC) src/UART_DRIVER0.c -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o UART.o
	# linking them here to get executable
	$(CC) -mmcu=atmega328p $(PROJECT_NAME).o GPIO.o ADC.o UART.o -o $(OUTPUT_NAME)
	# converting executable to inter hex format
	avr-objcopy -O ihex -R .eeprom $(OUTPUT_NAME) $(OUTPUT_NAME).hex

main.o : 
	$(CC) $(PROJECT_NAME).c -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o $(PROJECT_NAME).o  

GPIO.o :
	$(CC) src/GPIO_DRIVER0 -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o GPIO.o 
ADC.o :
	$(CC) src/ADC_DRIVER0 -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o ADC.o
UART.o :
	$(CC) src/UART_DRIVER0 -I inc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o UART.o
	
main.exe :
	$(CC) -mmcu=atmega328p $(PROJECT_NAME).o GPIO.o ADC.o UART.o -o $(OUTPUT_NAME)
	
main.hex :
	avr-objcopy -O ihex -R .eeprom buttons $(OUTPUT_NAME).hex
	
dump :
	avrdude -p atmega328p -P usb -c usbasp -U flash:w:$(OUTPUT_NAME).hex
	
	
# optimizations
cppcheck : 
	cppcheck --enable=all $(PROJECT_NAME).c src/GPIO_DRIVER0.c 
	
clean :
	rm $(OUTPUT_NAME)
	rm $(PROJECT_NAME).o
	rm $(OUTPUT_NAME).hex
	rm GPIO.o
	rm ADC.o
	rm UART.o
	

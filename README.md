# PIC18F4550-Data-Logger
Temperature data logger using PIC18F4550, RTC and EEPROM
# PIC18F4550 Temperature Data Logger

This project is a temperature data logger using:
- PIC18F4550
- DS3232 RTC
- 24LC256 EEPROM 
- LCD 16*02 (parallel Interface)
- LM35 (temperature sensor)
- USB_TTL

## Features
- Logs temperature every minute
- Stores data in EEPROM
- Displays time and temperature on LCD & on TERMINAL via UART (USB_TTL)
- Button to read stored data 
- Buttons to set Time & Date in the DS3232(RTC)

## Tools Used
- MPLAB X
- XC8 Compiler
- Proteus for simulation
- ## HOW IT WORK
- EEPROM(24LC256) & DS3232(RTC) use I2C for comunication
- MCU uses I²C to:
  - For DS3232:
    - Write time/date to DS3232 registers
    - Read current time/date from registers
    - Time is stored in BCD format
  - For EEPROM:
    - Select memory address
    - Write data (byte/page)
    - Read stored data later

- The DS3232 is used to keep accurate time and generate a periodic alarm every minute  
  This alarm triggers an interrupt (IOC) on the microcontroller

- When the interrupt occurs, the microcontroller:
  - Reads the current temperature value
  - Retrieves the timestamp from the DS3232
  - Stores the temperature and time data into the EEPROM
    
- A user-triggered interrupt is implemented to retrieve logged data  
  Upon interrupt activation, the microcontroller accesses the EEPROM, extracts the temperature records stored over the last 60 minutes, and sends the data through UART for external display or logging






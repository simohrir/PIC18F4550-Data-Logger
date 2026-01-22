
##HOW TO RUN THE SIMULATION.

1. Open the Proteus [sim].
2. Double-click on the **PIC18F4550**.
3. In **Program File**, select the compiled `.hex` file.
4. Set the clock frequency (example: 4 MHz or 8 MHz as used in the code).
5. Click [Run] to start the simulation.

##EDIT CLOCK (DS3232)

-To Start edit click on EDIT button .
-++ INC, Increments the value of the selected variable (min, hour, etc.).
-NEXT button goes to the next variable.
-SAVE saves your edit in the DS3232 and EEPROM.[*NOTE: It is better to reset your simulation in order to avoid a mismatch.]

##Last_1H

When pressed, this button transmits the temperature values stored at one-minute intervals over the last hour.[*NOTE: If you change the date and time, it is necessary to restart the SIM; otherwise, there will be a mismatch, and you will receive dummy data.]

##NOTES
*When the [EDIT] button is pressed, an interrupt is triggered and the program enters edit mode, where execution is paused until the interrupt flag is cleared. The flag is cleared once editing is completed and the changes are saved. If the system remains in edit mode for too long (more than 134 sec), the Watchdog Timer [WDT] automatically resets the microcontroller.
*



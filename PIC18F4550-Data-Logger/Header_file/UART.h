void uart_init(){
    TRISCbits.RC6=1;//all so risever if needed
    TRISCbits.RC7=1;//set trasmiter bit to 1 like in the datasheet
    TXSTAbits.BRGH=1;//hight baud rate
     BAUDCONbits.BRG16 = 1; // 16-bit baud rate
     SPBRGH = 0;
    SPBRG = 103;//9600 for 4MHz
    TXSTAbits.SYNC = 0; // asynchronous
    RCSTAbits.SPEN = 1; // Enable USART
    TXSTAbits.TXEN = 1; // Enable transmit
}
void write(unsigned char data){
    while(!PIR1bits.TXIF);//we will with until we have the flag that means that the TXREG is empty and we can writh
    TXREG = data;
}
void write_string(unsigned char *tab){
    for(int i=0;tab[i]!='\0';i++){
        write(tab[i]);

    }
}
//this function sends info via UART every 30sec
void detail_show(unsigned char sec,unsigned char min,unsigned char hour,unsigned char date,unsigned char month,unsigned char year,float temp,unsigned char *uart_String){
     sprintf(uart_String,"date:%u / %u / %u |[time: %u : %u : %u]|temp:%.2f°C\r\n",BCD_dicimal(date),BCD_dicimal(month),BCD_dicimal(year),BCD_dicimal(hour),BCD_dicimal(min),BCD_dicimal(sec),temp);
     write_string(uart_String);
}
//this function sends the stored data of the previous 60min
void temp_show(unsigned char min,unsigned char hour ,unsigned char temp,unsigned char *uart_String){
    sprintf(uart_String,"||        >>>time: %u : %u]|temp:%u °C            |\r\n",BCD_dicimal(hour),BCD_dicimal(min),temp);
    write_string(uart_String);
}

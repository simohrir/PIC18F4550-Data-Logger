
//  <||| A1=A2=A0=0 |||>
#define address_write 0xA0
#define  address_read 0xA1
//THIS FUNCTION STORE THE DATA IN EEPROM (24LC256)
            
void send_data(unsigned char sec,unsigned char min,unsigned char hour,unsigned char day,unsigned char date,unsigned char month,unsigned char year){  
     I2C_Stop();//
     I2C_Start();
    I2C_Write(address_write);
    I2C_Write(0X00);//addr high
    I2C_Write(0X00);//addr low
    I2C_Write(sec);
    I2C_Write(min);
    I2C_Write(hour);
    I2C_Write(day);
    I2C_Write(date);
    I2C_Write(month);
    I2C_Write(year);
    I2C_Stop();
}
//THIS FUNCTION TO READ THE DATA STORED
void read_data(unsigned char *sec,unsigned char *min,unsigned char *hour,unsigned char *day,unsigned char *date,unsigned char *month,unsigned char *year){
    I2C_Stop();//
    I2C_Start();
    I2C_Write(address_write);
    I2C_Write(0X00);//addr high
    I2C_Write(0X00);//addr low
    I2C_Stop();
    I2C_Start();
    I2C_Write(address_read);
    *sec=I2C_Read(0);
    *min=I2C_Read(0);
    *hour=I2C_Read(0);
    *day=I2C_Read(0);
    *date=I2C_Read(0);
    *month=I2C_Read(0);
    *year=I2C_Read(1);
    I2C_Stop();
}
void store_temp(uint8_t temp,uint8_t address,unsigned char min,unsigned char hour){
    I2C_Stop();//
    I2C_Start();
    I2C_Write(address_write);
    I2C_Write(0X01);//addr high
    I2C_Write(3*address);//addr low >> We need to multiply the address by 3 to provide 3 registers [min, hour, and temp].
    I2C_Write(min);
    I2C_Write(hour);//addr low
    I2C_Write(temp);
    I2C_Stop();
}
void read_stored(unsigned char *min,unsigned char *hour,unsigned char *temp,unsigned char address){
   I2C_Stop();//
   I2C_Start();
    I2C_Write(address_write);
    I2C_Write(0X01);//addr high
    I2C_Write(address*3);
    I2C_Stop();
    I2C_Start();
    I2C_Write(address_read);
    *min=I2C_Read(0);
    *hour=I2C_Read(0);////float temp;float temp;////float temp;
    *temp=I2C_Read(1);
     I2C_Stop();
}


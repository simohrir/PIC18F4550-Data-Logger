#include <xc.h>
#define _XTAL_FREQ 4000000

void ADC_Init(void) {
    TRISAbits.TRISA0 = 1;// AN0 input
    ADCON1 = 0x0E;// AN0 analog, others digital

    ADCON2bits.ADFM = 1;// right justified
    ADCON2bits.ACQT = 0b010; // 4 TAD
    ADCON2bits.ADCS = 0b110;// Fosc/64

    ADCON0bits.CHS = 0;// channel AN0
    ADCON0bits.ADON = 1;    // Enable ADC
}

unsigned int ADC_Read(void) {
    ADCON0bits.GO = 1;
    while(ADCON0bits.GO);
    return ((unsigned int)ADRESH << 8) | ADRESL;
}

float temperature(uint16_t ADC){//this fct returns the real value of temp
    float temp,Voltage;
    uint16_t AN9RES=ADC;//the value that we find in the ADC register
    Voltage = AN9RES * 0.0048828;//We multiply it by resolution.
    temp= Voltage / 0.01;//this for LM35
        return temp;
}





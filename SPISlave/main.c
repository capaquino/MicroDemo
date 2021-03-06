/*
 * SPISlave.c
 *
 * Created: 7/14/2017 11:07:00 AM
 * Author : dornback
 */ 

#include <avr/io.h>
#include "spi.h"
#include "led.h"


int main(void)
{
    DDRD = 0x01;
    DDRC = 0x20;
    SET_BIT(PORTC, 5);
    
    SPISlaveInit();
    
    while (1) 
    {
        if (SPIRead() ==  0x01)
        {
            Blink_LED(&PORTD, 0);
            SPIWrite(0x02);
        }
    }           
}
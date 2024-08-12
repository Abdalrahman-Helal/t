/*
 * App.c
 *
 *  Created on: Jul 28, 2024
 *      Author: Abdalrahman
 */



#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>


#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SSD/SSD_Interface.h"

#define F_CPU 8000000UL

int main(void)
{
	MDIO_voidSetPortDirection(DIO_PORTA,0xFF);
	while(1)
	{
		HSSD_voidDisplayNumber(DIO_PORTA,FIVE);
//		_delay_ms(1000);
//		HSSD_voidDisplayNumberAscending(DIO_PORTB , 1000);
	}
}



/*
 * App.c
 *
 *  Created on: Aug 5, 2024
 *      Author: Abdalrahman
 */

#include "../Include/LIB/BIT_MATH.h"
#include "../Include/LIB/STD_TYPES.h"
#include <util/delay.h>



#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/HAL/SSD/SSD_Interface.h"
//#include "../Include/HAL/LCD/LCD_interface.h"
//#include "../Include/HAL/Keypad/Keypad_Interface.h"
#define F_CPU 8000000UL


/********/


int main(void)
{

	MDIO_voidInit();
	u8 local_u8KeyPadValue;
	while(1)
	{
		HSSD_voidDisplayNumberAscending(DIO_PORTB,500);
	}



}


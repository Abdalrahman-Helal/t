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
#include "../Include/HAL/LCD/LCD_interface.h"
#include "../Include/HAL/Keypad/Keypad_Interface.h"
#define F_CPU 8000000UL

int main(void)
{

//	MDIO_voidInit();
//	HLCD_voidInit();
//
//	u8 local_u8KeyPadValue;
//	u8 local_u8CharCounter=0;
//	while(1)
//	{
//		local_u8KeyPadValue = HKEYPAD_u8GetPressedKey();
//		if(local_u8KeyPadValue != 255)
//		{
//			HLCD_voidSendData(local_u8KeyPadValue);
//			local_u8CharCounter++;
//			if(local_u8CharCounter == 16)
//			{
//				HLCD_voidGoToPos(LCD_ROW2,LCD_COL1);
//			}
//			else if(local_u8CharCounter == 32)
//			{
//				HLCD_voidClearDisplay();
//				HLCD_voidGoToPos(LCD_ROW1,LCD_COL1);
//				local_u8CharCounter=0;
//
//			}
//		}
//	}

	MDIO_voidInit();
	HLCD_voidInit();
	u8 Operand[2];
	u8 Operation;
	u8 Res;


	u8 local_u8KeyPadValue;
	u8 local_u8CharCounter=0;



	while(1)
	{
		for(u8 i=0; i<3;i++)
		{
			local_u8KeyPadValue=HKEYPAD_u8GetPressedKey();
			if(local_u8KeyPadValue != 255)
			{
				HLCD_voidSendData(local_u8KeyPadValue);
				local_u8CharCounter++;
				if(i == 0) // Enter 1st Operand
				{
					Operand[1]=local_u8KeyPadValue;
				}
				else if (i == 2) // Enter Operation
				{
					Operation = local_u8KeyPadValue;
				}
				else // Enter 2nd Operand
				{
					Operand[2]=local_u8KeyPadValue;
				}

				switch(Operation)
				{
				case'+':
					Res = Operand[1]+Operand[2];
					break;
				case'-':
					Res = Operand[1]-Operand[2];
					break;
				case'*':
					Res = Operand[1]*Operand[2];
					break;
				case'/':
					Res = Operand[1]/Operand[2];
					break;
				}

				if(local_u8CharCounter == 16)
				{
					HLCD_voidGoToPos(LCD_ROW2,LCD_COL1);
				}

				HLCD_voidSendData(Res);
				local_u8CharCounter++;

			}
		}
	}







}


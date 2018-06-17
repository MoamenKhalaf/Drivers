
#include "lcd.h"
#include "keypad.h"
#include <stdio.h>
#include <stdlib.h>

void main ()
{

LcdInit();
Keypad_Init();







while(1)
{
	//declarations
	unsigned char scan , op='0';
	long int num1=0 , num2=0 ;
	unsigned char i;
	unsigned char Result [7] = {'0','0','0','0','0','0','\0'};
	// loop until user enter three digits or any of operations
	for (i=0;i<3;i++)
	{
		// convert the entered number from ascii to integer
		scan = Keypad_Scan();
		UCLcdChar(scan);
		if (scan >=48 && scan <= 57)
		{
			scan -=48;
			num1 = (num1*10)+scan;
		}
		else 
		{
			op = scan;

			break;
		}
	}

	if (op == '0')
	{
		op = Keypad_Scan();
		UCLcdChar(op);
	} 
	else {/* MISRA*/}
	 
	// loop until user enter the second three digits or enter an equal sign
	for (i=0;i<3;i++)
	{
		// convert the entered number from ascii to integer
		scan = Keypad_Scan();
		UCLcdChar(scan);
		if (scan >=48 && scan <= 57)
		{
			scan -=48;
			num2 = (num2*10)+scan;
		}
		else 
		{
			break;
		}

		
	} 

	if (scan != '='){

		scan = Keypad_Scan();
		UCLcdChar('=');
		}
	// execute the operation
	switch (op)
	{
		case '+':{num1+=num2;break;}
		case '-':{num1-=num2;break;}
		case '*':{num1*=num2;break;}
		case '/':{num1/=num2;break;}
		default:{/*MISRA*/}
	}

	

	// convert the result to ascii digits and store them in array of characters
	for (i=0;i<7;i++)
	{
		if (num1 != 0)
		{
			Result[i]=(num1%10)+48;
			num1/=10;
		}
		else 
		{
			break;
		}
	}


	// loop over the array of characters and print the result on lcd
	for (i=5;i>0;i--)
	{
		if (Result[i] != '0')
		{
			break;
		}
	}

	gotoXY(0,1);

	

	
	for (num1=i; num1>=0 ; num1--)
	{
		UCLcdChar(Result[num1]);
	}

}
}
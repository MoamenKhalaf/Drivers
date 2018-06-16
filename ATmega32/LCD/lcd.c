#include "lcd.h"

unsigned char address = 0x80;

void LcdInit (void)
{
	//direction initialization

	RS_dir |= (1<<RS);
	RW_dir |= (1<<RW);
	E_dir  |= (1<<E);

	#ifdef _8_BITMODE
	D0_dir |= (1<<D0);
	D1_dir |= (1<<D1);
	D2_dir |= (1<<D2);
	D3_dir |= (1<<D3);
	#endif
	D4_dir |= (1<<D4);
	D5_dir |= (1<<D5);
	D6_dir |= (1<<D6);
	D7_dir |= (1<<D7);






	 //   INIT : RS  RW  D7 D6 D5 D4 D3 D2 D1 D0 

	// 1 - delay 15 ms

	_delay_ms (17);

	#ifdef _8_BITMODE

	// 2 - INIT : 0  0    0  0  1 1  *  *  *  *
	
	UCLcdCmd(0x30);

	// 3 - delay 5 ms

	_delay_ms (5);

	// 4 - INIT : 0  0    0  0  1 1  *  *  *  *

	UCLcdCmd(0x30);

	

	// 5 - delay 105 us

	_delay_us (105);

	// 6 - INIT : 0  0    0  0  1 1  *  *  *  *

	UCLcdCmd(0x30);


	
	// 7 - INIT : 0  0    0  0  1 1  1  *  *  *  2 lines lcd

	UCLcdCmd(0x38);

	
	

	
	// 8 - INIT : 0  0    0  0  0 0  1  *  *  *  

	UCLcdCmd(0x08);

	

	// 9 - INIT : 0  0    0  0  0 0  0  0  0  1  

	UCLcdCmd(0x01);

	
	// 10 - INIT : 0  0    0  0  0 0  0  1  1  0  

	UCLcdCmd(0x06);


	// 11 - INIT : 0  0    0  0  0 0  1  1  1  *  

	UCLcdCmd(0x0e);


	// 12 - INIT : 0  0    1  0  0 0  0  0  0  0  

	UCLcdCmd(0x80);
	#endif
//-----------------------------------------------------------------
	// 4 bitmode initialization

	#ifdef _4_BITMODE

	// 1 - delay 15 ms

	_delay_ms (17);

	// 2 - INIT : 000011

	UCLcdCmd(0x03);

	// 3 - delay 5 ms

	_delay_ms (5);

	// 4 - INIT : 000011

	UCLcdCmd(0x03);

	// 5 - delay 100 us

	_delay_us (105);

	// 6 - INIT : 000011

	UCLcdCmd(0x03);

	// 7 - INIT : 000010

	UCLcdCmd(0x02);


	// 9 - INIT : 000010

	UCLcdCmd(0x02);

	// 10 - INIT : 001000

	UCLcdCmd(0x08);


	// 12 - INIT : 000000

	UCLcdCmd(0x00);

	// 13 - INIT : 001000

	UCLcdCmd(0x08);


	// 15 - INIT : 000000

	UCLcdCmd(0x00);

	// 16 - INIT : 000001

	UCLcdCmd(0x01);


	// 18 - INIT : 000000

	UCLcdCmd(0x00);

	// 19 - INIT : 000110

	UCLcdCmd(0x06);


	// 21 - INIT : 000000

	UCLcdCmd(0x00);

	// 22 - INIT : 001110

	UCLcdCmd(0x0e);

	

	// 24 - INIT : 001000

	UCLcdCmd(0x08);

	// 25 - INIT : 000000

	UCLcdCmd(0x00);



	#endif // _4_BITMODE	
}



void UCLcdChar(unsigned char input)
{
	RS_OUTPUT |=  (1<<RS);
	RW_OUTPUT &= ~(1<<RW);

	/*PORTD=input;*/

	#ifdef _8_BITMODE

	if (input & (1<<0))
		{D0_OUTPUT |=  (1<<D0);}

	else if (!(input & (1<<0)))
		{D0_OUTPUT &= ~(1<<D0);}

	else{;} /*Misra*/


	if (input & (1<<1))
		{D1_OUTPUT |=  (1<<D1);}

	else if (!(input & (1<<1)))
		{D1_OUTPUT &= ~(1<<D1);}

	else{;} /*Misra*/

	if (input & (1<<2))
		{D2_OUTPUT |=  (1<<D2);}

	else if (!(input & (1<<2)))
		{D2_OUTPUT &= ~(1<<D2);}

	else{;} /*Misra*/

	if (input & (1<<3))
		{D3_OUTPUT |=  (1<<D3);}

	else if (!(input & (1<<3)))
		{D3_OUTPUT &= ~(1<<D3);}

	else{;} /*Misra*/

	if (input & (1<<4))
		{D4_OUTPUT |=  (1<<D4);}

	else if (!(input & (1<<4)))
		{D4_OUTPUT &= ~(1<<D4);}

	else{;} /*Misra*/

	if (input & (1<<5))
		{D5_OUTPUT |=  (1<<D5);}

	else if (!(input & (1<<5)))
		{D5_OUTPUT &= ~(1<<D5);}

	else{;} /*Misra*/

	if (input & (1<<6))
		{D6_OUTPUT |=  (1<<D6);}

	else if (!(input & (1<<6)))
		{D6_OUTPUT &= ~(1<<D6);}

	else{;} /*Misra*/

	if (input & (1<<7))
		{D7_OUTPUT |=  (1<<D7);}

	else if (!(input & (1<<7)))
		{D7_OUTPUT &= ~(1<<D7);}

	else{;} /*Misra*/
		
	E_OUTPUT  |=  (1<<E);
	E_OUTPUT  &= ~(1<<E);
	#endif // _8_BITMODE
//------------------------------------------------------
	// 4 bit mode send character

	// sending higher nibble
	#ifdef _4_BITMODE

	if (input & (1<<4))
		{D4_OUTPUT |=  (1<<D4);}

	else if (!(input & (1<<4)))
		{D4_OUTPUT &= ~(1<<D4);}

	else{;} /*Misra*/

	if (input & (1<<5))
		{D5_OUTPUT |=  (1<<D5);}

	else if (!(input & (1<<5)))
		{D5_OUTPUT &= ~(1<<D5);}

	else{;} /*Misra*/

	if (input & (1<<6))
		{D6_OUTPUT |=  (1<<D6);}

	else if (!(input & (1<<6)))
		{D6_OUTPUT &= ~(1<<D6);}

	else{;} /*Misra*/

	if (input & (1<<7))
		{D7_OUTPUT |=  (1<<D7);}

	else if (!(input & (1<<7)))
		{D7_OUTPUT &= ~(1<<D7);}

	else{;} /*Misra*/
		
	E_OUTPUT  |=  (1<<E);
	E_OUTPUT  &= ~(1<<E);
//----------------------------------------------------------
	// sending lwoer nibble

	if (input & (1<<0))
		{D4_OUTPUT |=  (1<<D4);}

	else if (!(input & (1<<0)))
		{D4_OUTPUT &= ~(1<<D4);}

	else{;} /*Misra*/

	if (input & (1<<1))
		{D5_OUTPUT |=  (1<<D5);}

	else if (!(input & (1<<1)))
		{D5_OUTPUT &= ~(1<<D5);}

	else{;} /*Misra*/

	if (input & (1<<2))
		{D6_OUTPUT |=  (1<<D6);}

	else if (!(input & (1<<2)))
		{D6_OUTPUT &= ~(1<<D6);}

	else{;} /*Misra*/

	if (input & (1<<3))
		{D7_OUTPUT |=  (1<<D7);}

	else if (!(input & (1<<3)))
		{D7_OUTPUT &= ~(1<<D7);}

	else{;} /*Misra*/
		
	E_OUTPUT  |=  (1<<E);
	E_OUTPUT  &= ~(1<<E);

	#endif // _4_bitmode

	address++;

	if (address == 0x80+16)
		gotoXY (0,1);

}


void UCLcdString(unsigned char* input)
{


	while ((*input)  != '\0')
	{
		UCLcdChar(*input);
		input++;
	}
}





	


void UCLcdCmd(unsigned char input)
{
	RS_OUTPUT &= ~(1<<RS);
	RW_OUTPUT &= ~(1<<RW);


	#ifdef _8_BITMODE
 //masking every bit of the data and assigning it to the corresponding output
	if (input & (1<<0)) 
		{D0_OUTPUT |=  (1<<D0);}

	else if (!(input & (1<<0)))
		{D0_OUTPUT &= ~(1<<D0);}

	else{;} /*Misra*/


	if (input & (1<<1))
		{D1_OUTPUT |=  (1<<D1);}

	else if (!(input & (1<<1)))
		{D1_OUTPUT &= ~(1<<D1);}

	else{;} /*Misra*/

	if (input & (1<<2))
		{D2_OUTPUT |=  (1<<D2);}

	else if (!(input & (1<<2)))
		{D2_OUTPUT &= ~(1<<D2);}

	else{;} /*Misra*/

	if (input & (1<<3))
		{D3_OUTPUT |=  (1<<D3);}

	else if (!(input & (1<<3)))
		{D3_OUTPUT &= ~(1<<D3);}

	else{;} /*Misra*/

	if (input & (1<<4))
		{D4_OUTPUT |=  (1<<D4);}

	else if (!(input & (1<<4)))
		{D4_OUTPUT &= ~(1<<D4);}

	else{;} /*Misra*/

	if (input & (1<<5))
		{D5_OUTPUT |=  (1<<D5);}

	else if (!(input & (1<<5)))
		{D5_OUTPUT &= ~(1<<D5);}

	else{;} /*Misra*/

	if (input & (1<<6))
		{D6_OUTPUT |=  (1<<D6);}

	else if (!(input & (1<<6)))
		{D6_OUTPUT &= ~(1<<D6);}

	else{;} /*Misra*/

	if (input & (1<<7))
		{D7_OUTPUT |=  (1<<D7);}

	else if (!(input & (1<<7)))
		{D7_OUTPUT &= ~(1<<D7);}

	else{;} /*Misra*/
		
	E_OUTPUT  |=  (1<<E);
	E_OUTPUT  &= ~(1<<E);

	_delay_ms (1);
	#endif // _8_BITMODE
//------------------------------------------------------
	//masking every bit of the data and assigning it to the corresponding output
	// sending lower nibble
	#ifdef _4_BITMODE
	if (input & (1<<0))
		{D4_OUTPUT |=  (1<<D4);}

	else if (!(input & (1<<0)))
		{D4_OUTPUT &= ~(1<<D4);}

	else{;} /*Misra*/

	if (input & (1<<1))
		{D5_OUTPUT |=  (1<<D5);}

	else if (!(input & (1<<1)))
		{D5_OUTPUT &= ~(1<<D5);}

	else{;} /*Misra*/

	if (input & (1<<2))
		{D6_OUTPUT |=  (1<<D6);}

	else if (!(input & (1<<2)))
		{D6_OUTPUT &= ~(1<<D6);}

	else{;} /*Misra*/

	if (input & (1<<3))
		{D7_OUTPUT |=  (1<<D7);}

	else if (!(input & (1<<3)))
		{D7_OUTPUT &= ~(1<<D7);}

	else{;} /*Misra*/
		
	E_OUTPUT  |=  (1<<E);
	E_OUTPUT  &= ~(1<<E);

	_delay_ms (1);

	#endif // _4_bitmode



}

void LcdClear (void)
{
	#ifdef  _8_BITMODE
	UCLcdCmd (0x01);
	UCLcdCmd (0x80);
	#endif //8 BITMODE

	#ifdef  _4_BITMODE
	UCLcdCmd (0x00);
	UCLcdCmd (0x01);
	UCLcdCmd (0x08);
	UCLcdCmd (0x00);

	#endif //4 BITMODE



}

void gotoXY (unsigned char X , unsigned char Y)
{

	#ifdef  _8_BITMODE
	if (Y == 0)
	{
		UCLcdCmd (0x80 + X);
		address += X;
	}

	else if (Y == 1)
	{
		UCLcdCmd (0xc0 + X);

	}
	else {UCLcdCmd (0x80);}

	#endif //8 BITMODE

	#ifdef  _4_BITMODE

	if (Y == 0)
	{
		UCLcdCmd (0x08);
		UCLcdCmd (0x00 + X);
		address += X;
	}

	else if (Y == 1)
	{
		UCLcdCmd (0x0c);
		UCLcdCmd (0x00 + X);
	}
	else 
	{
		UCLcdCmd (0x08);
		UCLcdCmd (0x00 );
	}


	#endif //4 BITMODE
}

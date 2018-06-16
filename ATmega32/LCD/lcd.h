#ifndef LCD_H_
#define LCD_H_

#include "LcdConfig.h"


#ifdef _4_BITMODE
#ifdef _8_BITMODE
	#error "Choose single mode 4 or 8 bit"
#endif
#endif

#ifndef _4_BITMODE
#ifndef _8_BITMODE
	#error "Choose mode 4 or 8 bit"
#endif
#endif


#include <avr/io.h>
#include <util/delay.h>



//function to intialize lcd control pins and mode of operation

void LcdInit (void);


//function to print single character

void UCLcdChar(unsigned char input);

//function to print string

void UCLcdString(unsigned char* input);

//function to execute commands
void UCLcdCmd(unsigned char input);
//function gotoxy

void gotoXY (unsigned char X , unsigned char Y);

//function to cleat the display

void LcdClear (void);

#endif //LCD_H_
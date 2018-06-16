#ifndef kEYPAD_H_
#define kEYPAD_H_


#include <avr/io.h>
#include "KeypadConfig.h"


#define Valid_INPUT  ((LINE0_INPUT&(1<<LINE0))&&\
					  (LINE1_INPUT&(1<<LINE1))&&\
					  (LINE1_INPUT&(1<<LINE2))&&\
					  (LINE1_INPUT&(1<<LINE3)))

void Keypad_Init (void);

unsigned char Keypad_Scan (void);

#endif

#include "keypad.h"



/* function to initialize the pins of the keypad
   four pins initialized as output
   and the other four initialize as input*/
void Keypad_Init (void)
{
	// initialize the rows as output
	ROW0_DIR |=(1<<ROW0);
	ROW1_DIR |=(1<<ROW1);
	ROW2_DIR |=(1<<ROW2);
	ROW3_DIR |=(1<<ROW3);
	// initialize the lines as inputs
	LINE0_DIR &=~(1<<LINE0);
	LINE1_DIR &=~(1<<LINE1);
	LINE2_DIR &=~(1<<LINE2);
	LINE3_DIR &=~(1<<LINE3);
	//pullup the line pins
	LINE0_OUTPUT |=(1<<LINE0);
	LINE1_OUTPUT |=(1<<LINE1);
	LINE2_OUTPUT |=(1<<LINE2);
	LINE3_OUTPUT |=(1<<LINE3);

	ROW0_OUTPUT |=(1<<ROW0);
	ROW1_OUTPUT |=(1<<ROW1);
	ROW2_OUTPUT |=(1<<ROW2);
	ROW3_OUTPUT |=(1<<ROW3);
}

/* function to scan the input entered by user on the keypad 
   and return the mapped value to the user*/
unsigned char Keypad_Scan (void)
{
	int Row;
	unsigned char result=0xff;
	// map keypad to two dimensional array
	unsigned char arr [4][4]
	={{'7','8','9','/'},
	  {'4','5','6','*'},
	  {'1','2','3','-'},
	  {'C','0','=','+'}
	} ;
	// loop over rows and output 0 on the corresponding row pin
	while (result == 0xff)
	{
	for (Row=0;Row<4;Row++)
	{
		ROW0_OUTPUT |=(1<<ROW0);
		ROW1_OUTPUT |=(1<<ROW1);
		ROW2_OUTPUT |=(1<<ROW2);
		ROW3_OUTPUT |=(1<<ROW3);
		switch (Row)
		{
			case 0: {ROW0_OUTPUT &=~(1<<ROW0); break;}
			case 1: {ROW1_OUTPUT &=~(1<<ROW1); break;}
			case 2: {ROW2_OUTPUT &=~(1<<ROW2); break;}
			case 3: {ROW3_OUTPUT &=~(1<<ROW3); break;}
			default: {}/* MISRA */
		}
		// check the input entered by user
		if      ((LINE0_INPUT&=(1<<LINE0))==0) {result=arr[Row][0]; break;}
		else if ((LINE1_INPUT&=(1<<LINE1))==0) {result=arr[Row][1]; break;}
		else if ((LINE1_INPUT&=(1<<LINE2))==0) {result=arr[Row][2]; break;}
		else if ((LINE1_INPUT&=(1<<LINE3))==0) {result=arr[Row][3]; break;}
		else {result = 0xff;}
	}  
	while (Valid_INPUT==0){;}
}
return result;

}
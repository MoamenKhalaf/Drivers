#include "timer.h"
//comment , define used function , ctc , normal compare , pwm T1

 unsigned int multi_loop,loop; // a global variable that carries the number of multi timer loops
  void (*usr_ptr)(void); // a global pointer to a function to carry the intrrupt function 

//----------------------------------------------------------------------------------------

//this function calculates the prescaler and the intialization of TCNTn
struct calc_prescaler calc (long long int time_us)
{

	//declarattions
	unsigned long long int TxF = 0 , counts = 0; //TxF ==> time * frequancy
	unsigned char prescaler = 0; //this is the required number of counts @ prescaler 1

	struct calc_prescaler output; //structure contains the prescaler and intialization of TCNTn register
	output.prescaler  = 1; //intialize the prescaler with 1
	output.TCNTn_init = 0; //intialize the TCNTn with 0
	
	// (prescaler * counts )= time * freqancy
	
	if (F_CPU == 1000000)
	{
		TxF = time_us;
	}
	else 
	{
		int scale = F_CPU >> 20; // frequancy / 1000000  using the shift instead of multiplication for time accuracy

		TxF = (time_us) * scale; 

	}
	
	//loop to get the prescaler

	while(1)
	{
		//required counts = (prescaler * counts )/prescaler 

		counts = TxF >> prescaler;

		// check the range of counts
		// if counts is an integer in range of (0 to 255)

		if (counts <= 255)
		{
			// TCNTn initialization = counts
			output.TCNTn_init = counts; 
			// break
			break;
		}
			
		// else if counts out of range and prescaler is less than 1024
		else if (prescaler < 10)
		{
			// switch case the prescaller and update its value 
			switch (prescaler)
			{
																									//	cs02	cs01	cs00
				case 0  : {prescaler = 3; output.prescaler = 2; break;} // prescaler used is 8			0		1		0
				case 3  : {prescaler = 6; output.prescaler = 3; break;}	// prescaler used is 64			0		1		1
				case 6 : {prescaler = 8 ; output.prescaler = 4; break;} // prescaler used is 256		1		0		0
				case 8: {prescaler = 10; output.prescaler = 5; break;}	// prescaler used is 1024		1		0		1
				default : {;} /*MISRA*/
			}
		}

		// else if prescaller reach its maximum value 1024 and counts is out of range
		else if (prescaler == 10 && counts > 255)
		{
			// calculate the required multiloop over overflow flage to get the required counts
			output.TCNTn_init = 255;
			multi_loop = counts >> 8;	//counts/255
			break;
		}

		else 
		{
			output.TCNTn_init = counts; 
			// break
			break;
		}


	}

	//subtract number of counts from the maximum 255 because the over flow flag sets at the switch from 255 to 0
	output.TCNTn_init = 255 - output.TCNTn_init;

	return output; 
}


//------------------------------------------------------------

//this function sets the prescaler and initializes the TCNTn from the calc function
//then starts the timer in the background till the time ends and the intrrupt is called 

//inputs  : the required time , a pointer to a function to execute when the time ends
//outputs : none

// timer 0 
void T0N_us(long long int time_us , void(*user_defined)())
{
	usr_ptr = user_defined ; // fill the global pointer to function with the pointer passed by the user

	//declaration 
	struct calc_prescaler input;
	//calculate prescales , counts 
	input = calc (time_us);

	//enable global intrrupt
	sei();
	//enable T0I intrrupt
	TIMSK = (1<<TOIE0);

	//intialize TCNT0 and TCCR0 
	TCNT0 = input.TCNTn_init;
	TCCR0 |= input.prescaler;
	TCCR0 &= ~(1<<WGM00);
	TCCR0 &= ~(1<<WGM01);

	loop = multi_loop;
	
}




//this function sets the prescaler and initializes the TCNTn from the calc function
//then starts the timer in the background till the time ends and the intrrupt is called 

//inputs  : the required time , a pointer to a function to execute when the time ends
//outputs : none

// timer 2
void T2N_us(long long int time_us , void(*user_defined)())
{
	usr_ptr = user_defined ; // fill the global pointer to function with the pointer passed by the user

	//declaration 
	struct calc_prescaler input;
	//calculate prescales , counts 
	input = calc (time_us);

	//enable global intrrupt
	sei();
	//enable T0I intrrupt
	TIMSK = (1<<TOIE2);

	//intialize TCNT0 and TCCR0 
	TCNT2 = input.TCNTn_init;
	TCCR2 |= input.prescaler;
	TCCR2 &= ~(1<<WGM00);
	TCCR2 &= ~(1<<WGM01);

	loop = multi_loop;
	
}





//-----------------------------------------------------------

ISR(TIMER2_OVF_vect)
{


	if (multi_loop == 0)
	{
		TIFR |= (1<< TOV2); //clear over flow flag
		usr_ptr(); // execute the required function 
		multi_loop = loop; 
			
	}
	else
	{
		multi_loop--; // decrement the multi loop indicator which determine the required loop over overflow flage to get the required counts 
		TIFR |= (1<< TOV2); // clear over flow flag
	}
	
}


//the intrrupt service routine that is trrigered when the overflow flag is set
ISR(TIMER0_OVF_vect)
{


	if (multi_loop == 0)
	{
		TIFR = 1; //clear over flow flag
		usr_ptr(); // execute the required function
		multi_loop = loop; 
			
	}
	else
	{
		multi_loop--;
		TIFR = 1; //clear over flow flag
	}
	
}



//-----------------------------------------------------------------------

//this function sets the prescaler and initializes the TCNTn from the calc function
//then starts the timer in the background till the time ends and the intrrupt is called 

//inputs  : the required time , a pointer to a function to execute when the time ends
//outputs : none

// timer 1
void T1N_us(long long int time_us, void(*user_defined)())
{
	//declarations
	unsigned long long int TxF=0;
	unsigned char prescaler=0;
	// Time * frequency = TxF
	if (F_CPU == 1000000)
	{
		TxF = time_us;
	}
	else 
	{
		int scale = F_CPU >> 20; // frequancy / 1000000

		TxF = (time_us) * scale; 
	}
	// if (TxF <=65536)
	if (TxF <= 65536)
	{
		// set prescaler = 1;
		prescaler = 1;
		//TCNTn=65536-TxF
		TCNT1 = 65536-TxF;
	}
		
	//else if (65536<TxF<=8*65536)
	else if (TxF > 65536 && TxF <= 524288)
	{
		// set prescaller = 8
		prescaler = 2;
		//TCNTn= 65536-TxF /8
		TCNT1 = 65536 - (TxF >> 3);
	}
		
	//else if (8*65536<TxF<==64*65536)
	else if (TxF > 524288 && TxF <= 4194304)
	{
		// set prescaller = 64
		prescaler = 3;
		//TCNTn= 65536-TxF/64
		TCNT1 = 65536 - (TxF >> 6);
	}

	// else if (64*65536<TxF<= 256*65536)
	else if (TxF > 4194304 && TxF <= 16777216)
	{
		// set prescaller = 256
		prescaler = 4;
		//TCNTn= 65536-TxF /256
		TCNT1 = 65536 - (TxF >> 8);
	}
	// else if (TxF>256*65536)
	else 
	{
		// if (TxF <= 1024*65536)
		if (TxF <= 67108864)
		{
			// set prescaler = 1024
			prescaler = 5;
			// TcnTn =65536 - TxF/1024
			TCNT1 = 65536 - (TxF >> 10);
		}
			
		//else 
		else
		{
			// set prescaler = 1024
			prescaler = 5;
			// TCNTn =0
			TCNT1 = 0;
			// Multiloop = TxF/1024
			multi_loop = TxF >> 10;
			//multiloop = multiloop/256
			multi_loop = multi_loop >> 8 ; 
		} 
	}
	usr_ptr = user_defined ;

	sei();
	//enable T0I intrrupt
	TIMSK = (1<<TOIE1);

	TCCR1A &= ~(1<<WGM10);
	TCCR1A &= ~(1<<WGM11);
	TCCR1B &= ~(1<<WGM12);
	TCCR1B &= ~(1<<WGM13);
	TCCR1B |=prescaler;

	loop = multi_loop;
}


ISR (TIMER1_OVF_vect)
{

	if (multi_loop == 0) 
	{	//if the time can be done in one timer loop or it is the last loop of the timer 
		//stop the timer , clear the overflow flag and call the function the user passed
		TIFR |= (1 << TOV1);
		multi_loop = loop;
		usr_ptr();
		
	}
	else
	{ 	//else decrement multi_loop and clear the overflow flag
		multi_loop--;
		TIFR |= (1 << TOV1);
	}
}


//---------------------------------------------------------------
// PWM using timer zeros timer zero
// this function initialize the fast PWM 
// inputs: the required duty cycle , mode of operation either inverted or non inverted
// outputs : none
void FPWM_T0 (unsigned char DutyCycle , unsigned char mode)
{	
	DDRB |= (1<<PB3);

	// initialize the OCR0 register to acheive the duty cycle
	// in timer0 OCR0 = DutyCycle * 256 / 100
	OCR0 = (DutyCycle << 8) / 100;

	//start the PWM
	

	switch (mode)
	{
		// non inverted mode
		case 'n' : 
		case 'N' : {TCCR0 |= (1<<COM01); TCCR0 &= ~(1<<COM00); break;}

		// inverted mode
		case 'i' : 
		case 'I' : {TCCR0 |= (1<<COM01); TCCR0 |= (1<<COM00); break;}

		default  : {TCCR0 |= (1<<COM01); TCCR0 &= ~(1<<COM00); break;}


	}

	// set the timer in fast PWM mode
	TCNT0 = 0;
	TCCR0 |= (1<<WGM00);
	TCCR0 |= (1<<WGM01);
	TCCR0 |= 1;


}

// Phase Correct PWM timer zero
void PCPWM_T0 (unsigned char DutyCycle , unsigned char mode)
{	
	DDRB |= (1<<PB3);

	// initialize the OCR0 register to acheive the duty cycle
	// in timer0 OCR0 = DutyCycle * 256 / 100
	OCR0 = (DutyCycle << 8) / 100;

	//start the PWM
	

	switch (mode)
	{
		case 'n' : 
		case 'N' : {TCCR0 |= (1<<COM01); TCCR0 &= ~(1<<COM00); break;}

		case 'i' : 
		case 'I' : {TCCR0 |= (1<<COM01); TCCR0 |= (1<<COM00); break;}

		default  : {TCCR0 |= (1<<COM01); TCCR0 &= ~(1<<COM00); break;}


	}

	// set the timer in phas Correct PWM

	TCNT0 = 0;
	TCCR0 |= (1<<WGM00);
	TCCR0 &= ~(1<<WGM01);
	TCCR0 |= 1;


}

//-------------------------------------------------------------------------

// PWM using timer zeros timer two
// this function initialize the fast PWM
void FPWM_T2 (unsigned char DutyCycle , unsigned char mode)
{	
	DDRD |= (1<<PD7);

	// initialize the OCR0 register to acheive the duty cycle
	// in timer0 OCR0 = DutyCycle * 256 / 100
	OCR2 = (DutyCycle << 8) / 100;

	//start the PWM
	

	switch (mode)
	{
		case 'n' : 
		case 'N' : {TCCR2 |= (1<<COM21); TCCR2 &= ~(1<<COM20); break;}

		case 'i' : 
		case 'I' : {TCCR2 |= (1<<COM21); TCCR0 |= (1<<COM20); break;}

		default  : {TCCR2 |= (1<<COM21); TCCR0 &= ~(1<<COM20); break;}


	}
	// set the timer in fast PWM mode
	TCNT2 = 0;
	TCCR2 |= (1<<WGM20);
	TCCR2 |= (1<<WGM21);
	TCCR2 |= 1;


}
// Phase Correct PWM timer two
void PCPWM_T2 (unsigned char DutyCycle , unsigned char mode)
{	
	DDRD |= (1<<PD7);

	// initialize the OCR0 register to acheive the duty cycle
	// in timer0 OCR0 = DutyCycle * 256 / 100
	OCR2 = (DutyCycle << 8) / 100;

	//start the PWM
	

	switch (mode)
	{
		case 'n' : 
		case 'N' : {TCCR2 |= (1<<COM21); TCCR0 &= ~(1<<COM20); break;}

		case 'i' : 
		case 'I' : {TCCR2 |= (1<<COM21); TCCR0 |= (1<<COM20); break;}

		default  : {TCCR2 |= (1<<COM21); TCCR0 &= ~(1<<COM20); break;}


	}

	// set the timer in phas Correct PWM
	TCNT2 = 0;
	TCCR2 |= (1<<WGM20);
	TCCR2 &= ~(1<<WGM21);
	TCCR2 |= 1;


}

void TC_Stop (unsigned char TCn)
{
	switch (TCn)
	{
		case 0 : {TCCR0 = 0; break;}

		case 2 : {TCCR2 = 0; break;}

		case 1 : {TCCR1A = 0; TCCR1B = 0; break;}

		default : {TCCR0 = 0; TCCR1A = 0 TCCR1B = 0 TCCR2 = 0 break;}
	}
}
#ifndef TIMER_H_
#define TIMER_H_


//define the cpu frequancy minimum frequancy is 1 MHz
#define F_CPU 1000000

//the main perpose i
//include required libs
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


//structure contains the prescaler and intialization of TCNTn register declaration
struct calc_prescaler {
	unsigned  char TCNTn_init;
	unsigned char prescaler;
} ;

//functions prototypes

//this function calculates the prescaler and the intialization of TCNTn
struct calc_prescaler calc (long long int time_us);

//this function sets the presaler and initializes the TCNTn from the calc function
//then starts the timer in the background till the time ends and the intrrupt is called 
//this 

//inputs  : the required time , a pointer to a function to execute when the time ends
//outputs : none

// timer zero 8 bit timer
void T0N_us(long long int time_us, void(*user_defined)());

// timer two 8 bit timer
void T2N_us(long long int time_us , void(*user_defined)());

// timer one 16 bit timer
void T1N_us(long long int time_us, void(*user_defined)());

// PWM using timer zeros
// this function initialize the fast PWM 
// inputs: the required duty cycle , mode of operation either inverted or non inverted
// outputs : none
void FPWM_T0 (unsigned char DutyCycle , unsigned char mode);

// Phase Correct PWM timer zero
void PCPWM_T0 (unsigned char DutyCycle , unsigned char mode);

// PWM using timer zeros timer two
// this function initialize the fast PWM
void FPWM_T2 (unsigned char DutyCycle , unsigned char mode);

// Phase Correct PWM timer two
void PCPWM_T2 (unsigned char DutyCycle , unsigned char mode);

//to stop all these above functions
void TC_Stop (unsigned char TCn);
#endif
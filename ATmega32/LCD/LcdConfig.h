

#define F_CPU 16000000UL


// choose your mode 

#define _4_BITMODE
//#define _8_BITMODE


#define RS        0
#define RS_dir    DDRB
#define RS_OUTPUT PORTB

#define RW       1
#define RW_dir    DDRB
#define RW_OUTPUT PORTB

#define E        2
#define E_dir    DDRB
#define E_OUTPUT PORTB




// if using 8 bit mode modify your pins according to your configuration here
// D0 corresponding to D0 Pin in LCD and so on
#ifdef _8_BITMODE

#define D0       0
#define D0_dir    DDRD
#define D0_OUTPUT PORTD

#define D1        1
#define D1_dir    DDRD
#define D1_OUTPUT PORTD

#define D2        2
#define D2_dir    DDRD
#define D2_OUTPUT PORTD

#define D3        3
#define D3_dir    DDRD
#define D3_OUTPUT PORTD

#define D4        4
#define D4_dir    DDRD
#define D4_OUTPUT PORTD

#define D5        5
#define D5_dir    DDRD
#define D5_OUTPUT PORTD

#define D6        6
#define D6_dir    DDRD
#define D6_OUTPUT PORTD

#define D7        7
#define D7_dir    DDRD
#define D7_OUTPUT PORTD

#endif // _8_bitmode



// if using 4 bit mode modify your pins according to your configuration here
// D4 corresponding to D4 Pin in LCD and so on
#ifdef _4_BITMODE

#define D4        4
#define D4_dir    DDRD
#define D4_OUTPUT PORTD

#define D5        5
#define D5_dir    DDRD
#define D5_OUTPUT PORTD

#define D6        6
#define D6_dir    DDRD
#define D6_OUTPUT PORTD

#define D7        7
#define D7_dir    DDRD
#define D7_OUTPUT PORTD

#endif // _4_BITMODE

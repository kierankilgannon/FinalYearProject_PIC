#include <pic.h>
 //Configure device

//-----------------------DATA MEMORY
unsigned char counter; //counter variable to count
//the number of TMR0 overflows
//----------------------PROGRAM MEMORY
/*----------------------------------------------------------
Subroutine: Timer0_ISR
Parameters: none
Returns: nothing
Synopsys: This is the Interrupt Service Routine for
Timer0 overflow interrupts. On TMR0 overflow
the counter variable is incremented by 1
----------------------------------------------------------*/
void interrupt Timer0_ISR(void)
{
    if (T0IE && T0IF) //are TMR0 interrupts enabled and
    //is the TMR0 interrupt flag set?
    {
        T0IF=0; //TMR0 interrupt flag must be
    //cleared in software
    //to allow subsequent interrupts
        ++counter; //increment the counter variable
    //by 1
    }
}

/*----------------------------------------------------------
Subroutine: INIT
Parameters: none
Returns: nothing
Synopsys: Initializes all registers
associated with the application
----------------------------------------------------------*/
Init(void)
{
    TMR0 = 0; //Clear the TMR0 register
    /*Configure Timer0 as follows:
    - Use the internal instruction clock
     as the source to the module
    - Assign the Prescaler to the Watchdog
     Timer so that TMR0 increments at a 1:1
     ratio with the internal instruction clock*/
    OPTION_REG = 0B00001000;
    T0IE = 1; //enable TMR0 overflow interrupts
    GIE = 1; //enable Global interrupts
}
/*----------------------------------------------------------
Subroutine: main
Parameters: none
Returns: nothing
Synopsys: Main program function
-----------------------------------------------------------*/
main(void)
{
    Init(); //Initialize the relevant registers
    while(1) {}
}
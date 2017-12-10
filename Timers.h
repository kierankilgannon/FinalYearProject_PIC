/*
 * File: Timers.h
 * Author: Kieran kilgannon
 * 
 */
#ifndef TIMERS_H
#define TIMERS_H

//Function declarations
void InitialiseTimers(void);

void Init_TMR0_PeriodTimer(void);



void InitialiseTimers(void){
    Init_TMR0_PeriodTimer();
    
    return;
}
void Init_TMR0_PeriodTimer(void){
    TMR0IE=1;
    TMR0IF=0;
    TMR0CS=0;
    PSA=1;
    PS2=0;
    PS1=0;
    PS0=0;
    TMR0=0;
    
return;
}

#endif  /*TIMERS_H */
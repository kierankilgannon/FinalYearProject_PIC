/**
  Generated Main Source File
  Company:
    Microchip Technology Inc.
  File Name:
    main.c
  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs 
  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs  - 1.45
        Device            :  PIC16F1823
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include <pic16f1824.h>

#include "mcc_generated_files/mcc.h"
#include "stdio.h"
#include "Usart.h"
#include "Timers.h"
#include "stdlib.h"
//#include "interrupt_manager.h"

unsigned volatile int tick_count;
unsigned volatile int yourtime1=0;
unsigned volatile int yourtime2=0;
int buttonpress=0;
int flag1=0;
int flag2=0;
unsigned int interval = 0;
int x=0;

void interrupt InterruptServiceRoutine(void);
//void interrupt TMR0_MyISR(void);
        
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    InitUSART();
    InitialiseTimers();

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();
    INTCONbits.GIE = 1;

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();
    INTCONbits.PEIE = 1;

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    printf("READY\r\n");
    //INTCONbits.INTE =0;
    while(1)
    {
//        if(buttonpress)
//        {
//            printf("%i", buttonpress);
//            buttonpress = 0;
//        }
        if(flag1==1)
        { 
            while(flag2==0){} //wait for second interrupt !flag2
            //printf("time  1: %i ",yourtime1);
            //printf("time  2: %i ",yourtime2);
            __delay_ms(100);
            interval = yourtime2 - yourtime1;
            printf("\r\n TRIPTIME: %i",(yourtime2-yourtime1));
            printf("Reg is: %i .... ", x);
            __delay_ms(1000);
            flag1 = 0;
            flag2 = 0;
            //tick_count =0;
            //__delay_ms(5000);
//            INTCONbits.IOCIE = 1;
//            INTCONbits.INTE = 1;
//             
        }   
    }  
}


void interrupt InterruptServiceRoutine(void)
{
    if(TMR0IF)
    {
        tick_count++;
        //TMR0=117;
        TMR0IF=0;
    }
//    if(INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1)
//    {
//        yourtime1 = tick_count;
//        printf("interrupt");
//        //tick_count = 0;
//        //flag1=1;
//        PIN_MANAGER_IOC();
//        //IOCAFbits.IOCAF4 = 0;
//        INTCONbits.IOCIF = 0;
//        //flag1=0;   
//        //INTCONbits.IOCIE = 0; //disable interrupt
//        //printf("pressed");
//        buttonpress++;
//    }
//    if(IOCAFbits.IOCAF4 == 1 )
//    {
//        buttonpress++;
//        IOCAFbits.IOCAF4 = 0;
//    }  
    
    
    if(IOCAFbits.IOCAF4 == 1 )
    {
        tick_count=0;
        //x = TMR0;
        TMR0 = 0;
        flag1 = 1;
        //printf(" %i hello" ,x);
        IOCAFbits.IOCAF4 = 0;
        INTCONbits.IOCIF = 0;
        //printf("1");
//        INTCONbits.IOCIE = 0;
    }
    
    if(INTCONbits.INTE == 1 && INTCONbits.INTF == 1)
    {
        yourtime2 = tick_count;
        x = TMR0;
        //INT_ISR();
        INTCONbits.INTF = 0;
        //INTCONbits.INTE = 0;
        //buttonpress++;
        flag2 = 1;
        //printf("2");
    }
}

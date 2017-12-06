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

#include "mcc_generated_files/mcc.h"
#include "stdio.h"
#include "Usart.h"
#include "Timers.h"
//#include "interrupt_manager.h"


/*
                         Main application
 */





unsigned int tick_count;
unsigned int yourtime1=0;
unsigned int yourtime2=0;
int buttonpress=0;

//void interrupt TMR0_ISR(){
//    TMR0IF=0;
//    tick_count++;
//}

        
    // add your TMR0 interrupt custom code
    // or set custom function using TMR0_SetInterruptHandler()



void main(void)
{
    
    // initialize the device
    SYSTEM_Initialize();
    InitUSART();
    InitialiseTimers();
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
   
    
    
    
    
    
    
   
        
        //break;
//        for(p=0; p<100000; p++);
//        p++;
        
        
   // printf("\tTicking is: %d\r\n",tick_count);
    
   
//    if(TMR0_InterruptHandler)
//    {
//        tick_count = tick_count++;
//        printf("\t it Tickied is: %d\r\n",tick_count);
//    }


//    if (TMR0IE && TMR0IF) //are TMR0 interrupts enabled and
//            //is the TMR0 interrupt flag set?
//    {
//        TMR0IF=0; //TMR0 interrupt flag must be
//            //cleared in software
//            //to allow subsequent interrupts
//        ++tick_count; //increment the counter variable
//            //by 1
//    }

    printf("Trip time measurement project\r\nWelcome to my Project Demonstration :)");
    
    while(1){
        //TxChar(65);
        if(TMR0IF){
            TMR0IF=0;
            tick_count++;
            if(tick_count>1000000)
            {
                tick_count=0;
            }
        }
//        if(tick_count==2000){
//            printf("Hey timer");
//            tick_count=0;
//        }
//        __delay_ms(500);
//        IO_RA2_SetHigh();
//        __delay_ms(500);
//        IO_RA2_SetLow();
//        printf("normal");
    }
    
    
    
    //TXREG=0;
            
            //putch('b');
            //printf("ok please work \n");
//        if(p<5){
//            if(TXIF==1){
//                
//                EUSART_Write(p);
//                
//                
//                TXIE=0;
//                
//            
//            p++;
//        }
//            
//            
//            
//        // Add your application code
//        }
    
}


//#include "interrupt_manager.h"
//#include "mcc.h"

void interrupt INTERRUPT_InterruptManager (void)
{
    // interrupt handler
    if(INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1)
    {
        PIN_MANAGER_IOC();
        IO_RA2_Toggle();
        INTCONbits.IOCIF=0;
        printf("buttonPress");
        if(buttonpress==0){
            yourtime1=tick_count;
            buttonpress++;
        }
        else{
            yourtime2=tick_count;
            buttonpress=0;
            printf("%d ms",yourtime2-yourtime1);
        }
    }
    else
    {
        //Unhandled Interrupt
    }
}
/**
 End of File
*/
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
int flag1=0;
int flag2=0;

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
        //printf("%d",tick_count);
//        if(tick_count%1000==0)
//        {
//            printf("1 second");
//        }
//        __delay_ms(6000);
//         IO_RC1_SetHigh();
        
//        printf("\r \n %d",buttonpress);
        //__delay_ms(1000);
        //IO_RC1_SetLow();
//        printf("\r \n %d",buttonpress);
        
        
        if(flag1){
            
            //while(flag2<1){
            //no nothing until trip
                //flag1=0;
                if(tick_count%2000==0){
                    printf("null trip time");
                    flag2=flag2+2;
                }
            //}
            if(flag2){
            yourtime2=tick_count;
            printf("Trip time = %d \n\r",yourtime2-yourtime1);
            
            //__delay_ms(5000);
            IO_RC1_SetLow();
            tick_count=0;
            flag1=0;
            flag2=0;
            INTCONbits.IOCIF=0;
            INTCONbits.INTF=0;
            INTCONbits.INTE=1;
            INTCONbits.IOCIE=1;
            yourtime2=0;
            yourtime1=0;
            
        }
        }
        
        
        
       
//        if(flag1&&flag2){
//            printf("Trip time = %d",yourtime2-yourtime1);
//            __delay_ms(1000);
//            flag1=0;
//            flag2=0;
//            INTCONbits.INTE = 1;
//            INTCONbits.IOCIE=1;
//        }
        
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
    if(TMR0IF){
        TMR0IF=0;
        tick_count++;
        if(tick_count>10000000)
        {
            tick_count=0;
        }
    
    if(INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1)
    {
        yourtime1=tick_count;
        //flag1=1;
        ++buttonpress;
        PIN_MANAGER_IOC();
        
        
        //printf("\r\n relay closed");
        INTCONbits.IOCIF =0;
        //INTCONbits.IOCIE=0;
        
        

    }
    if(flag1==1 &&INTCONbits.INTE ==1 && INTCONbits.INTF == 1)
    {
       //flag2++;
       INT_ISR();
       //__delay_ms(100);
       printf("unit trip");
       INTCONbits.INTF=0;
       //INTCONbits.INTE = 0;
       //flag2=1;
       
    }
      
       
    
    
    }
    
    
    
    // interrupt handler
 
    
  
}
/**
 End of File
*/

//#include "interrupt_manager.h"
//#include "mcc.h"
//
//void interrupt INTERRUPT_InterruptManager (void)
//{
//    // interrupt handler
//    if(INTCONbits.INTE == 1 && INTCONbits.INTF == 1)
//    {
//        INT_ISR();
//    }
//    else if(INTCONbits.IOCIE == 1 && INTCONbits.IOCIF == 1)
//    {
//        PIN_MANAGER_IOC();
//    }
//    else
//    {
//        //Unhandled Interrupt
//    }
//}
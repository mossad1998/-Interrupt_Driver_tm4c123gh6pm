#include "tm4c123gh6pm.h"
#include "GPIO_Driver.h"
#include "Interrupt_Driver.h"

//Example of using GPIO_Driver and Interrupt_Driver

/* This driver uses the GPIO_Driver and Interrupt_Driver libraries which provide definitions for
   different functions that help to intialize Tiva c  peripherals.
   To use this driver you will also need to use tm4c123gh6pm to map 
   registers correctly.
   this example toggle a led from port f every a switch from port f is pressed.

   Used pins
   ===========
   Pin F0 as digital input
   Pin F1 as digital output

   History
   =======
   2021/August/07  - First release (Mosad)
   mo.eldibani@gmail.com
*/

int main()
  {
     CLK_Enable('F');                                                           //Enable Port F
     GPIO_PORT_UNLOCK('F');                                                     //Unlock Port F
     
     PIN_ANALOG_DIGITAL('F',0,"Digital");                                       //Pin F0 as Digital
     PIN_ANALOG_DIGITAL('F',1,"Digital");                                       //Pin F1 as Digital

     PIN_FUNCTION_SELECT('F',0,"General I/O");                                  //Pin F0 as General Input
     PIN_FUNCTION_SELECT('F',1,"General I/O");                                  //Pin F1 as General Outout

     PIN_INPUT_OUTPUT('F',0,"Input");                                           //Pin F0 as Input Switch
     PIN_INPUT_OUTPUT('F',1,"Output");                                          //Pin F1 as Output Led
     
     PIN_PULLUP_RESISTOR('F',0,"Pullup");                                       //Pin F0 Pullup Switch

     PIN_Edge_Level_Trigger('F',0,"Edge_Sensitive");                            //Edge Sensitive Switch

     PIN_Both_Edge_Trigger('F',0,"False");                                      //Single Edge Sensitive
     
     PIN_Rising_Falling_Trigger('F',0,"Falling");                               //Falling Edge
     
     PIN_Clear_Interrupt('F',0);                                                //Clear Interrupt Pin F0
     
     PIN_Unmask('F',0);                                                         //Unmask Pin F0
     
     Interrupt_Priority(&NVIC_PRI17_R,21,3);                                    //Interrupt Priority
     Interrupt_Enable(&NVIC_EN0_R,30);                                          //Interrupt Enable
     
    __asm("CPSIE  I");
          
    while (1) 
      __asm("      wfi\n");                                                     //Sleep mode which saving power if there is no interrupt
  }

void GPIOF_Handler(void)                                                        //GPIO Handler Function that is triggered everytime a switch fro port f is pressed
  {   
    bool static flag = 1;
    if(flag==1)
    {
          PIN_WRITE_DIGITAL('F',1,"HIGH");                                      //To Turn on The Led
          flag=0;
    }
    else
    {
          PIN_WRITE_DIGITAL('F',1,"LOW");                                       //To Turn off The Led
          flag=1;
    }
     PIN_Clear_Interrupt('F',0);                                                //To Clear Interrupt Flag
  }

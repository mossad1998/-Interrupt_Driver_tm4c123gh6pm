#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "tm4c123gh6pm.h"
#include <string.h>



#ifndef __Interrupt_Driver_H__
#define __Interrupt_Driver_H__


extern void PIN_Edge_Level_Trigger(char port_name,int pin,char type[15]);             //To specify Edge or level Sensitive
extern void PIN_Both_Edge_Trigger(char port_name,int pin,char type[10]);              //To specify Both Edge Trigger or not
extern void PIN_Rising_Falling_Trigger(char port_name,int pin,char type[10]);         //To specify Rising or Falling
extern void PIN_Clear_Interrupt(char port_name,int pin);                              //To Clear The Interrput Flag
extern void PIN_Unmask(char port_name,int pin);                                       //To Unmask Specific Pin
extern void Interrupt_Priority(volatile uint32_t * priority_R,int bits,int priority); //To Set Interrupt priority
extern void Interrupt_Enable(volatile uint32_t * Interrupt_Enable_R,int bits);        //To Enable The Interrupt

#endif

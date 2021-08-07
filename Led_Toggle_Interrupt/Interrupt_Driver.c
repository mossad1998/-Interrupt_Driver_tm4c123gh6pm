#include "GPIO_Driver.h"


volatile uint32_t* PORT_IS_R[]={&GPIO_PORTA_IS_R,&GPIO_PORTB_IS_R,&GPIO_PORTC_IS_R,          //Array of IS Registers for each port
                              &GPIO_PORTD_IS_R,&GPIO_PORTE_IS_R,&GPIO_PORTF_IS_R};

volatile uint32_t* PORT_IBE_R[]={&GPIO_PORTA_IBE_R,&GPIO_PORTB_IBE_R,&GPIO_PORTC_IBE_R,      //Array of IBE Registers for each port
                              &GPIO_PORTD_IBE_R,&GPIO_PORTE_IBE_R,&GPIO_PORTF_IBE_R};

volatile uint32_t* PORT_IEV_R[]={&GPIO_PORTA_IEV_R,&GPIO_PORTB_IEV_R,&GPIO_PORTC_IEV_R,      //Array of IEV Registers for each port
                              &GPIO_PORTD_IEV_R,&GPIO_PORTE_IEV_R,&GPIO_PORTF_IEV_R};


volatile uint32_t* PORT_ICR_R[]={&GPIO_PORTA_ICR_R,&GPIO_PORTB_ICR_R,&GPIO_PORTC_ICR_R,      //Array of ICR Registers for each port
                              &GPIO_PORTD_ICR_R,&GPIO_PORTE_ICR_R,&GPIO_PORTF_ICR_R};

volatile uint32_t* PORT_IM_R[]={&GPIO_PORTA_IM_R,&GPIO_PORTB_IM_R,&GPIO_PORTC_IM_R,          //Array of IM Registers for each port
                              &GPIO_PORTD_IM_R,&GPIO_PORTE_IM_R,&GPIO_PORTF_IM_R};


void PIN_Edge_Level_Trigger(char port_name,int pin,char type[15])                            //To specify Edge or level Sensitive
  {
         if(strcmp(type , "Edge_Sensitive")==0)
      {
        *PORT_IS_R[port_name-65] &= ~(1UL << pin);                                           //To Enable Edge Sensitive
      }
         else if (strcmp(type , "Level_Sensitive")==0)
      {
        *PORT_IS_R[port_name-65] |= 1UL << pin;                                              //To Enable Level Sensitive
      }
  }

void PIN_Both_Edge_Trigger(char port_name,int pin,char type[10])                             //To specify Both Edge Trigger or not
  {
      if(strcmp(type , "False")==0)
      {
        *PORT_IBE_R[port_name-65] &= ~(1UL << pin);                                          //To Disable Both Edge Trigger
      }
         else if (strcmp(type , "True")==0)
      {
        *PORT_IBE_R[port_name-65] |= 1UL << pin;                                             //To Enable Both Edge Trigger
      }
  }

void PIN_Rising_Falling_Trigger(char port_name,int pin,char type[10])                        //To specify Rising or Falling
  {
      if(strcmp(type , "Falling")==0)
      {
        *PORT_IEV_R[port_name-65] &= ~(1UL << pin);                                          //To choose Falling
      }
         else if (strcmp(type , "Rising")==0)
      {
        *PORT_IEV_R[port_name-65] |= 1UL << pin;                                             //To choose Rising
      }
  }

void PIN_Clear_Interrupt(char port_name,int pin)                                              //To Clear The Interrput Flag
  {
      *PORT_ICR_R[port_name-65] |= 1UL << pin;
  }

void PIN_Unmask(char port_name,int pin)                                                       //To Unmask Specific Pin
  {
    *PORT_IM_R[port_name-65] |= 1UL << pin;
  }

void Interrupt_Priority(volatile uint32_t * priority_R,int bits,int priority)                 //To Set Interrupt priority
  {
    *priority_R = priority << bits ;
  }
void Interrupt_Enable(volatile uint32_t * Interrupt_Enable_R,int bits)                        //To Enable The Interrupt
  {
    *Interrupt_Enable_R |= 1UL << bits;
  }

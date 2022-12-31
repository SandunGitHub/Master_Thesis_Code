/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF19175
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set EN_01 aliases
#define EN_01_TRIS                 TRISBbits.TRISB0
#define EN_01_LAT                  LATBbits.LATB0
#define EN_01_PORT                 PORTBbits.RB0
#define EN_01_WPU                  WPUBbits.WPUB0
#define EN_01_OD                   ODCONBbits.ODCB0
#define EN_01_ANS                  ANSELBbits.ANSB0
#define EN_01_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define EN_01_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define EN_01_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define EN_01_GetValue()           PORTBbits.RB0
#define EN_01_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define EN_01_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define EN_01_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define EN_01_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define EN_01_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define EN_01_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define EN_01_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define EN_01_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set EN_02 aliases
#define EN_02_TRIS                 TRISBbits.TRISB2
#define EN_02_LAT                  LATBbits.LATB2
#define EN_02_PORT                 PORTBbits.RB2
#define EN_02_WPU                  WPUBbits.WPUB2
#define EN_02_OD                   ODCONBbits.ODCB2
#define EN_02_ANS                  ANSELBbits.ANSB2
#define EN_02_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define EN_02_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define EN_02_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define EN_02_GetValue()           PORTBbits.RB2
#define EN_02_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define EN_02_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define EN_02_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define EN_02_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define EN_02_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define EN_02_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define EN_02_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define EN_02_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set CTS aliases
#define CTS_TRIS                 TRISDbits.TRISD2
#define CTS_LAT                  LATDbits.LATD2
#define CTS_PORT                 PORTDbits.RD2
#define CTS_WPU                  WPUDbits.WPUD2
#define CTS_OD                   ODCONDbits.ODCD2
#define CTS_ANS                  ANSELDbits.ANSD2
#define CTS_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define CTS_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define CTS_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define CTS_GetValue()           PORTDbits.RD2
#define CTS_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define CTS_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define CTS_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define CTS_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define CTS_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define CTS_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define CTS_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define CTS_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set RTS aliases
#define RTS_TRIS                 TRISDbits.TRISD3
#define RTS_LAT                  LATDbits.LATD3
#define RTS_PORT                 PORTDbits.RD3
#define RTS_WPU                  WPUDbits.WPUD3
#define RTS_OD                   ODCONDbits.ODCD3
#define RTS_ANS                  ANSELDbits.ANSD3
#define RTS_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define RTS_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define RTS_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RTS_GetValue()           PORTDbits.RD3
#define RTS_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define RTS_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define RTS_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define RTS_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define RTS_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define RTS_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define RTS_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define RTS_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set nFault aliases
#define nFault_TRIS                 TRISDbits.TRISD6
#define nFault_LAT                  LATDbits.LATD6
#define nFault_PORT                 PORTDbits.RD6
#define nFault_WPU                  WPUDbits.WPUD6
#define nFault_OD                   ODCONDbits.ODCD6
#define nFault_ANS                  ANSELDbits.ANSD6
#define nFault_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define nFault_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define nFault_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define nFault_GetValue()           PORTDbits.RD6
#define nFault_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define nFault_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define nFault_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define nFault_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define nFault_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define nFault_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define nFault_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define nFault_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set n_Sleep aliases
#define n_Sleep_TRIS                 TRISDbits.TRISD7
#define n_Sleep_LAT                  LATDbits.LATD7
#define n_Sleep_PORT                 PORTDbits.RD7
#define n_Sleep_WPU                  WPUDbits.WPUD7
#define n_Sleep_OD                   ODCONDbits.ODCD7
#define n_Sleep_ANS                  ANSELDbits.ANSD7
#define n_Sleep_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define n_Sleep_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define n_Sleep_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define n_Sleep_GetValue()           PORTDbits.RD7
#define n_Sleep_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define n_Sleep_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define n_Sleep_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define n_Sleep_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define n_Sleep_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define n_Sleep_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define n_Sleep_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define n_Sleep_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

// get/set LED_EN aliases
#define LED_EN_TRIS                 TRISEbits.TRISE2
#define LED_EN_LAT                  LATEbits.LATE2
#define LED_EN_PORT                 PORTEbits.RE2
#define LED_EN_WPU                  WPUEbits.WPUE2
#define LED_EN_ANS                  ANSELEbits.ANSE2
#define LED_EN_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define LED_EN_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define LED_EN_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define LED_EN_GetValue()           PORTEbits.RE2
#define LED_EN_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define LED_EN_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define LED_EN_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define LED_EN_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define LED_EN_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define LED_EN_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/
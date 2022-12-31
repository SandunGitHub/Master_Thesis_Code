

#include "mcc_generated_files/mcc.h"
#include <string.h> /* memset */
#include "xc.h"

/*
                         Main application
 */

// necessary funstions for the motor IC
void MOTOR_IC_PWR_ON(void);
void MOTOR_IC_PWR_OFF(void);
void MOTOR_EN_01(void);
void MOTOR_DIS_01(void);
void Gen_PWM(uint8_t dc, uint8_t p);

// For the Data communication protocol; PVDF Reader
void stream_Data(void);
unsigned char ReadUART(void);

void stream_Data2(void);
unsigned char ReadUART2(void);

 


extern volatile uint8_t eusart1RxBuffer[128];
extern volatile uint8_t validity_Read[128];
extern volatile uint8_t stopBit;

extern volatile uint8_t eusart1TxBuffer[2];

extern volatile uint8_t validity_Read_02[128];
extern volatile uint8_t eusart2RxBuffer[128];
volatile uint8_t read = 0;
volatile uint8_t read_02 =0;
volatile uint8_t paramter[7];
volatile uint8_t cmd;
uint8_t  clear[7] = {0,0,0,0,0,0,0};



volatile uint8_t FingerCount = 0;


//Azzurra hand functions
//unsigned char GetFingerStatus(uint8_t Finger);
void My_TMR1_ISR(void);
void My_TMR4_ISR(void);
bool Flag = false;
unsigned long index;





//Data 
struct{
    
    uint8_t FiC;
    uint8_t FaC;
    uint8_t cmd_SFP;
    uint8_t cmd_GFP;
    uint8_t cmd_SHP;
    uint8_t cmd_GFS;
    uint8_t Duration;
    uint8_t FingerPosition;
    unsigned  char Finger;
 
}Data;



struct{

    
    uint8_t start;
    uint8_t stop;

}time_elapse;



volatile  uint8_t status_Byte;
volatile  unsigned long countDuration ;
volatile  unsigned long count ;
volatile  unsigned long Time_Elapsed;
bool messageSent;

//Start a counter in the transmitting interrupt   10ms
//As soon as the set position command is transfered to the Hand try to generate the Signals
// The take the time elapse from the counter : It should be onetime, please see below
// At the loop if the status is 0x50 then stop the generate signal: Use the time elapse and counter to stop the signals
//One counter is enough for the work!!!!
// stop the counter and clear necassary variables 
//Let's try this method and debug



void main(void)
{
    

     // initialize the device
    SYSTEM_Initialize();
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    //setting the timer1 interrupt 
    TMR1_SetInterruptHandler(My_TMR1_ISR);
    TMR4_SetInterruptHandler(My_TMR4_ISR);
    
    
    // initial parameters for the frequency
    long PWM_Freq = 100;
    uint8_t Timescaler = 128;  
    uint8_t period = (uint8_t)(_XTAL_FREQ/(PWM_Freq*4*Timescaler)); // Timer 02 // Duty Cycle 100 
    uint8_t dutycycle    = 100;
    
    Data.FiC = 0x42;
    Data.FaC = 0x46;
    Data.cmd_SFP = 0x44;
    Data.cmd_GFP = 0x45;
    Data.cmd_SHP = 0x48;
    Data.cmd_GFS = 0x4B;
    
    
   

    
    

    

   
   //indicators
   MOTOR_IC_PWR_ON();
   
   //stop the timers
   TMR1_StopTimer();
   TMR4_StopTimer(); 
 
  
   //getting the initial values of the finger
    //one time command can be sent via the EUSART_Read and EUSART write terms
    /**/
    /*

     */
   while(1){ 
      
        // first calibration
      
      if(validity_Read_02[read_02]){
             paramter[0] = ReadUART2();
             
           if( paramter[0] ==   Data.FiC){
             if(EUSART1_is_tx_ready()){ 
             EUSART1_Write(Data.FiC);                      
             if(EUSART1_is_tx_done()){
             memmove(paramter,clear,sizeof(clear)); //cleaning the Buffer
             }
             TMR1_StopTimer();           // stopping the unnecessary start in the timer
             MOTOR_DIS_01();             // disabling the motor
               }
           }
        // fast calibration     
          if( paramter[0] ==   Data.FaC){
            if(EUSART1_is_tx_ready()){ 
             EUSART1_Write(Data.FaC);
              if(EUSART1_is_tx_done()){
             memmove(paramter,clear,sizeof(clear)); //cleaning the Buffer
              }
             TMR1_StopTimer();                      // Timer stop
             MOTOR_DIS_01();                        // disabling the motor
            }
        }
             
           //set finger position  
            if( paramter[0] ==   Data.cmd_SFP){
             paramter[1] = ReadUART2();              // very important byte
             paramter[2] = ReadUART2();              // very important byte
           
             /// Not super faster method
               for(int i =0;i<3;i++){
                if(EUSART1_is_tx_ready()){ 
                  EUSART1_Write(paramter[i]);
                 }
                }
                while(!EUSART1_is_tx_done());               // transmission check
                          
                TMR1_StartTimer();                          // starting the by timer sending commands 
              //  TMR4_WriteTimer(0);                       // writing 0 to the timer 4
               
                
               // Initialize the counters 
                 countDuration = 0;
                 count = 0;
                 index = 0;
                 Time_Elapsed = 0;
                 messageSent = true;
                 
              
                memmove(paramter,clear,sizeof(clear)); //cleaning the Buffer 
                
                
                 MOTOR_EN_01();                         // start generating the signal after the posture set
                 Gen_PWM(dutycycle, period);  
             
                
                
                  
                }
                            
             //set hand posture
             if(paramter[0] == Data.cmd_SHP){
                 paramter[1] = ReadUART2();
                 paramter[2] = ReadUART2();
                 paramter[3] = ReadUART2();
                 paramter[4] = ReadUART2();
                 paramter[5] = ReadUART2();              
                 paramter[6] = ReadUART2();
                 if(paramter[6] == 0x48){
                   for(int i = 0;i<7;i++){
                     if(EUSART1_is_tx_ready()){
                      EUSART1_Write(paramter[i]);
                     }
                   }
                   }
                 while(!EUSART1_is_tx_done());         
                 TMR1_StartTimer();                            
                 memmove(paramter,clear,sizeof(clear)); //cleaning the Buffer  
                 
                 
     
             
                 
                 
                }
             
             
                 
             }
        
         // Implementation of a circular buffer to read the positions from Azzurra hand
                            if(validity_Read[read]){

                                    status_Byte = (ReadUART());    
                                    
                                
                                 if((status_Byte == 0x50) && messageSent){                 // 0b0101000  : position control achieved ? // duration 2 sec
                                    index++;   
                                     if(index == 1){                    // SEMAPHORE TO COUNT ONCE
                                     Time_Elapsed = countDuration;      // TIME FROM DSTARTING OF THE AZURRA HAND                                                                   
                                     messageSent = false; // clear byte 
                                                                   
                                    }
                                    while(countDuration <= 2*Time_Elapsed );     // change here to change the time duration
                                        TMR1_StopTimer();                        // stopping  the timer
                                        MOTOR_DIS_01();                          // disabling the motor
                                        index = 0;
                                    
                                 }
                                                                   
                                                           
                             }             
        
                                                        
                 
            
        
                        }
                      
   } 

   


       
            
//interrupting in each and every 50ms to set the commands
// count for setting the duration : 1000/50
void My_TMR1_ISR(void){
  
    LED_EN_Toggle();
    countDuration++;
    FingerCount = FingerCount + 1;
    uint8_t TX_seq[2] = {Data.cmd_GFS,FingerCount};
    if(FingerCount >= 4){
    FingerCount = 0;
    }
    
          
       for(int i = 0;i<2;i++){
           if(EUSART1_is_tx_ready()){
            EUSART1_Write(TX_seq[i]); 
           }
       }
       while(!EUSART1_is_tx_done());    
       TMR1_Reload();       //reloading the timer 1 to be executed in every 20ms
             
 } 

//1 ms
void My_TMR4_ISR(void){

    
    Time_Elapsed--;
        
    
    

}
     




         


void MOTOR_IC_PWR_ON(void){

    if(!nFault_GetValue()){  
   n_Sleep_SetHigh();

    }
}

void MOTOR_IC_PWR_OFF(void){

n_Sleep_SetLow();

}

void MOTOR_EN_01(void){


    EN_01_SetHigh();

}



void MOTOR_DIS_01(void){
  
    EN_01_SetLow();


}


void Gen_PWM(uint8_t dc, uint8_t p){
    
     PWM1_LoadDutyValue(dc); // CCP1
     TMR2_LoadPeriodRegister(p);


}


                
                void stream_Data(void){                  
                  read++;
                   if(read >= sizeof(eusart1RxBuffer)){
                       read = 0; 
                               }                   
                }
                
                void stream_Data2(void){                  
                  read_02++;
                   if(read_02 >= sizeof(eusart2RxBuffer)){
                       read_02 = 0; 
                               }                   
                }

                
                unsigned char ReadUART(void){
                    unsigned char value;
                    while(validity_Read[read]==0);
                        value = eusart1RxBuffer[read]; // getting teh balue from the universal buffer
                        validity_Read[read]= 0;    // the validity
                        stream_Data();
                        return value;
                                    
                }
                
                
                
                
              
                  unsigned char ReadUART2(void){
                      
                    unsigned char value;
                    while(validity_Read_02[read_02]==0);
                        value = eusart2RxBuffer[read_02]; // getting teh balue from the universal buffer
                        validity_Read_02[read_02]= 0;    // the validity
                        stream_Data2();
                        return value;
                                    
                }
               
                
                



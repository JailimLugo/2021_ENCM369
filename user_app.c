/*!*********************************************************************************************************************
@file user_app.c                                                                
@brief User's tasks / applications are written here.  This description
should be replaced by something specific to the task.

------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE

CONSTANTS
- NONE

TYPES
- NONE

PUBLIC FUNCTIONS
- NONE

PROTECTED FUNCTIONS
- void UserApp1Initialize(void)
- void UserApp1Run(void)


**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u8 G_u8UserAppFlags;                             /*!< @brief Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemTime1ms;                   /*!< @brief From main.c */
extern volatile u32 G_u32SystemTime1s;                    /*!< @brief From main.c */
extern volatile u32 G_u32SystemFlags;                     /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp_<type>" and be declared as static.
***********************************************************************************************************************/


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*!--------------------------------------------------------------------------------------------------------------------
@fn void UserAppInitialize(void)

@brief
Initializes the application's variables.

Should only be called once in main init section.

Requires:
- NONE

Promises:
- NONE

*/
void UserAppInitialize(void)
{
    
    T0CON0=0x90;
    
    T0CON1=0x54;
      /*Timer 0 enabled,16-bit timer,1:1 postscaler,FOsc/4*,1:256 prescaler,asynchronized */
    


} /* end UserAppInitialize() */

  
/*!----------------------------------------------------------------------------------------------------------------------
@fn void UserAppRun(void)

@brief Application code that runs once per system loop

Requires:
- 

Promises:
- 

*/

/*--------------------------------------------------------------------------------------------------------------------
 void TimeXus(INPUT_PARAMETER_)
 Sets Timer0 to count u16Microseconds_
 Requires:
 - Timer0 configured such that each timer tick is 1 microsecond
 -INPUT_PARAMETER_ is the value in microseconds to time from 1 to 65535
 
 Promises:
- Pre-loads TMR0H:L to clock out desired period
- TMR0IF cleared
- Timer0 enabled
 */


void TimeXus(u16 u16UserInput)
{
    T0CON0 = 0x10;
    
    u16 u16UserCount = 0xFFFF - u16UserInput;
    
    TMR0H = u16UserCount >> 8;
    
    TMR0L = u16UserCount << 8;
    
    PIR3bits.TMR0IF=0;
    
    T0CON0 = 0x90;
     
}


void UserAppRun(void)
{
      u8 u8Pattern[] = {0x20,0x10,0x08,0x04,0x02,0x01,0x02,0x04,0x08,0x10,0x20};
      
      u8 u8PatternLength = 0x0B;
      
       u8 u8Initial;
      
      static u8 u8Counter = 0x00;
      
      if(u8Counter  >= u8PatternLength)
      {
          u8Counter = 0x00;
          
      }
      
      u8Initial = LATA & 0xC0;
      
      LATA =  ( u8Pattern[u8Counter] ) | u8Initial;
      
      u8Counter = u8Counter +1;
      
} /* end UserAppRun */



/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/





/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/

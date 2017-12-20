/*!**********************************************************************************************************************
@file buttons.h        
@brief Header file for buttons.c
***********************************************************************************************************************/

#ifndef __BUTTONS_H
#define __BUTTONS_H

/***********************************************************************************************************************
Type Definitions
***********************************************************************************************************************/

/*! 
@enum ButtonStateType
@brief Self-documenting button state type */
typedef enum {RELEASED, PRESSED} ButtonStateType; 

typedef enum {BUTTON_PORTA = 0, BUTTON_PORTB = 0x80} ButtonPortType;  /* Offset between port registers (in 32 bit words) */
typedef enum {BUTTON_ACTIVE_LOW = 0, BUTTON_ACTIVE_HIGH = 1} ButtonActiveType;

typedef struct 
{
  ButtonActiveType eActiveState;
  ButtonPortType ePort;
}ButtonConfigType;


/***********************************************************************************************************************
Constants / Definitions
***********************************************************************************************************************/
#define BUTTON_INIT_MSG_TIMEOUT         (u32)1000     /* Time in ms for init message to send */
#define BUTTON_DEBOUNCE_TIME            (u32)10       /* Time in ms for button debouncing */


/***********************************************************************************************************************
Function Declarations
***********************************************************************************************************************/

/*------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/
bool IsButtonPressed(u32 u32Button_);
bool WasButtonPressed(u32 u32Button_);
void ButtonAcknowledge(u32 u32Button_);
bool IsButtonHeld(u32 u32Button_, u32 u32ButtonHeldTime_);

/*------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/
void ButtonInitialize(void);                        
void ButtonRunActiveState(void);

u32 GetButtonBitLocation(u8 u8Button_, ButtonPortType ePort_);

/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/***********************************************************************************************************************
State Machine Declarations
***********************************************************************************************************************/
static void ButtonSM_Idle(void);                
static void ButtonSM_ButtonActive(void);        


#endif /* __BUTTONS_H */

/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/

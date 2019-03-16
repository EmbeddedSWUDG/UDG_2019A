#include <stdio.h>
#include <stdlib.h>

#define TEMPLOW 0
#define TEMPHIGHT 20
#define CheckTemp 15

int LedRed,LedGreen,LedBlue;
int TempNormalHight;
int TempNormalLow;
int AirCondSystemStatus;
int HeatingSystemStatus;

typedef enum //TURN
{
    OFF,
    ON
}E_TURN;

typedef enum //BOOL
{
    FALSE,
    TRUE
}E_BOOL;

typedef enum // ACTION
{
    STOP,
    START
}E_ACTIONS;

typedef enum // STATES
{
    DEFAULT,
    NORMAL,
    AIRCONDITION_SYSTEM,
    HEATING_SYSTEM
}E_SM_CALEFACTION;

//extern void AIRCONDITION_SYSTEM (void);
//extern void HEATING_SYSTEM (void);

void aircondition (void)
{
    static E_SM_CALEFACTION CalefactionProcess = DEFAULT;
    static E_BOOL ResetFlag = TRUE;

    if(ResetFlag == TRUE)
    {
        ResetFlag = FALSE;
        LedGreen = OFF;
        LedBlue = OFF;
        LedRed = OFF;
        AirCondSystemStatus = STOP;
        HeatingSystemStatus = STOP;
        CalefactionProcess = NORMAL;
    }
    switch(CalefactionProcess)
    {
        case NORMAL:
            if(CheckTemp < TEMPLOW)
            {
                LedRed = OFF;
                LedGreen = OFF;
                LedBlue = ON;
                HeatingSystemStatus = START;
                CalefactionProcess = HEATING_SYSTEM;
            }
            else if (CheckTemp > TEMPHIGHT)
            {
                LedRed = ON;
                LedGreen = OFF;
                LedBlue = OFF;
                AirCondSystemStatus = START;
                CalefactionProcess = AIRCONDITION_SYSTEM;
            }
            else
            {
                LedRed = OFF;
                LedBlue = OFF;
                LedGreen = ON;
                CalefactionProcess = NORMAL;
            }
            break;

        case AIRCONDITION_SYSTEM:
            if(CheckTemp < TempNormalHight)
            {
                LedGreen = ON;
                LedBlue = OFF;
                LedRed = OFF;
                AirCondSystemStatus=STOP;
                CalefactionProcess=NORMAL;
            }else
            {
                LedRed = ON;
                LedGreen = OFF;
                LedBlue = OFF;
                CalefactionProcess = AIRCONDITION_SYSTEM;
            }
            break;
        case HEATING_SYSTEM:
            if(CheckTemp > TempNormalLow)
            {
                LedGreen = ON;
                LedBlue = OFF;
                LedRed = OFF;
                HeatingSystemStatus = STOP;
                CalefactionProcess =NORMAL;
            }
            else
            {
                LedGreen = OFF;
                LedBlue = ON;
                LedRed = OFF;
                CalefactionProcess = HEATING_SYSTEM;
            }
            break;
        default:
                ResetFlag = TRUE;
    }
}



#include <stdio.h>
#include "aire-acondcionado.h"

int main()
{
    volatile int i = FALSE;

    T_TEMP CheckTemp = TEMPNORMALLOW;

    printf("Maquina de estados para un aire acondicionado");

    while(TRUE)
    {
        /*Inicio del automata*/
        Reset();
        switch(Estado)
        {
            case NORMAL:
                if(CheckTemp < TEMPLOW)
                {
                    LedGreen = OFF;
                    LedBlue = ON;
                    LedRed = OFF;
                    HeadingSystem = START;
                    Estado = HEATINGSYSTEM;
                }
                else if (CheckTemp < TEMPHIGH)
                {
                    LedGreen = ON;
                    LedBlue = OFF;
                    LedRed = OFF;
                    AirCondSystem = START;
                    Estado = AIRCONDITIONERSYSTEM;
                }
                else
                {
                    LedGreen = OFF;
                    LedBlue = OFF;
                    LedRed = ON;
                    Estado = DEFAULT;
                }
                break;
            case AIRCONDITIONERSYSTEM:
                if(CheckTemp < TEMPNORMALLOW)
                {
                    LedGreen = OFF;
                    LedBlue = OFF;
                    LedRed = ON;
                    HeadingSystem = STOP;
                }
                else
                {
                    LedGreen = ON;
                    LedBlue = OFF;
                    LedRed = OFF;
                    Estado = AIRCONDITIONERSYSTEM;
                }
                break;
            case HEATINGSYSTEM:
                if(CheckTemp > TEMPNORMALLOW)
                {
                    LedGreen = OFF;
                    LedBlue = ON;
                    LedRed = OFF;
                    Estado = HEATINGSYSTEM;
                }
                break;
            default:
                Reset();
                break;
        }

        i++;
    }
    return 0;
}

void Reset(void)
{
    LedGreen = OFF;
    LedBlue = OFF;
    LedRed = OFF;
    AirCondSystem = STOP;
    HeadingSystem = STOP;
}

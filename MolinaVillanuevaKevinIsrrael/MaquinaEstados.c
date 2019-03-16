#include <iostream>

using namespace std;

typedef enum
{
NormalE=1,
AirConditionerSystemE,
HeatingSystemE
}ESTADOS;

    int AirCondSystem;
    int HeatingSystem;
    int estado;
    int CheckTemp = 10;
    int TempLow = 0;
    int TempNormalLow = 10;
    int TempHigh = 20;
    int LedGreen;
    int LedBlue;
    int LedRed;

extern void Reset()
{
    AirCondSystem = 0;
    HeatingSystem = 0;
    estado = 0;
    LedGreen = 0;
    LedBlue = 0;
    LedRed = 0;
}

int main()
{

    printf("Sistema Aire Acondicionado!");
    Reset();
    switch(estado)
    {
        case NormalE:
            if(CheckTemp < TempLow)
            {
                LedGreen = 0;
                LedBlue = 1;
                LedRed = 0;
                HeatingSystem = 1;
                estado = 3;
            }
            else if(CheckTemp > TempHigh)
            {
                LedGreen = 1;
                LedBlue = 0;
                LedRed = 0;
                AirCondSystem = 1;
                estado = 2;
            }
            else
            {
                LedGreen = 0;
                LedBlue = 0;
                LedRed = 1;
                estado = 0;
            }
            break;
        case AirConditionerSystemE:
            if(CheckTemp < TempNormalLow)
            {
                LedGreen = 0;
                LedBlue = 0;
                LedRed = 1;
                AirCondSystem = 1;
                estado = 1;
            }
            else
            {
                LedGreen = 1;
                LedBlue = 0;
                LedRed = 0;
                estado = 2;
            }
            break;
        case HeatingSystemE:
            if(CheckTemp > TempNormalLow)
            {
                LedGreen = 0;
                LedBlue = 0;
                LedRed = 1;
                HeatingSystem = 0;
                estado = 1;
            }
            else
            {
                LedGreen = 0;
                LedBlue = 1;
                LedRed = 0;
                estado = 3;
            }
            break;
        default:
                Reset();
            break;
    }
    return 0;
}

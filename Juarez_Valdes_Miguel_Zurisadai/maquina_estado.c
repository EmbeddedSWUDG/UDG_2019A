#include <stdio.h>
#include <stdlib.h>

typedef enum{
    DEFAULT,
    Normal,
    AirConditionerSystem,
    HeatingSystem
}N_ESTADOS;

typedef enum{
    FLS,
    TR
}ST_ESTADO;

typedef enum{
    FALSE,
    TRUE
}E_BOOL;

extern E_BOOL OFF;
extern E_BOOL ON;

extern ST_ESTADO STOP;
extern ST_ESTADO START;

N_ESTADOS estado = DEFAULT;
N_ESTADOS AIRCONDITIONERSYSTEM = AirConditionerSystem;
N_ESTADOS HEATINGSYSTEM = HeatingSystem;

int main(){

    static E_BOOL OFF = FALSE;
    static E_BOOL ON = TRUE;

    static ST_ESTADO STOP = FLS;
    static ST_ESTADO START = TR;


    printf("Maquina de Estados de Aire Acondicionado y Calefaccion");

    reset();

    switch(estado){
    case Normal:
        if(CheckTemp < TempLow){
            Led_Red = OFF;
            Led_Blue = ON;
            Led_Green = OFF;
            HeatingSystem = START;
            estado = HEATINGSYSTEM;
        }
        else if(CheckTemp > TempHigh){
            Led_Red = ON;
            Led_Blue = OFF;
            Led_Green = OFF;
            AirConditionerSystem = START;
            estado = AIRCONDITIONERSYSTEM;
        }
        else{
            Led_Red = OFF;
            Led_Blue = OFF;
            Led_Green = ON;
        }
    case AirConditionerSystem:
        if(CheckTemp < TempNormalHigh){
            Led_Red = OFF;
            Led_Blue = OFF;
            Led_Green = ON;
            AirConditionerSystem = STOP;
        }
        else{
            Led_Red = ON;
            Led_Blue = OFF;
            Led_Green = OFF;
        }
    case HeatingSystem:
        if(CheckTemp > TempNormalLow){
            Led_Red = OFF;
            Led_Blue = OFF;
            Led_Green = ON;
            HeatingSystem = STOP;
        }
        else{
            Led_Red = OFF;
            Led_Blue = ON;
            Led_Green = OFF;
        }
    }

    return 0;
}

void reset(){

    Led_Red = OFF;
    Led_Blue = OFF;
    Led_Green = ON;
    AirConditionerSystem = STOP;
    HeatingSystem = START;

}

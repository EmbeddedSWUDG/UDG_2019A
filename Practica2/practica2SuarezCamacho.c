#include "stdio.h"
#define TRUE 1
#define FALSE 0
#define START 1
#define STOP 0
#define ON 1
#define OFF 0
#define TEMPLOW 10
#define TEMPHIGH 30
#define NORMALHIGH 23
#define NORMALLOW 15


int ledGreen = FALSE;
int ledBlue = FALSE;
int ledRed = FALSE;

typedef enum{
    Default,
    normal,
    aireAcondicionadoEstado,
    calefaccionEstado
}Estado;
int checkTemp()
{
    int temp;
    scanf("%i", &temp);
    return temp;
}
void aireAcondicionado(int accion)
{
    if(accion == START)
    {
        printf("El aire acondicionado esta encendido\n");
    }
    else if(accion == STOP)
    {
        printf("El aire acondicionado se detuvo\n");
    }
}
void calefaccion(int accion)
{
    if(accion == START)
    {
        printf("La calefaccion esta encendida\n");
    }
    else if(accion == STOP)
    {
        printf("La calefaccion se detuvo\n");
    }
}



void maquinaEstados()
{
    static int reset = TRUE;
    static Estado estado = Default;

    if(reset == TRUE)
    {
        reset = FALSE;
        ledGreen = OFF;
        ledBlue = OFF;
        ledRed = OFF;
        aireAcondicionado(STOP);
        calefaccion(STOP);
        estado = normal;
    }

    switch (estado)
    {
        case normal:
            if(checkTemp()< TEMPLOW)
            {
                ledGreen = OFF;
                ledBlue = ON;
                ledRed = OFF;
                calefaccion(START);
                estado = calefaccionEstado;
            }
            else if(checkTemp()> TEMPHIGH)
            {
                ledGreen = OFF;
                ledBlue = OFF;
                ledRed = ON;
                aireAcondicionado(START);
                estado = aireAcondicionadoEstado;
            }
            else
            {
                ledGreen = ON;
                ledBlue = OFF;
                ledRed = OFF;
                estado = normal;
            }
            break;
        case aireAcondicionadoEstado:
            if(checkTemp()< NORMALHIGH)
            {
                ledGreen = ON;
                ledBlue = OFF;
                ledRed = OFF;
                aireAcondicionado(STOP);
                estado = normal;
            }
            else
            {
                ledGreen = OFF;
                ledBlue = OFF;
                ledRed = ON;
                estado = aireAcondicionadoEstado;
            }
            break;
        case calefaccionEstado:
            if(checkTemp()> NORMALLOW)
            {
                ledGreen = ON;
                ledBlue = OFF;
                ledRed = OFF;
                calefaccion(STOP);
                estado = normal;
            }
            else
            {
                ledGreen = OFF;
                ledBlue = ON;
                ledRed = OFF;
                estado = calefaccionEstado;
            }
            break;
        default:
            estado = Default;
            reset = TRUE;
    }
}

void main()
{
    while(1)
    {
        maquinaEstados();
    }
}

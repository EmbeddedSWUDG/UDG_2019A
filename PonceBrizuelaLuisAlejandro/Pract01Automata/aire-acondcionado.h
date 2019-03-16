#ifndef AIRE-ACONDCIONADO_H_INCLUDED
#define AIRE-ACONDCIONADO_H_INCLUDED

/*Defines*/
#define TEMPLOW 0
#define TEMPNORMALLOW 10
#define TEMPHIGH 20

/*Types*/
typedef enum
{
    OFF,
    ON
}E_ONOFF;

typedef enum
{
    TRUE,
    FALSE
}E_BOOL;

typedef enum
{
    DEFAULT,
    NORMAL,
    AIRCONDITIONERSYSTEM,
    HEATINGSYSTEM
}E_ESTADOS;

typedef enum
{
    STOP,
    START
}E_STATUS;

typedef unsigned int T_TEMP;



/*Prototypes*/
extern void Reset(void);

/*Declaration Type Data*/
E_ONOFF LedGreen = OFF;
E_ONOFF LedBlue = OFF;
E_ONOFF LedRed = OFF;
E_STATUS AirCondSystem = STOP;
E_STATUS HeadingSystem = STOP;
E_ESTADOS Estado = DEFAULT;

#endif // AIRE-ACONDCIONADO_H_INCLUDED




#include "stdio.h"
#define TEMPLOW 5
#define NORMALLOW 20
#define NORMALHIGH 30
#define TEMPHIGH 50

typedef enum
{
    FALSE,
    TRUE
}A_BOOL;

int LEDGREEN = FALSE;
int LEDRED = FALSE;
int LEDBLUE = FALSE;
int AIRCONDITIONERSYSTEM = FALSE;
int HEATINGSYSTEM = FALSE;
int ESTADO = FALSE;

typedef enum
{
    NORMAL_ESTADO,
    AIR_CONDITIONER_ESTADO,
    HEATING_SYSTEM_ESTADO
}ESTADOS;

void INIT(void)
{
    AIRCONDITIONERSYSTEM = FALSE;
    HEATINGSYSTEM = FALSE;
    LEDGREEN = FALSE;
    LEDRED = FALSE;
    LEDBLUE = FALSE;
    ESTADO = FALSE;
}

int TEMPERATURA()
{
    int TEMPERATURA;
    scanf("%i", &TEMPERATURA);
    return TEMPERATURA;
}

void main()
{
    INIT();
    while(1)
    {
        switch (ESTADO)
        {
                
            case NORMAL_ESTADO:
                
                if(TEMPERATURA()< TEMPLOW)
                {
                    LEDGREEN = FALSE;
                    LEDBLUE = TRUE;
                    LEDRED = FALSE;
                    HEATINGSYSTEM = TRUE;
                    ESTADO = HEATING_SYSTEM_ESTADO;
                }
                else if(TEMPERATURA()> TEMPHIGH)
                {
                    LEDGREEN = FALSE;
                    LEDBLUE = FALSE;
                    LEDRED = TRUE;
                    AIRCONDITIONERSYSTEM = TRUE;
                    ESTADO = AIR_CONDITIONER_ESTADO;
                }
                
                else
                {
                    LEDGREEN = TRUE;
                    LEDBLUE = FALSE;
                    LEDRED = FALSE;
                    ESTADO = NORMAL_ESTADO;
                }
                break;
                
            case AIR_CONDITIONER_ESTADO:
                
                if(TEMPERATURA()< NORMALHIGH)
                {
                    LEDGREEN = TRUE;
                    LEDBLUE = FALSE;
                    LEDRED = FALSE;
                    AIRCONDITIONERSYSTEM = FALSE;
                    ESTADO = NORMAL_ESTADO;
                }
                else
                {
                    LEDGREEN = FALSE;
                    LEDBLUE = FALSE;
                    LEDRED = TRUE;
                    ESTADO = AIR_CONDITIONER_ESTADO;
                }
                break;
                
            case HEATING_SYSTEM_ESTADO:
                
                if(TEMPERATURA()> NORMALLOW)
                {
                    LEDGREEN = TRUE;
                    LEDBLUE = FALSE;
                    LEDRED = FALSE;
                    HEATINGSYSTEM = FALSE;
                    ESTADO = NORMAL_ESTADO;
                }
                else
                {
                    LEDGREEN = FALSE;
                    LEDBLUE = TRUE;
                    LEDRED = FALSE;
                    ESTADO = HEATING_SYSTEM_ESTADO;
                }
                break;
                
            default:
                INIT();
        }
    }
}

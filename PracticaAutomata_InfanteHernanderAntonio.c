#include <stdio.h>
#define OFF 0
#define ON 1
#define Stop 0
#define Start 1
typedef struct {
    int st;
enum{
    TempLow,
    TempNormalLow,
    TempNormal,
    TempNormalHigh,
    TempHigh
}
}StatusTemp ;

typedef struct {
int Status;
}StatusAir;
StatusAir AirConditionSystem, HeatingConditionSystem;

typedef struct {
    int Status;
}Led;
Led LedGreen, LedRed, LedBlue;

void StatusNormal(StatusTemp CheckTemp);
void StatusHeatingSystem(StatusTemp CheckTemp);
void StatusAirConditionerSystem(StatusTemp CheckTemp);
void StatusReset(StatusTemp CheckTemp);

int main(void)
{
    StatusTemp CheckTemp;
    CheckTemp.st = TempNormal;
    StatusReset(CheckTemp);

    return 0;
}

void StatusNormal(StatusTemp CheckTemp)  /* Estado Normal */
{
    LedGreen.Status=ON;
    LedBlue.Status=OFF;
    LedRed.Status=OFF;
     if(CheckTemp.st<TempNormalLow)     /* Comprobacion de temperatura */
    {
        LedGreen.Status=OFF;
        LedBlue.Status=ON;
        HeatingConditionSystem.Status = Start;
        StatusHeatingSystem(CheckTemp);
    }


     if(CheckTemp.st>TempNormalHigh)   /* Comprobacion de temperatura */
    {
        LedRed.Status=ON;
        LedGreen.Status=OFF;
        AirConditionSystem.Status = Start;
        StatusAirConditionerSystem(CheckTemp);
    }

}
void StatusAirConditionerSystem(StatusTemp CheckTemp)
{
    LedGreen.Status=OFF;
    LedBlue.Status=OFF;
    LedRed.Status=ON;
     if(CheckTemp.st==TempNormal)
    {
        LedGreen.Status=ON;
        LedRed.Status=OFF;
        AirConditionSystem.Status = Stop;
        StatusNormal(CheckTemp);
    }
}
void StatusHeatingSystem(StatusTemp CheckTemp)
{
    LedGreen.Status=OFF;
    LedBlue.Status=ON;
    LedRed.Status=OFF;
    if(CheckTemp.st==TempNormal)
    {
        LedGreen.Status=ON;
        LedBlue.Status=OFF;
        HeatingConditionSystem.Status = Stop;
        StatusNormal(CheckTemp);
    }
}

void StatusReset(StatusTemp CheckTemp)
{
    LedGreen.Status=OFF;
    LedBlue.Status=OFF;
    LedRed.Status=OFF;
    AirConditionSystem.Status = Stop;
    HeatingConditionSystem.Status = Stop;
    StatusNormal(CheckTemp);
}

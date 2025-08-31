// -- IMPORTS

#include "base.h"
#include "level.h"

// -- VARIABLES

INT_8
    CannonXAngle;
INT_14_2
    TankX,
    TankZ;

// -- FUNCTIONS

void InitializeTank(
    )
{
    TankX = 0;
    TankZ = 0;
    CannonXAngle = DefaultCannonXAngle;
}

// ~~

void UpdateTank(
    )
{
    TankZ += TankSpeed;
}

// -- IMPORTS

#include "input.h"

// -- VARIABLES

UINT_8
    OldJoystick1State = 0,
    OldJoystick2State = 0;

// -- FUNCTIONS

void ClearInput(
    )
{
    OldJoystick1State = Joystick1State;
    OldJoystick2State = Joystick2State;
    Joystick1State = 0;
    Joystick2State = 0;
}

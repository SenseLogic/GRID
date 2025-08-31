#ifndef __INPUT_H__
    #define __INPUT_H__

    // -- CONSTANTS

    #define Joystick1State    ( *( volatile UINT_8 * )0x02FE )
    #define Joystick2State    ( *( volatile UINT_8 * )0x02FF )
    #define JoystickStateUpMask    0x01
    #define JoystickStateDownMask    0x02
    #define JoystickStateLeftMask    0x04
    #define JoystickStateRightMask    0x08
    #define JoystickStateUpLeftMask    0x05
    #define JoystickStateUpRightMask    0x09
    #define JoystickStateDownLeftMask    0x06
    #define JoystickStateDownRightMask    0x0A
    #define JoystickStateFireMask    0x10
#endif

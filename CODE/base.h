#ifndef __BASE_H__
    #define __BASE_H__

    // -- CONSTANTS

    #define false    0
    #define true    1
    #define AngleCount    256
    #define RamConfiguration    ( *( volatile char * )0x01 )

    // -- TYPES

    #define BOOL    unsigned char
    #define CHAR    char
    #define INT_2_6    signed char
    #define INT_4_4    signed char
    #define INT_6_2    signed char
    #define INT_8    signed char
    #define INT_14_2    signed int
    #define INT_16    signed int
    #define UINT_2_6    unsigned char
    #define UINT_4_4    unsigned char
    #define UINT_6_2    unsigned char
    #define UINT_8    unsigned char
    #define UINT_14_2    unsigned int
    #define UINT_16    unsigned int

    // ~~

    #define COLOR    unsigned char
    #define COLOR_Black    0x00
    #define COLOR_White    0x01
    #define COLOR_Red    0x02
    #define COLOR_Cyan    0x03
    #define COLOR_Purple    0x04
    #define COLOR_Green    0x05
    #define COLOR_Blue    0x06
    #define COLOR_Yellow    0x07
    #define COLOR_Orange    0x08
    #define COLOR_Brown    0x09
    #define COLOR_LightRed    0x0A
    #define COLOR_DarkGray    0x0B
    #define COLOR_Gray    0x0C
    #define COLOR_LightGreen    0x0D
    #define COLOR_LightBlue    0x0E
    #define COLOR_LightGray    0x0F

    // -- FUNCTIONS

    #define DisableInterrupts() \
        \
        __asm { sei }

    // ~~

    #define EnableInterrupts() \
        \
        __asm { cli }

    // ~~

    #define ClampInteger( _integer_, _minimum_, _maximum_ ) \
        \
        if ( ( _integer_ ) < _minimum_ ) \
        { \
            _integer_ = _minimum_; \
        } \
        else if (  ( _integer_ ) > _maximum_ ) \
        { \
            _integer_ = _maximum_; \
        }

    // ~~

    #define FixInterval( _minimum_, _maximum_, _old_minimum_ ) \
        \
        if ( ( _minimum_ ) > ( _maximum_ ) ) \
        { \
            _old_minimum_ = _minimum_; \
            _minimum_ = _maximum_; \
            _maximum_ = _old_minimum_; \
        }

    // ~~

    #define GetAngleCosinus( _angle_ ) \
        \
        AngleSinusArray[ ( UINT_8 )( ( _angle_ ) + 64 ) ]

    // ~~

    #define GetAngleSinus( _angle_ ) \
        \
        AngleSinusArray[ ( UINT_8 )( _angle_ ) ]

    // ~~

    #define GetAngleCosinusSinus( _angle_cosinus_, _angle_sinus_, _angle_ ) \
        \
        _angle_cosinus_ = AngleSinusArray[ ( UINT_8 )( ( _angle_ ) + 64 ) ]; \
        _angle_sinus_ = AngleSinusArray[ ( UINT_8 )( _angle_ ) ];

    // ~~

    #define GetDistance( _first_x_, _first_z_, _second_x_, _second_z_ ) \
        \
        GetOriginDistance( ( _second_x_ ) - ( _first_x_ ), ( _second_z_ ) - ( _first_z_ ) )
#endif

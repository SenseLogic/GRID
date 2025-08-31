#ifndef __BASE_H__
    #define __BASE_H__

    // -- IMPORTS

    #include <stdint.h>

    // -- CONSTANTS

    #define false    0
    #define true    1
    #define AngleCount    256

    // -- TYPES

    #define BOOL    uint8_t
    #define CHAR    char
    #define INT_2_6    int8_t
    #define INT_4_4    int8_t
    #define INT_6_2    int8_t
    #define INT_8    int8_t
    #define INT_14_2    int16_t
    #define INT_16    int16_t
    #define UINT_2_6    uint8_t
    #define UINT_4_4    uint8_t
    #define UINT_6_2    uint8_t
    #define UINT_8    uint8_t
    #define UINT_14_2    uint16_t
    #define UINT_16    uint16_t

    // ~~

    #define COLOR    uint8_t
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

    #define ClampInteger( _integer_, _minimum_, _maximum_ ) \
        \
        { \
            if ( ( _integer_ ) < _minimum_ ) \
            { \
                _integer_ = _minimum_; \
            } \
            else if (  ( _integer_ ) > _maximum_ ) \
            { \
                _integer_ = _maximum_; \
            } \
        }

    // ~~

    #define FixInterval( _minimum_, _maximum_, _old_minimum_ ) \
        \
        { \
            if ( ( _minimum_ ) > ( _maximum_ ) ) \
            { \
                _old_minimum_ = _minimum_; \
                _minimum_ = _maximum_; \
                _maximum_ = _old_minimum_; \
            } \
        }

    // ~~

    #define GetRandomNatural16() \
        \
        ( RandomNatural = RandomNatural * 45 + 21 )

    // ~~

    #define GetRandomNatural( _bit_count_ ) \
        \
        ( GetRandomNatural16() >> ( 16 - ( _bit_count_ ) ) )

    // ~~

    #define GetRandomInteger16() \
        \
        ( ( INT_16 )GetRandomNatural16() )

    // ~~

    #define GetRandomInteger( _bit_count_ ) \
        \
        ( GetRandomInteger16() >> ( 16 - ( _bit_count_ ) ) )

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

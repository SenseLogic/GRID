#ifndef __VIDEO_H__
    #define __VIDEO_H__

    // -- CONSTANTS

    #define ScreenByteCount    1000

    // -- FUNCTIONS

    #define SetBankAddress( _bank_address_ ) \
        \
        *( volatile UINT_8 * )0xDD00 = ( ( *( volatile UINT_8 * )0xD018 ) & 0xFC ) | ( 0x03 - ( ( _bank_address_ ) >> 14 ) );

    // ~~

    #define SetScreenAddress( _screen_address_ ) \
        \
        *( volatile UINT_8 * )0xD018 = ( ( *( volatile UINT_8 * )0xD018 ) & 0x0F ) | ( ( ( _screen_address_ ) & 0x3FFF ) >> 6 );

    // ~~

    #define SetFontAddress( _font_address_ ) \
        \
        *( volatile UINT_8 * )0xD018 = ( ( *( volatile UINT_8 * )0xD018 ) & 0xF1 ) | ( ( ( _font_address_ ) & 0x3FFF ) >> 10 );
#endif

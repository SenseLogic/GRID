#ifndef __SPRITE_H__
    #define __SPRITE_H__

    // -- CONSTANTS

    #define SpriteImageByteCount    63
    #define FirstTitleSpriteIndex    0
    #define TitleSpriteCount    3
    #define ReticleSpriteIndex    0
    #define RadarSpriteIndex    1
    #define RadarBackgroundSpriteIndex    2
    #define FirstMountainSpriteIndex    3

    #define FirstTitleSpriteImageIndex    0
    #define TitleSpriteImageCount    3
    #define ReticleSpriteImageIndex    3
    #define RadarSpriteImageIndex    4
    #define RadarBackgroundSpriteImageIndex    5
    #define FirstMountainSpriteImageIndex    6
    #define MountainSpriteImageCount    8

    // -- FUNCTIONS

    #define SetFirstSharedSpriteColor( _color_ ) \
        \
        *( volatile UINT_8 * )0xD025 = _color_

    // ~~

    #define SetSecondSharedSpriteColor( _color_ ) \
        \
        *( volatile UINT_8 * )0xD026 = _color_

    // ~~

    #define SetSpritesVisibilityMask( _bit_mask_ ) \
        \
        *( volatile UINT_8 * )0xD015 = _bit_mask_

    // ~~

    #define EnableSpriteVisibility( _sprite_index_ ) \
        \
        *( volatile UINT_8 * )0xD015 |= 1 << ( _sprite_index_ )

    // ~~

    #define SetSpritesMulticolorMask( _bit_mask_ ) \
        \
        *( volatile UINT_8 * )0xD01C = _bit_mask_

    // ~~

    #define EnableSpriteMulticolor( _sprite_index_ ) \
        \
        *( volatile UINT_8 * )0xD01C |= 1 << ( _sprite_index_ )

    // ~~

    #define SetSpritesXExpansionMask( _bit_mask_ ) \
        \
        *( volatile UINT_8 * )0xD01D = _bit_mask_

    // ~~

    #define EnableSpriteXExpansion( _sprite_index_ ) \
        \
        *( volatile UINT_8 * )0xD01D |= 1 << ( _sprite_index_ )

    // ~~

    #define SetSpritesYExpansionMask( _bit_mask_ ) \
        \
        *( volatile UINT_8 * )0xD017 = _bit_mask_

    // ~~

    #define EnableSpriteYExpansion( _sprite_index_ ) \
        \
        *( volatile UINT_8 * )0xD017 |= 1 << ( _sprite_index_ )

    // ~~

    #define SetSpritesPriorityMask( _bit_mask_ ) \
        \
        *( volatile UINT_8 * )0xD01B = _bit_mask_

    // ~~

    #define EnableSpritePriority( _sprite_index_ ) \
        \
        *( volatile UINT_8 * )0xD01B |= 1 << ( _sprite_index_ )

    // ~~

    #define SetSpriteXPosition( _sprite_index_, _x_position_ ) \
        \
        if ( ( _x_position_ ) & 0x100 ) \
        { \
            *( volatile UINT_8 * )0xD010 |= 1 << ( _sprite_index_ ); \
        } \
        else \
        { \
            *( volatile UINT_8 * )0xD010 &= ~( 1 << ( _sprite_index_ ) ); \
        } \
        \
        *( volatile UINT_8 * )( 0xD000 + ( _sprite_index_ << 1 ) ) = _x_position_;

    // ~~

    #define SetSpriteYPosition( _sprite_index_, _y_position_ ) \
        \
        *( volatile UINT_8 * )( 0xD001 + ( ( _sprite_index_ ) << 1 ) ) = _y_position_

    // ~~

    #define SetSpriteColor( _sprite_index_, _color_ ) \
        \
        *( volatile UINT_8 * )( 0xD027 + ( _sprite_index_ ) ) = _color_

    // ~~

    #define SetSpriteImageIndex( _sprite_index_, _sprite_image_index_ ) \
        \
        *( volatile UINT_8 * )( ScreenAddress + 0x03F8 + ( _sprite_index_ ) ) = ( ( SpriteAddress & 0x3FFF ) >> 6 ) + ( _sprite_image_index_ )

    // ~~

    #define GetSpriteImageByteArray( _sprite_image_index_ ) \
        \
        ( volatile UINT_8 * )( SpriteAddress + ( ( _sprite_image_index_ ) << 6 ) )
#endif

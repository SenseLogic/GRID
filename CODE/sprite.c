// -- IMPORTS

#include "base.h"
#include "memory.h"
#include "sprite.h"

// -- FUNCTIONS

void ClearSpriteImage(
    UINT_8 sprite_image_index
    )
{

    UINT_8
        *sprite_byte,
        sprite_byte_count;

    sprite_byte = GetSpriteImageByteArray( sprite_image_index );
    sprite_byte_count = SpriteImageByteCount;

    while ( sprite_byte_count-- )
    {
        *sprite_byte++ = 0;
    }
}

// ~~

void SetSpriteImage(
    UINT_8 sprite_image_index,
    const UINT_8 *sprite_image_byte_array,
    const UINT_8 sprite_image_byte_count
    )
{
    UINT_8
        *sprite_byte,
        sprite_byte_count;

    sprite_byte = GetSpriteImageByteArray( sprite_image_index );
    sprite_byte_count = SpriteImageByteCount - sprite_image_byte_count;

    while ( sprite_byte_count-- )
    {
        *sprite_byte++ = 0;
    }

    sprite_byte_count = sprite_image_byte_count;

    while ( sprite_byte_count-- )
    {
        *sprite_byte++ = *sprite_image_byte_array++;
    }
}

// ~~

void InitializeSprites(
    )
{
    SetSpritesVisibilityMask( 0b00000000 );
    SetSpritesMulticolorMask( 0b00000000 );
    SetSpritesXExpansionMask( 0b00000000 );
    SetSpritesYExpansionMask( 0b00000000 );
    SetSpritesPriorityMask( 0b00000000 );
}

// ~~

void InitializeSprite(
    UINT_8 sprite_index,
    INT_16 x_position,
    UINT_8 y_position,
    UINT_8 x_scale,
    UINT_8 y_scale,
    COLOR color,
    BOOL has_priority
    )
{
    if ( has_priority )
    {
        EnableSpritePriority( sprite_index );
    }

    if ( x_scale == 2 )
    {
        EnableSpriteXExpansion( sprite_index );
    }

    if ( y_scale == 2 )
    {
        EnableSpriteYExpansion( sprite_index );
    }

    SetSpriteXPosition( sprite_index, x_position );
    SetSpriteYPosition( sprite_index, y_position );
    SetSpriteColor( sprite_index, color );
}

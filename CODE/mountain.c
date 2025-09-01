// -- IMPORTS

#include "base.h"
#include "memory.h"
#include "sprite.h"

// -- CONSTANTS

#define MountainCount    5

// ~~

const UINT_8
    *BlankSpriteImageByteArray = 0,
    FirstMountainSpriteImageByteArray[ 12 ] =
        {
            0b00000011, 0b11100000, 0b00000000,
            0b00001111, 0b11111001, 0b11100000,
            0b00111111, 0b11111111, 0b11111000,
            0b11111111, 0b11111111, 0b11111111
        },
    SecondMountainSpriteImageByteArray[ 9 ] =
        {
            0b00000000, 0b00000111, 0b11000000,
            0b00001111, 0b00011111, 0b11111100,
            0b11111111, 0b11111111, 0b11111111
        },
    ThirdMountainSpriteImageByteArray[ 21 ] =
        {
            0b00000000, 0b00110000, 0b00000000,
            0b00000000, 0b01111100, 0b00000000,
            0b00000011, 0b11111110, 0b00000000,
            0b00001111, 0b11111111, 0b00000000,
            0b00011111, 0b11111111, 0b11110000,
            0b01111111, 0b11111111, 0b11111100,
            0b11111111, 0b11111111, 0b11111111
        },
    FourthMountainSpriteImageByteArray[ 9 ] =
        {
            0b00001111, 0b00100011, 0b00000000,
            0b01111111, 0b11111111, 0b11111100,
            0b11111111, 0b11111111, 0b11111111
        },
    FifthMountainSpriteImageByteArray[ 24 ] =
        {
            0b00000000, 0b00110000, 0b00000000,
            0b00000000, 0b01111000, 0b11100000,
            0b00000000, 0b01111101, 0b11110000,
            0b00000000, 0b11111101, 0b11110000,
            0b00000001, 0b11111111, 0b11111100,
            0b00000111, 0b11111111, 0b11111100,
            0b00111111, 0b11111111, 0b11111110,
            0b11111111, 0b11111111, 0b11111111
        },
    SixthMountainSpriteImageByteArray[ 9 ] =
        {
            0b00111110, 0b00000000, 0b11110000,
            0b01111111, 0b11100011, 0b11111100,
            0b11111111, 0b11111111, 0b11111111
        },
    SeventhMountainSpriteImageByteArray[ 12 ] =
        {
            0b00001000, 0b00001000, 0b00000000,
            0b00001111, 0b10001101, 0b00010000,
            0b00011111, 0b11111111, 0b11111000,
            0b11111111, 0b11111111, 0b11111111
        },
    EighthMountainSpriteImageByteArray[ 24 ] =
        {
            0b00000001, 0b10000000, 0b00000000,
            0b00000011, 0b10000100, 0b00000000,
            0b00000111, 0b11001110, 0b00000000,
            0b00000111, 0b11111110, 0b00000000,
            0b00001111, 0b11111111, 0b00000000,
            0b00011111, 0b11111111, 0b11000000,
            0b00111111, 0b11111111, 0b11111100,
            0b11111111, 0b11111111, 0b11111111
        };

// -- VARIABLES

UINT_8
    OldMountainXOffset,
    MountainXOffset;
INT_8
    MountainXOffsetArray[ 16 ];

// -- FUNCTIONS

void InitializeMountains(
    )
{
    UINT_8
        mountain_x_offset_index;

    SetSpriteImage( FirstMountainSpriteImageIndex, FirstMountainSpriteImageByteArray, sizeof( FirstMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 1, SecondMountainSpriteImageByteArray, sizeof( SecondMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 2, ThirdMountainSpriteImageByteArray, sizeof( ThirdMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 3, FourthMountainSpriteImageByteArray, sizeof( FourthMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 4, FifthMountainSpriteImageByteArray, sizeof( FifthMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 5, SixthMountainSpriteImageByteArray, sizeof( SixthMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 6, SeventhMountainSpriteImageByteArray, sizeof( SeventhMountainSpriteImageByteArray ) );
    SetSpriteImage( FirstMountainSpriteImageIndex + 7, EighthMountainSpriteImageByteArray, sizeof( EighthMountainSpriteImageByteArray ) );

    for ( mountain_x_offset_index = 0;
          mountain_x_offset_index < 16;
          ++mountain_x_offset_index )
    {
        MountainXOffsetArray[ mountain_x_offset_index ] = -24 + GetRandomNatural( 6 );
    }

    OldMountainXOffset = 255;
    MountainXOffset = 0;
}

// ~~

void DrawMountains(
    )
{
    INT_16
        mountain_sprite_x,
        mountain_sprite_x_position;
    UINT_8
        mountain_index,
        mountain_sprite_image_index,
        mountain_sprite_index,
        mountain_sprite_visibility_mask,
        mountain_sprite_x_offset_index,
        sprite_visibility_mask;

    if ( MountainXOffset != OldMountainXOffset )
    {
        sprite_visibility_mask = 0b00000111;
        mountain_sprite_visibility_mask = 0b00001000;
        mountain_sprite_index = FirstMountainSpriteIndex;
        mountain_sprite_image_index = MountainXOffset >> 3;
        mountain_sprite_x_position = ( 7 - ( MountainXOffset & 7 ) ) * 10;
        mountain_sprite_x_offset_index = mountain_sprite_image_index & 15;

        for ( mountain_index = 0;
              mountain_index < MountainCount;
              ++mountain_index )
        {
            mountain_sprite_x = mountain_sprite_x_position + MountainXOffsetArray[ mountain_sprite_x_offset_index ];

            if ( mountain_sprite_x >= 344 )
            {
                mountain_sprite_x = 344;
            }

            mountain_sprite_image_index &= 7;

            InitializeSprite( mountain_sprite_index, mountain_sprite_x, 0x87, 2, 2, COLOR_Blue, true );
            SetSpriteImageIndex( mountain_sprite_index, FirstMountainSpriteImageIndex + mountain_sprite_image_index );

            sprite_visibility_mask |= mountain_sprite_visibility_mask;
            mountain_sprite_visibility_mask <<= 1;
            ++mountain_sprite_index;
            ++mountain_sprite_image_index;
            mountain_sprite_x_position += 80;
            mountain_sprite_x_offset_index = ( mountain_sprite_x_offset_index + 1 ) & 15;
        }

        SetSpritesVisibilityMask( sprite_visibility_mask );
        OldMountainXOffset = MountainXOffset;
    }
}

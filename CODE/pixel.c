// -- IMPORTS

#include "base.h"
#include "memory.h"
#include "pixel.h"

// -- VARIABLES

UINT_8
    *PixelTileByteArray = ( UINT_8 * )PixelTileAddress;

// -- FUNCTIONS

void ClearBuffer(
    )
{
    UINT_8
        *post_pixel_tile_byte,
        *pixel_tile_byte;

    pixel_tile_byte = PixelTileByteArray;
    post_pixel_tile_byte = PixelTileByteArray + PixelTileByteCount;

    while ( pixel_tile_byte != post_pixel_tile_byte )
    {
        *pixel_tile_byte++ = 0;
        *pixel_tile_byte++ = 1;
    }
}

// ~~

#define GetPixelColorX( _pixel_x_ ) \
    \
    ( ( _pixel_x_ ) & 0xFE )

// ~~

#define GetPixelColorY( _pixel_y_ ) \
    \
    ( ( _pixel_y_ ) >> 2 )

// ~~

#define DrawGridPixel( _pixel_x_ , _pixel_y_ ) \
    \
    { \
        pixel_tile_character_bit = ( ( ( _pixel_y_ ) & 3 ) << 1 ) + ( ( _pixel_x_ ) & 1 ); \
        PixelTileByteArray[ ( UINT_16 )( ( _pixel_y_ ) >> 2 ) * 80 + ( ( _pixel_x_ ) & 0xFE ) ] |= ( 1 << pixel_tile_character_bit ); \
    }

// ~~

#define DrawLinePixel( _pixel_x_ , _pixel_y_, _color_ ) \
    \
    if ( ( _pixel_x_ ) >= 0 && ( _pixel_x_ ) < 80 && ( _pixel_y_ ) >= 0 && ( _pixel_y_ ) < 100 ) \
    { \
        pixel_tile_character_bit = ( ( ( _pixel_y_ ) & 3 ) << 1 ) + ( ( _pixel_x_ ) & 1 ); \
        pixel_tile_character_byte = PixelTileByteArray + ( ( UINT_16 )( ( _pixel_y_ ) >> 2 ) * 80 + ( ( _pixel_x_ ) & 0xFE ) ); \
        pixel_tile_color_byte = pixel_tile_character_byte + 1; \
        if ( *pixel_tile_color_byte == 1 ) *pixel_tile_character_byte = 0; \
        *pixel_tile_color_byte = _color_; \
        *pixel_tile_character_byte |= ( 1 << pixel_tile_character_bit ); \
    }

// ~~

void DrawPixelAreaColor(
    INT_16 first_pixel_x,
    INT_16 first_pixel_y,
    INT_16 last_pixel_x,
    INT_16 last_pixel_y,
    COLOR color
    )
{
    INT_8
        color_x,
        color_y,
        first_color_x,
        first_color_y,
        last_color_x,
        last_color_y;
    UINT_8
        *row_pixel_tile_color_byte;

    first_color_x = GetPixelColorX( first_pixel_x );
    first_color_y = GetPixelColorY( first_pixel_y );
    last_color_x = GetPixelColorX( last_pixel_x );
    last_color_y = GetPixelColorY( last_pixel_y );

    row_pixel_tile_color_byte = PixelTileByteArray + first_color_y * 80 + 1;

    for ( color_y = first_color_y;
          color_y <= last_color_y;
          ++color_y )
    {
        for ( color_x = first_color_x;
              color_x <= last_color_x;
              color_x += 2 )
        {
            row_pixel_tile_color_byte[ color_x ] = color;
        }

        row_pixel_tile_color_byte += 80;
    }
}

// ~~

void DrawPixelTextColor(
    INT_16 character_x,
    INT_16 character_y,
    UINT_8 character_count,
    COLOR color
    )
{
    DrawPixelAreaColor(
        character_x,
        character_y,
        character_x + ( character_count << 2 ) - 1,
        character_y + 7,
        color
        );
}


// ~~

UINT_8 DrawPixelCharacter(
    UINT_8 character_x,
    UINT_8 character_y,
    UINT_8 character_code,
    COLOR color
    )
{
    UINT_8
        *pixel_tile_character_byte;
    const UINT_8
        *font_byte;

    if ( character_code < 128 )
    {
        character_code -= 32;
    }
    else
    {
        character_code -= 128;
    }

    font_byte = FontByteArray + ( ( UINT_16 )character_code << 2 );

    pixel_tile_character_byte = PixelTileByteArray + ( ( UINT_16 )( character_y >> 2 ) * 80 + ( character_x & 0xFE ) );

    *pixel_tile_character_byte++ = *font_byte++;
    *pixel_tile_character_byte++ = color;

    *pixel_tile_character_byte++ = *font_byte++;
    *pixel_tile_character_byte = color;

    pixel_tile_character_byte += 77;

    *pixel_tile_character_byte++ = *font_byte++;
    *pixel_tile_character_byte++ = color;

    *pixel_tile_character_byte++ = *font_byte;
    *pixel_tile_character_byte = color;

    return character_x + 4;
}

// ~~

UINT_8 DrawPixelText(
    UINT_8 character_x,
    UINT_8 character_y,
    const CHAR *character_array,
    COLOR color
    )
{
    const CHAR
        *character;
    UINT_8
        character_code,
        x_offset,
        y_offset;

    x_offset = 0;
    y_offset = 0;

    for ( character = character_array;
          *character;
          ++character )
    {
        character_code = *character;

        if ( character_code == '\n' )
        {
            x_offset = 0;
            y_offset += 8;
        }
        else
        {
            DrawPixelCharacter( character_x + x_offset, character_y + y_offset, character_code, color );

            x_offset += 4;
        }
    }

    return character_x + x_offset;
}

// ~~

UINT_8 DrawPixelNatural(
    UINT_8 character_x,
    UINT_8 character_y,
    const CHAR *character_array,
    UINT_16 natural,
    COLOR color
    )
{
    UINT_16
        digit;

    if ( *character_array )
    {
        character_x = DrawPixelText( character_x, character_y, character_array, color );
    }

    if ( natural >= 10000 )
    {
        digit = 0;

        while ( natural >= 10000 )
        {
            ++digit;
            natural -= 10000;
        }

        character_x = DrawPixelCharacter( character_x, character_y, 48 + digit, color );
    }

    if ( natural >= 1000 )
    {
        digit = 0;

        while ( natural >= 1000 )
        {
            ++digit;
            natural -= 1000;
        }

        character_x = DrawPixelCharacter( character_x, character_y, 48 + digit, color );
    }

    if ( natural >= 100 )
    {
        digit = 0;

        while ( natural >= 100 )
        {
            ++digit;
            natural -= 100;
        }

        character_x = DrawPixelCharacter( character_x, character_y, 48 + digit, color );
    }

    if ( natural >= 10 )
    {
        digit = 0;

        while ( natural >= 10 )
        {
            ++digit;
            natural -= 10;
        }

        character_x = DrawPixelCharacter( character_x, character_y, 48 + digit, color );
    }

    return DrawPixelCharacter( character_x, character_y, 48 + natural, color );
}

// ~~

UINT_8 DrawPixelInteger(
    UINT_8 character_x,
    UINT_8 character_y,
    const CHAR *character_array,
    INT_16 integer,
    COLOR color
    )
{
    if ( integer >= 0 )
    {
        character_x = DrawPixelNatural( character_x, character_y, character_array, integer, color );
    }
    else
    {
        character_x = DrawPixelText( character_x, character_y, character_array, color );
        character_x = DrawPixelNatural( character_x, character_y, "-", -integer, color );
    }

    return character_x;
}

// ~~

void DrawPixel(
    INT_16 pixel_x,
    INT_16 pixel_y,
    COLOR color
    )
{
    UINT_8
        pixel_tile_character_bit,
        *pixel_tile_character_byte,
        *pixel_tile_color_byte;

    if ( IsVisiblePixelX( pixel_x )
         && IsVisiblePixelY( pixel_y ) )
    {
        DrawLinePixel( pixel_x, pixel_y, color );
    }
}

// ~~

void DrawPixelLine(
    INT_16 first_pixel_x,
    INT_16 first_pixel_y,
    INT_16 last_pixel_x,
    INT_16 last_pixel_y,
    COLOR color
    )
{
    INT_8
        iteration_count,
        pixel_x,
        pixel_y,
        x_step,
        y_step;
    INT_16
        distance_offset,
        double_distance_offset,
        x_distance,
        y_distance;
    UINT_8
        pixel_tile_character_bit,
        *pixel_tile_character_byte,
        *pixel_tile_color_byte;

    if ( !( ( first_pixel_x < 0
              && last_pixel_x < 0 )
            || ( first_pixel_x > 79
                 && last_pixel_x > 79 )
            || ( first_pixel_y < 0
                 && last_pixel_y < 0 )
            || ( first_pixel_y > 99
                 && last_pixel_y > 99 ) ) )
    {
        if ( first_pixel_x == last_pixel_x )
        {
            ClampPixelY( first_pixel_y );
            ClampPixelY( last_pixel_y );

            if ( first_pixel_y == last_pixel_y )
            {
                pixel_x = first_pixel_x;
                pixel_y = last_pixel_y;

                DrawLinePixel( pixel_x, pixel_y, color );
            }
            else
            {
                pixel_x = first_pixel_x;

                FixInterval( first_pixel_y, last_pixel_y, pixel_y );

                for ( pixel_y = first_pixel_y;
                      pixel_y <= last_pixel_y;
                      ++pixel_y )
                {
                    DrawLinePixel( pixel_x, pixel_y, color );
                }
            }
        }
        else if ( first_pixel_y == last_pixel_y )
        {
            pixel_y = first_pixel_y;

            ClampPixelX( first_pixel_x );
            ClampPixelX( last_pixel_x );
            FixInterval( first_pixel_x, last_pixel_x, pixel_x );

            for ( pixel_x = first_pixel_x;
                  pixel_x <= last_pixel_x;
                  ++pixel_x )
            {
                DrawLinePixel( pixel_x, pixel_y, color );
            }
        }
        else
        {
            if ( first_pixel_x < last_pixel_x )
            {
                x_step = 1;
            }
            else
            {
                x_step = -1;
            }

            if ( first_pixel_y < last_pixel_y )
            {
                y_step = 1;
            }
            else
            {
                y_step = -1;
            }

            pixel_x = first_pixel_x;
            pixel_y = first_pixel_y;

            x_distance = last_pixel_x - first_pixel_x;

            if ( first_pixel_x < last_pixel_x )
            {
                x_distance = last_pixel_x - first_pixel_x;
            }
            else
            {
                x_distance = first_pixel_x - last_pixel_x;
            }

            if ( first_pixel_y < last_pixel_y )
            {
                y_distance = last_pixel_y - first_pixel_y;
            }
            else
            {
                y_distance = first_pixel_y - last_pixel_y;
            }

            if ( x_distance == y_distance )
            {
                iteration_count = x_distance + 1;

                while ( iteration_count-- )
                {
                    DrawLinePixel( pixel_x, pixel_y, color );
                    pixel_x += x_step;
                    pixel_y += y_step;
                }
            }
            else
            {
                distance_offset = x_distance - y_distance;

                if ( distance_offset > 0 )
                {
                    iteration_count = x_distance + 1;
                }
                else
                {
                    iteration_count = y_distance + 1;
                }

                while ( iteration_count-- )
                {
                    DrawLinePixel( pixel_x, pixel_y, color );

                    double_distance_offset = distance_offset << 1;

                    if ( double_distance_offset > -y_distance )
                    {
                        distance_offset -= y_distance;
                        pixel_x += x_step;
                    }

                    if ( double_distance_offset < x_distance )
                    {
                        distance_offset += x_distance;
                        pixel_y += y_step;
                    }
                }
            }
        }
    }
}
// ~~

void CopyBuffer(
    )
{
    UINT_8
        *post_pixel_tile_byte,
        *pixel_tile_byte,
        *screen_byte,
        *color_byte;

    screen_byte = ( UINT_8 * )ScreenAddress;
    color_byte = ( UINT_8 * )ColorAddress;
    pixel_tile_byte = PixelTileByteArray;
    post_pixel_tile_byte = PixelTileByteArray + PixelTileByteCount;

    while ( pixel_tile_byte != post_pixel_tile_byte )
    {
        *screen_byte++ = *pixel_tile_byte++;
        *color_byte++ = *pixel_tile_byte++;
    }
}

// -- IMPORTS

#include "base.h"
#include "grid.h"

// -- VARIABLES

INT_8
    *RowArray = ( INT_8 * )RowAddress;
INT_14_2
    GridX = 0,
    GridZ = 0;

// -- FUNCTIONS

void InitializeGridRows(
    )
{
    INT_8
        *row;
    INT_14_2
        grid_x,
        grid_y,
        grid_z,
        view_vertex_x,
        view_vertex_z,
        screen_vertex_y;
    UINT_8
        row_index;

    row = RowArray;
    grid_y = -DefaultCameraY >> 2;

    for ( grid_z = 0;
          grid_z < GridSquareSize;
          ++grid_z )
    {
        for ( grid_x = 0;
              grid_x < GridSquareSize;
              ++grid_x )
        {
            for ( row_index = 0;
                  row_index < GridRowCount;
                  ++row_index )
            {
                view_vertex_z = row_index * GridSquareSize + 4 + GridSquareMask - grid_z;
                screen_vertex_y = GetPixelY( grid_y, view_vertex_z );

                if ( screen_vertex_y >= 0
                     && screen_vertex_y < 100 )
                {
                    *row++ = screen_vertex_y;
                }
                else
                {
                    *row++ = -128;
                }

                view_vertex_x = GridSquareMask - grid_x;
                *row++ = GetPixelX( view_vertex_x, view_vertex_z );
                *row++ = GetPixelX( view_vertex_x + GridSquareSize, view_vertex_z );
            }
        }
    }
}

// ~~

void InitializeGrid(
    )
{
    GridX = 0;
    GridZ = 0;
}

// ~~

void DrawGrid(
    )
{
    INT_8
        grid_y,
        *row;
    INT_16
        first_screen_vertex_x,
        screen_vertex_x,
        screen_vertex_x_offset,
        screen_vertex_y,
        second_screen_vertex_x,
        view_vertex_x,
        view_vertex_z;
    UINT_8
        pixel_tile_character_bit;
    UINT_16
        grid_x,
        grid_z,
        row_index;

    grid_x = ( GridX >> 2 ) & GridSquareMask;
    grid_z = ( GridZ >> 2 ) & GridSquareMask;

    if ( CameraY == DefaultCameraY )
    {
        row
            = RowArray
              + ( grid_z * GridSquareSize + grid_x ) * ( GridRowCount * 3 );

        for ( row_index = 0;
              row_index < GridRowCount;
              ++row_index )
        {
            screen_vertex_y = *row++;

            if ( screen_vertex_y >= 0
                 && screen_vertex_y < 100 )
            {
                first_screen_vertex_x = *row++;
                second_screen_vertex_x = *row++;
                screen_vertex_x_offset = second_screen_vertex_x - first_screen_vertex_x;

                DrawGridPixel( first_screen_vertex_x, screen_vertex_y );

                if ( screen_vertex_x_offset > 0 )
                {
                    for ( screen_vertex_x = first_screen_vertex_x - screen_vertex_x_offset;
                          screen_vertex_x >= 0;
                          screen_vertex_x -= screen_vertex_x_offset )
                    {
                        DrawGridPixel( screen_vertex_x, screen_vertex_y );
                    }

                    for ( screen_vertex_x = second_screen_vertex_x;
                          screen_vertex_x < 80;
                          screen_vertex_x += screen_vertex_x_offset )
                    {
                        DrawGridPixel( screen_vertex_x, screen_vertex_y );
                    }
                }
            }
            else
            {
                row += 2;
            }
        }
    }
    else
    {
        for ( row_index = 0;
              row_index < GridRowCount;
              ++row_index )
        {
            grid_y = -CameraY >> 2;
            view_vertex_z = row_index * GridSquareSize + 4 + GridSquareMask - grid_z;
            screen_vertex_y = GetPixelY( grid_y, view_vertex_z );

            if ( screen_vertex_y >= 0
                 && screen_vertex_y < 100 )
            {
                view_vertex_x = GridSquareMask - grid_x;
                first_screen_vertex_x = GetPixelX( view_vertex_x, view_vertex_z );
                second_screen_vertex_x = GetPixelX( view_vertex_x + GridSquareSize, view_vertex_z );
                screen_vertex_x_offset = second_screen_vertex_x - first_screen_vertex_x;

                DrawGridPixel( first_screen_vertex_x, screen_vertex_y );

                if ( screen_vertex_x_offset > 0 )
                {
                    for ( screen_vertex_x = first_screen_vertex_x - screen_vertex_x_offset;
                          screen_vertex_x >= 0;
                          screen_vertex_x -= screen_vertex_x_offset )
                    {
                        DrawGridPixel( screen_vertex_x, screen_vertex_y );
                    }

                    for ( screen_vertex_x = second_screen_vertex_x;
                          screen_vertex_x < 80;
                          screen_vertex_x += screen_vertex_x_offset )
                    {
                        DrawGridPixel( screen_vertex_x, screen_vertex_y );
                    }
                }
            }
        }
    }
}

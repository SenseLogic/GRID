// -- CONSTANTS

#define RainbowColorCount    4

// ~~

const COLOR
    RainbowColorArray[ RainbowColorCount ] =
        {
            COLOR_LightRed,
            COLOR_LightBlue,
            COLOR_Blue,
            COLOR_Purple
        };

// -- FUNCTIONS

void DrawPortal(
    COLOR portal_color,
    COLOR ray_color
    )
{
    DrawPixelLine( 2, 63, 5, 57, portal_color );
    DrawPixelLine( 77, 63, 74, 57, portal_color );

    DrawPixelLine( 5, 57, 18, 57, portal_color );
    DrawPixelLine( 74, 57, 61, 57, portal_color );

    DrawPixelLine( 16, 63, 21, 51, portal_color );
    DrawPixelLine( 63, 63, 58, 51, portal_color );

    DrawPixelLine( 21, 51, 31, 51, portal_color );
    DrawPixelLine( 58, 51, 48, 51, portal_color );

    DrawPixelLine( 29, 63, 35, 34, portal_color );
    DrawPixelLine( 50, 63, 44, 34, portal_color );

    DrawPixelLine( 35, 63, 39, 18, portal_color );
    DrawPixelLine( 44, 63, 40, 18, portal_color );

    DrawPixelLine( 35, 34, 44, 34, portal_color );
    DrawPixelLine( 39, 24, 40, 24, portal_color );

    DrawPixelLine( 39, 21, 39, 0, ray_color );
    DrawPixelLine( 40, 21, 40, 0, ray_color );
}

// ~~

void DrawPortalRays(
    COLOR first_ray_color,
    COLOR second_ray_color,
    COLOR third_ray_color
    )
{
    DrawPixelLine( 22, 47, 1, 26, first_ray_color );
    DrawPixelLine( 57, 47, 78, 26, first_ray_color );

    DrawPixelLine( 27, 37, 11, 10, second_ray_color );
    DrawPixelLine( 52, 37, 68, 10, second_ray_color );

    DrawPixelLine( 32, 28, 24, 0, third_ray_color );
    DrawPixelLine( 47, 28, 55, 0, third_ray_color );
}

// ~~

void UpdateVictoryInput(
    )
{
    if ( ( ( Joystick2State & JoystickStateFireMask )
           && !( OldJoystick2State & JoystickStateFireMask ) )
         || FrameIndex >= 25 )
    {
       GameState = GAME_STATE_ShowIntroScreen;
    }

    ClearInput();
}

// ~~

void ShowVictoryScreen(
    )
{
    UINT_8
        rainbox_color_index;

    InitializeSounds();
    ClearBuffer();
    InitializeCamera();
    InitializeGrid();
    GridZ = 25;
    DrawGrid();
    DrawPortal( COLOR_LightGreen, COLOR_Yellow );
    DrawPixelText( 26, 76, "VICTORY", COLOR_Yellow );
    rainbox_color_index = 0;

    for ( FrameIndex = 0;
          GameState == GAME_STATE_ShowVictoryScreen;
          ++FrameIndex )
    {
        UpdateVictoryInput();

        DrawPixelTextColor( 26, 76, 7, ( FrameIndex & 0x02 ) ? COLOR_Blue : COLOR_Yellow );
        DrawPortalRays(
            RainbowColorArray[ rainbox_color_index & 3 ],
            RainbowColorArray[ ( rainbox_color_index + 1 ) & 3 ],
            RainbowColorArray[ ( rainbox_color_index + 2 ) & 3 ]
            );
        CopyBuffer();

        if ( FrameIndex == 0 )
        {
            PlayVictorySound();
        }

        ++rainbox_color_index;
    }
}

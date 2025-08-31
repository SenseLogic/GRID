// -- FUNCTIONS

void DrawShattering(
    )
{
    INT_2_6
        angle_cosinus,
        angle_sinus;
    INT_8
        angle;
    UINT_8
        first_distance,
        line_index,
        second_distance;

    for ( line_index = 0;
          line_index < 16;
          ++line_index )
    {
        first_distance = 4 + GetRandomNatural( 4 );
        second_distance = first_distance + 8 + GetRandomNatural( 6 );

        angle = ( line_index << 4 ) + GetRandomInteger( 4 );
        GetAngleCosinusSinus( angle_cosinus, angle_sinus, angle );

        DrawPixelLine(
            40 + ( ( angle_cosinus * first_distance ) >> 6 ),
            50 + ( ( angle_sinus * first_distance ) >> 6 ),
            40 + ( ( angle_cosinus * second_distance ) >> 6 ),
            50 + ( ( angle_sinus * second_distance ) >> 6 ),
            COLOR_LightRed
            );
    }
}

// ~~

void UpdateDefeatInput(
    )
{
    if ( ( ( Joystick2State & JoystickStateFireMask )
           && !( OldJoystick2State & JoystickStateFireMask ) )
         || FrameIndex >= 80 )
    {
       GameState = GAME_STATE_ShowIntroScreen;
    }

    ClearInput();
}

// ~~

void ShowDefeatScreen(
    )
{
    InitializeSounds();
    ClearBuffer();
    DrawGrid();
    DrawModels();
    DrawShattering();
    DrawPixelText( 24, 48, "DEREZZED", COLOR_Yellow );

    for ( FrameIndex = 0;
          GameState == GAME_STATE_ShowDefeatScreen;
          ++FrameIndex )
    {
        UpdateDefeatInput();

        DrawPixelTextColor( 24, 48, 8, ( FrameIndex & 0x04 ) ? COLOR_Black : COLOR_Yellow );
        CopyBuffer();

        if ( FrameIndex == 0 )
        {
            PlayDefeatSound();
        }
    }
}

// -- CONSTANTS

#define PatternIndexCount    sizeof( PatternIndexArray )

// -- VARIABLES

const UINT_8
    FirstTitleSpriteImageByteArray[ 63 ] =
        {
            0b00000000, 0b11111111, 0b11100111,
            0b00000011, 0b00000000, 0b00010100,
            0b00001100, 0b00000000, 0b00010100,
            0b00010000, 0b00000000, 0b00010100,
            0b00100000, 0b00000000, 0b00010100,
            0b00100000, 0b00111111, 0b11110111,
            0b01000000, 0b11000000, 0b00000000,
            0b01000001, 0b00000000, 0b00000011,
            0b10000010, 0b00001111, 0b11000100,
            0b10000010, 0b00010000, 0b00100100,
            0b10000010, 0b00010000, 0b00010100,
            0b10000010, 0b00010000, 0b00010100,
            0b10000010, 0b00001110, 0b00010100,
            0b01000001, 0b00000010, 0b00010100,
            0b01000000, 0b11000010, 0b00010100,
            0b00100000, 0b00111110, 0b00010100,
            0b00100000, 0b00000000, 0b00010100,
            0b00010000, 0b00000000, 0b00010100,
            0b00001100, 0b00000000, 0b00010100,
            0b00000011, 0b00000000, 0b00010100,
            0b00000000, 0b11111111, 0b11100011
        },
    SecondTitleSpriteImageByteArray[ 63 ] =
        {
            0b11111111, 0b11111111, 0b10000011,
            0b00000000, 0b00000000, 0b01000100,
            0b00000000, 0b00000000, 0b00100100,
            0b00000000, 0b00000000, 0b00010100,
            0b00000000, 0b00000000, 0b00010100,
            0b11111111, 0b11111111, 0b11100100,
            0b00000000, 0b00000000, 0b00000100,
            0b11000111, 0b11111111, 0b11100100,
            0b00101000, 0b00000000, 0b00010100,
            0b00101000, 0b00000000, 0b00010100,
            0b00101000, 0b00000000, 0b00100100,
            0b00101000, 0b00000000, 0b01000100,
            0b00100100, 0b00001111, 0b10000100,
            0b00100010, 0b00000100, 0b00000100,
            0b00100001, 0b00000010, 0b00000100,
            0b00100000, 0b10000001, 0b00000100,
            0b00100000, 0b01000000, 0b10000100,
            0b00100000, 0b00100000, 0b01000100,
            0b00100000, 0b00010000, 0b00100100,
            0b00100000, 0b00001000, 0b00010100,
            0b11000000, 0b00000111, 0b11110011
        },
    ThirdTitleSpriteImageByteArray[ 63 ] =
        {
            0b11000111, 0b11111110, 0b00000000,
            0b00101000, 0b00000001, 0b10000000,
            0b00101000, 0b00000000, 0b01100000,
            0b00101000, 0b00000000, 0b00010000,
            0b00101000, 0b00000000, 0b00001000,
            0b00101000, 0b01111000, 0b00001000,
            0b00101000, 0b01000110, 0b00000100,
            0b00101000, 0b01000001, 0b00000100,
            0b00101000, 0b01000000, 0b10000010,
            0b00101000, 0b01000000, 0b10000010,
            0b00101000, 0b01000000, 0b10000010,
            0b00101000, 0b01000000, 0b10000010,
            0b00101111, 0b10000000, 0b10000010,
            0b00100000, 0b00000001, 0b00000100,
            0b00100000, 0b00000110, 0b00000100,
            0b00101111, 0b11111000, 0b00001000,
            0b00101000, 0b00000000, 0b00001000,
            0b00101000, 0b00000000, 0b00010000,
            0b00101000, 0b00000000, 0b01100000,
            0b00101000, 0b00000001, 0b10000000,
            0b11000111, 0b11111110, 0b00000000
        };
const INT_8
    NoteIndexArray[ 128 ] =
    {
        45, -1, 45, 45, -1, 45, 45, -1, 38, 38, -1, 41, 41, -1, 41, 41, 45, -1, 45, 45, -1, 45, 45, -1, 38, 38, -1, 41, 41, -1, 41, 41,
        50, 52, 57, 45, -1, -1, 50, -1, -1, 48, -1, -1, 53, -1, -1, -1, 50, 52, 57, 45, -1, -1, 50, -1, -1, 48, -1, -1, 41, -1, -1, -1,
        57, 55, 53, 50, -1, 57, 55, 53, 52, -1, 53, 52, 50, -1, 48, -1, 57, 55, 53, 50, -1, 57, 55, 53, 52, -1, 53, 52, 50, -1, 48, -1,
        41, 43, 45, 47, -1, 41, 43, 45, 48, -1, 50, 52, 53, 55, -1, 57, 50, 52, 53, 55, -1, 57, 50, 52, 53, -1, 55, 53, 52, -1, 50, -1
    },
    PatternIndexArray[ 36 ] =
    {
        0, -1, -1,
        0, -1, -1,
        0, 1, -1,
        0, 1, -1,
        0, 1, 1,
        0, 1, 1,
        0, 1, 2,
        0, 1, 3,
        0, -1, 1,
        0, -1, 1,
        0, -1, 2,
        0, -1, 3
    };
INT_8
    PatternIndexIndex,
    FirstPatternIndex,
    SecondPatternIndex,
    ThirdPatternIndex;

// -- FUNCTIONS

void InitializeIntroMusic(
    )
{
    PatternIndexIndex = -3;
}

// ~~

void InitializeIntroSprites(
    )
{
    InitializeSprites();
    InitializeMountains();

    SetSpriteImage( FirstTitleSpriteImageIndex, FirstTitleSpriteImageByteArray, sizeof( FirstTitleSpriteImageByteArray ) );
    SetSpriteImage( FirstTitleSpriteImageIndex + 1, SecondTitleSpriteImageByteArray, sizeof( SecondTitleSpriteImageByteArray ) );
    SetSpriteImage( FirstTitleSpriteImageIndex + 2, ThirdTitleSpriteImageByteArray, sizeof( ThirdTitleSpriteImageByteArray ) );

    InitializeSprite( FirstTitleSpriteIndex, 0x71, 0x00, 2, 2, COLOR_Yellow, false );
    InitializeSprite( FirstTitleSpriteIndex + 1, 0xA1, 0x00, 2, 2, COLOR_Yellow, false );
    InitializeSprite( FirstTitleSpriteIndex + 2, 0xD1, 0x00, 2, 2, COLOR_Yellow, false );

    SetSpriteImageIndex( FirstTitleSpriteIndex, FirstTitleSpriteImageIndex );
    SetSpriteImageIndex( FirstTitleSpriteIndex + 1, FirstTitleSpriteImageIndex + 1);
    SetSpriteImageIndex( FirstTitleSpriteIndex + 2, FirstTitleSpriteImageIndex + 2 );

    DrawMountains();
}

// ~~

void UpdateIntroMusic(
    )
{
    UINT_8
        pattern_note_index;

    if ( ( FrameIndex & 0x01 ) == 0 )
    {
        pattern_note_index = ( FrameIndex >> 1 ) & 0x1F;

        if ( pattern_note_index == 0 )
        {
            PatternIndexIndex += 3;

            if ( PatternIndexIndex >= PatternIndexCount )
            {
                PatternIndexIndex = 0;
            }

            FirstPatternIndex = PatternIndexArray[ PatternIndexIndex ];
            SecondPatternIndex = PatternIndexArray[ PatternIndexIndex + 1 ];
            ThirdPatternIndex = PatternIndexArray[ PatternIndexIndex + 2 ];
        }

        if ( FirstPatternIndex >= 0 )
        {
            PlayNote( 0, NoteIndexArray[ ( FirstPatternIndex << 5 ) + pattern_note_index ], 0x0800, 0x20, 0x09, 0x98 );
        }
        else
        {
            MuteChannel( 0x00 );
        }

        if ( SecondPatternIndex >= 0 )
        {
            PlayNote( 1, NoteIndexArray[ ( SecondPatternIndex << 5 ) + pattern_note_index ], 0x0800, 0x20, 0x09, 0x98 );
        }
        else
        {
            MuteChannel( 0x07 );
        }

        if ( ThirdPatternIndex >= 0 )
        {
            PlayNote( 2, NoteIndexArray[ ( ThirdPatternIndex << 5 ) + pattern_note_index ] - 12, 0x0800, 0x20, 0x09, 0x98 );
        }
        else
        {
            MuteChannel( 0x0E );
        }
    }
}

// ~~

void UpdateIntroSprites(
    )
{
    UINT_8
        sprite_y_position;

    if ( FrameIndex <= 14 )
    {
        sprite_y_position = FrameIndex * 5;

        SetSpriteYPosition( FirstTitleSpriteIndex, sprite_y_position );
        SetSpriteYPosition( FirstTitleSpriteIndex + 1, sprite_y_position );
        SetSpriteYPosition( FirstTitleSpriteIndex + 2, sprite_y_position );
    }
}

// ~~

void UpdateIntroInput(
    )
{
    if ( ( Joystick2State & JoystickStateFireMask )
         && !( OldJoystick2State & JoystickStateFireMask ) )
    {
       GameState = GAME_STATE_ShowLevelScreen;
    }

    ClearInput();
}

// ~~

void ShowIntroScreen(
    )
{
    SetSpritesVisibilityMask( 0b00000000 );
    InitializeSounds();
    InitializeIntroMusic();
    InitializeIntroSprites();
    InitializeCamera();
    InitializeGrid();
    InitializeTank();
    InitializeModels();

    for ( FrameIndex = 0;
          GameState == GAME_STATE_ShowIntroScreen;
          ++FrameIndex )
    {
        UpdateIntroInput();
        UpdateIntroMusic();

        ClearBuffer();
        UpdateTank();
        UpdateModels();
        UpdateIntroSprites();

        if ( FrameIndex >= 14 )
        {
            DrawPixelText( 20, 40, "PRESS START", ( FrameIndex & 0x04 ) ? COLOR_LightRed : COLOR_Black );
        }

        DrawGrid();
        CopyBuffer();
        SetSpritesVisibilityMask( 0b11111111 );
    }
}

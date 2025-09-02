// -- IMPORTS

#include "base.h"
#include "level.h"

// -- CONSTANTS

const INT_6_2
    RecognizerModelVertexComponentArray[ 39 ] =
        {
            5, 0, 0,
            9, 0, 0,
            9, 14, 0,
            -9, 14, 0,
            -9, 0, 0,
            -5, 0, 0,
            -7, 2, 0,
            -7, 9, 0,
            7, 9, 0,
            7, 2, 0,
            5, 14, 0,
            0, 18, 0,
            -5, 14, 0
        };
const UINT_8
    RecognizerModelEdgeVertexIndexArray[ 24 ] =
        {
            0, 1,
            1, 2,
            2, 3,
            3, 4,
            4, 5,
            5, 6,
            6, 7,
            7, 8,
            8, 9,
            9, 0,
            10, 11,
            11, 12
        };
const INT_6_2
    FarRecognizerModelVertexComponentArray[ 33 ] =
        {
            5, 0, 0,
            9, 0, 0,
            9, 14, 0,
            -9, 14, 0,
            -9, 0, 0,
            -5, 0, 0,
            5, 14, 0,
            0, 18, 0,
            -5, 14, 0,
            9, 9, 0,
            -9, 9, 0
        };
const UINT_8
    FarRecognizerModelEdgeVertexIndexArray[ 16 ] =
        {
            0, 1,
            1, 2,
            2, 3,
            3, 4,
            4, 5,
            6, 7,
            7, 8,
            9, 10
        };
const INT_6_2
    VeryFarRecognizerModelVertexComponentArray[ 27 ] =
        {
            5, 0, 0,
            9, 0, 0,
            9, 12, 0,
            -9, 12, 0,
            -9, 0, 0,
            -5, 0, 0,
            5, 12, 0,
            0, 18, 0,
            -5, 12, 0
        };
const UINT_8
    VeryFarRecognizerModelEdgeVertexIndexArray[ 14 ] =
        {
            0, 1,
            1, 2,
            2, 3,
            3, 4,
            4, 5,
            6, 7,
            7, 8
        };
const INT_6_2
    SuperFarRecognizerModelVertexComponentArray[ 15 ] =
        {
            9, 0, 0,
            9, 12, 0,
            -9, 12, 0,
            -9, 0, 0,
            0, 18, 0
        };
const UINT_8
    SuperFarRecognizerModelEdgeVertexIndexArray[ 10 ] =
        {
            0, 1,
            1, 2,
            2, 3,
            1, 4,
            4, 2
        };
const INT_6_2
    ArrowModelVertexComponentArray[ 9 ] =
        {
            1, 0, 0,
            0, 0, 2,
            -1, 0, 0
        };
const UINT_8
    ArrowModelEdgeVertexIndexArray[ 4 ] =
        {
            0, 1,
            1, 2
        };
const INT_6_2
    FarArrowModelVertexComponentArray[ 6 ] =
        {
            1, 0, 0,
            -1, 0, 0
        };
const UINT_8
    FarArrowModelEdgeVertexIndexArray[ 2 ] =
        {
            0, 1
        };
const INT_6_2
    VeryFarArrowModelVertexComponentArray[ 3 ] =
        {
            0, 0, 0
        };
const UINT_8
    VeryFarArrowModelEdgeVertexIndexArray[ 2 ] =
        {
            0, 0
        },
    ReticleSpriteImageByteArray[ 63 ] =
        {
            0b00000001, 0b10000001, 0b10000000,
            0b00000010, 0b10000001, 0b01000000,
            0b00000100, 0b10000001, 0b00100000,
            0b00001000, 0b10000001, 0b00010000,
            0b00010000, 0b10000001, 0b00001000,
            0b00100000, 0b10000001, 0b00000100,
            0b01000000, 0b00000000, 0b00000010,
            0b10000000, 0b00000000, 0b00000001,
            0b11111100, 0b00000000, 0b00011111,
            0b00000000, 0b00000000, 0b00000000,
            0b00000000, 0b00011000, 0b00000000,
            0b00000000, 0b00000000, 0b00000000,
            0b11111100, 0b00000000, 0b00011111,
            0b10000000, 0b00000000, 0b00000001,
            0b01000000, 0b00000000, 0b00000010,
            0b00100000, 0b10000001, 0b00000100,
            0b00010000, 0b10000001, 0b00001000,
            0b00001000, 0b10000001, 0b00010000,
            0b00000100, 0b10000001, 0b00100000,
            0b00000010, 0b10000001, 0b01000000,
            0b00000001, 0b10000001, 0b10000000
        },
    RadarBackgroundSpriteImageByteArray[ 63 ] =
        {
            0b00011111, 0b11111111, 0b11111111,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000100, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00010000, 0b00000000, 0b00000001,
            0b00011111, 0b11111111, 0b11111111
        };
INT_6_2
    RecognizerTypeSpeedArray[ RecognizerTypeCount ] =
        {
            3, 3, 2, 2
        };
INT_8
    RecognizerTypeEnergyArray[ RecognizerTypeCount ] =
        {
            1, 2, 3, 4
        };
COLOR
    RecognizerTypeColorArray[ RecognizerTypeCount ] =
        {
            COLOR_Red, COLOR_LightRed, COLOR_Orange, COLOR_Purple
        };
INT_8
    RecognizerTypeArray[ RecognizerWaveCount * RecognizerModelCount ] =
        {
            0, 0, 0, -1, -1,
            0, 0, 0, 0, 0,
            0, 0, 0, 1, 1,
            1, 1, 1, 2, 2,
            2, 2, 2, 3, 3,
            3, 3, 3, 3, 3
        };

// -- VARIABLES

UINT_8
    FirstNoteIndex,
    SecondNoteIndex;
INT_8
    ReloadingFrameCount,
    RecognizerWaveIndex;

// -- FUNCTIONS

void RezRecognizer(
    MODEL *recognizer_model,
    INT_6_2 speed,
    INT_8 energy,
    COLOR color
    )
{
    BOOL
        recognizer_model_is_too_close;
    INT_2_6
        y_angle_cosinus,
        y_angle_sinus;
    INT_8
        recognizer_model_y_angle;
    INT_14_2
        recognizer_model_distance,
        recognizer_model_x,
        recognizer_model_y,
        recognizer_model_z;
    UINT_8
        attempt_count;
    MODEL
        *other_recognizer_model;

    attempt_count = 10;

    while ( attempt_count-- )
    {
        recognizer_model_x = GetRandomInteger( 7 );
        recognizer_model_y = 128 + GetRandomNatural( 7 );
        recognizer_model_z = GetRandomInteger( 7 );
        recognizer_model_distance = 400 + GetRandomNatural( 7 );
        recognizer_model_y_angle = GetRandomNatural( 8 );

        GetAngleCosinusSinus( y_angle_cosinus, y_angle_sinus, recognizer_model_y_angle );
        recognizer_model_x += ( y_angle_sinus * recognizer_model_distance ) >> 6;
        recognizer_model_z += ( y_angle_cosinus * recognizer_model_distance ) >> 6;
        recognizer_model_y_angle += -128;

        recognizer_model_is_too_close = GetOriginDistance( recognizer_model_x, recognizer_model_z ) < 10;

        for ( other_recognizer_model = FirstRecognizerModel;
              !recognizer_model_is_too_close
              && other_recognizer_model != PostRecognizerModel;
              ++other_recognizer_model )
        {
            if ( other_recognizer_model->Type == MODEL_TYPE_Recognizer
                 && other_recognizer_model != recognizer_model )
            {
                recognizer_model_is_too_close
                    = ( GetDistance( recognizer_model_x, recognizer_model_z, other_recognizer_model->X, other_recognizer_model->Z ) < 40 );
            }
        }

        if ( !recognizer_model_is_too_close )
        {
            InitializeModel(
                recognizer_model,
                MODEL_TYPE_Recognizer,
                MODEL_STATE_Rezzed,
                true,
                recognizer_model_x,
                recognizer_model_y,
                recognizer_model_z,
                0,
                recognizer_model_y_angle,
                0,
                16,
                RecognizerModelVertexComponentArray,
                39,
                RecognizerModelEdgeVertexIndexArray,
                24,
                30,
                FarRecognizerModelVertexComponentArray,
                33,
                FarRecognizerModelEdgeVertexIndexArray,
                16,
                50,
                VeryFarRecognizerModelVertexComponentArray,
                27,
                VeryFarRecognizerModelEdgeVertexIndexArray,
                14,
                80,
                SuperFarRecognizerModelVertexComponentArray,
                15,
                SuperFarRecognizerModelEdgeVertexIndexArray,
                10,
                RecognizerXRadius,
                RecognizerZRadius,
                speed,
                energy,
                color
                );

            break;
        }
    }
}

// ~~

void RezRecognizers(
    )
{
    INT_8
        recognizer_type;
    UINT_8
        recognizer_model_index;

    if ( RecognizerWaveIndex < RecognizerWaveCount )
    {
        FrameIndex = 0;

        for ( recognizer_model_index = 0;
              recognizer_model_index < RecognizerModelCount;
              ++recognizer_model_index )
        {
            recognizer_type = RecognizerTypeArray[ RecognizerWaveIndex * 5 + recognizer_model_index ];

            if ( recognizer_type >= 0 )
            {
                RezRecognizer(
                    FirstRecognizerModel + recognizer_model_index,
                    RecognizerTypeSpeedArray[ recognizer_type ],
                    RecognizerTypeEnergyArray[ recognizer_type ],
                    RecognizerTypeColorArray[ recognizer_type ]
                    );
            }
        }

        ++RecognizerWaveIndex;
    }
    else
    {
        GameState = GAME_STATE_ShowVictoryScreen;
    }
}

// ~~

void HitRecognizer(
    MODEL *recognizer_model,
    MODEL *arrow_model
    )
{
    recognizer_model->Energy -= arrow_model->Energy;

    if ( recognizer_model->Energy > 0 )
    {
        PlayImpactSound();
    }
    else
    {
        DerezModel( recognizer_model );
        PlayExplosionSound();
    }
}

// ~~

void InitializeLevelScreen(
    )
{
    MODEL
        *recognizer_model;

    InitializeSounds();

    SetSpritesVisibilityMask( 0b00000000 );
    InitializeSprites();
    SetSpriteImage( ReticleSpriteImageIndex, ReticleSpriteImageByteArray, sizeof( ReticleSpriteImageByteArray ) );
    SetSpriteImage( RadarBackgroundSpriteImageIndex, RadarBackgroundSpriteImageByteArray, sizeof( RadarBackgroundSpriteImageByteArray ) );
    SetSpriteImage( RadarSpriteImageIndex, 0, 0 );
    InitializeMountains();
    InitializeSprite( ReticleSpriteIndex, 0xA0, 0x88, 2, 2, COLOR_LightGreen, false );
    InitializeSprite( RadarSpriteIndex, 0x128, 0xD0, 2, 2, COLOR_LightRed, false );
    InitializeSprite( RadarBackgroundSpriteIndex, 0x128, 0xD0, 2, 2, COLOR_LightBlue, false );
    SetSpriteImageIndex( ReticleSpriteIndex, ReticleSpriteImageIndex );
    SetSpriteImageIndex( RadarSpriteIndex, RadarSpriteImageIndex );
    SetSpriteImageIndex( RadarBackgroundSpriteIndex, RadarBackgroundSpriteImageIndex );
    DrawMountains();

    InitializeTank();
    InitializeCamera();
    InitializeGrid();
    InitializeModels();

    FirstArrowModel = ModelArray;
    PostArrowModel = FirstArrowModel + ArrowModelCount;
    FirstRecognizerModel = PostArrowModel;
    PostRecognizerModel = FirstRecognizerModel + RecognizerModelCount;

    for ( recognizer_model = FirstRecognizerModel;
          recognizer_model != PostRecognizerModel;
          ++recognizer_model )
    {
        recognizer_model->DecisionFrameIndex = recognizer_model - FirstRecognizerModel;
    }

    FirstNoteIndex = GetRandomNatural( 7 );
    SecondNoteIndex = GetRandomNatural( 7 );
    ArrowModelIndex = 0;
    ReloadingFrameCount = 0;
    RecognizerWaveIndex = 0;
}

// ~~

void ShootArrow(
    )
{
    MODEL
        *arrow_model;

    PlayShotSound();

    arrow_model = FirstArrowModel + ArrowModelIndex;

    InitializeModel(
        arrow_model,
        MODEL_TYPE_Arrow,
        MODEL_STATE_Attacking,
        false,
        0,
        0,
        12,
        CannonXAngle,
        CannonYAngle,
        0,
        16,
        ArrowModelVertexComponentArray,
        9,
        ArrowModelEdgeVertexIndexArray,
        4,
        15,
        FarArrowModelVertexComponentArray,
        6,
        FarArrowModelEdgeVertexIndexArray,
        2,
        20,
        VeryFarArrowModelVertexComponentArray,
        3,
        VeryFarArrowModelEdgeVertexIndexArray,
        2,
        100,
        VeryFarArrowModelVertexComponentArray,
        3,
        VeryFarArrowModelEdgeVertexIndexArray,
        2,
        ArrowXRadius,
        ArrowZRadius,
        ArrowSpeed,
        ArrowEnergy,
        COLOR_Cyan
        );

    MoveModel( arrow_model );

    ++ArrowModelIndex;

    if ( ArrowModelIndex >= ArrowModelCount )
    {
        ArrowModelIndex = 0;
    }

    ReloadingFrameCount = 4;
}

// ~~

void UpdateLevelInput(
    )
{
    if ( ReloadingFrameCount > 0 )
    {
        --ReloadingFrameCount;
    }

    if ( ( Joystick2State & JoystickStateFireMask )
         && !( OldJoystick2State & JoystickStateFireMask )
         && ReloadingFrameCount == 0 )
    {
        ShootArrow();
    }

    if ( Joystick2State & JoystickStateLeftMask )
    {
        CameraYRotationAngle = 5;
        --MountainXOffset;
    }

    if ( Joystick2State & JoystickStateRightMask )
    {
        CameraYRotationAngle = -5;
        ++MountainXOffset;
    }

    if ( Joystick2State & JoystickStateDownMask )
    {
        CannonXAngle -= 4;

        if ( CannonXAngle <= MinimumCannonXAngle )
        {
            CannonXAngle = MinimumCannonXAngle;
        }
    }

    if ( Joystick2State & JoystickStateUpMask )
    {
        CannonXAngle += 4;

        if ( CannonXAngle >= MaximumCannonXAngle )
        {
            CannonXAngle = MaximumCannonXAngle;
        }
    }

    ClearInput();
}

// ~~

void UpdateLevelMusic(
    )
{
    if ( ( FrameIndex & 0x01 ) == 0 )
    {
        if ( GetRandomNatural( 2 ) )
        {
            FirstNoteIndex = ( FirstNoteIndex + GetRandomNatural( 3 ) ) & 0x7F;
            PlayNote( 0, NoteIndexArray[ FirstNoteIndex ] - 24, 0x0800, 0x10, 0x2D, 0x02 );
        }

        if ( GetRandomNatural( 2 ) )
        {
            SecondNoteIndex = ( SecondNoteIndex + GetRandomNatural( 3 ) ) & 0x7F;
            PlayNote( 1, NoteIndexArray[ SecondNoteIndex ] - 12, 0x0800, 0x10, 0x2D, 0x02 );
        }
    }
}

// ~~

#define GetPositionInterval( _minimum_value_, _maximum_value_, _first_value_, _second_value_, _radius_ ) \
    \
    if ( ( _first_value_ ) <= ( _second_value_ ) ) \
    { \
        _minimum_value_ = ( _first_value_ ) - ( _radius_ ); \
        _maximum_value_ = ( _second_value_ ) + ( _radius_ ); \
    } \
    else \
    { \
        _minimum_value_ = ( _second_value_ ) - ( _radius_ ); \
        _maximum_value_ = ( _first_value_ ) + ( _radius_ ); \
    }

// ~~

BOOL IsArrowHittingRecognizer(
    INT_14_2 arrow_old_position,
    INT_14_2 arrow_new_position,
    INT_8 arrow_radius,
    INT_14_2 recognizer_old_position,
    INT_14_2 recognizer_new_position,
    INT_8 recognizer_radius
    )
{
    INT_14_2
        arrow_minimum_position,
        arrow_maximum_position,
        recognizer_minimum_position,
        recognizer_maximum_position;

    GetPositionInterval( arrow_minimum_position, arrow_maximum_position, arrow_old_position, arrow_new_position, arrow_radius );
    GetPositionInterval( recognizer_minimum_position, recognizer_maximum_position, recognizer_old_position, recognizer_new_position, recognizer_radius );

    return
        arrow_minimum_position <= recognizer_maximum_position
        && recognizer_minimum_position <= arrow_maximum_position;
}

// ~~

void UpdateArrows(
    )
{
    INT_14_2
        recognizer_model_old_x,
        recognizer_model_old_z,
        recognizer_model_x,
        recognizer_model_y,
        recognizer_model_z,
        arrow_model_old_x,
        arrow_model_old_z,
        arrow_model_x,
        arrow_model_y,
        arrow_model_z;
    MODEL
        *arrow_model,
        *recognizer_model;

    for ( arrow_model = FirstArrowModel;
          arrow_model != PostArrowModel;
          ++arrow_model )
    {
        if ( arrow_model->State != MODEL_STATE_None )
        {
            if ( arrow_model->State == MODEL_STATE_Attacking )
            {
                if ( arrow_model->FrameIndex >= 15
                     || arrow_model->Y <= 0 )
                {
                    arrow_model->State = MODEL_STATE_None;
                }
                else
                {
                    if ( arrow_model->FrameIndex >= 4 )
                    {
                        arrow_model->XAngle -= 4;
                    }

                    arrow_model_old_x = arrow_model->OldX >> 2;
                    arrow_model_old_z = arrow_model->OldZ >> 2;
                    arrow_model_x = arrow_model->X >> 2;
                    arrow_model_y = arrow_model->Y >> 2;
                    arrow_model_z = arrow_model->Z >> 2;

                    for ( recognizer_model = FirstRecognizerModel;
                          recognizer_model != PostRecognizerModel;
                          ++recognizer_model )
                    {
                        if ( recognizer_model->State > MODEL_STATE_Derezzed )
                        {
                            recognizer_model_old_x = recognizer_model->OldX >> 2;
                            recognizer_model_old_z = recognizer_model->OldZ >> 2;
                            recognizer_model_x = recognizer_model->X >> 2;
                            recognizer_model_y = recognizer_model->Y >> 2;
                            recognizer_model_z = recognizer_model->Z >> 2;

                            if ( IsArrowHittingRecognizer(
                                     arrow_model_old_x,
                                     arrow_model_x,
                                     ArrowXRadius,
                                     recognizer_model_old_x,
                                     recognizer_model_x,
                                     RecognizerXRadius
                                     )
                                 && IsArrowHittingRecognizer(
                                     arrow_model_old_z,
                                     arrow_model_z,
                                     ArrowZRadius,
                                     recognizer_model_old_z,
                                     recognizer_model_z,
                                     RecognizerZRadius
                                     )
                                 && arrow_model_y >= recognizer_model_y
                                 && arrow_model_y <= recognizer_model_y + RecognizerHeight )
                            {
                                arrow_model->State = MODEL_STATE_None;
                                HitRecognizer( recognizer_model, arrow_model );

                                break;
                            }
                        }
                    }
                }
            }
            else if ( arrow_model->State == MODEL_STATE_Exploding )
            {
                if ( arrow_model->FrameIndex < 2 )
                {
                    ++arrow_model->Scale;
                }
                else
                {
                    arrow_model->State = MODEL_STATE_None;
                }
            }
        }
    }
}

// ~~

void UpdateRecognizers(
    )
{
    MODEL
        *recognizer_model;
    UINT_8
        recognizer_count;
    UINT_14_2
        recognizer_distance;

    recognizer_count = 0;

    for ( recognizer_model = FirstRecognizerModel;
          recognizer_model != PostRecognizerModel;
          ++recognizer_model )
    {
        if ( recognizer_model->State != MODEL_STATE_None )
        {
            ++recognizer_count;

            if ( recognizer_model->State == MODEL_STATE_Rezzed )
            {
                recognizer_model->State = MODEL_STATE_Landing;
                SetModelFinalY( recognizer_model, 0, RecognizerLandingSpeed );
            }
            else if ( recognizer_model->State == MODEL_STATE_Landing )
            {
                if ( !recognizer_model->HasFinalY )
                {
                    recognizer_model->State = MODEL_STATE_Attacking;
                    MoveModel( recognizer_model );
                }
            }
            else if ( recognizer_model->State == MODEL_STATE_Attacking )
            {
                if ( ( FrameIndex & DecisionFrameMask ) == recognizer_model->DecisionFrameIndex )
                {
                    recognizer_distance = GetOriginDistance( recognizer_model->X, recognizer_model->Z );

                    if ( recognizer_distance > RecognizerAttackDistance )
                    {
                        TurnModel( recognizer_model, 0, 0, RecognizerTurnSpeed );
                        recognizer_model->HasFinalXZ = false;
                    }
                    else if ( recognizer_distance > RecognizerVictoryDistance )
                    {
                        SetModelFinalXZ( recognizer_model, 0, 0, RecognizerMotionSpeed );
                        recognizer_model->IsMoving = false;
                    }
                    else
                    {
                        GameState = GAME_STATE_ShowDefeatScreen;
                    }
                }
            }
            else if ( recognizer_model->State == MODEL_STATE_Derezzed )
            {
                if ( recognizer_model->FrameIndex >= 4 )
                {
                    recognizer_model->State = MODEL_STATE_None;
                }
            }
        }
    }

    if ( recognizer_count == 0 )
    {
        RezRecognizers();
    }
}

// ~~

void DrawRadar(
    )
{
    INT_8
        pixel_x,
        pixel_y;
    volatile UINT_8
        *radar_sprite_image_byte_array;
    UINT_8
        radar_sprite_image_byte_index;
    MODEL
        *recognizer_model;

    radar_sprite_image_byte_array = GetSpriteImageByteArray( RadarSpriteImageIndex );

    for ( recognizer_model = FirstRecognizerModel;
          recognizer_model != PostRecognizerModel;
          ++recognizer_model )
    {
        radar_sprite_image_byte_array[ recognizer_model->RadarSpriteImageByteIndex ] = 0;
    }

    for ( recognizer_model = FirstRecognizerModel;
          recognizer_model != PostRecognizerModel;
          ++recognizer_model )
    {
        radar_sprite_image_byte_index = 0;

        if ( recognizer_model->State != MODEL_STATE_None )
        {
            pixel_x = 13 + ( ( recognizer_model->X + 32 ) >> 6 );
            pixel_y = 10 - ( ( recognizer_model->Z + 32 ) >> 6 );

            if ( pixel_x < 3 )
            {
                pixel_x = 3;
            }
            else if ( pixel_x > 20 )
            {
                pixel_x = 20;
            }

            if ( pixel_y < 0 )
            {
                pixel_y = 0;
            }
            else if ( pixel_y > 20 )
            {
                pixel_y = 20;
            }

            radar_sprite_image_byte_index = pixel_y * 3 + ( pixel_x >> 3 );

            DisableInterrupts();
            RamConfiguration = 0x30;
            radar_sprite_image_byte_array[ radar_sprite_image_byte_index ] |= 0x80 >> ( pixel_x & 7 );
            RamConfiguration = 0x37;
            EnableInterrupts();
        }

        recognizer_model->RadarSpriteImageByteIndex = radar_sprite_image_byte_index;
    }
}

// ~~

void DrawReticle(
    )
{
    UINT_16
        reticle_sprite_x;
    UINT_8
        reticle_sprite_y;

    reticle_sprite_x = 0xA0;
    reticle_sprite_y = 0xA0 - ( CannonXAngle - MinimumCannonXAngle ) * 2;

    SetSpriteXPosition( ReticleSpriteIndex, reticle_sprite_x );
    SetSpriteYPosition( ReticleSpriteIndex, reticle_sprite_y );
}

// ~~

void ShowLevelScreen(
    )
{
    InitializeLevelScreen();

    for ( FrameIndex = 0;
          GameState == GAME_STATE_ShowLevelScreen;
          ++FrameIndex )
    {
        UpdateLevelInput();
        UpdateLevelMusic();

        ClearBuffer();
        UpdateTank();
        UpdateModels();
        UpdateArrows();
        UpdateRecognizers();
        DrawGrid();
        DrawModels();
        DrawRadar();
        DrawReticle();
        DrawMountains();

        if ( FrameIndex < 6 )
        {
            DrawPixelNatural( ( RecognizerWaveIndex < 10 ) ? 30 : 28, 10, "WAVE ", RecognizerWaveIndex, COLOR_Yellow );
        }

        CopyBuffer();
        SetSpritesVisibilityMask( 0b1111111 );
    }
}

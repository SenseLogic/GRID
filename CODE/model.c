/*
    Axes : +X right, +Y up, +Z forward
    X rotation : +Z towards +Y
    Y rotation : +Z towards +X
    Z rotation : +Y towards +X
*/

// -- IMPORTS

#include "base.h"
#include "model.h"

// -- CONSTANTS

const INT_16
    DepthFactorArray[ DepthFactorCount ] =
        {
            513, 342, 257, 205, 171, 147, 128, 114, 103, 93, 86, 79, 73, 68, 64, 60, 57, 54, 51, 49, 47, 45, 43, 41, 39, 38, 37, 35, 34, 33, 32, 31,
            30, 29, 29, 28, 27, 26, 26, 25, 24, 24, 23, 23, 22, 22, 21, 21, 21, 20, 20, 19, 19, 19, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16,
            16, 15, 15, 15, 15, 14, 14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11,
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8,
            8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6,
            6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
            5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
            3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
            2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
        };

// -- VARIABLES

MODEL
    ModelArray[ ModelCount ],
    *FirstRecognizerModel,
    *PostRecognizerModel,
    *FirstArrowModel,
    *PostArrowModel;
UINT_8
    ArrowModelIndex;

// -- FUNCTIONS

void InitializeModels(
    )
{
    MODEL
        *model,
        *post_model;

    post_model = ModelArray + ModelCount;

    for ( model = ModelArray;
          model != post_model;
          ++model )
    {
        model->Type = MODEL_TYPE_None;
        model->State = MODEL_STATE_None;
    }
}

// ~~

void InitializeModel(
    MODEL *model,
    MODEL_TYPE type,
    MODEL_STATE state,
    BOOL model_is_facing_camera,
    INT_14_2 x,
    INT_14_2 y,
    INT_14_2 z,
    INT_8 x_angle,
    INT_8 y_angle,
    INT_8 z_angle,
    INT_4_4 scale,
    const INT_6_2 *vertex_component_array,
    UINT_8 vertex_component_count,
    const UINT_8 *edge_vertex_index_array,
    UINT_8 edge_vertex_index_count,
    INT_8 far_distance,
    const INT_6_2 *far_vertex_component_array,
    UINT_8 far_vertex_component_count,
    const UINT_8 *far_edge_vertex_index_array,
    UINT_8 far_edge_vertex_index_count,
    INT_8 very_far_distance,
    const INT_6_2 *very_far_vertex_component_array,
    UINT_8 very_far_vertex_component_count,
    const UINT_8 *very_far_edge_vertex_index_array,
    UINT_8 very_far_edge_vertex_index_count,
    INT_8 super_far_distance,
    const INT_6_2 *super_far_vertex_component_array,
    UINT_8 super_far_vertex_component_count,
    const UINT_8 *super_far_edge_vertex_index_array,
    UINT_8 super_far_edge_vertex_index_count,
    UINT_6_2 x_radius,
    UINT_6_2 z_radius,
    INT_6_2 speed,
    INT_8 energy,
    COLOR color
    )
{
    model->Type = type;
    model->State = state;
    model->IsFacingCamera = model_is_facing_camera;
    model->OldX = x;
    model->OldY = y;
    model->OldZ = z;
    model->X = x;
    model->Y = y;
    model->Z = z;
    model->XAngle = x_angle;
    model->YAngle = y_angle;
    model->ZAngle = z_angle;
    model->Scale = scale;
    model->OldVertexComponentArray = 0;
    model->VertexComponentArray = vertex_component_array;
    model->VertexComponentCount = vertex_component_count;
    model->EdgeVertexIndexArray = edge_vertex_index_array;
    model->EdgeVertexIndexCount = edge_vertex_index_count;
    model->FarDistance = far_distance;
    model->FarVertexComponentArray = far_vertex_component_array;
    model->FarVertexComponentCount = far_vertex_component_count;
    model->FarEdgeVertexIndexArray = far_edge_vertex_index_array;
    model->FarEdgeVertexIndexCount = far_edge_vertex_index_count;
    model->VeryFarDistance = very_far_distance;
    model->VeryFarVertexComponentArray = very_far_vertex_component_array;
    model->VeryFarVertexComponentCount = very_far_vertex_component_count;
    model->VeryFarEdgeVertexIndexArray = very_far_edge_vertex_index_array;
    model->VeryFarEdgeVertexIndexCount = very_far_edge_vertex_index_count;
    model->SuperFarDistance = super_far_distance;
    model->SuperFarVertexComponentArray = super_far_vertex_component_array;
    model->SuperFarVertexComponentCount = super_far_vertex_component_count;
    model->SuperFarEdgeVertexIndexArray = super_far_edge_vertex_index_array;
    model->SuperFarEdgeVertexIndexCount = super_far_edge_vertex_index_count;
    model->HasCache = false;
    model->CacheXAngle = 0;
    model->CacheYAngle = 0;
    model->XRadius = x_radius;
    model->ZRadius = z_radius;
    model->Speed = speed;
    model->OldEnergy = energy;
    model->Energy = energy;
    model->Color = color;
    model->IsDrawn = false;
    model->IsMoving = false;
    model->HasFinalXZ = false;
    model->HasFinalY = false;
    model->FinalX = 0;
    model->FinalY = 0;
    model->FinalZ = 0;
    model->FinalXZSpeed = 0;
    model->FinalYSpeed = 0;
    model->HasFinalYAngle = false;
    model->FinalYAngle = 0;
    model->FinalYAngleSpeed = 0;
    model->IsDerezzed = false;
    model->FrameIndex = 0;
    model->DecisionFrameIndex = 0;
    model->RadarSpriteImageByteIndex = 0;
}

// ~~

void SetModelFinalXZ(
    MODEL *model,
    INT_14_2 final_x,
    INT_14_2 final_z,
    INT_6_2 final_xz_speed
    )
{
    model->HasFinalXZ = ( model->X != final_x || model->Z != final_z );
    model->FinalX = final_x;
    model->FinalZ = final_z;
    model->FinalXZSpeed = final_xz_speed;
}

// ~~

void SetModelFinalY(
    MODEL *model,
    INT_14_2 final_y,
    INT_6_2 final_y_speed
    )
{
    model->HasFinalY = ( model->Y != final_y );
    model->FinalY = final_y;
    model->FinalYSpeed = final_y_speed;
}

// ~~

void SetModelFinalYAngle(
    MODEL *model,
    INT_8 final_y_angle,
    INT_8 final_y_angle_speed
    )
{
    model->HasFinalYAngle = ( model->YAngle != final_y_angle );
    model->FinalYAngle = final_y_angle;
    model->FinalYAngleSpeed = final_y_angle_speed;
}

// ~~

void MoveModel(
    MODEL *model
    )
{
    model->IsMoving = true;
}

// ~~

void TurnModel(
    MODEL *model,
    INT_14_2 x,
    INT_14_2 z,
    INT_8 final_y_angle_speed
    )
{
    SetModelFinalYAngle(
        model,
        GetYAngle( x - model->X, z - model->Z ),
        final_y_angle_speed
        );
}

// ~~

void DerezModel(
    MODEL *model
    )
{
    model->State = MODEL_STATE_Derezzed;
    model->IsDerezzed = true;
    model->IsMoving = false;
    model->HasFinalXZ = false;
    model->HasFinalY = false;
    model->HasFinalYAngle = false;
    model->FrameIndex = 0;
}

// ~~

void UpdateModels(
    )
{
    INT_8
        camera_y_rotation_angle,
        model_y_angle,
        model_y_angle_offset,
        model_final_y_angle_speed;
    INT_6_2
        model_final_x_speed,
        model_final_y_speed,
        model_final_z_speed,
        model_speed;
    INT_2_6
        x_angle_sinus,
        y_angle_cosinus,
        y_angle_sinus;
    INT_14_2
        model_x_offset,
        model_y_offset,
        model_z_offset,
        tank_x,
        tank_z;
    MODEL
        *model,
        *post_model;

    tank_x = TankX;
    tank_z = TankZ;

    post_model = ModelArray + ModelCount;

    for ( model = ModelArray;
          model != post_model;
          ++model )
    {
        if ( model->State != MODEL_STATE_None )
        {
            model->OldX = model->X;
            model->OldY = model->Y;
            model->OldZ = model->Z;

            if ( model->IsMoving )
            {
                x_angle_sinus = GetAngleSinus( model->XAngle );
                model_y_angle = model->YAngle;
                GetAngleCosinusSinus( y_angle_cosinus, y_angle_sinus, model_y_angle );

                model_speed = model->Speed;
                model->X += ( y_angle_sinus * model_speed ) >> 6;
                model->Y += ( x_angle_sinus * model_speed ) >> 6;
                model->Z += ( y_angle_cosinus * model_speed ) >> 6;
            }

            if ( model->HasFinalYAngle )
            {
                model_y_angle_offset = model->FinalYAngle - model->YAngle;

                if ( model_y_angle_offset != 0 )
                {
                    model_final_y_angle_speed = model->FinalYAngleSpeed;

                    if ( model_y_angle_offset < -model_final_y_angle_speed )
                    {
                        model_y_angle_offset = -model_final_y_angle_speed;
                    }
                    else if ( model_y_angle_offset > model_final_y_angle_speed )
                    {
                        model_y_angle_offset = model_final_y_angle_speed;
                    }

                    model->YAngle += model_y_angle_offset;
                }
                else
                {
                    model->HasFinalYAngle = false;
                }
            }

            if ( model->HasFinalXZ )
            {
                model_x_offset = model->FinalX - model->X;

                if ( model_x_offset != 0 )
                {
                    model_final_x_speed = model->FinalXZSpeed;

                    if ( model_x_offset < -model_final_x_speed )
                    {
                        model_x_offset = -model_final_x_speed;
                    }
                    else if ( model_x_offset > model_final_x_speed )
                    {
                        model_x_offset = model_final_x_speed;
                    }

                    model->X += model_x_offset;
                }

                model_z_offset = model->FinalZ - model->Z;

                if ( model_z_offset != 0 )
                {
                    model_final_z_speed = model->FinalXZSpeed;

                    if ( model_z_offset < -model_final_z_speed )
                    {
                        model_z_offset = -model_final_z_speed;
                    }
                    else if ( model_z_offset > model_final_z_speed )
                    {
                        model_z_offset = model_final_z_speed;
                    }

                    model->Z += model_z_offset;
                }

                if ( model_x_offset == 0
                     && model_z_offset == 0 )
                {
                    model->HasFinalXZ = false;
                }
            }

            if ( model->HasFinalY )
            {
                model_y_offset = model->FinalY - model->Y;

                if ( model_y_offset != 0 )
                {
                    model_final_y_speed = model->FinalYSpeed;

                    if ( model_y_offset < -model_final_y_speed )
                    {
                        model_y_offset = -model_final_y_speed;
                    }
                    else if ( model_y_offset > model_final_y_speed )
                    {
                        model_y_offset = model_final_y_speed;
                    }

                    model->Y += model_y_offset;
                }
                else
                {
                    model->HasFinalY = false;
                }
            }

            ++model->FrameIndex;
            model->X -= tank_x;
            model->Z -= tank_z;

            ClampInteger( model->X, -1024, 1023 );
            ClampInteger( model->Z, -1024, 1023 );
        }
    }

    GridX = ( GridX + tank_x ) & GridMask;
    GridZ = ( GridZ + tank_z ) & GridMask;

    TankX = 0;
    TankZ = 0;

    camera_y_rotation_angle = CameraYRotationAngle;

    if ( camera_y_rotation_angle != 0 )
    {
        for ( model = ModelArray;
              model != post_model;
              ++model )
        {
            if ( model->State != MODEL_STATE_None )
            {
                RotatePosition( &model->X, &model->Z, camera_y_rotation_angle );

                if ( model->HasFinalXZ )
                {
                    RotatePosition( &model->FinalX, &model->FinalZ, camera_y_rotation_angle );
                }

                model->YAngle += camera_y_rotation_angle;
                model->FinalYAngle += camera_y_rotation_angle;
            }
        }

        CameraYRotationAngle = 0;
    }
}

// ~~

#define IsInsideCameraFrustum( _half_model_x_, _model_z_, _model_x_radius_, _model_z_radius_ ) \
    \
    ( _model_z_ >= _model_z_radius_ \
      && _model_z_ <= 2047 \
      && _half_model_x_ + _model_x_radius_ >= -( _model_z_ ) \
      && _half_model_x_ - _model_x_radius_ <= _model_z_ ) \

// ~~

#define GetModelData( _model_vertex_component_array_, _model_vertex_component_count_, _model_edge_vertex_index_array_, _model_edge_vertex_index_count_, _model_, _model_z_ ) \
    \
    if ( _model_z_ < _model_->FarDistance ) \
    { \
        _model_vertex_component_array_ = _model_->VertexComponentArray; \
        _model_vertex_component_count_ = _model_->VertexComponentCount; \
        _model_edge_vertex_index_array_ = _model_->EdgeVertexIndexArray; \
        _model_edge_vertex_index_count_ = _model_->EdgeVertexIndexCount; \
    } \
    else if ( _model_z_ < _model_->VeryFarDistance ) \
    { \
        _model_vertex_component_array_ = _model_->FarVertexComponentArray; \
        _model_vertex_component_count_ = _model_->FarVertexComponentCount; \
        _model_edge_vertex_index_array_ = _model_->FarEdgeVertexIndexArray; \
        _model_edge_vertex_index_count_ = _model_->FarEdgeVertexIndexCount; \
    } \
    else if ( _model_z_ < _model_->SuperFarDistance ) \
    { \
        _model_vertex_component_array_ = _model_->VeryFarVertexComponentArray; \
        _model_vertex_component_count_ = _model_->VeryFarVertexComponentCount; \
        _model_edge_vertex_index_array_ = _model_->VeryFarEdgeVertexIndexArray; \
        _model_edge_vertex_index_count_ = _model_->VeryFarEdgeVertexIndexCount; \
    } \
    else \
    { \
        _model_vertex_component_array_ = _model_->SuperFarVertexComponentArray; \
        _model_vertex_component_count_ = _model_->SuperFarVertexComponentCount; \
        _model_edge_vertex_index_array_ = _model_->SuperFarEdgeVertexIndexArray; \
        _model_edge_vertex_index_count_ = _model_->SuperFarEdgeVertexIndexCount; \
    }

// ~~

void DrawCameraFacingModel(
    MODEL *model
    )
{
    BOOL
        model_is_derezzed,
        model_is_drawn;
    INT_2_6
        z_angle_sinus,
        z_angle_cosinus;
    INT_4_4
        model_scale;
    INT_6_2
        rotated_vertex_x,
        rotated_vertex_y;
    const INT_6_2
        *model_vertex_component_array,
        *post_vertex,
        *vertex;
    INT_8
        *first_screen_vertex,
        first_vertex_index,
        model_x_radius,
        model_z_angle,
        model_z_radius,
        *screen_vertex,
        *screen_vertex_component_array,
        *second_screen_vertex,
        second_vertex_index,
        vertex_x,
        vertex_y;
    INT_16
        depth_factor,
        half_model_x,
        model_x,
        model_y,
        model_z,
        screen_vertex_x,
        screen_vertex_y;
    UINT_8
        model_color,
        model_edge_vertex_index_count,
        model_vertex_component_count;
    const UINT_8
        *edge_vertex_index,
        *model_edge_vertex_index_array,
        *post_edge_vertex_index;

    model_is_drawn = false;
    model_x = model->X >> 2;
    model_y = ( model->Y - CameraY ) >> 2;
    model_z = model->Z >> 2;

    half_model_x = model_x >> 1;
    model_x_radius = model->XRadius;
    model_z_radius = model->ZRadius;

    if ( IsInsideCameraFrustum( half_model_x, model_z, model_x_radius, model_z_radius ) )
    {
        model_is_drawn = true;
        screen_vertex_component_array = model->ScreenVertexComponentArray;
        screen_vertex_x = GetPixelX( model_x, model_z );
        screen_vertex_y = GetPixelY( model_y, model_z );

        if ( screen_vertex_x > -128
             && screen_vertex_x < 127
             && screen_vertex_y > -128
             && screen_vertex_y < 127 )
        {
            model_is_drawn = true;
            model_is_derezzed = model->IsDerezzed;

            if ( model_z < DepthFactorCount )
            {
                depth_factor = DepthFactorArray[ model_z ];
            }
            else
            {
                depth_factor = 1;
            }

            model_z_angle = model->ZAngle;

            if ( model_z_angle != 0 )
            {
                GetAngleCosinusSinus( z_angle_cosinus, z_angle_sinus, model_z_angle );
            }

            model_scale = model->Scale;

            GetModelData( model_vertex_component_array, model_vertex_component_count, model_edge_vertex_index_array, model_edge_vertex_index_count, model, model_z );

            vertex = model_vertex_component_array;
            post_vertex = model_vertex_component_array + model_vertex_component_count;
            screen_vertex = screen_vertex_component_array;

            while ( vertex != post_vertex )
            {
                vertex_x = *vertex;
                vertex_y = vertex[ 1 ];

                if ( model_is_derezzed )
                {
                    vertex_x += GetRandomInteger( 2 );
                    vertex_y += GetRandomInteger( 2 );
                }

                if ( model_z_angle == 0 )
                {
                    if ( model_scale != 8 )
                    {
                        vertex_x = ( vertex_x * model_scale ) >> 4;
                        vertex_y = ( vertex_y * model_scale ) >> 4;
                    }

                    *screen_vertex++ = screen_vertex_x - ( ( vertex_x * depth_factor ) >> 6 );
                    *screen_vertex++ = screen_vertex_y - ( ( vertex_y * depth_factor ) >> 5 );
                    *screen_vertex++ = model_z;
                }
                else
                {
                    rotated_vertex_x = ( ( vertex_x * z_angle_cosinus ) >> 6 ) + ( ( vertex_y * z_angle_sinus ) >> 6 );
                    rotated_vertex_y = ( ( vertex_y * z_angle_cosinus ) >> 6 ) - ( ( vertex_x * z_angle_sinus ) >> 6 );

                    if ( model_scale != 8 )
                    {
                        rotated_vertex_x = ( rotated_vertex_x * model_scale ) >> 4;
                        rotated_vertex_y = ( rotated_vertex_y * model_scale ) >> 4;
                    }

                    *screen_vertex++ = screen_vertex_x - ( ( rotated_vertex_x * depth_factor ) >> 6 );
                    *screen_vertex++ = screen_vertex_y - ( ( rotated_vertex_y * depth_factor ) >> 5 );
                    *screen_vertex++ = model_z;
                }

                vertex += 3;
            }

            if ( model->Energy < model->OldEnergy )
            {
                model->OldEnergy = model->Energy;
                model_color = COLOR_Yellow;
            }
            else
            {
                model_color = model->Color;
            }

            edge_vertex_index = model_edge_vertex_index_array;
            post_edge_vertex_index = edge_vertex_index + model_edge_vertex_index_count;

            while ( edge_vertex_index != post_edge_vertex_index )
            {
                first_vertex_index = *edge_vertex_index++;
                second_vertex_index = *edge_vertex_index++;

                first_screen_vertex = screen_vertex_component_array + ( first_vertex_index * 3 );
                second_screen_vertex = screen_vertex_component_array + ( second_vertex_index * 3 );

                DrawPixelLine(
                    *first_screen_vertex,
                    first_screen_vertex[ 1 ],
                    *second_screen_vertex,
                    second_screen_vertex[ 1 ],
                    model_color
                    );
            }
        }
    }

    model->IsDrawn = model_is_drawn;
}

// ~~

void DrawModel(
    MODEL *model
    )
{
    BOOL
        model_has_cache,
        model_is_drawn;
    INT_2_6
        x_angle_sinus,
        x_angle_cosinus,
        y_angle_sinus,
        y_angle_cosinus;
    INT_6_2
        *rotated_vertex,
        rotated_vertex_x,
        rotated_vertex_y,
        rotated_vertex_z,
        vertex_x,
        vertex_y,
        vertex_z;
    const INT_6_2
        *model_vertex_component_array,
        *post_vertex,
        *vertex;
    INT_8
        *first_screen_vertex,
        first_vertex_index,
        model_x_angle,
        model_x_radius,
        model_y_angle,
        model_z_radius,
        *screen_vertex,
        *screen_vertex_component_array,
        *second_screen_vertex,
        second_vertex_index;
    INT_16
        half_model_x,
        model_x,
        model_y,
        model_z,
        screen_vertex_x,
        screen_vertex_y,
        screen_vertex_z,
        view_vertex_x,
        view_vertex_y,
        view_vertex_z;
    UINT_8
        model_color,
        model_edge_vertex_index_count,
        model_vertex_component_count;
    const UINT_8
        *model_edge_vertex_index_array,
        *edge_vertex_index,
        *post_edge_vertex_index;

    model_is_drawn = false;
    model_x = model->X >> 2;
    model_y = ( model->Y - CameraY ) >> 2;
    model_z = model->Z >> 2;

    half_model_x = model_x >> 1;
    model_x_radius = model->XRadius;
    model_z_radius = model->ZRadius;

    if ( IsInsideCameraFrustum( half_model_x, model_z, model_x_radius, model_z_radius ) )
    {
        model_x_angle = model->XAngle;

        if ( model_x_angle != 0 )
        {
            GetAngleCosinusSinus( x_angle_cosinus, x_angle_sinus, model_x_angle );
        }

        model_y_angle = model->YAngle;

        if ( model_y_angle != 0 )
        {
            GetAngleCosinusSinus( y_angle_cosinus, y_angle_sinus, model_y_angle );
        }

        GetModelData( model_vertex_component_array, model_vertex_component_count, model_edge_vertex_index_array, model_edge_vertex_index_count, model, model_z );

        model_has_cache = model->HasCache;

        if ( model_has_cache
             && ( model_y_angle != model->CacheYAngle
                  || model_x_angle != model->CacheXAngle
                  || model->OldVertexComponentArray != model_vertex_component_array ) )
        {
            model_has_cache = false;
        }

        model->OldVertexComponentArray = model_vertex_component_array;
        vertex = model_vertex_component_array;
        post_vertex = model_vertex_component_array + model_vertex_component_count;
        rotated_vertex = model->RotatedVertexComponentArray;
        screen_vertex = model->ScreenVertexComponentArray;

        while ( vertex != post_vertex )
        {
            if ( model_has_cache )
            {
                view_vertex_x = model_x + *rotated_vertex++;
                view_vertex_y = model_y + *rotated_vertex++;
                view_vertex_z = model_z + *rotated_vertex++;
            }
            else
            {
                vertex_x = *vertex;
                vertex_y = vertex[ 1 ];
                vertex_z = vertex[ 2 ];

                if ( model_x_angle != 0 )
                {
                    rotated_vertex_y = ( ( vertex_y * x_angle_cosinus ) >> 6 ) + ( ( vertex_z * x_angle_sinus ) >> 6 );
                    rotated_vertex_z = ( ( vertex_z * x_angle_cosinus ) >> 6 ) - ( ( vertex_y * x_angle_sinus ) >> 6 );
                }
                else
                {
                    rotated_vertex_y = vertex_y;
                    rotated_vertex_z = vertex_z;
                }

                if ( model_y_angle != 0 )
                {
                    rotated_vertex_x = ( ( vertex_x * y_angle_cosinus ) >> 6 ) + ( ( rotated_vertex_z * y_angle_sinus ) >> 6 );
                    rotated_vertex_z = ( ( rotated_vertex_z * y_angle_cosinus ) >> 6 ) - ( ( vertex_x * y_angle_sinus ) >> 6 );
                }
                else
                {
                    rotated_vertex_x = vertex_x;
                }

                *rotated_vertex++ = rotated_vertex_x;
                *rotated_vertex++ = rotated_vertex_y;
                *rotated_vertex++ = rotated_vertex_z;

                view_vertex_x = model_x + rotated_vertex_x;
                view_vertex_y = model_y + rotated_vertex_y;
                view_vertex_z = model_z + rotated_vertex_z;
            }

            if ( view_vertex_x >= -1535
                 && view_vertex_x <= 1535
                 && view_vertex_y >= -1023
                 && view_vertex_y <= 1023
                 && view_vertex_z >= 1
                 && view_vertex_z <= 2047 )
            {
                screen_vertex_x = GetPixelX( view_vertex_x, view_vertex_z );
                screen_vertex_y = GetPixelY( view_vertex_y, view_vertex_z );
                screen_vertex_z = view_vertex_z;

                if ( screen_vertex_x > -128
                     && screen_vertex_x < 127
                     && screen_vertex_y > -128
                     && screen_vertex_y < 127
                     && screen_vertex_z > 0 )
                {
                    *screen_vertex++ = screen_vertex_x;
                    *screen_vertex++ = screen_vertex_y;
                    *screen_vertex++ = screen_vertex_z;

                    model_is_drawn = true;
                }
                else
                {
                    *screen_vertex++ = -128;
                    *screen_vertex++ = -128;
                    *screen_vertex++ = -128;
                }
            }

            vertex += 3;
        }

        model->HasCache = true;
        model->CacheXAngle = model_x_angle;
        model->CacheYAngle = model_y_angle;

        if ( model_is_drawn )
        {
            model_color = model->Color;

            screen_vertex_component_array = model->ScreenVertexComponentArray;
            edge_vertex_index = model_edge_vertex_index_array;
            post_edge_vertex_index = edge_vertex_index + model_edge_vertex_index_count;

            while ( edge_vertex_index != post_edge_vertex_index )
            {
                first_vertex_index = *edge_vertex_index++;
                second_vertex_index = *edge_vertex_index++;

                first_screen_vertex = screen_vertex_component_array + ( first_vertex_index * 3 );
                second_screen_vertex = screen_vertex_component_array + ( second_vertex_index * 3 );

                if ( *first_screen_vertex != -128
                     && *second_screen_vertex != -128
                     && !( ( *first_screen_vertex < 0
                              && *second_screen_vertex < 0 )
                            || ( *first_screen_vertex >= 80
                                 && *second_screen_vertex >= 80 )
                            || ( first_screen_vertex[ 1 ] < 0
                                 && second_screen_vertex[ 1 ] < 0 )
                            || ( first_screen_vertex[ 1 ] >= 100
                                 && second_screen_vertex[ 1 ] >= 100 ) ) )
                {
                     DrawPixelLine(
                        *first_screen_vertex,
                        first_screen_vertex[ 1 ],
                        *second_screen_vertex,
                        second_screen_vertex[ 1 ],
                        model_color
                        );
                }
            }
        }
    }

    model->IsDrawn = model_is_drawn;
}

// ~~

void DrawModels(
    )
{
    MODEL
        *model,
        *post_model;

    model = ModelArray;
    post_model = ModelArray + ModelCount;

    while ( model != post_model )
    {
        if ( model->State != MODEL_STATE_None )
        {
            if ( model->IsFacingCamera )
            {
                DrawCameraFacingModel( model );
            }
            else
            {
                DrawModel( model );
            }
        }

        ++model;
    }
}

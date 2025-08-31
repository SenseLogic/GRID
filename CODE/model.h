#ifndef __MODEL_H__
    #define __MODEL_H__

    // -- IMPORTS

    #include "base.h"
    #include "base.h"

    // -- CONSTANTS

    #define MaximumVertexComponentCount    39

    #define RecognizerModelCount    5
    #define ArrowModelCount    3
    #define ModelCount    8

    #define DecisionFrameMask    3
    #define DepthFactorCount    704

    // -- TYPES

    #define MODEL_TYPE    UINT_8
    #define MODEL_TYPE_None    0x00
    #define MODEL_TYPE_Recognizer    0x01
    #define MODEL_TYPE_Arrow    0x02

    // ~~

    #define MODEL_STATE    UINT_8
    #define MODEL_STATE_None    0x00
    #define MODEL_STATE_Derezzed    0x01
    #define MODEL_STATE_Rezzed    0x02
    #define MODEL_STATE_Landing    0x03
    #define MODEL_STATE_Attacking   0x04
    #define MODEL_STATE_Exploding    0x05

    // ~~

    typedef
        struct MODEL_
        {
            MODEL_TYPE
                Type;
            MODEL_STATE
                State;
            BOOL
                IsFacingCamera;
            INT_14_2
                OldX,
                OldY,
                OldZ,
                X,
                Y,
                Z;
            INT_8
                XAngle,
                YAngle,
                ZAngle;
            INT_4_4
                Scale;
            const INT_6_2
                *OldVertexComponentArray,
                *VertexComponentArray;
            UINT_8
                VertexComponentCount;
            const UINT_8
                *EdgeVertexIndexArray;
            UINT_8
                EdgeVertexIndexCount;
            INT_8
                FarDistance;
            const INT_6_2
                *FarVertexComponentArray;
            UINT_8
                FarVertexComponentCount;
            const UINT_8
                *FarEdgeVertexIndexArray;
            UINT_8
                FarEdgeVertexIndexCount;
            INT_8
                VeryFarDistance;
            const INT_6_2
                *VeryFarVertexComponentArray;
            UINT_8
                VeryFarVertexComponentCount;
            const UINT_8
                *VeryFarEdgeVertexIndexArray;
            UINT_8
                VeryFarEdgeVertexIndexCount;
            INT_8
                SuperFarDistance;
            const INT_6_2
                *SuperFarVertexComponentArray;
            UINT_8
                SuperFarVertexComponentCount;
            const UINT_8
                *SuperFarEdgeVertexIndexArray;
            UINT_8
                SuperFarEdgeVertexIndexCount;
            BOOL
                HasCache;
            INT_8
                CacheXAngle,
                CacheYAngle;
            INT_6_2
                RotatedVertexComponentArray[ MaximumVertexComponentCount ],
                ScreenVertexComponentArray[ MaximumVertexComponentCount ];
            INT_6_2
                XRadius,
                ZRadius,
                Speed;
            INT_8
                OldEnergy,
                Energy;
            UINT_8
                Color;
            BOOL
                IsDrawn,
                IsMoving;
            BOOL
                HasFinalXZ,
                HasFinalY;
            INT_14_2
                FinalX,
                FinalY,
                FinalZ;
            INT_6_2
                FinalXZSpeed,
                FinalYSpeed;
            BOOL
                HasFinalYAngle;
            INT_8
                FinalYAngle,
                FinalYAngleSpeed;
            BOOL
                IsDerezzed;
            UINT_8
                FrameIndex,
                DecisionFrameIndex,
                RadarSpriteImageByteIndex;
        }
        MODEL;
#endif

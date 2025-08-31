/*
    Axes : +X right, +Y up, +Z forward
*/

// -- IMPORTS

#include "base.h"
#include "camera.h"

// -- VARIABLES

INT_6_2
    CameraY;
INT_8
    CameraYRotationAngle;

// -- FUNCTIONS

void InitializeCamera(
    )
{
    CameraY = DefaultCameraY;
    CameraYRotationAngle = 0;
}

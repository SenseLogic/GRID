#ifndef __PIXEL_H__
    #define __PIXEL_H__

    // -- CONSTANTS

    #define PixelTileByteCount    2000

    // -- FUNCTIONS

    #define GetPixelX( _view_vertex_x_, _view_vertex_z_ ) \
        \
        ( ( ( ( ( _view_vertex_x_ ) << 4 ) + CameraDepth ) / ( _view_vertex_z_ + CameraDepth ) ) + 40 )

    // ~~

    #define GetPixelY( _view_vertex_y_, _view_vertex_z_ ) \
        \
        ( -( ( ( ( _view_vertex_y_ ) << 5 ) + CameraDepth ) / ( _view_vertex_z_ + CameraDepth ) ) + 60 )

    // ~~

    #define IsVisiblePixelX( _pixel_x_ )\
        \
        ( ( _pixel_x_ ) >= 0 && ( _pixel_x_ ) <= 79 )

    // ~~

    #define IsVisiblePixelY( _pixel_y_ )\
        \
        ( ( _pixel_y_ ) >= 0 && ( _pixel_y_ ) <= 99 )

    // ~~

    #define ClampPixelX( _pixel_x_ ) \
        \
        ClampInteger( _pixel_x_, 0, 79 )

    // ~~

    #define ClampPixelY( _pixel_y_ ) \
        \
        ClampInteger( _pixel_y_, 0, 100 )
#endif

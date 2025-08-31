#ifndef __AUDIO_H__
    #define __AUDIO_H__

    // -- CONSTANTS

    #define ChannelCount    3
    #define PatternIndexCount    sizeof( PatternIndexArray )

    // -- FUNCTIONS

    #define InitializeChannels( _volume_ ) \
        \
        { \
            *( volatile UINT_8 * )( 0xD400 ) = 0; \
            *( volatile UINT_8 * )( 0xD401 ) = 0; \
            *( volatile UINT_8 * )( 0xD402 ) = 0; \
            *( volatile UINT_8 * )( 0xD403 ) = 0; \
            *( volatile UINT_8 * )( 0xD404 ) = 0; \
            *( volatile UINT_8 * )( 0xD405 ) = 0; \
            *( volatile UINT_8 * )( 0xD406 ) = 0; \
            \
            *( volatile UINT_8 * )( 0xD407 ) = 0; \
            *( volatile UINT_8 * )( 0xD408 ) = 0; \
            *( volatile UINT_8 * )( 0xD409 ) = 0; \
            *( volatile UINT_8 * )( 0xD40A ) = 0; \
            *( volatile UINT_8 * )( 0xD40B ) = 0; \
            *( volatile UINT_8 * )( 0xD40C ) = 0; \
            *( volatile UINT_8 * )( 0xD40D ) = 0; \
            \
            *( volatile UINT_8 * )( 0xD40E ) = 0; \
            *( volatile UINT_8 * )( 0xD40F ) = 0; \
            *( volatile UINT_8 * )( 0xD410 ) = 0; \
            *( volatile UINT_8 * )( 0xD411 ) = 0; \
            *( volatile UINT_8 * )( 0xD412 ) = 0; \
            *( volatile UINT_8 * )( 0xD413 ) = 0; \
            *( volatile UINT_8 * )( 0xD414 ) = 0; \
            \
            *( volatile UINT_8 * )( 0xD415 ) = 0; \
            *( volatile UINT_8 * )( 0xD416 ) = 0; \
            *( volatile UINT_8 * )( 0xD417 ) = 0; \
            *( volatile UINT_8 * )( 0xD418 ) = ( _volume_ ) & 0x0F; \
        }

    // ~~

    #define MuteChannel( _channel_offset_ ) \
        \
        *( volatile UINT_8 * )( 0xD404 + ( _channel_offset_ ) ) &= 0xFE


    // ~~

    #define PlayChannel( _channel_offset_, _frequency_, _pulse_, _waveform_, _attack_decay_, _sustain_release_ ) \
        \
        { \
            MuteChannel( _channel_offset_ ); \
            *( volatile UINT_8 * )( 0xD400 + ( _channel_offset_ ) ) = ( _frequency_ ); \
            *( volatile UINT_8 * )( 0xD401 + ( _channel_offset_ ) ) = ( _frequency_ ) >> 8; \
            *( volatile UINT_8 * )( 0xD402 + ( _channel_offset_ ) ) = ( _pulse_ ); \
            *( volatile UINT_8 * )( 0xD403 + ( _channel_offset_ ) ) = ( _pulse_ ) >> 8; \
            *( volatile UINT_8 * )( 0xD404 + ( _channel_offset_ ) ) = ( _waveform_ ) | 0x01; \
            *( volatile UINT_8 * )( 0xD405 + ( _channel_offset_ ) ) = ( _attack_decay_ ); \
            *( volatile UINT_8 * )( 0xD406 + ( _channel_offset_ ) ) = ( _sustain_release_ ); \
        }

    // ~~

    #define MuteChannels() \
        \
        { \
            MuteChannel( 0x00 ); \
            MuteChannel( 0x07 ); \
            MuteChannel( 0x0E ); \
        }

    // ~~

    #define SetVolume( _volume_ ) \
        \
        *( volatile UINT_8 * )( 0xD418 ) = _volume_

    // ~~

    #define PlayShotSound() \
        \
        PlaySound( 2, 0x2200, 10, 0x1200, 0x80, 0x2D, 0x02 )

    // ~~

    #define PlayImpactSound() \
        \
        PlaySound( 2, 0x1400, 9, 0x0000, 0x80, 0x2D, 0x02 )

    // ~~

    #define PlayExplosionSound() \
        \
        PlaySound( 2, 0x0400, 9, 0x0000, 0x80, 0x2D, 0x02 )

    // ~~

    #define PlayDefeatSound() \
        \
        { \
            PlayNote( 0, 38, 0x0800, 0x20, 0x2D, 0x02 ); \
            PlayNote( 1, 41, 0x0800, 0x20, 0x2D, 0x02 ); \
            PlayNote( 2, 45, 0x0800, 0x20, 0x2D, 0x02 ); \
        }

    // ~~

    #define PlayVictorySound() \
        \
        { \
            PlayNote( 0, 48, 0x0800, 0x20, 0x2D, 0x02 ); \
            PlayNote( 1, 52, 0x0800, 0x20, 0x2D, 0x02 ); \
            PlayNote( 2, 55, 0x0800, 0x20, 0x2D, 0x02 ); \
        }
#endif

// -- IMPORTS

#include "base.h"

// -- IMPORTS

#include "base.c"
#include "audio.c"
#include "video.c"
#include "sprite.c"
#include "input.c"
#include "background.c"
#include "camera.c"
#include "mountain.c"
#include "tank.c"
#include "pixel.c"
#include "grid.c"
#include "model.c"
#include "game.c"
#include "intro.c"
#include "level.c"
#include "defeat.c"
#include "victory.c"

// -- FUNCTIONS

int main(
    )
{
    InitializeGame();

    GameState = GAME_STATE_ShowIntroScreen;

    while ( GameState )
    {
        switch ( GameState )
        {
            case GAME_STATE_ShowIntroScreen :
            {
                ShowIntroScreen();

                break;
            }

            case GAME_STATE_ShowLevelScreen :
            {
                ShowLevelScreen();

                break;
            }

            case GAME_STATE_ShowDefeatScreen :
            {
                ShowDefeatScreen();

                break;
            }

            case GAME_STATE_ShowVictoryScreen :
            {
                ShowVictoryScreen();

                break;
            }
        }
    }
}

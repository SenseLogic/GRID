// -- IMPORTS

#include "base.h"
#include "input.h"
#include "game.h"

// -- VARIABLES

GAME_STATE
    GameState;

// -- FUNCTIONS

void InitializeGame(
    )
{
    ClearInput();
    ClearScreen();
    InitializeFont();
    InitializeSprites();
    InitializeBackground();
    InitializeGridRows();
}

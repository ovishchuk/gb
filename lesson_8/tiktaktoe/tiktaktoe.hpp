/*
    tiktaktoe.hpp
*/

#include <cstdlib>

// TikTakToe
namespace TTT
{

enum TGameState
{
    IN_PROGRESS,
    HUMAN_WON,
    AI_WON,
    DRAW
};

enum TCell : char 
{
    CROSS = 'X',
    ZERO = '0',
    EMPTY = '_'
};

struct TCoord 
{
    size_t y{0U};
    size_t x{0U};
};

struct TGame
{
    const size_t SIZE{ 3U };
    TCell **ppField{ nullptr };
    TGameState state{ IN_PROGRESS };
    TCell human, ai;
    size_t turn{ 0U };
};

//============================================================================//

int32_t getRandomNumber(int32_t min, int32_t max);
void initGame(TGame &game);
void deinitGame(TGame &game);
void printGame(const TGame &game);
TCoord getHumanCoord(const TGame &game);
TGameState getGameState(const TGame &game);
TCoord getAiCoord(const TGame &game);
void congrats(const TGame &game);
void runGame(TGame &game);
void run(TGame &game);

} // namespace TTT
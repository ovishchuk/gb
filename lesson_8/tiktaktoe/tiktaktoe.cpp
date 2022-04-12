/*
    tiktaktoe.cpp
*/
#include "tiktaktoe.hpp"
#include <iostream>
#include <chrono>
#include <random>

#if defined(__linux__) || defined(_LINUX)
    #define clear() system("clear");
#elif defined(_WIN32) || defined(_WIN64)
    #define clear() system("cls");
#else 
    #error Unsupported Operating System!
#endif

//============================================================================//

// TikTakToe
namespace TTT
{

int32_t getRandomNumber(int32_t min, int32_t max)
{
    const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937_64 generator(seed);
    std::uniform_int_distribution<int32_t> dis(min, max);
    return dis(generator);
}

void initGame(TGame &game)
{
    game.ppField = new TCell * [game.SIZE];

    for ( size_t i = 0; i < game.SIZE; i++ )
    {
        game.ppField[i] = new TCell [game.SIZE];
    }

    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        for ( size_t x = 0; x < game.SIZE; x++ )
        {
            game.ppField[y][x] = TCell::EMPTY;
        }
    }

    if ( getRandomNumber(0, 1000) % 2 )
    {
        game.human = CROSS;
        game.ai = ZERO;
        game.turn = 0;
    }
    else
    {
        game.ai = CROSS;
        game.human = ZERO;
        game.turn = 1;
    }
}

void deinitGame(TGame &game)
{
    for ( size_t i = 0; i < game.SIZE; i++ )
    {
        delete [] game.ppField[i];
    }

    delete [] game.ppField;
    game.ppField = nullptr;
}

void printGame(const TGame &game)
{
    clear();

    std::cout << "-=== TIK TAK TOE GAME ===-\n" 
            << "\n     ";
    
    for ( size_t i = 1; i <= game.SIZE; i++ )
    {
        std::cout << i << "   ";
    }
    std::cout << std::endl;

    for ( size_t i = 0; i < game.SIZE; i++ )
    {
        std::cout << " " << i + 1 << " | ";

        for ( size_t j = 0; j < game.SIZE; j++ )
        {
            std::cout << (char)game.ppField[i][j] << " | ";
        }

        std::cout << std::endl;
    }

    std::cout << "\nHuman: " << (char)game.human 
        << "\nAI: " << (char)game.ai << std::endl;
}

TCoord getHumanCoord(const TGame &game)
{
    TCoord coord;

    do
    {
        std::cout << "-= Human turn=-\nEnter X (1..3): ";
        std::cin >> coord.x;
        std::cout << "Enter Y (1..3): ";
        std::cin >> coord.y;
        coord.x--;
        coord.y--;
    } while ( coord.x > 2 || coord.y > 2 || game.ppField[coord.y][coord.x] != EMPTY );
    
    return coord;
}

TGameState getGameState(const TGame &game)
{
    // проверяем строки
    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        if ( game.ppField[y][0] == game.ppField[y][1] && game.ppField[y][0] == game.ppField[y][2] )
        {
            if ( game.ppField[y][0] == game.human )
            {
                return TGameState::HUMAN_WON;
            }

            if (game.ppField[y][0] == game.ai)
            {
                return TGameState::AI_WON;
            }
        }
    }

    // проверяем столбцы
    for ( size_t x = 0; x < game.SIZE; x++ )
    {
        if ( game.ppField[0][x] == game.ppField[1][x] && game.ppField[0][x] == game.ppField[2][x] )
        {
            if ( game.ppField[0][x] == game.human )
            {
                return TGameState::HUMAN_WON;
            }

            if (game.ppField[0][x] == game.ai)
            {
                return TGameState::AI_WON;
            }
        }
    }

    // проверяем диагональ 1
    if ( game.ppField[0][0] == game.ppField[1][1] && game.ppField[0][0] == game.ppField[2][2] )
    {
        if ( game.ppField[1][1] == game.human )
        {
            return TGameState::HUMAN_WON;
        }

        if (game.ppField[1][1] == game.ai)
        {
            return TGameState::AI_WON;
        }
    }
    
    // проверяем диагональ 2
    if ( game.ppField[0][2] == game.ppField[1][1] && game.ppField[0][2] == game.ppField[2][0] )
    {
        if ( game.ppField[1][1] == game.human )
        {
            return TGameState::HUMAN_WON;
        }

        if (game.ppField[1][1] == game.ai)
        {
            return TGameState::AI_WON;
        }
    }

    // проверяем ничью
    bool draw{true};
    
    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        for ( size_t x = 0; x < game.SIZE; x++ )
        {
            if ( game.ppField[y][x] == TCell::EMPTY )
            {
                draw = false;
                break;
            }
        }

        if ( !draw )
        {
            break;
        }
    }

    if ( draw )
    {
        return TGameState::DRAW;
    }

    return TGameState::IN_PROGRESS;
}

TCoord getAiCoord(const TGame &game)
{
    // search winning cell
    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        for ( size_t x = 0; x < game.SIZE; x++ )
        {
            if ( game.ppField[y][x] == TCell::EMPTY )
            {
                game.ppField[y][x] = game.ai;
                
                if ( getGameState(game) == TGameState::AI_WON )
                {
                    game.ppField[y][x] == TCell::EMPTY;
                    return { y, x };
                }

                game.ppField[y][x] = TCell::EMPTY;
            }
        }
    }

    // search to prevent human win
    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        for ( size_t x = 0; x < game.SIZE; x++ )
        {
            if ( game.ppField[y][x] == TCell::EMPTY )
            {
                game.ppField[y][x] = game.human;
                
                if ( getGameState(game) == TGameState::HUMAN_WON )
                {
                    game.ppField[y][x] == TCell::EMPTY;
                    return { y, x };
                }

                game.ppField[y][x] = TCell::EMPTY;
            }
        }
    }

    // random case
    std::vector<TCoord> emptyCells;

    for ( size_t y = 0; y < game.SIZE; y++ )
    {
        for ( size_t x = 0; x < game.SIZE; x++ )
        {
            if ( game.ppField[y][x] == TCell::EMPTY )
            {
                emptyCells.push_back({ y, x });
            }
        }
    }

    return emptyCells[getRandomNumber(0, emptyCells.size() - 1)];
}

void congrats(const TGame &game)
{
    printGame(game);

    if ( game.state == TGameState::HUMAN_WON )
    {
        std::cout << "Human won! :-)" << std::endl;
    }
    else if ( game.state == TGameState::AI_WON )
    {
        std::cout << "Computer won! :-/" << std::endl;
    }
    else if ( game.state == TGameState::DRAW )
    {
        std::cout << "Draw! :-(" << std::endl;
    }
}

void runGame(TGame &game)
{
    do
    {
        printGame(game);

        if ( game.turn % 2 == 0 )
        {
            TCoord coord = getHumanCoord(game);
            game.ppField[coord.y][coord.x] = game.human;
        }
        else
        {
            TCoord coord = getAiCoord(game);
            game.ppField[coord.y][coord.x] = game.ai;
        }

        game.turn++;
        game.state = getGameState(game);
    } while ( game.state == TGameState::IN_PROGRESS );

    congrats(game);
}

// pack for all core functions
void run(TGame &game)
{
    initGame(game);
    runGame(game);
    deinitGame(game);
}

} // namespace TTT
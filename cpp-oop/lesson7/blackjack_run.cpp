/*
    @file blackjack_run.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/
/*
    5. Написать функцию main() к игре Блекджек. В этой функции вводятся имена 
    игроков. Создается объект класса Game и запускается игровой процесс. 
    Предусмотреть возможность повторной игры.
*/
#include "blackjack.hpp"

int main()
{
    std::vector<std::string> names;
    std::string newName = "null";
    std::cout << "Enter players names (type \"done\" to finish):" << std::endl;

    while ( newName != "done" )
    {
        std::cout << "Name: ";
        std::cin >> newName;
        if ( newName != "done" )
        {
            names.push_back(newName);
        }
    }

    std::cout << std::endl;
    Game game(names);
    bool playAgain = true;
    
    while ( playAgain )
    {
        game.Play();

        std::string answer = "null";
        do
        {
            std::cout << "Do you want to play again? [yes/no]: ";
            std::cin >> answer;
        } 
        while ( answer != "yes" && answer != "no" );

        answer == "yes" ? playAgain = true : playAgain = false;
    }

    return 0;
}
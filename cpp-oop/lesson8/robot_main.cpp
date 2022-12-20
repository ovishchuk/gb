#include <iostream>
#include "robot.hpp"
#include "robot_exceptions.hpp"

int main()
{
    Robot robot;
    std::string command;

    do
    {
        try
        {
            std::cout << "Enter command (or type 'help'): ";
            std::cin >> command;
            if ( command == "help" )
            {
                std::cout << "\nCommands:\n\n"
                    << "    Straight:  up left right down\n"
                    << "    Diagonal:  upleft upright downleft downright\n"
                    << "    Other   :  help exit\n" << std::endl;
            }
            else if ( command == "exit" ) {}
            else
            { 
                robot.Move(command);
                std::cout << robot.Location() << std::endl;
            }
        }
        catch (const IllegalCommand& ex)
        {
            std::cerr << "Error: IllegalCommand:\n" 
                << ex.Position() << " | " << ex.Direction() << '\n';
        }
        catch (const OffTheField& ex)
        {
            std::cerr << "Error: OffTheField:\n" 
                << ex.Position() << " | " << ex.Direction() << '\n';
        }

    } while ( command != "exit" );

    return 0;
}
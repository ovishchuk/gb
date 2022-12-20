#ifndef GB_ROBOT_HPP
#define GB_ROBOT_HPP

#include <string>

class Robot
{
public:
    enum Direction
    {
        UP,
        LEFT,
        UP_LEFT,
        UP_RIGHT,
        DOWN_LEFT,
        DOWN_RIGHT,
        RIGHT,
        DOWN
    };
    struct Position
    {
        int x = 0;
        int y = 0;
    };

    Robot();
    void Move(std::string command);
    std::string Location();
private:
    Position m_position;    
};

#endif // GB_ROBOT_HPP
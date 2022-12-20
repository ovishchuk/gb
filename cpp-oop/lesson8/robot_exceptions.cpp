#include "robot_exceptions.hpp"

OffTheField::OffTheField(const Robot::Position& pos, const Robot::Direction& dir)
    : m_position(pos), m_direction(dir)
{        
}

OffTheField::~OffTheField() {}

std::string OffTheField::Direction() const
{
    std::string dir;

    switch (m_direction)
    {
        case Robot::UP:
            dir = "UP";
            break;
        case Robot::LEFT:
            dir = "LEFT";
            break;
        case Robot::UP_LEFT:
            dir = "UP_LEFT";
            break;
        case Robot::UP_RIGHT:
            dir = "UP_RIGHT";
            break;
        case Robot::DOWN_LEFT:
            dir = "DOWN_LEFT";
            break;
        case Robot::DOWN_RIGHT:
            dir = "DOWN_RIGHT";
            break;
        case Robot::RIGHT:
            dir = "RIGHT";
            break;
        case Robot::DOWN:
            dir = "DOWN";
            break;
        default:
            dir = "null";
            break;
        }        

    return dir;
}

std::string OffTheField::Position() const
{
    return "x: " + std::to_string(m_position.x) + " y: " + 
        std::to_string(m_position.y);
}

//============================================================================//

IllegalCommand::IllegalCommand(const Robot::Position& pos, const Robot::Direction& dir)
    : OffTheField(pos, dir)
{        
}
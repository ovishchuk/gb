#ifndef GB_ROBOT_EXCEPTIONS_HPP
#define GB_ROBOT_EXCEPTIONS_HPP

#include "robot.hpp"

class OffTheField
{
private:
    const Robot::Direction& m_direction;
    const Robot::Position& m_position;
public:
    OffTheField(const Robot::Position& pos, const Robot::Direction& dir);
    virtual ~OffTheField();
    std::string Direction() const;
    std::string Position() const;
};

class IllegalCommand : public OffTheField
{
public:
    IllegalCommand(const Robot::Position& pos, const Robot::Direction& dir);
};

#endif // GB_ROBOT_EXCEPTIONS_HPP
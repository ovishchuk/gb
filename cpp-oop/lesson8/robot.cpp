/*
    3. Написать класс «робот», моделирующий перемещения робота по сетке 10x10, у 
    которого есть метод, означающий задание переместиться на соседнюю позицию. 
    Эти методы должны запускать классы-исключения OffTheField, если робот должен 
    уйти с сетки, и IllegalCommand, если подана неверная команда (направление не 
    находится в нужном диапазоне). Объект исключения должен содержать всю 
    необходимую информацию — текущую позицию и направление движения. Написать 
    функцию main, пользующуюся этим классом и перехватывающую все исключения от 
    его методов, а также выводящую подробную информацию о всех возникающих 
    ошибках.
*/
#include "robot.hpp"
#include "robot_exceptions.hpp"

Robot::Robot()
{
    m_position.x = 0;
    m_position.y = 0;
}

void Robot::Move(std::string command)
{
    Direction dir;
    if ( command == "up" ) { dir = UP; }
    else if ( command == "down" ) { dir = DOWN; }
    else if ( command == "left" ) { dir = LEFT; }
    else if ( command == "right" ) { dir = RIGHT; }
    else if ( command == "upleft" ) { dir = UP_LEFT; }
    else if ( command == "upright" ) { dir = UP_RIGHT; }
    else if ( command == "downleft" ) { dir = DOWN_LEFT; }
    else if ( command == "downright" ) { dir = DOWN_RIGHT; } 
    else { throw IllegalCommand(m_position, dir); }

    Position new_pos;
    new_pos.x = m_position.x;
    new_pos.y = m_position.y;

    switch ( dir ) 
    {
        case LEFT:
            --new_pos.x;
            break;
        case RIGHT:
            ++new_pos.x;
            break;
        case UP:
            --new_pos.y;
            break;
        case DOWN:
            ++new_pos.y;
            break;
        case UP_LEFT:
            --new_pos.y;
            --new_pos.x;
            break;
        case UP_RIGHT:
            --new_pos.y;
            ++new_pos.x;
            break;
        case DOWN_LEFT:
            ++new_pos.y;
            --new_pos.x;
            break;
        case DOWN_RIGHT:
            ++new_pos.y;
            ++new_pos.x;
            break;
        
        default:
            new_pos.x = -1;
            new_pos.y = -1;
            break;
    }

    if ( new_pos.x < 0 || new_pos.x > 9 || new_pos.y < 0 || new_pos.y > 9 )
    {
        throw OffTheField(m_position, dir);
    }
    m_position.x = new_pos.x;
    m_position.y = new_pos.y;
}

std::string Robot::Location()
{
    return "x: " + std::to_string(m_position.x) + ", y: " + std::to_string(m_position.y);
}
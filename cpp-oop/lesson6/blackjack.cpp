/*
    @file blackjack.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

/*
  3. Реализовать класс Player, который наследует от класса GenericPlayer. У 
  этого класса будет 4 метода:

  • virtual bool IsHitting() const - реализация чисто виртуальной функции 
    базового класса. Метод спрашивает у пользователя, нужна ли ему еще одна 
    карта и возвращает ответ пользователя в виде true или false.
  • void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
  • void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
  • void Push() const - выводит на экран имя игрока и сообщение, что он сыграл 
    вничью.
*/

/*
  4. Реализовать класс House, который представляет дилера. Этот класс наследует 
  от класса GenericPlayer. У него есть 2 метода:

  • virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна 
    карта. Если у дилера не больше 16 очков, то он берет еще одну карту.
  • void FlipFirstCard() - метод переворачивает первую карту дилера.
*/

/*
  5. Написать перегрузку оператора вывода для класса Card. Если карта 
  перевернута рубашкой вверх (мы ее не видим), вывести ХХ, если мы ее видим, 
  вывести масть и номинал карты. Также для класса GenericPlayer написать 
  перегрузку оператора вывода, который должен отображать имя игрока и его карты,
  а также общую сумму очков его карт.
*/
#include "blackjack.hpp"
#include <iostream>
#include <vector>

//============================================================================//
// Class Card

Card::Card(Card::Value value, Card::Suit suit, bool state = false)
    : m_value(value), m_suit(suit), m_state(state)
{
}

Card::~Card()
{
}

void Card::Flip() { m_state = !m_state; }

int Card::GetValue()
{
    // for Jack, Qeen & King
    if ( m_value > TEN && m_value < ACE ) return 10;
    // for Ace
    if ( m_value == ACE ) return 11;
    // default
    return m_value; 
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    std::string str = "null";
    if ( card.m_state )
    {
        switch (card.m_suit)
        {
            case Card::DIAMONDS:
                str = "Diamonds";
                break;
            case Card::HEARTS:
                str = "Hearts";
                break;
            case Card::CLUBS:
                str = "Clubs";
                break;
            case Card::SPADES:
                str = "Spades";
                break;
            default:
                break;
        };
        switch (card.m_value)
        {
            case Card::JACK:
                str += " Jack";
                break;
            case Card::QUEEN:
                str += " Queen";
                break;
            case Card::KING:
                str+= " King";
                break;
            case Card::ACE:
                str += " Ace";
                break;
            default:
                str += " " + std::to_string(card.m_value);
                break;
        };
    }
    else str = "XX";
    out << str;
    return out;
}

//============================================================================//
// Class Hand

Hand::~Hand()
{
    Clear();
}

void Hand::Add(Card* card)
{
    m_cards.push_back(card);
}

void Hand::Clear()
{
    while ( m_cards.size() > 0 )
    {
        m_cards.pop_back();
    }
}

int Hand::GetValue()
{
    int value = 0;
    
    for( size_t i = 0; i < m_cards.size(); i++ )
    {
        value += m_cards[i]->GetValue();
    }
    
    if ( value > 21 )
    {
        for ( size_t i = 0; i < m_cards.size(); i++ )
        {
            if ( m_cards[i]->GetValue() == 11 )
            value -= 10;
        }
    }

    return value;
}

//============================================================================//
// Class GenericPlayer

GenericPlayer::GenericPlayer(std::string name) : m_name(name)
{
}

GenericPlayer::~GenericPlayer()
{
}
    
bool GenericPlayer::IsBoosted()
{
    if ( GetValue() > 21 ) return true;
    return false;
}

void GenericPlayer::Bust()
{
    std::cout << m_name << " is boosted." << std::endl;
}

std::ostream& operator<<(std::ostream& out, GenericPlayer& player)
{
    out << player.m_name << " cards: \n";

    for ( size_t i = 0; i < player.m_cards.size(); i++ )
    {
        out << *player.m_cards[i] << "\n";
    }

    out << "Value: " << player.GetValue() << std::endl; 

    return out;
}

//============================================================================//
// Class Player

Player::Player(std::string name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::IsHitting()
{
    std::string answer = "null";
    
    do 
    {
        std::cout << "Need one more card? [yes/no]: ";
        std::cin >> answer;
        std::cout << "Your answer: " << answer << std::endl;
    } while ( answer != "yes" && answer != "no");

    if ( answer == "yes" ) return true;
    else return false;
}

void Player::Win() const
{
    std::cout << m_name << " won!" << std::endl;
}

void Player::Lose() const
{
    std::cout << m_name << " lose!" << std::endl;
}

void Player::Push() const
{
    std::cout << m_name << " played push." << std::endl;
}

//============================================================================//
// Class House

House::House() : GenericPlayer("House")
{
}

House::~House()
{
}

bool House::IsHitting()
{
    if (GetValue() <= 16) return true;
    else return false;
}

void House::FlipFirstCard()
{
    m_cards[0]->Flip();
}
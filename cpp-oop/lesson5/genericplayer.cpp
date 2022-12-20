/*
4. Согласно иерархии классов, которая представлена в методичке к уроку 3, от 
класса Hand наследует класс GenericPlayer, который обобщенно представляет 
игрока, ведь у нас будет два типа игроков - человек и компьютер. Создать класс 
GenericPlayer, в который добавить поле name - имя игрока. 
Также добавить 3 метода:

• IsHitting() - чисто виртуальная функция, возвращает информацию, нужна ли 
  игроку еще одна карта.
• IsBoosted() - возвращает bool значение, есть ли у игрока перебор
• Bust() - выводит на экран имя игрока и объявляет, что у него перебор.
*/
#include <iostream>
#include <vector>

class Card
{
public:
    enum Suit
    {
        DIAMONDS,
        HEARTS,
        CLUBS,
        SPADES
    };
    enum Value
    {
        TWO = 2,
        TREE = 3,
        FOUR = 4,
        FIVE = 5,
        SIX = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE = 9,
        TEN = 10,
        JACK = 10,
        QUEEN = 10,
        KING = 10,
        ACE = 11
    };
    Card(Card::Value value, Card::Suit suit, bool state = false)
        : m_value(value), m_suit(suit), m_state(state)
    {
    }
    ~Card() {}
    void Flip() { m_state -= m_state; }
    int GetValue() { return m_value; }
private:
    const Card::Suit m_suit;
    const Card::Value m_value;
    bool m_state; // face == true, back == false
};

class Hand
{
private:
    std::vector<Card*> m_cards;
public:
    ~Hand()
    {
        Clear();
    }
    void Add(Card* card)
    {
        m_cards.push_back(card);
    }
    void Clear()
    {
        while ( m_cards.size() > 0 )
        {
            m_cards.pop_back();
        }
    }
    int GetValue()
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
                if ( m_cards[i]->GetValue() == Card::ACE )
                value -= 10;
            }
        }

        return value;
    }
};

class GenericPlayer : public Hand
{
protected:
    std::string m_name;
public:
    virtual bool IsHitting() = 0;
    bool IsBosted()
    {
        if ( GetValue() > 21 ) return true;
        return false;
    }
    void Bust()
    {
        std::cout << m_name << " is boosted." << std::endl;
    }
};
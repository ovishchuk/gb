/*
  3. Реализовать класс Hand, который представляет собой коллекцию карт. В классе
  будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это 
  по сути динамический массив, а тип его элементов должен быть - указатель на 
  объекты класса Card). Также в классе Hand должно быть 3 метода:

  • метод Add, который добавляет в коллекцию карт новую карту, соответственно он
    принимает в качестве параметра указатель на новую карту
  • метод Clear, который очищает руку от карт
  • метод GetValue, который возвращает сумму очков карт руки (здесь 
    предусмотреть возможность того, что туз может быть равен 11).
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

int main()
{
    Hand hand1;
    hand1.Add(new Card(Card::FOUR, Card::DIAMONDS, false));
    hand1.Add(new Card(Card::ACE, Card::SPADES, false));
    hand1.Add(new Card(Card::ACE, Card::CLUBS, false));

    Hand hand2;
    hand2.Add(new Card(Card::SIX, Card::DIAMONDS, false));
    hand2.Add(new Card(Card::ACE, Card::SPADES, false));
    hand2.Add(new Card(Card::TWO, Card::CLUBS, false));

    std::cout << "Hand 1: " << hand1.GetValue() << std::endl;
    std::cout << "Hand 2: " << hand2.GetValue() << std::endl;
    return 0;
}
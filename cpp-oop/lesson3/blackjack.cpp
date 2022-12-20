/*
  4. Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса 
  должно быть три поля: масть, значение карты и положение карты (вверх лицом или
  рубашкой). Сделать поля масть и значение карты типом перечисления (enum). 
  Положение карты - тип bool. Также в этом классе должно быть два метода:

  метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх,
  то он ее поворачивает лицом вверх, и наоборот.
  метод GetValue(), который возвращает значение карты, пока можно считать, что 
  туз = 1.
*/
#include <iostream>

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
        ACE = 1
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

int main()
{
    Card QueenSpades(Card::Value::QUEEN, Card::Suit::SPADES, false);
    std::cout << QueenSpades.GetValue() << std::endl;

    return 0;
}
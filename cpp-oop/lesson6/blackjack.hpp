/*
    @file blackjack.hpp
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

#ifndef GB_OOP_BLACKJACK_HPP
#define GB_OOP_BLACKJACK_HPP

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
        JACK = 11,
        QUEEN = 12,
        KING = 13,
        ACE = 14
    };
    Card(Card::Value value, Card::Suit suit, bool state);
    virtual ~Card();
    void Flip();
    int GetValue();
    friend std::ostream& operator<<(std::ostream&, const Card&);
protected:
    const Card::Suit m_suit;
    const Card::Value m_value;
    bool m_state; // face == true, back == false
};

std::ostream& operator<<(std::ostream& out, const Card& card);

class Hand
{
protected:
    std::vector<Card*> m_cards;
public:
    virtual ~Hand();
    void Add(Card* card);
    void Clear();
    int GetValue();
};

class GenericPlayer : public Hand
{
protected:
    const std::string m_name;
public:
    GenericPlayer(std::string name);
    virtual ~GenericPlayer();
    virtual bool IsHitting() = 0;
    bool IsBoosted();
    void Bust();
    friend std::ostream& operator<<(std::ostream&, GenericPlayer&);
};

std::ostream& operator<<(std::ostream& out, GenericPlayer& player);

class Player : public GenericPlayer
{
public:
    Player(std::string name);
    ~Player();
    virtual bool IsHitting() override;
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House : public GenericPlayer
{
public:
    House();
    ~House();
    virtual bool IsHitting() override;
    void FlipFirstCard();
};

#endif // GB_OOP_BLACKJACK_HPP
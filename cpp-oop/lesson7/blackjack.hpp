/*
    @file blackjack.hpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

/*
    3. Создать класс Deck, который наследует от класса Hand и представляет собой
    колоду карт. Класс Deck имеет 4 метода:

    • vold Populate() - Создает стандартную колоду из 52 карт, вызывается из 
      конструктора.
    • void Shuffle() - Метод, который тасует карты, можно использовать функцию 
      из алгоритмов STL random_shuffle
    • vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
    • void AddltionalCards (GenericPlayer& aGenerlcPlayer) - раздает игроку 
      дополнительные карты до тех пор, пока он может и хочет их получать

    Обратите внимание на применение полиморфизма. В каких методах применяется 
    этот принцип ООП?
*/

/*
    4. Реализовать класс Game, который представляет собой основной процесс игры.
    У этого класса будет 3 поля:

    • колода карт
    • рука дилера
    • вектор игроков.
    Конструктор класса принимает в качестве параметра вектор имен игроков и 
    создает объекты самих игроков. В конструкторе создается колода карт и затем 
    перемешивается.
    Также класс имеет один метод play(). В этом методе раздаются каждому игроку 
    по две стартовые карты, а первая карта дилера прячется. Далее выводится на 
    экран информация о картах каждого игра, в т.ч. и для дилера. Затем раздаются 
    игрокам дополнительные карты. Потом показывается первая карта дилера и дилер 
    набирает карты, если ему надо. После этого выводится сообщение, кто победил, 
    а кто проиграл. В конце руки всех игроков очищаются. 
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
        CLUBS,
        DIAMONDS,
        HEARTS,
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
    Card(Card::Value value, Card::Suit suit);
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
    int GetTotal();
};

class GenericPlayer : public Hand
{
protected:
    const std::string m_name;
public:
    GenericPlayer(std::string name);
    virtual ~GenericPlayer();
    virtual bool IsHitting() = 0;
    bool IsBusted();
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

class Deck : public Hand
{
public:
    Deck();
    void Populate();
    void Shuffle();
    void Deal(Hand& hand);
    void AdditionalCards (GenericPlayer& aGenerlcPlayer);
};

class Game
{
private:
    Deck m_deck;
    House m_house;
    std::vector<Player> m_players;
public:
    Game(const std::vector<std::string>& names);
    void Play(); 
};

#endif // GB_OOP_BLACKJACK_HPP
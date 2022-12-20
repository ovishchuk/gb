/*
    @file blackjack.cpp
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
#include "blackjack.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

//============================================================================//
// Class Card

Card::Card(Card::Value value, Card::Suit suit)
    : m_value(value), m_suit(suit), m_state(true)
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

int Hand::GetTotal()
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
    
bool GenericPlayer::IsBusted()
{
    if ( GetTotal() > 21 ) return true;
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

    out << "Value: " << player.GetTotal() << std::endl; 

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
        std::cout << m_name << ", need one more card? [yes/no]: ";
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
    if (GetTotal() <= 16) return true;
    else return false;
}

void House::FlipFirstCard()
{
    m_cards[0]->Flip();
}

//============================================================================//
// Class Deck

Deck::Deck()
{
    Populate();
}

void Deck::Populate()
{
    Clear();
    // 1 iteration per Suit
    for ( size_t suit = Card::CLUBS; suit <= Card::SPADES; suit++ )
    {
        // values
        for ( int value = Card::TWO; value <= Card::ACE; value++ )
        {
            Add(new Card(static_cast<Card::Value>(value), static_cast<Card::Suit>(suit)));
        }
    }
}

void Deck::Shuffle()
{
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::Deal(Hand& hand)
{
    if ( !m_cards.empty() )
    {
        hand.Add(m_cards.back());
        m_cards.pop_back();
    }
    else
    {
        std::cout << "No cards left. Cannot deal." << std::endl;
    }
}

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    // продолжает раздавать карты до тех пор, пока у игрока не случается
    // перебор или пока он хочет взять еще одну карту
    while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
    {
        Deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;
        if (aGenericPlayer.IsBusted())
        {
            aGenericPlayer.Bust();
        }
    }
}

//============================================================================//
// Class Game

Game::Game(const std::vector<std::string>& names)
{
    for ( size_t i = 0; i < names.size(); i++ )
    {
        m_players.push_back(Player(names[i]));
    }

    srand(time(NULL));
    m_deck.Populate();
    m_deck.Shuffle();
}

void Game::Play()
{
    // раздает каждому по две стартовые карты
    std::vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i)
    {
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            m_deck.Deal(*pPlayer);
        }
        m_deck.Deal(m_house);
    }
    // прячет первую карту дилера
    m_house.FlipFirstCard();
    // открывает руки всех игроков
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        std::cout << *pPlayer << std::endl;
    }
    std::cout << m_house << std::endl;
    // раздает игрокам дополнительные карты
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        m_deck.AdditionalCards(*pPlayer);
    }
    // показывает первую карту дилера
    m_house.FlipFirstCard();
    std::cout << std::endl << m_house;
    // раздает дилеру дополнительные карты
    m_deck.AdditionalCards(m_house);
    if (m_house.IsBusted())
    {
        // все, кто остался в игре, побеждают
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        {
            if (!(pPlayer->IsBusted()))
            {
                if (pPlayer->GetTotal() > m_house.GetTotal())
                {
                    pPlayer->Win();
                }
                else if (pPlayer->GetTotal() < m_house.GetTotal())
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }
    }
    // очищает руки всех игроков
    for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    {
        pPlayer->Clear();
    }
    m_house.Clear();
}
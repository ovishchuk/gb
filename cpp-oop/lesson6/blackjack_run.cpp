/*
    @file blackjack_run.cpp
    @author Oleksandr Ishchuk <o.v.ishchuk@gmail.com>
*/

#include "blackjack.hpp"

int main()
{
    Player player("Bob");
    player.IsHitting();
    player.Win();
    player.Push();
    player.Lose();

    Card card1(Card::KING, Card::DIAMONDS, false);
    std::cout << card1 << std::endl;
    card1.Flip();
    std::cout << card1 << std::endl;

    Card card2(Card::EIGHT, Card::SPADES, false);
    std::cout << card2 << std::endl;
    card2.Flip();
    std::cout << card2 << std::endl;

    player.Add(new Card(Card::JACK, Card::SPADES, true));
    player.Add(new Card(Card::ACE, Card::DIAMONDS, true));
    player.Add(new Card(Card::TWO, Card::HEARTS, true));
    std::cout << "\n" << player << std::endl;

    return 0;
}
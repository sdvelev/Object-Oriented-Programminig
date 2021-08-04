/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 2
* @compiler VC
*/

#include <iostream>
#include "MonsterCard.hpp"
#include "MagicCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"

using namespace std;

int main()
{

    MonsterCard DarkMagician("Dark Magician", 2500, 2100);

    DarkMagician.printName();

    MagicCard Reflection("Reflection", "Reflects the last played spell", trap);

    MonsterCard BlueEyesDragon("Blue-Eyes Dragon", 3000, 2500);



    Deck d;
    cout << d.getMonsterCardCount() << endl;
    
    d.changeMonsterCard(DarkMagician);
    d.changeMonsterCard(10, DarkMagician);
    d.changeMonsterCard(10, BlueEyesDragon);
    
    Deck f;

    Duelist player1("Yu-Gi-Oh How", d);

    player1.printName();

    player1.setDeck(d);
    player1.setName("Yu-Gi-Oh");

    player1.printName();

    player1.changeMonsterCardInDeck(17, DarkMagician);

    cout << player1.getMonsterCardCount() << endl;

    cout << d.getMonsterCardCount() << endl;

    Duelist player2;
    player2.printName();
    player2.setName("Seto");
    player2.printName();
    cout << player2.getMonsterCardCount() << endl;
    player2.changeMonsterCardInDeck(14, DarkMagician);
    cout << player2.getMonsterCardCount() << endl;

    cout << d.getMonsterCardCount() << endl;
    cout << f.getMonsterCardCount() << endl;


    return 0;
}

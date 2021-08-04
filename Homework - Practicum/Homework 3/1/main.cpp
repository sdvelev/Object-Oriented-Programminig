/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 1
* @compiler VC
*/

#include <iostream>
#include<string>
#include"PendulumCard.hpp"
#include "Deck.hpp"
#include "Duelist.hpp"

using namespace std;

int main()
{
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards",
        1200, 600, CardType::SPELL, 8);

    timegazer.print();

    Duelist first("Ivan Ivanov");
    first.getDeck().addPendulumCard(timegazer);
 
    cout << first.getDeck().getNumberOfPendulumCards() << endl;
    cout << first.getDeck().getNumberOfMagicCards() << endl;
   

    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);

    dragon.print();

    MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);

    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
    
    swords.print();

    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);

    Deck two("Magician Deck");
    two.addMagicCard(cylinder);
    two.addMonsterCard(dragon);
    two.addMonsterCard(magician);
    two.addMagicCard(swords);

    Duelist three("Georgi", two);

    three.saveDeck("magician_deck.txt");

    three.getDeck().setDeckName("George");
    three.getDeck().addPendulumCard(timegazer);

    magician.setName("Dark-Magician");
    three.getDeck().setMonsterCard(1, magician);

    three.saveDeck("magician_deck.txt");
  
    three.loadDeck("example.txt");
    cout << three.getDeck().getDeckName() << endl << endl;

    three.saveDeck("example2.txt");

    three.getDeck().printDeck();

    cout << endl;

    three.display();

    Deck deckexample;
    cout << deckexample.getDeckName() << endl;
    cout << deckexample.getNumberOfMagicCards() << endl;
    deckexample.addMonsterCard(magician);
    deckexample.addMonsterCard(dragon);
    deckexample.addMonsterCard(magician);
    deckexample.addMonsterCard(dragon);
    deckexample.addMonsterCard(magician);
    deckexample.addMonsterCard(dragon);
    deckexample.addMonsterCard(magician);
    deckexample.addMonsterCard(dragon);
    deckexample.addPendulumCard(timegazer);
    deckexample.addPendulumCard(timegazer);

    three.setDuelistDeck(deckexample);
    cout << three.getDeck().getNumberOfMagicCards() << endl;
    three.saveDeck("example3.txt");

    three.getDeck().setDeckName("random deck");

    three.saveDeck("example3.txt");
    
    MagicCard magicCardExample("Name", "Effect", CardType::NONE);
    magicCardExample.print();

    magicCardExample.setCardType(CardType::NONE);

    magicCardExample.print();

    magicCardExample.setCardType(CardType::SPELL);

    magicCardExample.print();

    magicCardExample.setCardType(CardType::NONE);

    magicCardExample.print();

    Duelist exampleDuelist("Chris");
    cout << exampleDuelist.loadDeck("example3.txt") << endl;;
    cout << exampleDuelist.getDeck().getNumberOfMonsterCards() << endl;
    cout << exampleDuelist.getDeck().getDeckName() << endl;
    
    cout << exampleDuelist.loadDeck("example2.txt") << endl;
    cout << exampleDuelist.getDeck().getNumberOfMonsterCards() << endl;
    cout << exampleDuelist.getDeck().getDeckName() << endl;

    cout << exampleDuelist.loadDeck("example4.txt") << endl;
    cout << exampleDuelist.getDeck().getNumberOfMonsterCards() << endl;
    cout << exampleDuelist.getDeck().getDeckName() << endl;

    return 0;

}


/**
* Solution to homework assignment 4
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
#include"Card.hpp"
#include"MonsterCard.hpp"
#include"MagicCard.hpp"
#include"PendulumCard.hpp"
#include"Deck.hpp"
#include"Duelist.hpp"

int main()
{    

    MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
    MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
    MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
    MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
    PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::SPELL);

    PendulumCard timegazer2("Timegazer Magician2", "Your opponent cannot", 6, 1500, 800, 10, CardType::BUFF);


    Deck _deck("My deck");

    _deck.addCard(&dragon);
    _deck.addCard(&magician);
    _deck.addCard(&swords);
    _deck.addCard(&cylinder);
    _deck.addCard(&timegazer);

    //_deck.setCard(2, &dragon);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl;

    _deck.setCard(0, &timegazer);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl;

    _deck.addCard(&timegazer);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;


    cout << endl;

    _deck.addCard(&timegazer);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl;

    cout << _deck.getCards()[4]->getName() << endl;

    _deck.setCard(4, &timegazer2);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    _deck.setCard(0, &magician);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    
    cout << _deck.getCards()[0]->getName() << endl;
    cout << _deck.getCards()[4]->getName() << endl;

    cout << endl << endl << endl;

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl << endl << endl;

    _deck.addCard(&magician);
    _deck.addCard(&magician);

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl << endl << endl;

    _deck.clearDeck();

    cout << _deck.getNumberOfMonsterCards() << endl;
    cout << _deck.getNumberOfMagicCards() << endl;
    cout << _deck.getNumberOfPendulumCards() << endl;
    cout << _deck.getNumberOfCards() << endl;

    cout << endl << endl << endl;

    Duelist exampleDuelist("Mark", _deck);

    exampleDuelist.saveDeck("example1.txt");
    
    _deck.setDeckName("Updated Deck");

    _deck.addCard(&dragon);
    _deck.addCard(&magician);
    _deck.addCard(&swords);
    _deck.addCard(&cylinder);
    _deck.addCard(&timegazer);

    exampleDuelist.setDuelistDeck(_deck);
    exampleDuelist.saveDeck("example1.txt");


   // MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
  //  MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
  //  MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
  //  MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9,CardType::TRAP);
  //  PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::SPELL);
    Duelist firstDuelist("Ivan Ivanov");
    firstDuelist.getDeck().setDeckName("Magician Deck");
    firstDuelist.getDeck().addCard(&dragon);
    firstDuelist.getDeck().addCard(&swords);
    firstDuelist.getDeck().addCard(&magician);
    firstDuelist.getDeck().addCard(&cylinder);
    firstDuelist.getDeck().addCard(&timegazer);
    //firstDuelist.getDeck().shuffle();
    firstDuelist.saveDeck("magician_deck.txt");
    MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
    firstDuelist.getDeck().setCard(1, &box);
    Duelist secondDuelist("Gosho Goshev");
    secondDuelist.getDeck().addCard(&dragon);
    secondDuelist.getDeck().addCard(&swords);
    secondDuelist.getDeck().addCard(&magician);
    secondDuelist.getDeck().addCard(&cylinder);
    secondDuelist.getDeck().addCard(&timegazer);

    Deck _deck2 ("Random deck");

    MonsterCard dragon2("Blue-Eyes White Dragon2", "This legendary dragon is a powerful engine of destruction.2", 43, 3000, 2500);
    MonsterCard dragon3("Blue-Eyes White Dragon3", "This legendary dragon is a powerful engine of destruction.3", 43, 3000, 2500);

    _deck2.addCard(&dragon2);

    Duelist chris ("Chris");   
    
    chris.getDeck().addCard(&dragon3);

    cout << chris.getDeck().getNumberOfCards() << endl;

    cout << endl << endl << endl;

    secondDuelist.getDeck().printDeck();
    cout << endl << endl;

    secondDuelist.getDeck().shuffle();


    secondDuelist.getDeck().addCard(&dragon2);

    secondDuelist.getDeck().printDeck();

    secondDuelist.getDeck().setDeckName("Another deck");

    secondDuelist.saveDeck("magician_deck.txt");

    Duelist thirdDuelist("Charles");

    thirdDuelist.loadDeck("example2.txt");
    
    cout << endl << endl << endl << endl << endl << endl;

    cout << thirdDuelist.getDuelistName() << endl;
    cout << thirdDuelist.getDeck().getDeckName() << endl;
    thirdDuelist.getDeck().printDeck();

    cout << endl << endl << endl << endl << endl << endl;
    thirdDuelist.getDeck().shuffle();
    thirdDuelist.getDeck().printDeck();

    Duelist fourthDuelist("Amy");

    fourthDuelist.loadDeck("example2.txt");

    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    fourthDuelist.getDeck().printDeck();

    //fourthDuelist.getDeck().addCard(&cylinder);

    fourthDuelist.duel(thirdDuelist);

    dragon.setAttackPoints(10000);

    cout << endl << endl << endl << endl;
    secondDuelist.getDeck().getCards()[0]->print();

    cout << endl << endl;

    cout << dragon.getAttackPoints();
    cout << endl << endl;


    Deck otherDeck;
    otherDeck.addCard(&magician);
    otherDeck.addCard(&cylinder);
    otherDeck.printDeck();

    cout << endl;

    magician.setAttackPoints(5000);

    Deck otherDeck2;
    otherDeck2.addCard(&cylinder);
    otherDeck2.addCard(&magician);
    otherDeck2.printDeck();
   // otherDeck2.clearDeck();
    //otherDeck2.printDeck();

    Duelist otherDuelist("Fred");
    otherDuelist.setDuelistDeck(otherDeck);

    Duelist otherDuelist2("Michael", otherDeck2);
    otherDuelist2.getDeck().addCard(&dragon);

    otherDuelist.duel(otherDuelist2);
    otherDuelist.getDeck().addCard(&dragon2);

    otherDuelist.getDeck().addCard(&timegazer);
    otherDuelist2.getDeck().addCard(&timegazer2);

    duel(otherDuelist, otherDuelist2);

    cout << endl << endl << endl << endl << endl;
    otherDuelist2.display();

    MonsterCard exampleOne("1", "1", 1, 1, 1);
    MonsterCard exampleTwo("2", "2", 2, 2, 2);
    MonsterCard exampleThree("3", "3", 3, 3, 3);

    MagicCard exampleFour("4", "4", 4, CardType::TRAP);
    MagicCard exampleFive("5", "5", 5, CardType::TRAP);
    MagicCard exampleSix("6", "6", 6, CardType::SPELL);

    PendulumCard exampleSeven("7", "7",7,7,7,7,CardType::BUFF);
    PendulumCard exampleEight("8", "8", 8, 8, 8, 8, CardType::BUFF);

    Duelist exampleNine("Ben");
    exampleNine.getDeck().addCard(&exampleOne);
    exampleNine.getDeck().addCard(&exampleTwo);
    exampleNine.getDeck().addCard(&exampleThree);
    exampleNine.getDeck().addCard(&exampleFour);
    exampleNine.getDeck().addCard(&exampleFive);
    exampleNine.getDeck().addCard(&exampleSix);
    exampleNine.getDeck().addCard(&exampleSeven);
    exampleNine.getDeck().addCard(&exampleEight);


    exampleNine.display();
    exampleNine.getDeck().shuffle();
    exampleNine.display();

    return 0;
}


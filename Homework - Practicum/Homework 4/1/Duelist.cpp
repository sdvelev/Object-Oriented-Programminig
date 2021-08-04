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

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Duelist.hpp"

using namespace std;

Duelist::Duelist() {
	this->duelistName = "";
}

Duelist::Duelist(string _duelistName) {
	this->duelistName = _duelistName;
}

Duelist::Duelist(string _duelistName, const Deck& _duelistDeck) {
	this->duelistName = _duelistName;
	this->duelistDeck = _duelistDeck;
}

Deck& Duelist::getDeck() {
	return this->duelistDeck;
}

string Duelist::getDuelistName() const {
	return this->duelistName;
}

void Duelist::setDuelistName(const string& _duelistName) {
	this->duelistName = _duelistName;
}

void Duelist::setDuelistDeck(const Deck& _duelistDeck) {
	this->duelistDeck = _duelistDeck;
}

bool Duelist::saveDeck(string filename) {

	if (this->duelistDeck.getDeckName().empty() || (this->duelistDeck.getNumberOfMagicCards() == 0
		&& this->duelistDeck.getNumberOfMonsterCards() == 0 && this->duelistDeck.getNumberOfPendulumCards() == 0)) {
		return false;
	}

	ofstream outfile(filename, ios::out);
	

	string toPublish;
	char divider = '|';
	char newLine = '\n';

	toPublish = this->duelistDeck.getDeckName();
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfCards());
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfMonsterCards());
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfMagicCards());
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfPendulumCards());
	toPublish += newLine;

	outfile << toPublish;


		for (int j = 0; j < this->duelistDeck.getNumberOfCards(); j++) {
			MonsterCard* _monsterCard = dynamic_cast<MonsterCard*>(this->duelistDeck.getCards()[j]);
			PendulumCard* _pendulumCard = dynamic_cast<PendulumCard*>(this->duelistDeck.getCards()[j]);

			if (_monsterCard && !_pendulumCard) {

				outfile << *(_monsterCard);
			}
		}

		for (int j = 0; j < this->duelistDeck.getNumberOfCards(); j++) {
			MagicCard* _magicCard = dynamic_cast<MagicCard*>(this->duelistDeck.getCards()[j]);
			PendulumCard* _pendulumCard = dynamic_cast<PendulumCard*>(this->duelistDeck.getCards()[j]);

			if (_magicCard && !_pendulumCard) {
				outfile << *(_magicCard);
			}
		}

		for (int j = 0; j < this->duelistDeck.getNumberOfCards(); j++) {
			PendulumCard* _pendulumCard = dynamic_cast<PendulumCard*>(this->duelistDeck.getCards()[j]);

			if (_pendulumCard) {
				
				outfile << *(_pendulumCard);
			}
		}

	outfile.close();

	return true;
}

bool Duelist::loadDeck(string filename) {
	
	char divider = '|';
	char newLine = '\n';
	char nullSymbol = '\0';

	ifstream infile;
	infile.open(filename, ios::in);

	if (!infile.is_open()) {
		return false;
	}

	string row;
	vector<string> fileContent;

	while (getline(infile, row)) {
		fileContent.push_back(row);
	}

	infile.close();

	string newDeckName;

	string newNumberOfCardsInString;
	string newNumberOfMonsterCardsInString;
	string newNumberOfMagicCardsInString;
	string newNumberOfPendulumCardsInString;

	unsigned int newNumberOfCards;
	unsigned int newNumberOfMonsterCards;
	unsigned int newNumberOfMagicCards;
	unsigned int newNumberOfPendulumCards;

	string title = fileContent[0];
	title.push_back(nullSymbol);
	unsigned int flagDivider = 0;


	for (int i = 0; title[i] != divider; i++) {
		newDeckName.push_back(title[i]);
		if (title[i + 1] == divider) {
			flagDivider = i + 1;
		}
	}

	for (int i = flagDivider + 1; title[i] != divider; i++) {

		newNumberOfCardsInString.push_back(title[i]);
		if (title[i + 1] == divider) {
			flagDivider = i + 1;
		}
	}

	for (int i = flagDivider + 1; title[i] != divider; i++) {

		newNumberOfMonsterCardsInString.push_back(title[i]);
		if (title[i + 1] == divider) {
			flagDivider = i + 1;
		}
	}


	for (int i = flagDivider + 1; title[i] != divider; i++) {

		newNumberOfMagicCardsInString.push_back(title[i]);
		if (title[i + 1] == divider) {
			flagDivider = i + 1;
		}
	}


	for (int i = flagDivider + 1; title[i] != nullSymbol; i++) {

		newNumberOfPendulumCardsInString.push_back(title[i]);
	}


	for (int i = 0; newNumberOfCardsInString[i] != nullSymbol; i++) {
		if (newNumberOfCardsInString[i] < '0' || newNumberOfCardsInString[i] > '9') {
			return false;
		}
	}


	for (int i = 0; newNumberOfMonsterCardsInString[i] != nullSymbol; i++) {
		if (newNumberOfMonsterCardsInString[i] < '0' || newNumberOfMonsterCardsInString[i] > '9') {
			return false;
		}
	}

	for (int i = 0; newNumberOfMagicCardsInString[i] != nullSymbol; i++) {
		if (newNumberOfMagicCardsInString[i] < '0' || newNumberOfMagicCardsInString[i] > '9') {
			return false;
		}
	}

	for (int i = 0; newNumberOfPendulumCardsInString[i] != nullSymbol; i++) {
		if (newNumberOfPendulumCardsInString[i] < '0' || newNumberOfPendulumCardsInString[i] > '9') {
			return false;
		}
	}

	newNumberOfCards = stoi(newNumberOfCardsInString);
	newNumberOfMonsterCards = stoi(newNumberOfMonsterCardsInString);
	newNumberOfMagicCards = stoi(newNumberOfMagicCardsInString);
	newNumberOfPendulumCards = stoi(newNumberOfPendulumCardsInString);

	if ((newNumberOfMagicCards + newNumberOfMonsterCards + newNumberOfPendulumCards) != newNumberOfCards) {
		return false;
	}


	this->duelistDeck.clearDeck();
	this->duelistDeck.setDeckName(newDeckName);

	string currentRow;

	string newCardName;
	string newCardEffect;
	string newCardRarityInString;
	string newCardAttackPointsInString;
	string newCardDefencePointsInString;
	string newCardTypeInString;
	string newCardPendulumScaleInString;

	unsigned int newCardRarity;
	unsigned int newCardAttackPoints;
	unsigned int newCardDefencePoints;

	double newCardPendulumScale;

	CardType newCardType;

	for (int i = 0; i < newNumberOfMonsterCards; i++) {

		currentRow = fileContent[i + 1];
		currentRow.push_back(nullSymbol);

		for (int j = 0; currentRow[j] != divider; j++) {
			newCardName.push_back(currentRow[j]);
			if (currentRow[j + 1] == divider) {
				flagDivider = j + 1;
			}
		}

		for (int k = flagDivider + 1; currentRow[k] != divider; k++) {
			newCardEffect.push_back(currentRow[k]);
			if (currentRow[k + 1] == divider) {
				flagDivider = k + 1;
			}
		}

		for (int n = flagDivider + 1; currentRow[n] != divider; n++) {
			newCardRarityInString.push_back(currentRow[n]);
			if (currentRow[n + 1] == divider) {
				flagDivider = n + 1;
			}
		}

		for (int l = flagDivider + 1; currentRow[l] != divider; l++) {
			newCardAttackPointsInString.push_back(currentRow[l]);
			if (currentRow[l + 1] == divider) {
				flagDivider = l + 1;
			}
		}

		for (int m = flagDivider + 1; currentRow[m] != nullSymbol; m++) {
			newCardDefencePointsInString.push_back(currentRow[m]);
			if (currentRow[m + 1] == divider) {
				flagDivider = m + 1;
			}
		}

		newCardRarity = stoi(newCardRarityInString);
		newCardAttackPoints = stoi(newCardAttackPointsInString);
		newCardDefencePoints = stoi(newCardDefencePointsInString);

		MonsterCard newMonsterCard(newCardName, newCardEffect, newCardRarity, newCardAttackPoints, newCardDefencePoints);

		this->duelistDeck.addCard(&newMonsterCard);

		newCardName.clear();
		newCardEffect.clear();
		newCardRarityInString.clear();
		newCardAttackPointsInString.clear();
		newCardDefencePointsInString.clear();
	}


	for (int i = 0; i < newNumberOfMagicCards; i++) {

		currentRow = fileContent[i + newNumberOfMonsterCards + 1];
		currentRow.push_back(nullSymbol);

		for (int j = 0; currentRow[j] != divider; j++) {
			newCardName.push_back(currentRow[j]);
			if (currentRow[j + 1] == divider) {
				flagDivider = j + 1;
			}
		}

		for (int k = flagDivider + 1; currentRow[k] != divider; k++) {
			newCardEffect.push_back(currentRow[k]);
			if (currentRow[k + 1] == divider) {
				flagDivider = k + 1;
			}
		}

		for (int n = flagDivider + 1; currentRow[n] != divider; n++) {
			newCardRarityInString.push_back(currentRow[n]);
			if (currentRow[n + 1] == divider) {
				flagDivider = n + 1;
			}
		}

		for (int m = flagDivider + 1; currentRow[m] != nullSymbol; m++) {
			newCardTypeInString.push_back(currentRow[m]);
			if (currentRow[m + 1] == divider) {
				flagDivider = m + 1;
			}
		}


		newCardRarity = stoi(newCardRarityInString);

		if (newCardTypeInString == "TRAP") {
			newCardType = CardType::TRAP;
		}
		else if (newCardTypeInString == "BUFF") {
			newCardType = CardType::BUFF;
		}
		else if (newCardTypeInString == "SPELL") {
			newCardType = CardType::SPELL;
		}

		MagicCard newMagicCard(newCardName, newCardEffect, newCardRarity, newCardType);

		this->duelistDeck.addCard(&newMagicCard);

		newCardName.clear();
		newCardEffect.clear();
		newCardRarityInString.clear();
		newCardTypeInString.clear();
	}


	for (int i = 0; i < newNumberOfPendulumCards; i++) {

		currentRow = fileContent[i + newNumberOfMonsterCards + newNumberOfMagicCards + 1];
		currentRow.push_back(nullSymbol);


		for (int j = 0; currentRow[j] != divider; j++) {
			newCardName.push_back(currentRow[j]);
			if (currentRow[j + 1] == divider) {
				flagDivider = j + 1;
			}
		}

		for (int k = flagDivider + 1; currentRow[k] != divider; k++) {
			newCardEffect.push_back(currentRow[k]);
			if (currentRow[k + 1] == divider) {
				flagDivider = k + 1;
			}
		}

		for (int p = flagDivider + 1; currentRow[p] != divider; p++) {
			newCardRarityInString.push_back(currentRow[p]);
			if (currentRow[p + 1] == divider) {
				flagDivider = p + 1;
			}
		}

		for (int l = flagDivider + 1; currentRow[l] != divider; l++) {
			newCardAttackPointsInString.push_back(currentRow[l]);
			if (currentRow[l + 1] == divider) {
				flagDivider = l + 1;
			}
		}

		for (int m = flagDivider + 1; currentRow[m] != divider; m++) {
			newCardDefencePointsInString.push_back(currentRow[m]);
			if (currentRow[m + 1] == divider) {
				flagDivider = m + 1;
			}
		}

		for (int n = flagDivider + 1; currentRow[n] != divider; n++) {
			newCardPendulumScaleInString.push_back(currentRow[n]);
			if (currentRow[n + 1] == divider) {
				flagDivider = n + 1;
			}
		}

		for (int s = flagDivider + 1; currentRow[s] != nullSymbol; s++) {
			newCardTypeInString.push_back(currentRow[s]);
			if (currentRow[s + 1] == divider) {
				flagDivider = s + 1;
			}
		}


		if (newCardTypeInString == "TRAP") {
			newCardType = CardType::TRAP;
		}
		else if (newCardTypeInString == "BUFF") {
			newCardType = CardType::BUFF;
		}
		else if (newCardTypeInString == "SPELL") {
			newCardType = CardType::SPELL;
		}
		else {
			newCardType = CardType::NONE;
		}

		newCardRarity = stoi(newCardRarityInString);
		newCardAttackPoints = stoi(newCardAttackPointsInString);
		newCardDefencePoints = stoi(newCardDefencePointsInString);

		newCardPendulumScale = stod(newCardPendulumScaleInString);

		if (newCardPendulumScale < 1 || newCardPendulumScale > 13) {
			newCardPendulumScale = 0;
		}


		PendulumCard newPendulumCard(newCardName, newCardEffect, newCardRarity,
			newCardAttackPoints, newCardDefencePoints, newCardPendulumScale, newCardType);

		this->duelistDeck.addCard(&newPendulumCard);


		newCardName.clear();
		newCardEffect.clear();
		newCardRarityInString.clear();
		newCardAttackPointsInString.clear();
		newCardDefencePointsInString.clear();
		newCardPendulumScaleInString.clear();
		newCardTypeInString.clear();
	}

	return true;
}

void Duelist::display() const {
	cout << "Duelist Name: " << this->duelistName << endl;
	cout << "Duelist Deck Name: " << this->duelistDeck.getDeckName() << endl;
	if (this->duelistDeck.getNumberOfMagicCards() > 0 || this->duelistDeck.getNumberOfMonsterCards() > 0 ||
		this->duelistDeck.getNumberOfPendulumCards() > 0) {
		
		for (auto card : this->duelistDeck.getCards()) {
			
			MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(card);
			MagicCard* magicCard = dynamic_cast<MagicCard*>(card);
			PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(card);

			if (pendulumCard) {
				cout << *(pendulumCard);
			}
			else if (monsterCard) {
				cout << *(monsterCard);
			}
			else if (magicCard) {
				cout << *(magicCard);
			}
		}
	}
	else {
		cout << "The deck is empty!" << endl;
	}
}

void Duelist::duel(Duelist& _duelist) {
	
	if (this == &_duelist) {
		cout << "You cannot play a duel with yourself!" << endl;
	}
	else {
		if (this->duelistDeck.getNumberOfCards() == _duelist.duelistDeck.getNumberOfCards()) {

			unsigned int pointsPlayer1 = 0;
			unsigned int pointsPlayer2 = 0;

			this->duelistDeck.shuffle();
			_duelist.duelistDeck.shuffle();

			for (int i = 0; i < this->duelistDeck.getCards().size(); i++) {
				if (*(this->duelistDeck.getCards()[i]) > *(_duelist.duelistDeck.getCards()[i])) {
					++pointsPlayer1;
				}
				else if (*(this->duelistDeck.getCards()[i]) < *(_duelist.duelistDeck.getCards()[i])) {
					++pointsPlayer2;
				}
			}

			this->display();
			cout << endl;
			_duelist.display();
			cout << endl;

			if (pointsPlayer1 > pointsPlayer2) {
				cout << "Player 1 wins the duel!" << endl;
			}
			else if (pointsPlayer1 < pointsPlayer2) {
				cout << "Player 2 wins the duel!" << endl;
			}
			else {
				cout << "The duel finsihes with equality!" << endl;
			}
		}
		else {
			cout << "The numbers of cards in deck are different! Duel cannot be played!" << endl;
		}
	}
}

void duel(Duelist& _duelist1, Duelist& _duelist2) {
	if (&_duelist1 == &_duelist2) {
		cout << "You cannot play a duel with yourself!" << endl;
	}
	else {
		if (_duelist1.duelistDeck.getNumberOfCards() == _duelist2.duelistDeck.getNumberOfCards()) {

			unsigned int pointsPlayer1 = 0;
			unsigned int pointsPlayer2 = 0;

			_duelist1.duelistDeck.shuffle();
			_duelist2.duelistDeck.shuffle();


			for (int i = 0; i < _duelist1.duelistDeck.getCards().size(); i++) {
				if (*(_duelist1.duelistDeck.getCards()[i]) > *(_duelist2.duelistDeck.getCards()[i])) {
					++pointsPlayer1;
				}
				else if (*(_duelist1.duelistDeck.getCards()[i]) < *(_duelist2.duelistDeck.getCards()[i])) {
					++pointsPlayer2;
				}
			}

			_duelist1.display();
			cout << endl;
			_duelist2.display();
			cout << endl;

			if (pointsPlayer1 > pointsPlayer2) {
				cout << "Player 1 wins the duel!" << endl;
			}
			else if (pointsPlayer1 < pointsPlayer2) {
				cout << "Player 2 wins the duel!" << endl;
			}
			else {
				cout << "The duel finsihes with equality!" << endl;
			}
		}
		else {
			cout << "The numbers of cards in deck are different! Duel cannot be played!" << endl;
		}
	}
}
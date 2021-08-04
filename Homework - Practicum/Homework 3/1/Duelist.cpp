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

void Duelist::setDuelistName(string _duelistName) {
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
	
	string toPublish;
	char divider = '|';
	char newLine = '\n';

	toPublish = this->duelistDeck.getDeckName();
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfMonsterCards());
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfMagicCards());
	toPublish += divider;
	toPublish += to_string(this->duelistDeck.getNumberOfPendulumCards());
	toPublish += newLine;

	for (int i = 0; i < this->duelistDeck.getNumberOfMonsterCards(); i++) {
		toPublish += this->duelistDeck.getMonsterCards()[i].getName();
		toPublish += divider;
		toPublish += this->duelistDeck.getMonsterCards()[i].getEffect();
		toPublish += divider;
		toPublish += to_string(this->duelistDeck.getMonsterCards()[i].getAttackPoints());
		toPublish += divider;
		toPublish += to_string(this->duelistDeck.getMonsterCards()[i].getDefencePoints());
		toPublish += newLine;
	}

	for (int i = 0; i < this->duelistDeck.getNumberOfMagicCards(); i++) {
		toPublish += this->duelistDeck.getMagicCards()[i].getName();
		toPublish += divider;
		toPublish += this->duelistDeck.getMagicCards()[i].getEffect();
		toPublish += divider;
		toPublish += this->duelistDeck.getMagicCards()[i].getCardTypeInString();
		toPublish += newLine;
	}

	for (int i = 0; i < this->duelistDeck.getNumberOfPendulumCards(); i++) {
		toPublish += this->duelistDeck.getPendulumCards()[i].getName();
		toPublish += divider;
		toPublish += this->duelistDeck.getPendulumCards()[i].getEffect();
		toPublish += divider;
		toPublish += to_string(this->duelistDeck.getPendulumCards()[i].getAttackPoints());
		toPublish += divider;
		toPublish += to_string(this->duelistDeck.getPendulumCards()[i].getDefencePoints());
		toPublish += divider;
		toPublish += to_string(this->duelistDeck.getPendulumCards()[i].getPendulumScale());
		toPublish += divider;
		toPublish += this->duelistDeck.getPendulumCards()[i].getCardTypeInString();
		toPublish += newLine;
	}

	ofstream outfile(filename, ios::out);

	outfile << toPublish;

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

	string newNumberOfMonsterCardsInString;
	string newNumberOfMagicCardsInString;
	string newNumberOfPendulumCardsInString;

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

	newNumberOfMonsterCards = stoi(newNumberOfMonsterCardsInString);
	newNumberOfMagicCards = stoi(newNumberOfMagicCardsInString);
	newNumberOfPendulumCards = stoi(newNumberOfPendulumCardsInString);

	this->duelistDeck.clearDeck();
	this->duelistDeck.setDeckName(newDeckName);

	string currentRow;

	string newCardName;
	string newCardEffect;
	string newCardAttackPointsInString;
	string newCardDefencePointsInString;
	string newCardTypeInString;
	string newCardPendulumScaleInString;

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

		newCardAttackPoints = stoi(newCardAttackPointsInString);
		newCardDefencePoints = stoi(newCardDefencePointsInString);

		MonsterCard newMonsterCard(newCardName, newCardEffect, newCardAttackPoints, newCardDefencePoints);
		
		this->duelistDeck.addMonsterCard(newMonsterCard);

		newCardName.clear();
		newCardEffect.clear();
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

		for (int m = flagDivider + 1; currentRow[m] != nullSymbol; m++) {
			newCardTypeInString.push_back(currentRow[m]);
			if (currentRow[m + 1] == divider) {
				flagDivider = m + 1;
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

		MagicCard newMagicCard (newCardName, newCardEffect, newCardType);

		this->duelistDeck.addMagicCard(newMagicCard);

		newCardName.clear();
		newCardEffect.clear();
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

		newCardAttackPoints = stoi(newCardAttackPointsInString);
		newCardDefencePoints = stoi(newCardDefencePointsInString);

		newCardPendulumScale = stod(newCardPendulumScaleInString);
		
		if (newCardPendulumScale < 1 || newCardPendulumScale > 13) {
			newCardPendulumScale = 0;
		}

		
		PendulumCard newPendulumCard(newCardName, newCardEffect, newCardAttackPoints, newCardDefencePoints, newCardType,
				newCardPendulumScale);

		this->duelistDeck.addPendulumCard(newPendulumCard);
		
		

		newCardName.clear();
		newCardEffect.clear();
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
		this->duelistDeck.printDeck();
	}
	else {
		cout << "The deck is empty!" << endl;
	}
}
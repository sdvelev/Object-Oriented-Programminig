#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include"ElectionResultsDatabase.hpp"

using namespace std;

ElectionResultsDatabase::ElectionResultsDatabase() {
	this->votesParty1 = 0;
	this->votesParty2 = 0;
	this->votesParty3 = 0;
	this->numberSections = 0;
	this->content = "";
}

ElectionResultsDatabase::ElectionResultsDatabase(int _votesParty1, int _votesParty2, int _votesParty3) {
	this->votesParty1 = _votesParty1;
	this->votesParty2 = _votesParty2;
	this->votesParty3 = _votesParty3;
}

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	ifstream infile;
	infile.open(filename, ios::in);

	if (!infile.is_open()) {
		return;
	}

	int lines = 0;
	string container;
	while (!infile.eof()) {
		getline(infile, container);
		this->content = this->content + container + "\n";
		++lines;
	}

	this->content.pop_back();
		
	--lines;
	this->numberSections = this->numberSections + lines;
	infile.close();

	infile.open(filename, ios::in);

	int votesSingleForParty1;
	int counter1;
	string strNum1;
	int number1;

	int votesSingleForParty2;
	int counter2;
	string strNum2;
	int number2;

	int votesSingleForParty3;
	int counter3;
	string strNum3;
	int number3;

	char ch = '\0';

	for (int j = 0; j < lines; j++) {
		votesSingleForParty1 = 0;
		counter1 = 0;
		strNum1.clear();
		number1 = 0;

		votesSingleForParty2 = 0;
		counter2 = 0;
		strNum2.clear();
		number2 = 0;

		votesSingleForParty3 = 0;
		counter3 = 0;
		strNum3.clear();
		number3 = 0;

		ch = '\0';
		while (ch != 32) {
			infile.get(ch);
			++counter1;
			strNum1 = strNum1 + ch;
		}
		--counter1;

		for (int i = counter1 - 1; i >= 0; --i) {
			number1 = number1 + (strNum1[counter1 - i - 1] - '0') * (pow(10, i));
		}

		ch = '\0';
		while (ch != 32) {
			infile.get(ch);
			++counter2;
			strNum2 = strNum2 + ch;
		}
		--counter2;

		for (int i = counter2 - 1; i >= 0; --i) {
			number2 = number2 + (strNum2[counter2 - i - 1] - '0') * (pow(10, i));
		}

		ch = '\0';
		while (ch != '\n') {
			infile.get(ch);
			++counter3;
			strNum3 = strNum3 + ch;
		}
		--counter3;

		for (int i = counter3 - 1; i >= 0; --i) {
			number3 = number3 + (strNum3[counter3 - i - 1] - '0') * (pow(10, i));
		}

		this->votesParty1 = this->votesParty1 + number1;
		this->votesParty2 = this->votesParty2 + number2;
		this->votesParty3 = this->votesParty3 + number3;
	}
	infile.close();
}

int ElectionResultsDatabase::votesForParty(Party party) const{
	if (party == Party::PARTY1) {
		return this->votesParty1;
	}
	if (party == Party::PARTY2) {
		return this->votesParty2;
	}
	if (party == Party::PARTY3) {
		return this->votesParty3;
	}
}

int ElectionResultsDatabase::numberOfSections() const {
	return this->numberSections;
}

Party ElectionResultsDatabase::winningParty() const {
	if ((this->votesParty1 >= this->votesParty2) && (this->votesParty1 >= this->votesParty3)) {
		return Party::PARTY1;
	}

	if ((this->votesParty2 > this->votesParty1) && (this->votesParty2 >= this->votesParty3)) {
		return Party::PARTY2;
	}
	
	if ((this->votesParty3 > this->votesParty1) && (this->votesParty3 > this->votesParty2)) {
		return Party::PARTY3;
	}

	if (this->votesParty1 >= this->votesParty3 && this->votesParty1 == this->votesParty2) {
		return Party::PARTY1;
	}

	if (this->votesParty2 >= this->votesParty3 && this->votesParty2 == this->votesParty3) {
		return Party::PARTY2;
	}
}

void ElectionResultsDatabase::addVotes(int _votesParty1, int _votesParty2, int _votesParty3) {
	this->votesParty1 += _votesParty1;
	this->votesParty2 += _votesParty2;
	this->votesParty3 += _votesParty3;
}

istream& operator>>(istream& in, ElectionResultsDatabase& other) {
	


	if (&in == &std::cin) {

		/*int votesParty1;
		int votesParty2;
		int votesParty3;
		in >> votesParty1 >> votesParty2 >> votesParty3;
		other.addVotes(votesParty1, votesParty2, votesParty3);
		other.addToContent(votesParty1, votesParty2, votesParty3);
		other.addSection();*/

		string input;
		int counter1 = 0;
		int counter2 = 0;
		int counter3 = 0;
		int votesParty1 = 0;
		int votesParty2 = 0;
		int votesParty3 = 0;

		int flag;


		getline(std::cin, input);
		//in >> input;
		while (!input.empty()) {
			for (int i = 0; input[i] != 32; i++) {
				++counter1;
				flag = i;
			}

			for (int i = counter1 - 1; i >= 0; i--) {
				/*if (i == 0) {
					if (counter1 == 1) {
						votesParty1 += pow(10, i) * (input[i] - '0');
					}
					else {
						votesParty1 += pow(10, i) * (input[i + counter1-1] - '0');
					}
				}
				else {
					votesParty1 += pow(10, i) * (input[i - 1] - '0');
				}	*/
				votesParty1 += pow(10, i) * (input[(counter1 - 1) - i] - '0');
			}

			input.erase(0, flag + 2);


			for (int i = 0; input[i] != 32; i++) {
				++counter2;
				flag = i;
			}

			for (int i = counter2 - 1; i >= 0; i--) {
				/*if (i == 0) {
					if (counter2 == 1) {
						votesParty2 += pow(10, i) * (input[i] - '0');
					}
					else {
						votesParty2 += pow(10, i) * (input[i + counter2 - 1] - '0');
					}
				}
				else {
					votesParty2 += pow(10, i) * (input[i - 1] - '0');
				}*/

				votesParty2 += pow(10, i) * (input[(counter2 - 1) - i] - '0');
			}
			input.erase(0, flag + 2);



			for (int i = 0; (input[i] != 32); i++) {
				++counter3;
				flag = i;
				if (i == input.size() - 1) {
					break;
				}
			}

			for (int i = counter3 - 1; i >= 0; i--) {
				/*	if (i == 0) {
						if (counter3 == 1) {
							votesParty3 += pow(10, i) * (input[i] - '0');
						}
						else {
							votesParty3 += pow(10, i) * (input[i + counter3 - 1] - '0');
						}
					}
					else {
						votesParty3 += pow(10, i) * (input[i - (counter3 - 1)] - '0');
					}*/

				votesParty3 += pow(10, i) * (input[(counter3 - 1) - i] - '0');

			}
			input.erase(0, flag + 2);



			/*	for (int i = flag + 1; input[i] != 32; i++) {
					++counter2;
					flag = i;
				}

				for (int i = counter2 - 1; i >= 0; i--) {
					if (i == 0) {
						votesParty2 += pow(10, i) * (input[flag - counter2 + 1] - '0');
					}
					else {
						votesParty2 += pow(10, i) * (input[flag - counter2-1] - '0');
					}
					--flag;
				}

				for (int i = flag + 1; input[i] != 32; i++) {
					++counter3;
					flag = i;
				}

				for (int i = counter3 - 1; i >= 0; i--) {
					votesParty3 = pow(10, i) * (input[i-1]-'0');
				}*/

			other.addVotes(votesParty1, votesParty2, votesParty3);
			other.addToContent(votesParty1, votesParty2, votesParty3);
			other.addSection();

			counter1 = 0;
			counter2 = 0;
			counter3 = 0;
			votesParty1 = 0;
			votesParty2 = 0;
			votesParty3 = 0;
		}

		return in;
	}



	int lines = 0;
	string container;

	while (!in.eof()) {
		getline(in, container);
		other.content = other.content + container + "\n";
		++lines;
	}
	other.content.pop_back();

	--lines;
	other.numberSections = other.numberSections + lines;

	in.clear();
	in.seekg(0, in.beg);

	int votesSingleForParty1;
	int counter1;
	string strNum1;
	int number1;

	int votesSingleForParty2;
	int counter2;
	string strNum2;
	int number2;

	int votesSingleForParty3;
	int counter3;
	string strNum3;
	int number3;

	char ch = '\0';

	for (int j = 0; j < lines; j++) {
		votesSingleForParty1 = 0;
		counter1 = 0;
		strNum1.clear();
		number1 = 0;

		votesSingleForParty2 = 0;
		counter2 = 0;
		strNum2.clear();
		number2 = 0;

		votesSingleForParty3 = 0;
		counter3 = 0;
		strNum3.clear();
		number3 = 0;

		ch = '\0';
		while (ch != 32) {
			in.get(ch);
			++counter1;
			strNum1 = strNum1 + ch;
		}
		--counter1;

		for (int i = counter1 - 1; i >= 0; --i) {
			number1 = number1 + (strNum1[counter1 - i - 1] - '0') * (pow(10, i));
		}

		ch = '\0';
		while (ch != 32) {
			in.get(ch);
			++counter2;
			strNum2 = strNum2 + ch;
		}
		--counter2;

		for (int i = counter2 - 1; i >= 0; --i) {
			number2 = number2 + (strNum2[counter2 - i - 1] - '0') * (pow(10, i));
		}

		ch = '\0';
		while (ch != '\n') {
			in.get(ch);
			++counter3;
			strNum3 = strNum3 + ch;
		}
		--counter3;

		for (int i = counter3 - 1; i >= 0; --i) {
			number3 = number3 + (strNum3[counter3 - i - 1] - '0') * (pow(10, i));
		}

		other.votesParty1 = other.votesParty1 + number1;
		other.votesParty2 = other.votesParty2 + number2;
		other.votesParty3 = other.votesParty3 + number3;
	}
	return in;
}


string ElectionResultsDatabase::getContent() const {
	return this->content;
}

void ElectionResultsDatabase::addToContent(int _votesParty1, int _votesParty2, int _votesParty3) {
	string toAdd;
	toAdd.append(to_string(_votesParty1));
	char interval = 32;
	toAdd.push_back(interval);

	toAdd.append(to_string(_votesParty2));
	toAdd.push_back(interval);

	toAdd.append(to_string(_votesParty3));
	char newLine = '\n';
	toAdd.push_back(newLine);

	this->content.append(toAdd);
	//this->content += _votesParty1 + " " + _votesParty2 + " " + votesParty3 + "\n";
}

void ElectionResultsDatabase::addSection() {
	this->numberSections = this->numberSections + 1;
}

ostream& operator<<(ostream& out, const ElectionResultsDatabase& other) {
	out << other.getContent();
	return out;
}
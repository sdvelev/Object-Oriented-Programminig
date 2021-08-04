/**
* Solution to homework assignment 1
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
#include "Date.hpp"

using namespace std;

Date::Date() {
	day = 1;
	month = 1;
	year = 2000;
}


int Date::MaxDays(int month) const{
	int maxDays = 0;
	if (month == 1 || month == 3 ||month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		maxDays = 31;
	}
	else if (month == 2) {
		if (isLeapYear() == 1) {
			maxDays = 29;
		}
		else {
			maxDays = 28;
		}
	}
	else {
		maxDays = 30;
	}
	return maxDays;
}

Date::Date(const Date& a) {
	this->day = a.day;
	this->month = a.month;
	this->year = a.year;
}

Date::Date(int day, int month, int year) {

	if (day <= 0 || day > 31 || month <= 0 || month > 12 || year == 0 || day > MaxDays(month)) {
		cout << "Not valid date!" << endl;
	}
	else {

		this->day = day;
		this->month = month;
		this->year = year;
	}
}

void Date::addDays(int n) {

	if (n < 0) {
		cout << "Not valid parameter!" << endl;
	}
	else {
		if ((this->day + n) <= MaxDays(this->month)) {
			this->day = this->day + n;
		}
		else {
			this->day = this->day + n;
			int currentMonth = this->month;
			while (this->day > MaxDays(currentMonth)) {
				this->day = this->day - MaxDays(currentMonth);
				if (currentMonth == 12) {
					currentMonth = 1;
					(this->year)++;
				}
				else {
					++currentMonth;
				}
			}
			this->month = currentMonth;
		}
	}
}

void Date::removeDays(int n) {
	if (n < 0) {
		cout << "Not valid parameter!" << endl;
	}
	else {
		if ((this->day - n) > 0) {
			this->day = this->day - n;
		}
		else {
			this->day = this->day - n;
			int currentMonth = this->month - 1;
			while (this->day <= 0) {
				this->day = this->day + MaxDays(currentMonth);
				if (currentMonth == 1) {
					currentMonth = 12;
					(this->year)--;
				}
				else {
					--currentMonth;
				}
			}
			
			if (currentMonth == 12) {
				currentMonth = 1;
				(this->year)++;
			}
			else {
				++currentMonth;
			}
			this->month = currentMonth;
		}
	}

}

int Date::DaysToSpecificDate(const Date& a) const{
	
	int days1;
	int days2;

	Date helper;

	if (a.day < this->day && a.month < this->month && a.year < this->year) {
		cout << "Not valid parameter!" << endl;
		return -1;
	}

	days1 = this->year * 365;

	int counterLeapyears = 0;
	helper.year= this->year;
	while (helper.year > 0) {
		if (helper.isLeapYear() == true) {
			++counterLeapyears;
		}
		helper.year = helper.year - 1;
	}
	
	days1 = days1 + counterLeapyears;

	helper.month = this->month;

	while (helper.month > 0) {
		days1 = days1 + MaxDays(helper.month - 1);
		helper.month = helper.month - 1;
	}

	days1 = days1 + this->day;

	days2 = a.year * 365;

	counterLeapyears = 0;
	helper.year = a.year;
	while (helper.year > 0) {
		if (helper.isLeapYear() == true) {
			++counterLeapyears;
		}
		helper.year = helper.year - 1;
	}

	days2 = days2 + counterLeapyears;

	helper.month = a.month;

	while (helper.month > 0) {
		days2 = days2 + MaxDays(helper.month - 1);
		helper.month = helper.month - 1;
	}

	days2 = days2 + a.day;
	return (days2 - days1);
}

int Date::DaysToXmas() const {

	int days = 0;

	Date christmas(25, 12, 2000);

	if (this->month < 12 || (this->month == 12 && this->day < 25)) {
		christmas.year = this->year;
		days = this->DaysToSpecificDate(christmas);
	}
	else {
		christmas.year = (this->year) + 1;
		days = this->DaysToSpecificDate(christmas);
	}

	return days;
}

int Date::DaysToNextYear() const {

	int days = 0;

	Date newYear(1, 1, 2000);
	newYear.year = (this->year) + 1;

	days = this->DaysToSpecificDate(newYear);

	return days;
}

bool Date::isLeapYear() const{
	if (this->year % 4 != 0) {
		return false;
	}
	else if (this->year % 100 != 0) {
		return true;
	}
	else if (this->year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

bool Date::isLaterThan(const Date& a) const {
	if (this->year < a.year) {
		return true;
	}
	else if (this->year > a.year) {
		return false;
	}
	else {
		if (this->month < a.month) {
			return true;
		}
		else if (this->month > a.month) {
			return false;
		}
		else {
			if (this->day < a.day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void Date::printDate() const {
	if (day <= 0 || day > 31 || month <= 0 || month > 12 || year == 0 || day > MaxDays(this->month)) {
		cout << "Not valid date!" << endl;
	}
	else {
		cout << day << "." << month << "." << year << endl;
	}
}
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

#pragma once

class Date {
public:
	Date();
	Date(int day, int month, int year);
	void addDays(int n);
	void removeDays(int n);
	bool isLeapYear() const;
	int DaysToXmas() const;
	int DaysToNextYear() const;
	int DaysToSpecificDate(const Date& a) const;
	bool isLaterThan(const Date& a) const;

	int MaxDays(int month) const;
	void printDate() const;
	Date(const Date& a);
private:
	int day;
	int month;
	int year;
};
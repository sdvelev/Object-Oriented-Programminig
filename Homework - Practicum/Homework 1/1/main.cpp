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

#include <iostream>
#include "Date.hpp"

using namespace std;

int main()
{
    Date a;
    a.printDate();

    Date b(29, 2, 2000);
    b.printDate();

    b.addDays(33333);
    b.printDate();

    Date c(29, 2, 2000);
    c.removeDays(30);
    c.printDate();

    Date d(1, 1, 2021);
    Date e(15, 12, 2030);
    cout << d.DaysToSpecificDate(e) << endl;

    cout << d.DaysToXmas() << endl;
    cout << d.DaysToNextYear() << endl;

    Date f(10,3,2021);
    cout << f.DaysToXmas() << endl;
    cout << f.isLeapYear() << endl;

    Date x(13, 4, 2016);
    Date z(21, 3, 2021);

    cout << x.DaysToSpecificDate(z) << endl;

    Date init(14,7,1787);
    Date fin(14, 12, 1818);

    cout << init.DaysToSpecificDate(fin) << endl;

    Date today(21, 3, 2021);
    today.removeDays(21);
    today.printDate();

    Date d1(31, 3, 2014);
    Date d2;
    d1.addDays(1);
    d1.printDate();
    d1.removeDays(1);
    d1.printDate();
    d2.printDate();
    cout << d1.isLaterThan(d2);

    return 0;
}

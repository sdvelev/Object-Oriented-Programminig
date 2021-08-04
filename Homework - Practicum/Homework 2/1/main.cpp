/**
* Solution to homework assignment 2
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
#include"Inventory.hpp"
#include "Materials.hpp"
#include "Money.hpp"
#include "Armor.hpp"
#include "Weapon.hpp"
#include"Backpack.hpp"
#include"Equipment.hpp"
using namespace std;

int main()
{
	
	//Tests for methods in Backpack<Materials>

   Backpack<Materials> first;
   first.addInBackpack(materialsTypeEnum::herbs, 25);
   first.print();
   cout << endl;

   cout << first.isEmpty() << endl;
   first.removeInBackpack(materialsTypeEnum::herbs, 15);
   first.print();
   cout << endl;

   first.emptyBackpack();
   first.print();
   cout << endl;

   first.removeInBackpack(materialsTypeEnum::herbs, 1);
   first.print();
   cout << endl;

   first.addInBackpack(ores, 21);
   first.print();
   cout << endl;

   first.addInBackpack(essence, 31);
   first.print();
   cout << endl;

   first.removeInBackpack(essence, 11);
   first.print();
   cout << endl;

   first.emptyBackpack();
   first.print();
   cout << endl;
	
   cout << first.isEmpty() << endl;

   first.addInBackpack(cloth, 314);
   first.print();
   cout << endl;

   first.addInBackpack(cloth, 1);
   first.print();
   cout << endl;


   first.removeInBackpack(cloth, 1);
   first.print();
   cout << endl;

   first.addInBackpack(essence, 1);
   first.print();
   cout << endl;

   first.addInBackpack(herbs, 1);
   first.print();
   cout << endl;

   first.removeInBackpack(cloth, 21);
   first.print();
   cout << endl;

   first.addInBackpack(herbs, 20);
   first.print();
   cout << endl;
   
   first.emptyBackpack();
   first.print();

   first.addInBackpack(herbs, 43);
   first.print();

   first.removeInBackpack(herbs, 3);
   first.print();
   cout << endl;

   first.removeInBackpack(essence, 10);
   first.print();
   cout << endl;

   first.removeInBackpack(herbs, 40);
   first.print();
   cout << endl;

   cout << first.isEmpty() << endl;


	
	//Tests for methods in Backpack<Money>

	Backpack<Money> second;
	cout << second.isEmpty() << endl;
	cout << second.isFull() << endl;

	second.print();
	cout << endl;

	second.addInBackpack(silver, 60);
	second.print();
	cout << endl;

	second.addInBackpack(silver, 39);
	second.print();
	cout << endl;

	second.addInBackpack(silver, 1);
	second.print();
	cout << endl;

	cout << second.isFull() << endl;

	second.addInBackpack(silver, 3);
	second.print();
	cout << endl;

	second.removeInBackpack(silver, 102);
	second.print();
	cout << endl;

	second.removeInBackpack(silver, 2);
	second.print();
	cout << endl;

	second.addInBackpack(gold, 3);
	second.print();
	cout << endl;

	second.removeInBackpack(silver, 4);
	second.print();
	cout << endl;

	cout << second.isEmpty() << endl;

	second.removeInBackpack(gold, 3);
	second.print();
	cout << endl;


	second.emptyBackpack();
	second.print();
	cout << endl;

	second.removeInBackpack(silver, 1);
	second.print();
	cout << endl;

	cout << second.isEmpty() << endl;
	

	

	//Test for methods in Equipment<Armor>

	Equipment<Armor> third;
	cout << third.isEmpty() << endl;
	Armor a;
	a.setType(ArmorType::cloth);
	a.setDefence(600);
	a.addEffect("example 1", 10);
	a.addEffect("example 2", 20);
	a.addEffect("example 3", 30);
	a.addEffect("example 4", 40);
	a.addEffect("example 5", 50);
	a.addEffect("example 6", 60);
	a.addEffect("example 7", 70);
	third.addInEquipment(a);

	Armor b;
	b.setType(ArmorType::leather);
	b.setDefence(700);
	b.addEffect("example 8", 80);
	b.addEffect("example 9", 20);
	b.addEffect("example 10", 30);
	b.addEffect("example 11", 40);
	b.addEffect("example 12", 50);
	b.addEffect("example 13", 60);
	b.addEffect("example 14", 70);
	third.addInEquipment(b);

	cout << third.isEmpty() << endl;
	cout << third.isFull() << endl;

	//third.emptyBackpack();
	cout << third.isEmpty() << endl;
	cout << third.getBestEquipment().getGearscore() << endl;;
	//third.addInEquipment();

	Armor c;
	c.setType(ArmorType::leather);
	c.setDefence(700);

	Armor d;
	d.setType(ArmorType::leather);
	d.setDefence(700);

	Armor f;
	f.setType(ArmorType::leather);
	f.setDefence(600);

	Armor g;
	g.setType(ArmorType::leather);
	g.setDefence(500);

	Armor h;
	h.setType(ArmorType::leather);
	h.setDefence(300);

	Armor i;
	i.setType(ArmorType::leather);
	i.setDefence(100);

	Armor j;
	j.setType(ArmorType::leather);
	j.setDefence(700);

	Armor k;
	k.setType(ArmorType::leather);
	k.setDefence(700);

	Armor l;
	l.setType(ArmorType::leather);
	l.setDefence(700);

	Armor m;
	m.setType(ArmorType::leather);
	m.setDefence(700);

	Armor n;
	n.setType(ArmorType::leather);
	n.setDefence(700);

	Armor p;
	p.setType(ArmorType::leather);
	p.setDefence(700);

	third.addInEquipment(c);
	third.addInEquipment(d);
	cout << third.getSlots() << endl;
	third.addInEquipment(f);
	third.addInEquipment(g);
	third.addInEquipment(h);
	third.addInEquipment(i);
	third.addInEquipment(j);
	third.addInEquipment(k);
	third.addInEquipment(l);
	third.addInEquipment(m);
	third.addInEquipment(n);


	cout << third.getSlots() << endl;
	third.removeInEquipment(4);
	cout << third.getSlots() << endl;
	third.addInEquipment(p);
	cout << third.getSlots() << endl;

	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.addInEquipment(n);
	cout << third.getSlots() << endl;

	cout << endl << endl;
	cout << (boolalpha) << third.isEmpty() << endl;


	cout << endl << endl;
	cout << third.getSlots() << endl;

	cout << endl << endl;
	cout << (boolalpha) << third.isFull() << endl;

	third.addInEquipment(n);
	cout << third.getSlots() << endl;
	third.print();

	cout << endl << endl;
	third.emptyBackpack();
	cout << third.getSlots() << endl;

	Equipment<Armor> fourth;
	cout << fourth.getSlots() << endl;
	
	

	
	//Tests for Equipment<Armor>
	
	Armor _d;
	_d.setType(ArmorType::leather);
	_d.setDefence(700);
	_d.addEffect("Effect1", 100);
	_d.addEffect("Effect2", 300);

	Armor _h;
	_h.setType(ArmorType::leather);
	_h.setDefence(300);
	_h.addEffect("Effect3", 400);

	Armor _i;
	_i.setType(ArmorType::leather);
	_i.setDefence(100);
	_h.addEffect("Effect4", 100);

	Equipment<Armor> example1;
	Equipment<Armor> example2;


	example1.addInEquipment(_i);
	example1.addInEquipment(_h);

	example2.addInEquipment(_d);

	if (example1 == example2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}

	if (example1 != example2) {
		cout << "Not Equal" << endl;
	}
	else {
		cout << "Equal" << endl;
	}

	cout << example2.getBestEquipment().getGearscore() << endl;

	example2.print();
	
	//Tests for Inventory<Equipment<Weapon>>

	Inventory<Equipment<Weapon>> fifth;
	Inventory<Equipment<Weapon>> sixth;


	cout << sixth << endl;;


	if (fifth == sixth) {
		cout << "Equal I" << endl;
	}

	if (fifth != sixth) {
		cout << "Not equal" << endl;
	}
	else {
		cout << "Equal" << endl;
	}

	cout << sixth;

	//Tests for Backpack<Materials>

	Backpack<Materials> ex1;
	ex1.print();

	cout << (boolalpha) << ex1.isEmpty() << endl;
	cout << ex1.getSlots() << endl;
	ex1.addInBackpack(materialsTypeEnum::ores, 32);
	ex1.removeInBackpack(materialsTypeEnum::ores, 16);

	ex1.print();
	//ex1.emptyBackpack();
	ex1.print();

	cout << ex1.getSlots() << endl;
	cout << (boolalpha) << ex1.isEmpty() << endl;
	cout << (boolalpha) << ex1.isFull() << endl;

	ex1.addInBackpack(materialsTypeEnum::essence, 149);
	ex1.print();
	
   //Tests for Equipment<Weapon>

	Weapon weap1;
	weap1.print();
	weap1.setType(WeaponType::oneHanded);
	weap1.setName("dagger");
	weap1.print();
	cout << endl << endl;
	weap1.setType(WeaponType::twoHanded);
	weap1.print();

	weap1.addEffect("Effect 1", 2000);
	cout << endl;
	weap1.print();

	cout << endl;
	weap1.removeEffect("Effect 1");
	weap1.print();
	cout << endl;

	weap1.addEffect("Effect 1", 2000);
	weap1.addEffect("Effect 2", 3000);

	weap1.print();
	cout << endl;

	weap1.setEffectPower("Effect 2", 4000);
	weap1.print();
	cout << endl;

	weap1.setHitDamage(1000, 2000);
	weap1.print();
	cout << endl;

	weap1.setHitDamageMaximum(3000);
	weap1.print();
	cout << endl;

	weap1.setType(WeaponType::twoHanded);
	weap1.print();
	cout << endl;

	weap1.setName("axe");
	weap1.setType(WeaponType::twoHanded);
	weap1.print();
	cout << endl;

	Equipment<Weapon> eq1;
	eq1.addInEquipment(weap1);
	eq1.addInEquipment(weap1);
	eq1.print();

	cout << (boolalpha) << eq1.isEmpty() << endl;
	cout << (boolalpha) << eq1.isFull() << endl;

	for (int i = 0; i < 5; i++) {
		eq1.addInEquipment(weap1);
		eq1.addInEquipment(weap1);
	}

	//24 Slots
	cout << (boolalpha) << eq1.isEmpty() << endl;
	cout << (boolalpha) << eq1.isFull() << endl;

	//26 Slots - Error Message
	eq1.addInEquipment(weap1);
	
	eq1.removeInEquipment("axe");
	cout << eq1.getSlots() << endl;
	eq1.print();

	cout << endl;
	Equipment<Weapon> eq2;
	if (eq1 == eq2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not Equal" << endl;
	}

	if (eq1 != eq2) {
		cout << "Not Equal" << endl;
	}
	else {
		cout << "Equal" << endl;
	}

	eq1.print();
	eq2.print();
	

	eq1.emptyBackpack();
	eq1.print();
	cout << (boolalpha) << eq1.isEmpty() << endl;

	cout << eq1.getBestEquipment().getWeaponScore() << endl;

	cout << endl;

	//Tests for Equipment<Armor>

	Equipment<Armor> eqAr1;
	Equipment<Armor> eqAr2;

	Armor arm;
	arm.setType(ArmorType::leather);
	arm.addEffect("effect", 300);
	eqAr1.addInEquipment(arm);
	eqAr1.print();
	if (eqAr1 == eqAr2) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}

	if (eqAr1 != eqAr2) {
		cout << "Not Equal" << endl;
	}
	else {
		cout << "Equal" << endl;
	}

	//Test for Inventory<Backpack<Materials>>

	Backpack<Materials> ex2;

	cout << endl << endl;
	ex1.print();
	ex2.print();

	Inventory<Backpack<Materials>> example11;

	example11.setInventory(ex1);
	cout << example11;

	Inventory<Backpack<Materials>> example22;
	cout << example22;

	example22.setInventory(ex2);
	if (example11 != example22) {
		cout << "Not Equal" << endl;
	}
	else{
		cout << "Equal" << endl;
	}

	//Test for Inventory<Backpack<Money>>

	second.print();
	second.addInBackpack(silver, 99);
	second.addInBackpack(silver, 46);
	second.addInBackpack(silver, 46);
	second.addInBackpack(silver, 9);
	second.emptyBackpack();
	second.addInBackpack(silver, 145, gold, 3);
	second.print();

	Inventory<Backpack<Money>> example33;
	cout << example33;
	example33.setInventory(second);
	cout << example33;

	Inventory<Backpack<Money>> example44;
	cout << example44;
	second.addInBackpack(gold, 7);
	second.print();
	example33.setInventory(second);
	cout << example33;

	if (example33 == example44) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}

	//Test for Inventory<Equipment<Armor>>
	
	Inventory<Equipment<Armor>> example55;

	eqAr1.print();

	cout << example55;

	example55.setInventory(eqAr1);
	cout << example55;

	Inventory<Equipment<Armor>> example66;
	cout << example66;
	if (example55 == example66) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}

	//Test for Inventory<Equipment<Weapon>>
	Inventory<Equipment<Weapon>> example77;
	cout << example77;

	eq1.print();
	eq1.addInEquipment(weap1);
	eq1.print();

	example77.setInventory(eq1);
	cout << example77;
	
	Inventory<Equipment<Weapon>> example88;
	Weapon weap4;
	weap4.setName("Weapon4");
	weap4.setType(WeaponType::twoHanded);
	weap4.addEffect("name1", 3000);
	weap4.addEffect("name2", 4000);
	weap4.addEffect("name3", 5000);

	Equipment<Weapon> eqWeapon;
	eqWeapon.addInEquipment(weap4);

	example88.setInventory(eqWeapon);

	if (example77 == example88) {
		cout << "Equal" << endl;
	}
	else {
		cout << "Not equal" << endl;
	}

	return 0;
}


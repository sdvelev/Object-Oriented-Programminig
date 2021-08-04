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

#pragma once
#include<iostream>

enum materialsTypeEnum {
	herbs,
	ores,
	cloth,
	essence,
	none
};

class Materials {
private:
	materialsTypeEnum materialsType;
	int quantityHerbs;
	int quantityOres;
	int quantityCloth;
	int quantityEssence;
	int slots;

	void convertSlots();
public:
	Materials();
	
	int getQuantityHerbs() const;
	int getQuantityOres() const;
	int getQuantityCloth() const;
	int getQuantityEssence() const;
	int getSlots() const;

	void setQuantityHerbs(int quantityHerbs);
	void setQuantityOres(int quantityOres);
	void setQuantityCloth(int quantityCloth);
	void setQuantityEssence(int quantityEssence);

	void emptyMaterials();
	void print() const;

};
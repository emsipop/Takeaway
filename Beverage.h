#pragma once

#include "Item.h"

class Beverage :
	public Item
{
	// Inherited fields from Item parent class:
		// calories;
		// name;
		// price;

	// Store info about the beverage volume & alcohol content
	float abv;
	int volume;

public:
	// Constructor
	Beverage(std::string name, float price, int calories, int volume, float abv);

	// Function to check if the beverage contains alcohol
	bool isAlcoholic();

	// Function to display beverage items in menu
	std::string toString(int index);
};


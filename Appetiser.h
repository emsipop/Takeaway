#pragma once

#include "Item.h"

class Appetiser :
	public Item
{
	// Inherited fields from Item parent class:
		// calories;
		// name;
		// price;

	// Store info about the appetiser deals available
	bool shareable = false;
	bool twoForOne = false;

public:
	// Constuctor
	Appetiser(std::string name, float price, int calories, std::string shareable, std::string twoForOne);

	// Function to display appetiser items in menu
	std::string toString(int index);

	bool getTwoForOne() {
		return twoForOne;
	}
};

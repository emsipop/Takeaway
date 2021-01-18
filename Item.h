#pragma once

#include <string>


class Item
{
protected:
	// Store general info about food & drink items available
	int calories;
	std::string name;
	float price;

public:
	// Virtual function to display items in menu
	// Overriden by child toString functions
	virtual std::string toString(int index);

	// Function converts float to string without trailing 0s
	std::string convertValue(float value);

	std::string getName() {
		return name;
	}

	float getPrice() {
		return price;
	}
};

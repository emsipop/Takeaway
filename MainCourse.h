#pragma once

#include "Item.h"

class MainCourse :
	public Item
{
	// Inherited fields from Item parent class:
		// calories;
		// name;
		// price;

public:
	// Constructor
	MainCourse(std::string name, float price, int calories);
};
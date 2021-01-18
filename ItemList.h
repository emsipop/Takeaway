#pragma once

#include "Item.h"

#include <vector>


// Abstract class
// Provides an interface for storing & manipulating menu items
class ItemList
{
protected:
	// Vector of pointers to instances of the Item class 
	std::vector<Item*> items;

public:
	// Pure virtual function
	virtual std::string toString() = 0;
};


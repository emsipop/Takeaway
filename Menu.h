#pragma once

#include "ItemList.h"

class Menu :
	public ItemList
{
	// Inherited fields from ItemList parent class:
		// items;

public:
	// Constuctor initialises and loads a menu object from the file path passed in
	Menu(const std::string& filePath);

	// Display items from the vector in menu
	std::string toString();

	Item* getItems(int index)
	{
		return items[index - 1];
	}
};
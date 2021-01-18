/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		try {
			if (userCommand.empty()) {
				throw userCommand;
			}
			char* cstr = new char[userCommand.length() + 1];
			strcpy(cstr, userCommand.c_str());

			char* token;
			token = strtok(cstr, " ");

			while (token != NULL)
			{
				parameters.push_back(token);
				token = strtok(NULL, " ");
			}

			string command = parameters[0];

			if (command.compare("menu") == 0) {
				cout << menu.toString();
			}
			else if (command.compare("add") == 0)
			{
				// Loop through input parameters to allow multiple additions at once (e.g. 'add 1 2 3')
				int vecSize = parameters.size();
				for (int i = 1; i < vecSize; i++)
				{
					// Instantiate using the menu object
					Item* choice;

					try {
						if (stoi(parameters[i]) > 13 || stoi(parameters[i]) < 1) {
							throw stoi(parameters[i]);
						}
						choice = menu.getItems(stoi(parameters[i]));
						// Add user's choice to order
						order.add(choice);
					}
					catch (int ex) {
						cout << "\nException: " << ex << " is out of bounds!\n";
					}
				}
			}
			else if (command.compare("remove") == 0)
			{
				// Loop through input parameters to allow multiple removals at once (e.g. 'remove 1 2 3')
				int vecSize = parameters.size();
				for (int i = 1; i < vecSize; i++) {

					try {
						if (stoi(parameters[1]) > order.getOrderSize() || stoi(parameters[1]) < 1) {
							throw stoi(parameters[1]);
						}
						// Remove user's choice from order
						order.remove(stoi(parameters[1]));
					}
					catch (int ex) {
						cout << "\nException: " << ex << " is out of bounds!\n";
					}
				}
			}
			else if (command.compare("checkout") == 0)
			{
				// Display items in order
				cout << order.toString();

				// Allow user to print receipt or make changes to order
				cout << "Do you want to place your order?\nType 'y' to confirm, or 'n' to go back and modify it.\n";
				getline(cin, userCommand);
				if (userCommand == "y") {
					order.printReceipt(order.toString());
					break;
				}
			}
			else if (command.compare("help") == 0)
			{
				// Display help menu to user
				cout << "\n----------------Help Menu-----------------\n"
					"    menu - displays the menu\n"
					"   add 1 - adds menu item 1 to your order (or add multiple items at once!)\n"
					"remove 1 - removes menu item 1 from your order (or remove multiple items at once!\n"
					"checkout - displays the items currently in your order\n"
					"    help - displays a help menu\n"
					"    exit - terminates the program\n\n";
			}
			else {
				cout << "\nPlease enter a valid command! Type 'help' for more information.\n";
			}

			parameters.clear();
		}
		catch (string ex) {
			cout << "Exception: '" << ex << "' is not a valid command!\nType 'help' for more information!\n";
		}
	}

	cout << "Press any key to quit...";
	std::getchar();

}
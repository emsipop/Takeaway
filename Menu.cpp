#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <typeinfo>
#include <algorithm>

Menu::Menu(const std::string& cvsFile)
{
    // Open input file for reading
    std::ifstream inputFile;
    inputFile.open(cvsFile);

    std::string line;
    std::string word;

    // Check if the file can be opened before extracting
    if (inputFile.fail()) {
        std::cout << "Couldn't open '" << cvsFile << "'!" << std::endl;
    }
    else {
        // Loop through each line in the input file
        while (std::getline(inputFile, line)) {

            // Store each word for the current line in a vector
            std::vector<std::string> cvs_vector;
            std::stringstream strStrm(line);
            while (std::getline(strStrm, word, ','))
                cvs_vector.push_back(word);

            // Create pointers to objects based on item type
            if (cvs_vector[0] == "a") {
                Item* appetiser = new Appetiser(cvs_vector[1], std::stof(cvs_vector[2]), std::stoi(cvs_vector[3]), cvs_vector[4], cvs_vector[5]);
                this->items.push_back(appetiser);
            }
            else if (cvs_vector[0] == "m") {
                Item* main = new MainCourse(cvs_vector[1], std::stof(cvs_vector[2]), std::stoi(cvs_vector[3]));
                this->items.push_back(main);
            }
            else if (cvs_vector[0] == "b") {
                Item* beverage = new Beverage(cvs_vector[1], std::stof(cvs_vector[2]), std::stoi(cvs_vector[3]), std::stoi(cvs_vector[6]), std::stof(cvs_vector[7]));
                this->items.push_back(beverage);
            }
        }
    }
    inputFile.close();
}

std::string Menu::toString()
{
    // Store menu display, size of vector, and index value for menu position
    std::string menu = "";
    int vectorSize = items.size();
    int index = 0;

    // Let user sort by price
    std::string userCommand;
    std::cout << "\nDo you want the menu sorted in order of price?\nType 'a' for ascending order, 'd' for descending order, or press enter to continue.\n";
    std::getline(std::cin, userCommand);

    if (userCommand == "a") {
        std::sort(items.begin(), items.end(), [](Item* a, Item* b)->bool 
            {
                if (typeid(*a) == typeid(*b)) {
                    return a->getPrice() < b->getPrice();
                }
                else {
                    return false;
                }
            });
    }
    else if (userCommand == "d") {
        std::sort(items.begin(), items.end(), [](Item* a, Item* b)->bool
            {
                if (typeid(*a) == typeid(*b)) {
                    return a->getPrice() > b->getPrice();
                }
                else {
                    return false;
                }
            });
    }

    // Add appetisers to menu display 
    menu += "\n----------------Appetisers----------------\n";
    for (int i = 0; i < vectorSize; i++) {
        // If the object type is of the class type then it is displayed
        if (typeid(*items[i]) == typeid(Appetiser)) {
            menu += items[i]->toString(index) + "\n";
            index++;
        }
    }

    // Add main dishes to menu display  
    menu += "----------------Main dishes---------------\n";
    for (int i = 0; i < vectorSize; i++) {
        if (typeid(*items[i]) == typeid(MainCourse)) {
            menu += items[i]->toString(index) + "\n";
            index++;
        }
    }

    // Add beverages to menu display 
    menu += "----------------Beverages-----------------\n";
    for (int i = 0; i < vectorSize; i++) {
        if (typeid(*items[i]) == typeid(Beverage)) {
            menu += items[i]->toString(index) + "\n";
            index++;
        }
    }

    // Return display of menu
    return menu + "\n";
}
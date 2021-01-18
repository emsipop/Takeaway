#include "Beverage.h"

#include <iomanip>
#include <sstream>

Beverage::Beverage(std::string name, float price, int calories, int volume, float abv)
{
    this->name = name;
    this->price = price;
    this->calories = calories;
    this->volume = volume;
    this->abv = abv;
}

bool Beverage::isAlcoholic()
{
    // Checks whether the beverage is alcoholic
    if (abv > 0) {
        return true;
    }
    else {
        return false;
    }
}

std::string Beverage::toString(int index)
{
    std::string bevString = "";

    if (isAlcoholic()) {
        // Convert abv to a string while removing trailing 0s
        std::stringstream str_strm;
        str_strm << abv;
        std::string abvString = str_strm.str();

        // If the beverage is alcoholic the abv value is displayed in menu
        bevString += "(" + std::to_string(index + 1) + ") " + name + ": £" + convertValue(price) + ", " + std::to_string(calories) + " cal (" + std::to_string(volume) + "ml, " + abvString + "% abv)";
    }
    else {
        bevString += "(" + std::to_string(index + 1) + ") " + name + ": £" + convertValue(price) + ", " + std::to_string(calories) + " cal (" + std::to_string(volume) + "ml)";
    }

    // Return value to be added to 'menu' string
    return bevString;
}
#include "Appetiser.h"

Appetiser::Appetiser(std::string name, float price, int calories, std::string shareable, std::string twoForOne)
{
    this->name = name;
    this->price = price;
    this->calories = calories;

    if (shareable == "y") {
        this->shareable = true;
    }

    if (twoForOne == "y") {
        this->twoForOne = true;
    }
}

std::string Appetiser::toString(int index)
{
    std::string appString = "(" + std::to_string(index + 1) + ") " + name + ": $" + convertValue(price) + ", " + std::to_string(calories) + " cal ";

    if (shareable) {
        appString += "(shareable)";
    }

    if (twoForOne) {
        appString += "(2-4-1)";
    }

    // Return value to be added to 'menu' string
    return appString;
}
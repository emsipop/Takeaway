#include "Item.h"

#include <iomanip>
#include <sstream>

std::string Item::toString(int index)
{
    // Return value to be added to 'menu' string
    return "(" + std::to_string(index + 1) + ") " + name + ": $" + convertValue(price) + ", " + std::to_string(calories) + " cal";
}

std::string Item::convertValue(float value) {
    // Set precision of float value and convert to string 
    std::stringstream str_strm;
    str_strm << std::fixed << std::setprecision(2) << value;
    std::string valueString = str_strm.str();
    return valueString;
}
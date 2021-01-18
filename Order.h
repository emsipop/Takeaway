#pragma once

#include "ItemList.h"

class Order :
    public ItemList
{
    // Inherited fields from ItemList parent class:
        // items;

    // Store the total and savings of the order
    float total = 0;
    float savings = 0;

    // Vectors to store the items in order and item prices on the 2-4-1 deal
    std::vector<Item*> orderItems;
    std::vector<float> twoForOnePrices;

public:
    // Add and remove items from order
    void add(Item* item);
    void remove(int index);

    // Calculate the total and savings - taking into account the 2-4-1 deals
    void calculateTotal();

    // Write the user's order to a text file called 'receipt.txt'
    void printReceipt(std::string orderString);

    // Display items in the order vector with total price and savings
    std::string toString();

    // Function converts float to string without trailing 0s
    std::string convertValue(float value);

    int getOrderSize() {
        return orderItems.size();
    }
};


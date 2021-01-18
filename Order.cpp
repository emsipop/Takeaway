#include "Order.h"
#include "Appetiser.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>


void Order::add(Item* item)
{
	// Notify user of change and add item to the order
	std::cout << item->getName() << " added to order!\n";
	orderItems.push_back(item);

	// If the item is an appetiser check for 2-4-1 deal
	if (typeid(*item) == typeid(Appetiser)) {
		Appetiser* a = static_cast<Appetiser*>(item);
		if (a->getTwoForOne()) {
			twoForOnePrices.push_back(a->getPrice());
		}
	}
}

void Order::remove(int index)
{
	int i = index - 1;

	// Check if item is in the order
	if (std::count(orderItems.begin(), orderItems.end(), orderItems[i]))
	{
		// Notify user of change
		std::cout << orderItems[i]->getName() << " removed from order!\n";

		// If the item is an appetiser check for 2-4-1 deal
		if (typeid(*orderItems[i]) == typeid(Appetiser)) {
			Appetiser* a = static_cast<Appetiser*>(orderItems[i]);
			if (a->getTwoForOne()) {
				auto value = std::find(twoForOnePrices.begin(), twoForOnePrices.end(), a->getPrice());
				if (value != twoForOnePrices.end()) {
					twoForOnePrices.erase(value);
				}
			}
		}
		// Remove item from the order
		orderItems.erase(std::remove(orderItems.begin(), orderItems.end(), orderItems[i]), orderItems.end());
	}
	else
	{
		std::cout << "That item is not in your order!\n";
	}
}

void Order::calculateTotal()
{
	total = 0;
	savings = 0;

	// Add order item prices to total
	for (auto item : orderItems) {
		total += item->getPrice();
	}

	// Sort 2-4-1 prices in order
	std::sort(twoForOnePrices.begin(), twoForOnePrices.end());

	// Add lowest 2-4-1 price(s) to savings
	int count = twoForOnePrices.size();
	if (count > 1) {
		if (count % 2 == 0) {
			for (int i = 0; i < count / 2; i++) {
				savings += twoForOnePrices[i];
			}
		}
		else {
			for (int i = 0; i < (count - 1) / 2; i++) {
				savings += twoForOnePrices[i];
			}
		}
	}

	total -= savings;
}

void Order::printReceipt(std::string orderString)
{
	// Output order summary to receipt.txt
	std::ofstream receiptFile;
	receiptFile.open("receipt.txt");
	receiptFile << orderString;
	std::cout << "\nOrder complete!\nYour receipt can be found in 'receipt.txt'\n\n";
}

std::string Order::toString()
{
	std::string order = "\n===== Order Summary =====\n";

	// Add each item's display to order string
	int vectorSize = orderItems.size();
	for (int i = 0; i < vectorSize; i++) {
		order += orderItems[i]->toString(i) + "\n";
	}

	order += "-------------\n";

	// Calculate total and savings
	calculateTotal();

	if (savings > 0) {
		order += "2-4-1 discount applied! Savings: £" + convertValue(savings) + "\n";
	}

	order += "Total: £" + convertValue(total) + "\n\n";

	return order;
}

std::string Order::convertValue(float value)
{
	// Set precision of float value and convert to string 
	std::stringstream str_strm;
	str_strm << std::fixed << std::setprecision(2) << value;
	std::string valueString = str_strm.str();
	return valueString;
}

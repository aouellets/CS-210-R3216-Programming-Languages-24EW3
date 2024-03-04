#include "ItemTracker.h"
#include <iostream>
#include <string>

int main() {
    ItemTracker tracker;
    tracker.initializeFromFile("CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        std::cout << "Menu:\n"
                  << "1. Find frequency of an item\n"
                  << "2. Print all item frequencies\n"
                  << "3. Print histogram of item frequencies\n"
                  << "4. Exit program\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string item;
                std::cout << "Enter item name: ";
                std::cin >> item;
                int freq = tracker.findFrequency(item);
                if (freq != -1) {
                    std::cout << "Frequency of " << item << ": " << freq << std::endl;
                } else {
                    std::cout << "Item not found." << std::endl;
                }
                break;
            }
            case 2:
                tracker.printAllFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid option, please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}

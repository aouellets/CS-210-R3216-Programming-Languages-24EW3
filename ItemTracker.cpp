#include "ItemTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void ItemTracker::initializeFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string item;
    while (infile >> item) {
        ++itemFrequencies[item];
    }
    infile.close();

    // Write to frequency.dat file as a backup
    writeFrequencyFile("frequency.dat");
}

int ItemTracker::findFrequency(const std::string& item) {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    } else {
        return -1; // Item not found
    }
}

void ItemTracker::printAllFrequencies() {
    for (const auto& pair : itemFrequencies) {
        std::cout << std::setw(15) << std::left << pair.first << " " << pair.second << std::endl;
    }
}

void ItemTracker::printHistogram() {
    for (const auto& pair : itemFrequencies) {
        std::cout << std::setw(15) << std::left << pair.first;
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void ItemTracker::writeFrequencyFile(const std::string& filename) {
    std::ofstream outfile(filename);
    if (!outfile.is_open()) {
        std::cerr << "Error creating file: " << filename << std::endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        outfile << pair.first << " " << pair.second << std::endl;
    }
    outfile.close();
}

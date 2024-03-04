#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies;

public:
    void initializeFromFile(const std::string& filename);
    int findFrequency(const std::string& item);
    void printAllFrequencies();
    void printHistogram();
    void writeFrequencyFile(const std::string& filename);
};

#endif // ITEMTRACKER_H

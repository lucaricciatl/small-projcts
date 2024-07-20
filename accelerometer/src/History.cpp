
#include <iostream>
#include "accelerometer/History.h"
#include "accelerometer/Writer.h"

// Method to add a string to the history
void History::addString(const std::string& str) {
   mHistory.push_back(str);

}

// Method to clear the history
void History::clearHistory() {
    mHistory.clear();

}

// Method to display the history
void History::displayHistory() const {
    for (const auto& entry : mHistory) {
        std::cout << entry;
    }
}

// Method to display the history
void History::saveHistory(const std::string& aFilename) {
    Writer mWriter;
    mWriter.writeStringsToFile(mHistory, aFilename);
}


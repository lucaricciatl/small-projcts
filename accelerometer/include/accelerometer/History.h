#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>
#include <vector>

class History{
private:
    std::vector<std::string> mHistory;  // Private member to store history
public:

    void saveHistory(const std::string& aFilename);

    // Method to add a string to the history
    void addString(const std::string& str);

    // Method to clear the history
    void clearHistory();

    // Optional: Method to display the history
    void displayHistory() const;


};

#endif // HISTORY_HPP

#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <string>
#include "Parser.h"
#include "accelerometer/Logging.h"
#include <memory>
class DataProcessor {
public:
    DataProcessor(const std::shared_ptr<AccLogger> logger)
        : logger(logger), parser(logger) {};
    void SetInputFile(const std::string& aFilename) { mFilename = aFilename; }
    void StartProcessing();
    void SaveLogs(const std::string& aFilename);
    void ShowStatistics();
private:
    // Method to process each line from the file
    void processLine(const std::string& line);
    std::string mFilename;
    const std::shared_ptr<AccLogger> logger; // Shared ownership of AccLogger
    Parser parser;

};

#endif // DATAPROCESSOR_H

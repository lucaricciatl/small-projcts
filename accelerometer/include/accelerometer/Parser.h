#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <memory>
#include <sstream>
#include "accelerometer/Logging.h"

class Parser {
public:
    // Constructor to initialize the logger with a unique pointer
    explicit Parser(const std::shared_ptr<AccLogger> logger);
    // Function to calculate checksum
    static uint8_t calculateChecksum(const std::string& message);

    // Function to validate the checksum
    bool validateChecksum(const std::string& message, const std::string& checksumStr);

    void extractAccelerometerData(const std::string& line);

    const std::shared_ptr<AccLogger> logger;
};

#endif // PARSER_H

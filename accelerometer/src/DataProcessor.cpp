
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "accelerometer/DataProcessor.h"
#include "accelerometer/Logging.h"
#include "accelerometer/History.h"

void DataProcessor::StartProcessing() {
    // Open the file
    std::ifstream file(mFilename);
    // Check if the file stream is open
    if (!file.is_open()) {
        logger->error("Unable to open file");
    }

    // Check if the file is empty
    if (file.peek() == std::ifstream::traits_type::eof()) {
        logger->error("File is empty");
    }

    // Read the file line by line
    std::string line;
    while (std::getline(file, line)) {
        // Process each line
        processLine(line);
    }

    // Check for errors during reading
    if (file.bad()) {
        logger->error("Error occurred while reading the file");
    }

    // Close the file
    file.close();

    logger->ShowStatistics();
}


void DataProcessor::processLine(const std::string& line) {
    #ifdef WIN32
        const int linesize = 14;
    #else LINUX
        const int linesize = 15;
    #endif
    if (line.size() != linesize || line.substr(0, 3) != "#G4") {
        logger->error("invalid string format");
        logger->stats.incrementInvalidParsed();
        return;
    }
    std::string message = line.substr(0, 12); // Get the message part without checksum
    std::string checksumStr = line.substr(12, 2); // Get the checksum part
    if (parser.validateChecksum(message, checksumStr)) {
        std::string datastring = line.substr(3, 9);
        parser.extractAccelerometerData(datastring);
    };
}

void DataProcessor::SaveLogs(const std::string& aFilename) {
    SetInputFile(aFilename);
    History historyRef = logger->GetHistory();
    historyRef.saveHistory(aFilename);
}

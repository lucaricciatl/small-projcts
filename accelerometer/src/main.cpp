#include <iostream>
#include <memory>
#include "accelerometer/DataProcessor.h"
#include "accelerometer/Parser.h"


const std::string LOGS_FILENAME = "logs.txt";
const std::string SAMPLE_DATA_FILENAME = "sample_data.txt";
const bool compensateG = true;

// Function to wait for a key press
void pressAnyKeyToContinue() {
    std::cout << "Press any key to continue...";
    std::cin.get();
}

int main() {

    std::shared_ptr<AccLogger> logger = std::make_shared<AccLogger>();
    logger->SetGravityCompensation(true);
    logger->logtime(true,false);
    DataProcessor dataProcessor(logger);
    dataProcessor.SetInputFile(SAMPLE_DATA_FILENAME);
    dataProcessor.StartProcessing();
    dataProcessor.SaveLogs(LOGS_FILENAME);
    pressAnyKeyToContinue();
}

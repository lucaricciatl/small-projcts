#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <iomanip>
#include "accelerometer/Logging.h"
#include "accelerometer/Parser.h"
#include "accelerometer/Parameters.h"

namespace {
    int hexCharToValue(char c) {
        int asciiValue = (int)c; // Convert char to int (ASCII value)
        return asciiValue;
    }



    int hexToSignedInt8(const std::string& hexStr) {
        // Convert hex string to unsigned 8-bit integer
        uint8_t value = static_cast<uint8_t>(std::stoul(hexStr, nullptr, 16));

        // Convert to signed 8-bit integer using 2's complement
        if (value & 0x80) { // Check if the sign bit (8th bit) is set
            return static_cast<int8_t>(value - 0x100); // Subtract 256 to get the correct negative value
        }
        else {
            return static_cast<int8_t>(value);
        }
    }

    uint8_t hexToUnsignedInt8(const std::string& hexStr) {
        // Convert hex string to unsigned 8-bit integer
        return static_cast<uint8_t>(std::stoul(hexStr, nullptr, 16));
    }

    int16_t hexToSignedInt(const std::string& hexStr) {
        // Convert hex string to unsigned integer
        uint16_t value = std::stoul(hexStr, nullptr, 16);

        // Convert to signed integer using 2's complement
        if (value & 0x800) { // Check if the sign bit is set
            return static_cast<int16_t>(value | 0xF000); // Extend sign to 16 bits
        }
        else {
            return static_cast<int16_t>(value);
        }
    }



    // Function to convert an integer to its hexadecimal string representation
    std::string intToHexString(int value) {
        std::stringstream ss;
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(value);
        return ss.str();
    }

    // Function to convert a hexadecimal string to an integer
    int hexStringToInt(const std::string& hexStr) {
        int value;
        std::stringstream ss;
        ss << std::hex << hexStr;
        ss >> value;
        return value;
    }
    // Function to sum two hexadecimal values given as strings
    std::string sumHexValues(const std::string& hex1, const std::string& hex2) {
        // Convert hexadecimal strings to integers
        int value1 = hexStringToInt(hex1);
        int value2 = hexStringToInt(hex2);

        // Sum the integer values
        int sum = value1 + value2;

        // Convert the sum back to a hexadecimal string
        return intToHexString(sum);
    }


}

// Function to calculate checksum
uint8_t Parser::calculateChecksum(const std::string& message){
    uint8_t checksumint = 0;
    int checksumhextoint = 0;
    unsigned char value = 0;
    int checksum = 0;
    size_t  lenght = message.length();
    for (size_t i = 0; i < lenght; i++) {
        value = (unsigned char)message[i];
        std::string hexstr = intToHexString(value);
        int hexstrval = std::stoi(hexstr);
        checksum = hexStringToInt(hexstr);
        checksumhextoint += checksum;
    };
    
    return (uint8_t)checksumhextoint;
}

// Constructor definition
Parser::Parser(std::shared_ptr<AccLogger> logger)
    : logger(std::move(logger)) {} // Move the unique_ptr to the member

// Method to extract and print accelerometer data
void Parser::extractAccelerometerData(const std::string& line) {
    if (line.length() < 8) {
        logger->warning("Invalid message format");
        return;
    }
    std::string xStr = line.substr(0, 3);
    std::string yStr = line.substr(3, 3);
    std::string zStr = line.substr(6, 3);

    try {
        int readx = hexToSignedInt8(xStr) ;
        int ready = hexToSignedInt8(yStr) ;
        int readz = hexToSignedInt8(zStr) ;
        float accX = static_cast<float>(readx) * params.measureToAcc;
        float accY = static_cast<float>(ready) * params.measureToAcc;
        float accZ = static_cast<float>(readz) * params.measureToAcc;
        logger->info("Valid message recived");
        logger->Acceleration(accX, accY, accZ);
    } catch (const std::invalid_argument& e) {
        logger->error("Error converting accelerometer data ");
    } catch (const std::out_of_range& e) {
        logger->error("Error: accelerometer data out of range ");
    }
}

bool Parser::validateChecksum(const std::string& message, const std::string& checksumStr) {
    uint8_t calculatedChecksum = calculateChecksum(message);
    uint8_t providedChecksum = hexToUnsignedInt8(checksumStr);
    bool valid = (calculatedChecksum == providedChecksum);
    if (!valid) { logger->stats.incrementInvalidChecksum(); };
    return valid;
}

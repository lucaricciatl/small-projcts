#include <iostream>
#include <sstream>
#include <vector>

#include "accelerometer/Writer.h"

void Writer::openDocument(const std::string& aFilename) {
    FileStream.open(aFilename, std::ios::out | std::ios::app);
    if (!FileStream.is_open()) {
        std::cerr << "Failed to open or create document: " << aFilename << std::endl;
    }
}

void Writer::writeString(const std::string& content, const std::string& aFilename) {
    FileStream.open(aFilename, std::ios::out | std::ios::app);
    if (FileStream.is_open()) {
        FileStream << content;
    } 
}

void Writer::writeStringsToFile(const std::vector<std::string>& content, const std::string& aFilename) {
    CreateDocument(aFilename);
    const std::string fileContent = AssembleString(content);
    writeString(fileContent,aFilename);
}

std::string Writer::AssembleString(const std::vector<std::string>& content) {
    std::string result;
    for (const auto& line : content) {
        result += line + "\n";
    }
    return result;
}

void Writer::CreateDocument(const std::string& aFilename) {
    std::ofstream outFile(aFilename);
}

void Writer::SetFilename(const std::string& aFilename) {
    std::ofstream outFile(aFilename);
}

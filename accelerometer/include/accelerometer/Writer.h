#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <fstream>
#include <vector>

class Writer {
public:
    void writeStringsToFile(const std::vector<std::string>& content, const std::string& aFilename);

    // Method to write content to the document
    void writeString(const std::string& content, const std::string& aFilename);
    void SetFilename(const std::string& aFilename);
private:
    std::string mFilename;
    std::ofstream FileStream;

    // Method to open or create a document file
    void openDocument(const std::string& aFilename);
    void CreateDocument(const std::string& aFilename);
    std::string AssembleString(const std::vector<std::string>& content);
};

#endif // WRITER_H

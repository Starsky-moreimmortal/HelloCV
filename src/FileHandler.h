#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler {
public:
    static std::string readTextFromFile(const std::string& filepath);
    static bool writeTextToFile(const std::string& filepath, const std::string& content);
    static bool fileExists(const std::string& filepath);
};

#endif
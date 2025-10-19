#include "FileHandler.h"
#include <fstream>
#include <iostream>
#include <sys/stat.h>

// 检查文件是否存在
bool FileHandler::fileExists(const std::string& filepath) {
    struct stat buffer;
    return (stat(filepath.c_str(), &buffer) == 0);
}

// 从文件读取文本内容
std::string FileHandler::readTextFromFile(const std::string& filepath) {
    if (!fileExists(filepath)) {
        std::cerr << "❌ 错误：文件不存在 - " << filepath << std::endl;
        return "";
    }
    
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "❌ 错误：无法打开文件 - " << filepath << std::endl;
        return "";
    }
    
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return content;
}

// 将文本写入文件
bool FileHandler::writeTextToFile(const std::string& filepath, const std::string& content) {
    std::ofstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "❌ 错误：无法创建文件 - " << filepath << std::endl;
        return false;
    }
    
    file << content;
    file.close();
    std::cout << "✅ 文件已保存: " << filepath << std::endl;
    return true;
}
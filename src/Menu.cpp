#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>
#include <cstdlib>

// 清屏函数（跨平台）
void Menu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 显示主菜单
void Menu::showMainMenu() {
    clearScreen();
    std::cout << "================================\n";
    std::cout << "🔐 文本加密解密工具\n";
    std::cout << "================================\n";
    std::cout << "1. 加密文本\n";
    std::cout << "2. 解密文本\n";
    std::cout << "3. 加密文件\n";
    std::cout << "4. 解密文件\n";
    std::cout << "5. 退出程序\n";
    std::cout << "================================\n";
    std::cout << "请选择操作 (1-5): ";
}

// 获取用户选择
int Menu::getUserChoice() {
    int choice;
    while (!(std::cin >> choice) || choice < 1 || choice > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "无效输入，请选择 1-5: ";
    }
    std::cin.ignore(); // 清除换行符
    return choice;
}

// 获取加密密钥
int Menu::getEncryptionKey() {
    int key;
    std::cout << "请输入加密密钥 (整数): ";
    while (!(std::cin >> key)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "无效密钥，请输入整数: ";
    }
    std::cin.ignore();
    return key;
}

// 获取文本输入
std::string Menu::getInputText() {
    std::string text;
    std::cout << "请输入文本: ";
    std::getline(std::cin, text);
    return text;
}

// 获取文件路径
std::string Menu::getFilePath(const std::string& prompt) {
    std::string path;
    std::cout << prompt;
    std::getline(std::cin, path);
    return path;
}

// 处理加密操作
void Menu::handleEncryption() {
    clearScreen();
    std::cout << "🔒 加密操作\n";
    std::cout << "================================\n";
    
    std::string text = getInputText();
    int key = getEncryptionKey();
    
    std::string encrypted = Crypto::encrypt(text, key);
    std::cout << "\n✅ 加密完成！\n";
    std::cout << "加密结果: " << encrypted << std::endl;
}

// 处理解密操作
void Menu::handleDecryption() {
    clearScreen();
    std::cout << "🔓 解密操作\n";
    std::cout << "================================\n";
    
    std::string text = getInputText();
    int key = getEncryptionKey();
    
    std::string decrypted = Crypto::decrypt(text, key);
    std::cout << "\n✅ 解密完成！\n";
    std::cout << "解密结果: " << decrypted << std::endl;
}

// 处理文件加密
void Menu::handleFileEncryption() {
    clearScreen();
    std::cout << "📁 文件加密\n";
    std::cout << "================================\n";
    
    std::string inputFile = getFilePath("请输入要加密的文件路径: ");
    int key = getEncryptionKey();
    std::string outputFile = getFilePath("请输入输出文件路径: ");
    
    std::string content = FileHandler::readTextFromFile(inputFile);
    if (!content.empty()) {
        std::string encrypted = Crypto::encrypt(content, key);
        if (FileHandler::writeTextToFile(outputFile, encrypted)) {
            std::cout << "\n✅ 文件加密完成！\n";
        }
    }
}

// 处理文件解密
void Menu::handleFileDecryption() {
    clearScreen();
    std::cout << "📁 文件解密\n";
    std::cout << "================================\n";
    
    std::string inputFile = getFilePath("请输入要解密的文件路径: ");
    int key = getEncryptionKey();
    std::string outputFile = getFilePath("请输入输出文件路径: ");
    
    std::string content = FileHandler::readTextFromFile(inputFile);
    if (!content.empty()) {
        std::string decrypted = Crypto::decrypt(content, key);
        if (FileHandler::writeTextToFile(outputFile, decrypted)) {
            std::cout << "\n✅ 文件解密完成！\n";
        }
    }
}

// 暂停等待
void Menu::pressAnyKeyToContinue() {
    std::cout << "\n按回车键继续...";
    std::cin.get();
}
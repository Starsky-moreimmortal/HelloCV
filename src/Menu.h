#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
// 主菜单操作
static void showMainMenu();
static int getUserChoice();

// 加密操作
static void handleEncryption();
static void handleDecryption();
static void handleFileEncryption();
static void handleFileDecryption();

// 用户输入
static std::string getInputText();
static int getEncryptionKey();
static std::string getFilePath(const std::string& prompt);

// 工具函数
static void clearScreen();
static void pressAnyKeyToContinue();
};

#endif
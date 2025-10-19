#include <iostream>
#include "Crypto.h"
#include "FileHandler.h"
#include "Menu.h"

int main() {
    while (true) {
        Menu::showMainMenu();
        int choice = Menu::getUserChoice();
        
        switch (choice) {
            case 1: // 加密文本
                Menu::handleEncryption();
                break;
                
            case 2: // 解密文本
                Menu::handleDecryption();
                break;
                
            case 3: // 加密文件
                Menu::handleFileEncryption();
                break;
                
            case 4: // 解密文件
                Menu::handleFileDecryption();
                break;
                
            case 5: // 退出
                std::cout << "\n感谢使用！再见！👋\n";
                return 0;
        }
        
        Menu::pressAnyKeyToContinue();
    }
}
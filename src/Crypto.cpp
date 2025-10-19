#include"Crypto.h"
#include<string>
#include<cctype>

std::string Crypto::encrypt(const std::string& text, int key){
    std::string result = "";

    key%=26;
    if(key < 0) key += 26;

    for(char c : text){
        if(isalpha(c)){
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + key) % 26 + base;
        }
        result += c;
    }
    return result;
}

std::string Crypto::decrypt(const std::string& text, int key){
    return encrypt(text, 26 - (key % 26));
}

    
  
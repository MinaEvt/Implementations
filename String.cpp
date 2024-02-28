//
// Created by Mina on 28.2.2024 г..
//

#include "String.h"
#include <iostream>
#pragma warning (disable: 4996)

const int ONE = 1;

MyString::MyString() : str{nullptr} {
    str = new char[ONE];
    str[0] = '\0';
}

MyString::MyString(char *val) {
    if (val == nullptr){
        str = new char[ONE];
        str[0] = '\0';
    }else{
        str = new char[strlen(val) + ONE];
        strcpy(str, val);
        str[strlen(val)] = '\0';
        std::cout << "The string passed is: " << str << std::endl;
    }
}

MyString::MyString(const MyString &other) {
    str = new char[strlen(other.str) + ONE];
    strcpy(str, other.str);
    str[strlen(other.str)] =  '\0';
}

MyString::MyString(MyString &&source) {
    str = source.str;
    source.str = nullptr;
}
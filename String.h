//
// Created by Mina on 28.2.2024 г..
//

#ifndef IMPLEMENTATIONS_STRING_H
#define IMPLEMENTATIONS_STRING_H

#endif //IMPLEMENTATIONS_STRING_H
class MyString{
    char* str;

public:
    MyString();

    MyString(char* val);

    MyString(const MyString &other);

    MyString(MyString &&source);

    ~MyString();
};
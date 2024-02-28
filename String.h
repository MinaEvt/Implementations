#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
class MyString {
private:
    char* str;

public:
    MyString();

    MyString(const char* val);

    MyString(const MyString& other);

    MyString &operator=(const MyString & other);

    bool operator==(const MyString& other);

    bool operator!=(const MyString& other);

    friend std::ostream& operator<<(std::ostream& ost,const MyString& other);

    friend std::istream& operator>>(std::istream& ist, MyString& other);

    char operator[](int index) const;

    int getLength();

    void print();

    char* toStr() const;

    ~MyString();
};
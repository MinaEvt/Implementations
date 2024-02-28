#include "MyString.h"

MyString::MyString() {
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char *val) {
    if (val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(val) + 1];

        strcpy(str, val);
    }
}

MyString::MyString(const MyString &other) {
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}

MyString &MyString::operator=(const MyString &other) {
    if (this == &other) return *this;
    if (other.str == nullptr) return *this;

    char *new_str = new char[strlen(other.str) + 1];
    strcpy(new_str, other.str);
    delete[] str;
    str = new_str;

    return *this;
}

bool MyString::operator==(const MyString &other) {
    return strcmp(str, other.str) == 0;
}

bool MyString::operator!=(const MyString &other) {
    return !(this == &other);
}

int MyString::getLength() {
    return strlen(str);
}

void MyString::print() {
    std::cout << str << std::endl;
}

char *MyString::toStr() const {
    return str;
}

std::ostream &operator<<(std::ostream &ost, const MyString &other) {
    return (ost << other.toStr());
}

std::istream &operator>>(std::istream &ist, MyString &other) {
    char arr[2048];
    ist.getline(arr, 2048);
    other = arr;
    return ist;
}

char MyString::operator[](int index) const {
    if (index >= strlen(str)) {
        std::cout << "out of bound";
    }
    return str[index];
}

MyString::~MyString() {
    delete[] str;
}
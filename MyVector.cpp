//
// Created by Mina on 28.2.2024 г..
//
#pragma once
#include <iostream>
//#include <cstring>

template <typename T> class MyVector {
private:
    T* arr;

    int capasity;

    int currSize;

public:
    MyVector();

    MyVector(const MyVector& other);

    MyVector& operator=(const MyVector& other);

    void push(const T &other);

    void push(T other, int index);

    T& get(int index) const;

    void pop();

    void remove(int index);

    int getCurrSize() const;

    void print() const;

    ~MyVector()
    {
        delete[] arr;
    }
};


template <typename T> MyVector<T>::MyVector()
{
    arr = new T[1];
    capasity = 1; //capacity
    currSize = 0;
}

template <typename T> MyVector<T>::MyVector(const MyVector& other)
        : arr(nullptr)
{
    arr = new T[other.capasity];
    capasity = other.capasity;
    currSize = other.currSize;
    for (int i = 0; i < capasity; i++) {
        arr[i] = other.arr[i];
    }
}

template <typename T> void MyVector<T>::push(const T& other)
{
    if (currSize == capasity)
    {
        T* temp = new T[2 * capasity];

        for (size_t i = 0; i < capasity; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        capasity *= 2;
        arr = temp;
    }
    arr[currSize] = other;
    currSize++;

}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
    if (this == &other) return *this;
    T arrTemp = new T[other.capasity];
    delete[] arr;
    arr = arrTemp;
    for (int i = 0; i < capasity; i++) {
        arr[i] = other.arr[i];
    }
    capasity = other.capasity;
    currSize = other.currSize;
    return *this;
}

template <typename T> void MyVector<T>::remove(int index)
{
    T* temp = new T[currSize - 1];
    int ind = 0;
    for (size_t i = 0; i < currSize; i++)
    {
        if (i != index){
            temp[ind++] = arr[i];
        }
    }
    delete[] arr;
    arr = temp;
    currSize--;
}

template <typename T> void MyVector<T>::push(T other, const int i)
{
    if (i == currSize)
    {
        push(other);
    }
    else {
        arr[i] = other;
    }
}

template <typename T> T& MyVector<T>::get(int i) const
{
    if (i < currSize)
    {
        return arr[i];
    }
}

template <typename T> void MyVector<T>::pop()
{
    currSize--;
}


template <typename T> int MyVector<T>::getCurrSize() const
{
    return currSize;
}

template <typename T> void MyVector<T>::print() const
{
    for (size_t i = 0; i < currSize; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}
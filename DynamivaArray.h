#pragma once

#include <iostream>

using namespace std;

class DynamicArray {
    int *dynamicArray;
    int length;
    int resv;
public:
    DynamicArray();

    DynamicArray(int);

    DynamicArray(int, int);

    DynamicArray(const DynamicArray &);

    DynamicArray(DynamicArray &&);

    ~DynamicArray();

    int getLength();

    void resize(int);

    int &operator[](int);

    friend DynamicArray operator+(DynamicArray, DynamicArray);

    DynamicArray &operator=(const DynamicArray &);

    DynamicArray &operator=(DynamicArray &&);

    friend bool operator==(DynamicArray &, DynamicArray &);

    friend bool operator!=(DynamicArray &, DynamicArray &);

    friend bool operator>(DynamicArray &, DynamicArray &);

    friend bool operator>=(DynamicArray &, DynamicArray &);

    friend bool operator<(DynamicArray &, DynamicArray &);

    friend bool operator<=(DynamicArray &, DynamicArray &);

    friend ostream &operator<<(ostream &, const DynamicArray &);

    friend istream &operator>>(istream &, const DynamicArray &);

    void reserve(int);

    int capacity();

    void pushBack(int);

    int popBack();


};
//#include "stdafx.h"
#include "DynamivaArray.h"
#include <iostream>
#include <math.h>

DynamicArray::DynamicArray() {
    length = 1;
    dynamicArray = new int[length];
    dynamicArray[0] = 0;
    resv = 0;

}

DynamicArray::DynamicArray(int length, int n) {
    if (length <= 0) {
        throw "Size of the array must be positive.";
    }
    this->length = length;
    dynamicArray = new int[length];
    for (int i = 0; i < length; i++) {
        dynamicArray[i] = n;
    }
    resv = 0;
}

DynamicArray::DynamicArray(int length) {
    if (length <= 0) {
        throw "Size of the array must be positive.";
    }
    this->length = length;
    dynamicArray = new int[length];
    for (int i = 0; i < length; i++) {
        dynamicArray[i] = 0;
    }
    resv = 0;
}

DynamicArray::DynamicArray(const DynamicArray &other) {
    this->length = other.length;
    dynamicArray = new int[this->length];
    for (int i = 0; i < length; i++) {
        dynamicArray[i] = other.dynamicArray[i];
    }
    this->resv = other.resv;
}

DynamicArray::DynamicArray(DynamicArray &&stolen) {
    this->length = stolen.length;
    this->resv = stolen.resv;
    dynamicArray = stolen.dynamicArray;
    stolen.dynamicArray = nullptr;
    stolen.length = 0;
}

DynamicArray::~DynamicArray() {
    delete[] dynamicArray;
}

int DynamicArray::getLength() {
    return length;
}

void DynamicArray::resize(int newSize) {
    if (newSize <= (this->length + this->resv)) {
        for (int i = length; i < newSize; i++) {
            dynamicArray[i] = 0;
        }
        this->length += (newSize - length);
        this->resv -= (newSize - length);
    } else {


        int *arr = new int[newSize];
        for (int i = 0; i < length; i++) {
            arr[i] = dynamicArray[i];
        }
        for (int i = length; i < newSize; i++) {
            arr[i] = 0;
        }

        delete dynamicArray;
        dynamicArray = arr;
        arr = nullptr;
        this->length = newSize;
        this->resv = 0;
    }
}

int &DynamicArray::operator[](int i) {
    if (i >= length) {
        throw "The number is out of bounds of the array";
    }
    return dynamicArray[i];
}

DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
    if (this == &other) {
        return *this;
    }
    length = other.length;
    dynamicArray = new int[length];
    for (int i = 0; i < this->length; i++) {
        dynamicArray[i] = other.dynamicArray[i];
    }

    return *this;
}

DynamicArray &DynamicArray::operator=(DynamicArray &&stolen) {
    delete[] dynamicArray;
    this->length = stolen.length;
    dynamicArray = stolen.dynamicArray;
    stolen.dynamicArray = nullptr;
    stolen.length = 0;
    return *this;
}


void DynamicArray::reserve(int n) {
    int *arr = new int[this->length + n];
    this->resv = n;
    for (int i = 0; i < getLength(); i++) {
        arr[i] = dynamicArray[i];
    }
    delete[] dynamicArray;
    dynamicArray = arr;
    arr = nullptr;
}

int DynamicArray::capacity() {
    return this->resv;
}

void DynamicArray::pushBack(int val) {
    resize(this->length + 1);
    dynamicArray[this->length - 1] = val;
}

int DynamicArray::popBack() {
    int buf = dynamicArray[getLength() - 1];
    resize(getLength() - 1);
    return buf;
}

DynamicArray operator+(DynamicArray first, DynamicArray second) {
    DynamicArray arr(first.length + second.length);
    for (int i = 0; i < first.length; i++) {
        arr[i] = first[i];
    }
    for (int i = first.length; i < second.length; i++) {
        arr[i] = second[i];
    }

    return arr;
}

bool operator==(DynamicArray &first, DynamicArray &second) {
    if (first.length != second.length) {
        throw "Lengths of the arrays do not match";
    }
    for (int i = 0; i < first.getLength(); i++) {
        if (first[i] != second[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(DynamicArray &first, DynamicArray &second) {
    if (first.getLength() != second.getLength()) {
        throw "Lengths of the arrays do not match";
    }
    for (int i = 0; i < first.getLength(); i++) {
        if (first[i] != second[i]) {
            return true;
        }
    }
    return false;
}

bool operator>(DynamicArray &first, DynamicArray &second) {
    int minLength = first.getLength();
    if (minLength > second.getLength()) {
        minLength = second.getLength();
    }
    for (int i = 0; i < minLength; i++) {
        if (first[i] <= second[i]) {
            return false;
        }
    }
    return true;
}

bool operator>=(DynamicArray &first, DynamicArray &second) {
    int minLength = first.getLength();
    if (minLength > second.getLength()) {
        minLength = second.getLength();
    }
    for (int i = 0; i < minLength; i++) {
        if (first[i] < second[i]) {
            return false;
        }
    }
    return true;
}

bool operator<(DynamicArray &first, DynamicArray &second) {
    int minLength = first.getLength();
    if (minLength > second.getLength()) {
        minLength = second.getLength();
    }
    for (int i = 0; i < minLength; i++) {
        if (first[i] >= second[i]) {
            return false;
        }
    }
    return true;
}

bool operator<=(DynamicArray &first, DynamicArray &second) {
    int minLength = first.getLength();
    if (minLength > second.getLength()) {
        minLength = second.getLength();
    }
    for (int i = 0; i < minLength; i++) {
        if (first[i] > second[i]) {
            return false;
        }
    }
    return true;
}

ostream &operator<<(ostream &os, const DynamicArray &arr) {
    for (int i = 0; i < arr.length; i++) {
        os << arr.dynamicArray[i] << " ";
    }
    return os;
}

istream &operator>>(istream &is, const DynamicArray &arr) {
    std::cout << "Enter " << arr.length << " numbers:\n";
    for (int i = 0; i < arr.length; i++) {
        std::cin >> arr.dynamicArray[i];
    }
    return is;
}
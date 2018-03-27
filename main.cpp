#include <iostream>
#include "DynamivaArray.h"

int main() {
    try {
        DynamicArray arr(5, 3);
        DynamicArray arr1(4, 8);
        DynamicArray arr3(arr);
        DynamicArray arr4(4, 7);
        cout << "arr: " << arr << endl;
        DynamicArray arr5(std::move(arr));
        cout << "arr3: " << arr3<<endl;
        cout << "arr5: " << arr5 << endl;
        cout << "arr: " << arr;
        cout << arr1 << endl;
        cout << arr3;
        cout << "length " << arr3.getLength() << endl;
        cout << "arr1: " << arr1 << endl;
        arr1.resize(10);
        cout << "arr1: " << arr1 << endl;
        arr1.pushBack(2);
        arr1.pushBack(5);
        cout << "arr1: " << arr1 << endl;
        arr3.resize(4);
        cout << "arr3: " << arr3 << endl;
        cout << "arr1[7]= " << arr1[7] << endl;
        arr4 = arr1;
        cout << "arr4: " << arr4 << endl;
        cout << "arr + arr4: " << arr + arr4 << endl;
        cout << "arr4 == arr1: " << (arr4 == arr1) << endl;
        cout << "arr4 != arr1: " << (arr4 != arr1) << endl;
        cout << "arr4 > arr: " << (arr4 > arr) << endl;
        cout << "arr4 >= arr: " << (arr4 >= arr) << endl;
        cout << "arr4 < arr: " << (arr4 < arr) << endl;
        cout << "arr4 <= arr: " << (arr4 <= arr) << endl;
    }
    catch (char *s) {
        cout << s << endl;
    }
}
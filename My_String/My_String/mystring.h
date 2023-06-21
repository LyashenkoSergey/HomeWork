#pragma once
#include <iostream>

using namespace std;

class MyString {
private:
    char* array=nullptr;
    int counter=0;
    int maxSize = 10;
    int size = 0;

    int countSymbol(const char array2[]) {
        int counter = 0;
        for (int i = 0; array2[i] !='\0'; i++){
            counter++;
        }
        return counter;
    }

public:
    MyString() {
        array = new char[maxSize];
    }
    MyString(const char* array2[]) {
        array = new char[maxSize];
        operator = (array2);
    }

    MyString(const char array2[]) {
        int size = countSymbol(array2);
        char* buf = new char[size+1];
        for (int i = 0; i < size; i++) {
            buf[i] = array2[i];
        }
        buf[size]='\0';
        delete[] array;
        array = buf;
        this->size = size;
    }
    
    void operator =(const char array2[]) {
        int size2 = countSymbol(array2);
        this->size = size2;
        if (size2 > maxSize) {
            maxSize = size2;
            delete[] array;
            array = new char[maxSize+1];
        }
        for (int i = 0; i < size2; i++) {
            array[i] = array2[i];
        }
        array[size2]='\0';
    }

    bool operator !=(const char array2[]) {
        if (array2 == nullptr) return true;
        else {
            int size2 = countSymbol(array2);
            if (this->size != size2) {
                return true;
            }
            else {
                for (int i = 0; i < size; i++) {
                    if (array[i] != array2[i]) {
                        break;
                        return true;
                    }
                }
                
            }
        }
        return  false;
    };

    void operator +=(const char array2[]) {
        int size2 = countSymbol(array2);
        int newSize = size+size2;
        if (newSize > maxSize) {
            maxSize = newSize;
        }
        char* buf = new char[maxSize];
        for (int i = 0; i < size; i++) {
            buf[i] = array[i];
        }
        for (int i = 0; i < size2; i++) {
            buf[size+i] = array2[i];
        }
        delete[] array;
        array = buf;
        size = newSize;
    }

    char* operator +(const char array2[]) {
        int size2 = countSymbol(array2);
        maxSize = size + size2;
        char* buf = new char[maxSize];
        for (int i = 0; i < size; i++) {
            buf[i] = array[i];
        }
        for (int i = 0; i < size2; i++) {
            buf[size + i] = array2[i];
        }
        return buf;
    }

    bool operator >(const char array2[]) {
        for (int i = 0; i < size; i++) {
            if (array[i] > array2[i]) return true;
            if (array[i] < array2[i]) return false;
        }
        return false;
    }

    bool operator <(const char array2[]) {
        for (int i = 0; i < size; i++) {
            if (array[i] < array2[i]) return true;
            if (array[i] > array2[i]) return false;
        }
        return false;
    }

    bool operator <=(const char array2[]) {
        for (int i = 0; i < size; i++) {
            if (array[i] < array2[i]) return true;
            if (array[i] > array2[i]) return false;
        }
        return true;
    }
    bool operator >=(const char array2[]) {
        for (int i = 0; i < size; i++) {
            if (array[i] < array2[i]) return true;
            if (array[i] > array2[i]) return false;
        }
        return true;
    }

    int stoi() {
        int num = 0;
        int index = 0;
        int k = 1;
        if (array[0] == '-') {
            k = -1;
            index = 1;
        }
        for (int i = index; i < size; i++) {
            num = num * 10 + array[i]-'0';
        }
        num *= k;
        return num;
    }

    char operator [](int i) {
        return array[i];
    }

    bool empty() {
        if (array == nullptr) return true;
        else return false;
    }

    int max_size() {
        return this->size;
    }

    void clear() {
        delete[] array;
        array = nullptr;
    }

    void insert(char ch, int num) {
        if (maxSize < size + 1)
            maxSize = size + 1;
        char* buf = new char[maxSize];
        for (int i = 0; i < num; i++) {
            buf[i] = array[i];
        }
        buf[num] = ch;
        for (int i = num+1; i < size; i++) {
            buf[i] = array[i - 1];
        }
        delete[] array;
        size++;
        array = buf;
    }

    void push(char ch) {
        if (size < maxSize) {
            array[size++] = ch;
        }
        else {
            maxSize = size + 1;
            char* buf = new char[maxSize];
            for (int i = 0; i < size; i++) {
                buf[i] = array[i];
            }
            buf[size] = ch;
            delete[] array;
            size++;
            array = buf;
        }
    }

    void pop(char ch) {
        if (size > 0) {
            size--;
            array[size] = '\0';
        }
    }





    void show() {
        for (int i = 0; i < size; i++) {
            std::cout << array[i];
        }
        cout<<endl;
    }


    ~MyString() {
        if (array!=nullptr) delete[] array;
    }
};

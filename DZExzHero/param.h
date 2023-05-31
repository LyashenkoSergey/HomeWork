

#include <iostream>
#include <fstream>
#include <string>
#include <malloc/malloc.h>
#include <stdio.h>

using namespace std;

template<typename T>
T** createArray(int size1, int size2);
template<typename T>
T* createArray(int size);
template<typename T>
void fillingArray(T**& array, T a, T b);
template<typename T>
void fillingArray(T*& array, T a, T b);
template<typename T>
void showArray(T** array);
template<typename T>
void showArray(T* array);
template<typename T>
void sortArray(T**& array);
template<typename T>
void sortArray(T*& array);
template<typename T>
T** deleteIndexInArray (T** array, int index);
template<typename T>
T* deleteIndexInArray (T* array, int index);
template<typename T>
int findSymbolInArray(T** array, T symbol);
template<typename T>
int findSymbolInArray(T* array, T symbol);



#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>

const int MAX_SIZE = 100;  // Maximum array size

// Function declarations
void loadArrayFromFile(const char *filename, int arr[], int &size);
int findIndex(int arr[], int size, int value);
void modifyValue(int arr[], int index, int newValue);
bool addValue(int arr[], int &size, int value);
bool removeValue(int arr[], int &size, int index);
void displayArray(int arr[], int size);

#endif

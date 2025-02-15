#include "header.h"
#include <stdexcept>  //standard exceptions

using namespace std;

// loading array from file
void loadArrayFromFile(const char *filename, int arr[], int &size) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }

    size = 0;
    while (inFile >> arr[size] && size < MAX_SIZE) {
        size++;
    }

    inFile.close();
}

// checks value exists in the array
int findIndex(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Modify value at a given index (with exception handling)
void modifyValue(int arr[], int index, int newValue) {
    try {
        if (index < 0 || index >= MAX_SIZE) {
            throw out_of_range("Index out of bounds!");
        }
        cout << "Value at index " << index << " changed from " << arr[index] << " to " << newValue << endl;
        arr[index] = newValue;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }
}

// Add a new value to the end of the array (with exception handling)
bool addValue(int arr[], int &size, int value) {
    try {
        if (size >= MAX_SIZE) {
            throw overflow_error("Array is full! Cannot add more elements.");
        }
        arr[size++] = value;
        return true;
    } catch (const overflow_error &e) {
        cout << "Error: " << e.what() << endl;
        return false;
    }
}

// remove value at a given index
bool removeValue(int arr[], int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!" << endl;
        return false;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Reduce array size
    return true;
}

// dsplay  array
void displayArray(int arr[], int size) {
    cout << "Array contents: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

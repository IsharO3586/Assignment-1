//Name: Oh May Ishar


#include "header.h"

using namespace std;

int main() {
    int arr[MAX_SIZE];  // Array storage
    int size = 0;       // Array size
    int choice, value, index, newValue;

    // Load the array from the input file
    loadArrayFromFile("A1input.txt", arr, size);

    while (true) {
        // Display the menu
        cout << "\nMenu:\n";
        cout << "1. Display array\n";
        cout << "2. Search for a number\n";
        cout << "3. Modify a number\n";
        cout << "4. Add a new number\n";
        cout << "5. Remove a number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:  // Display array
                    displayArray(arr, size);
                    break;

                case 2:  // Search for a number
                    cout << "Enter the number to search: ";
                    cin >> value;
                    index = findIndex(arr, size, value);
                    if (index != -1)
                        cout << "Value " << value << " found at index " << index << endl;
                    else
                        cout << "Value " << value << " not found in the array." << endl;
                    break;

                case 3:  // Modify a number with exception handling
                    cout << "Enter the index to modify: ";
                    cin >> index;
                    if (index < 0 || index >= size) {
                        throw out_of_range("Invalid index!");
                    }
                    cout << "Enter the new value: ";
                    cin >> newValue;
                    modifyValue(arr, index, newValue);
                    break;

                case 4:  // Add a new number with exception handling
                    cout << "Enter the number to add: ";
                    cin >> value;
                    if (!addValue(arr, size, value)) {
                        throw overflow_error("Array is full! Cannot add more elements.");
                    } else {
                        cout << "Value " << value << " added to the array." << endl;
                    }
                    break;

                case 5:  // Remove a number
                    cout << "Enter the index to remove: ";
                    cin >> index;
                    if (removeValue(arr, size, index))
                        cout << "Value at index " << index << " removed." << endl;
                    break;

                case 6:  // Exit program
                    cout << "Exiting program..." << endl;
                    return 0;

                default:
                    cout << "Invalid choice! Please try again." << endl;
            }
        } catch (const exception &e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    }

    return 0;
}

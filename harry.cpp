#include <iostream> // Include the standard input-output stream library
using namespace std;

const int SIZE = 10; // Maximum number of elements allowed per array

// Declare global arrays and variables
double arr1[SIZE], arr2[SIZE], merged[SIZE * 2]; // Arrays for storing user inputs and merged data
int n1, n2, mergedSize; // Variables for storing the number of elements in each array and the merged array size

// Function to validate user input (checks if input is between 1 and 10)
bool isValidInput(int n) {
    return (n > 0 && n <= 10);
}

int main() {
    // Input for the first array
    do {
        cout << "Enter number of elements for first array (1-10): ";
        cin >> n1;
        // Check if input is valid
        if (cin.fail() || !isValidInput(n1)) {
            cin.clear();            // Clear error state of cin
            cin.ignore(1000, '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 10.\n";
        }
    } while (!isValidInput(n1)); // Repeat until valid input is provided

    // User enters elements for the first array
    cout << "Enter " << n1 << " decimal numbers: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for the second array
    do {
        cout << "Enter number of elements for second array (1-10): ";
        cin >> n2;
        // Check if input is valid
        if (cin.fail() || !isValidInput(n2)) {
            cin.clear();            // Clear error state of cin
            cin.ignore(1000, '\n'); // Ignore invalid input
            cout << "Invalid input! Please enter a number between 1 and 10.\n";
        }
    } while (!isValidInput(n2)); // Repeat until valid input is provided

    // User enters elements for the second array
    cout << "Enter " << n2 << " decimal numbers: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Merging both arrays into the merged array
    mergedSize = n1 + n2; // Total size of the merged array
    for (int i = 0; i < n1; i++) {
        merged[i] = arr1[i]; // Copy elements of the first array
    }
    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = arr2[i]; // Copy elements of the second array
    }

    // Sorting the merged array in descending order using Bubble Sort
    for (int i = 0; i < mergedSize - 1; i++) {
        for (int j = i + 1; j < mergedSize; j++) {
            if (merged[i] < merged[j]) { // Swap if the next element is greater
                double temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }

    // Display the merged and sorted array
    cout << "Merged array in descending order: ";
    for (int i = 0; i < mergedSize; i++) {
        cout << merged[i] << " "; // Print each element in sorted order
    }
    cout << endl;

    return 0; // Indicate that the program executed successfully
}

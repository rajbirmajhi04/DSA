#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

// Function for Arithmatic Operations
void operations(const int arr1[], const int arr2[],const double arr3[], double result[], double result1[],int size){
    // Addition
    for (int i = 0; i < size; i++){
        result[i] = static_cast<double>(arr1[i]) + static_cast<double>(arr2[i]) + arr2[i];
    }  
    // Substraction
    for (int i = 0; i < size; i++){
        result1[i] = static_cast<double>(arr1[i]) - static_cast<double>(arr2[i]) - arr2[i];
    }  
}

// Function to Find Minimum and Maximum
void findMinMax(const int arr[], int size, int& minValue, int& maxValue) {
    minValue = arr[0];
    maxValue = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
}


// Function to display array
void displayArray(const double arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{   
    const int aSize = 4;

    int arr1[aSize] = {5, 3, 8, 6};
    int arr2[aSize] = {7, 5, 2, 1};
    double arr4[aSize] = {56.56, 23.56, 12.01, 11.45};

    int sum[aSize];
    double result[aSize];

    int substract[aSize];
    double result1[aSize];

    // Function Call
    operations(arr1, arr2, arr4, result, result1, aSize);

    // Display Array
    cout << "Added Array: ";
    displayArray(result, aSize);

    cout << "Substracted Array: ";
    displayArray(result1, aSize);

    // Code to display the sum of an array 
    int array1Size = sizeof(arr1) / sizeof(arr1[0]);
    int array1Sum = 0;
    for (int i = 0; i < array1Size; i++){
        array1Sum += arr1[i];
    }
    cout << "The sum of array 1: " << array1Sum << endl;

    // Code to find the Minimum and Maximum of an array
    int array2Size = sizeof(arr2) / sizeof(arr2[0]);
    int minValue, maxValue;
    findMinMax(arr2, array2Size, minValue, maxValue);
    cout << "Minimum Value: " << minValue << endl;
    cout << "Maximum Value: " << maxValue << endl;

    // Code to compare two arrays
    bool isEqual = true;
    for (int i = 0; i < 5; ++i) {
        if (arr1[i] != arr2[i]) {
            isEqual = false;
            break;
        }
    }
    if (isEqual) {
        cout << "Arrays are equal";
    } else {
        cout << "Arrays are not equal";
    }





    






    


    return 0;
}
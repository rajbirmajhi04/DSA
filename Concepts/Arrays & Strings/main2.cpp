#include <iostream>
using namespace std;

// Passing array using pointer
void displayArray(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

// Passing array using reference
void displayArray(int (&arr)[5]){
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    displayArray(arr, size);
    displayArray(arr, size);

    int s;
    int *array = new(nothrow) int[s];
    cout << "Enter array size: ";
    cin >> s;

    for(int i = 0; i < s; i++){
        arr[i] = i + 1;
    }
    cout << endl;
    
    for(int i = 0; i < s; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    array = nullptr;

    return 0;
}
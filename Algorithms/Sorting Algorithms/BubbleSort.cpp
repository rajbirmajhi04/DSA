#include <iostream>
using namespace std;

void bubbleSort(int array[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < (size - i - 1); j++){
            if(array[j] >= array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void displayArray(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    int array[] = {-2, 45, 0, 11, -9};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted Array: " << endl;
    displayArray(array, size);
    bubbleSort(array, size);
    cout << "Sorted Array: " << endl;
    displayArray(array, size);

    return 0;
}
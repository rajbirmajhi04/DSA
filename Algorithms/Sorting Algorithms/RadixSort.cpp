#include <iostream>
using namespace std;

void display(int array[], int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int getMax(int array[], int size){
    int maxElement = array[0];
    for (int i = 0; i < size; ++i){
        if(array[0] > maxElement){
            maxElement = array[0];
        }
    }
    return maxElement;
}

void countSort(int array[], int size, int exp){
    int output[size];
    int count[10] = {0};

    // store the count of each occurences of each digit 
    // in count array
    for (int i = 0; i < size; i++){
        count[(array[i] / exp) % 10] ++;
    }

    // update count[i] so that it contains 
    // the actual position of the digit in the output array
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    // build the output array using the count array
    for(int i = size - 1;  i >= 0; i--){
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    // copy the sorted array using the output 
    // array back to the original array
    for(int i = 0; i < size; i++){
        array[i] = output[i];
    }
}

void RadixSort(int array[], int size){
    // find the maximum number to determine the number of digits
    int max = getMax(array, size);

    // perform counting sort for each digit
    // starting from the LSD
    for(int exp = 1; max / exp > 0; exp *= 10){
        countSort(array, size, exp);
    }
}

int main()
{
    int array[] = {170, 45, 75, 90, 802, 24, 2, 66, 20, 785, 523, 29, 654, 856, 890, 37, 700};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted Array: " << endl;
    display(array, size);

    RadixSort(array, size);

    cout << "Sorted Array: " << endl;
    display(array, size);

    return 0;
}
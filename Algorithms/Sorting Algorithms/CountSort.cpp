#include <iostream>
using namespace std;

void countSort(int array[], int size){

        // maximum element 
        int maxElement = array[0];
        for(int i = 0; i < size; ++i){
            if(array[i] > maxElement){
                maxElement = array[i];
            }
        }
      
        // create a count array with all elements zeros
        int *count = new int[maxElement + 1];
        for(int i = 0; i <= maxElement; ++i){
            count[i] = 0;
        }

        // count the occurences of each element in the input array
        for(int i = 0; i < size; ++i){
            count[array[i]]++;
        }

        // storing cuilative count 
        for(int i = 1; i <= maxElement; ++i){
            count[i] += count[i - 1];
        }

        // create an output array to store the sorted elements
        int *output = new int[size];

        // place the element in correct position in the output array
        for(int i = size - 1; i >= 0; --i){
            output[count[array[i]] - 1] = array[i];
            count[array[i]]--;
        }

        // copy the sorted elements back to the original array
        for(int i = 0; i < size; ++i){
            array[i] = output[i];
        }


        // deallocate memory
        delete[] count;
        delete[] output;
}
int main()
{
    int array[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 2};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Unsorted Array: " << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    
    cout << endl;
    cout << endl;

    cout << "Sorted Array: " << endl;
    countSort(array, size);
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
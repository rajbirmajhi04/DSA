#include <iostream>
using namespace std;

void quickSort(int array[], int low, int high){
    if(low < high){
        int pivot = array[high]; 
        int low_idx = low - 1; 

        for(int j = low; j <= high - 1; j++){
            if(array[j] <= pivot){
                low_idx++;
                int temp = array[low_idx];
                array[low_idx] = array[j];
                array[j] = temp;
            }
        }
        // swap pivot element
        int temp = array[low_idx + 1];
        array[low_idx] = array[high];
        array[high] = temp;

        // partition index
        int pi = low_idx + 1; 
        
        // recursively apply quick sort to the left and right sub arrays
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
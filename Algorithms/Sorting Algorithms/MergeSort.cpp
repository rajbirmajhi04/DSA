#include <iostream>
#include <cstring>
using namespace std;

void mergeSort(int array[], int left, int right){
    if(left < right){
        // find mid point
        int mid = left + (right - left) / 2;

        // recursively sort the first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // create temporary arrays sizes
        int s1 = mid - left + 1;
        int s2 = right - mid;

        // create temporary arrays 
        int *leftArray = new int[s1]; 
        int *righArray = new int[s2]; 

        // copy data to temporary arrays
        for(int i = 0; i < s1; i++){
            leftArray[i] = array[left + i];
        }
        for(int j = 0; j < s2; j++){
            righArray[j] = array[mid + 1 + j];
        }

        // merge the temporary arrays back into original array
        int i = 0, j = 0, k = left;
        while(i < s1 && j < s2){
            if(leftArray[i] <= righArray[j]){
                array[k] = leftArray[i];
                i++;
            }
            else {
                array[k] = righArray[j];
                j++;
            }
            k++;
        }

        // copy the remaining elements of left array and right array
        while(i < s1){
            array[k] = leftArray[i];
            i++;
            k++;
        }
        while(j < s2){
            array[k] = righArray[j];
            j++;
            k++;
        }
    }
}
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for (int i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    mergeSort(arr, 0, arr_size - 1);
    
    cout << "Sorted array: ";
    for (int i = 0; i < arr_size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
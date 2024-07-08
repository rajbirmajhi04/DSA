#include <iostream>
using namespace std;
int main()
{
    /*
    ? realloc(): used to change the memory allcoation of a previously allocated memory.
    ? reallcoation of memory maintains the already present value and new blocks will be initialized with 
    ? default garbage value

    ! ptr = realloc(ptr, newSize);
    */

    int *arr;
    int size, i;

    // Allocate Memory
    arr = (int*)malloc(size * sizeof(int));
    if(!arr){
        cout << "Memory Allocation Failed!" << endl;
        exit(0);
    }
    else {
        cout << "Memory successfully allocated!" << endl;
        for(int i = 0; i < size; i++){
            arr[i] = i + 1;
        }

        cout << "Array Elements: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

        // Resize Array
        int n;
        cout << "Enter new size: ";
        cin >> n;
        arr = (int*)realloc(arr, n * sizeof(int));

        if(!arr){
            cout << "Memory re-allocation failed!" << endl;
            exit(0);
        }
        else {
            cout << "Memory re-allocated successfully!" << endl;
            for(int i = 5; i < n; i++){
                arr[i] = i + 1;
            }
            cout << "Resized array elements: ";
            for(int i = 0; i < n; i++){
                cout << arr[i] << " ";
            }
            cout << endl;

            free(arr);
        }
        free(arr);
    }





















    return 0;
}
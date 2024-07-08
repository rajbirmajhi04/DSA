#include <iostream>
using namespace std;
int main()
{
    /*
    ? calloc(): used to dynamically allocate the specified number of blocks of memory of the specified type.
    ? It initialze each block with a default value 0. It has two parameters or arguments 

    ! ptr = (int*)calloc(n, sizeof(int));
    ! ptr = (cast-type*)calloc(n, element-size);
    * n is the no. of elements 
    * allcoates a contiguous space in memory for n elements each with size of the int
    * if space is insufficient, allocation fails and returns a NULL pointer
    */

    int n, i;

    // get the number of elements for the arrays
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Entered number of elements: " << n << endl;

    // dynamically allocate memory using calloc()
    int *ptr = (int*)calloc(n, sizeof(int));

    if (ptr == NULL){
        cout << "Memory allocation failed!" << endl;
        exit(0);
    }
    else {
        cout << "Memory successfully allocated!" << endl;
        for(int i = 0; i < n; i++){
            ptr[i] = i + 1;
        }

        for(int i = 0; i < n; i++){
            cout << ptr[i] << " ";
        }

        free(ptr);
    }





















    return 0;
}
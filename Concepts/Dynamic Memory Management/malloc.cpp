#include <iostream>
using namespace std;
int main()
{
    /*
    ? malloc(): used to dynamically allocate a single large block of memory with specified size.
    ? It returns a pointer of type void which can be cast into a pointer of any form. It doesn't initialize
    ? memory at execution time so that it has initialzied each block with the default garbage value initially

    ! ptr = (int*)malloc(100 * sizeof(int));
    ! ptr = (cast-type*)malloc(100 * sizeof(byte size));
    * Means: this will allocate 400 bytes of memory and the pointer holds the address of the first byte in the 
    * allocated memory
    */

    int n, i;

    // get the number of elements for the arrays
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Entered number of elements: " << n << endl;

    // dynamically allocate memory using malloc()
    // this poinetr will hold the base address of the block created
    int *ptr = (int*)malloc(n * sizeof(int));

    // check if the memory has been successfully allocated by the malloc or not
    if(ptr == NULL){
        cout << "Memory not allocated!" << endl;
        exit(0);
    }
    else {
        cout << "Memory allcoated successfully!" << endl;

        // assign values to the allocated memory
        for(int i = 0; i < n; i++){
            ptr[i] = (i + 1);
        }

        // print the elements of the array
        cout << "Array eleemnts are: ";
        for(int i = 0; i < n; i++){
            cout << ptr[i] << " ";
        }

        // free the allocated memory
        free(ptr);
    }


  







 



























    return 0;
}
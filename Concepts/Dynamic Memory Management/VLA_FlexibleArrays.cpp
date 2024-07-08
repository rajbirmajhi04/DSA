#include <iostream>
using namespace std;

typedef struct FlexibleArray{
    int length;
    int array[];
}fam;

int main()
{

    // Variable Length Array
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int array[n];
    for(int i = 0; i < n; i++){
        array[i] = i + 1;
    }

    cout << "Array Elements: ";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    
    // Flexible Array Members
    // that is defined inside a structure without any dimensions and their size is flexible
    

    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    // Declaration
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing Using Indexing
    cout << arr[4] << endl;

    // Accessing Using Loop
    cout << "Displaying Array Using For Loop: " << endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Displaying Array Using Ranged Loop: " << endl;
    for(int n: arr){
        cout << n << " ";
    }
    cout << endl;

    cout << "Displaying Array Using While Loop: " << endl;
    int i = 0;
    while(i < 5){
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;

    cout << "Displaying Array Using Do-While Loop: " << endl;
    i = 0;
    do {
        cout << arr[i] << " ";
        i++;
    }
    while(i < 5);
    cout << endl;

    // Using Pointers
    int *pointer = arr;
    int first_element = *pointer;
    int second_element = *(pointer + 1);
    int third_element = *(pointer + 2);

    // Length of an array
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Length: " << length << endl;
    
    // Modifying Elements
    arr[0] = 10;

    // Max and Min Elements
    int max = arr[0];
    int min = arr[0];
    for(int i = 0; i < length; i++){
        if(arr[i] > max){
            max = arr[i];
        }
        if(arr[i] < min){
            min = arr[i];
        }
    }
    cout << "Minimum Element: " << min << endl;
    cout << "Maximum Element: " << max << endl;

    // Searching 
    int target;
    bool found = false;
    cout << "Enter element to find: ";
    cin >> target;

    for(int i = 0; i < length; i++){
        if(arr[i] == target){
            found = true;
            break;
        }
        else {
            found = false;
            break;
        }
    }

    // Inserting Elements (Manually)
    int pos;
    int value;
    cout << "Enter position: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    for(int i = 5 - 1; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    
    // Deleting Element (Manually)
    for(int i = pos; i < 5 - 1; i++){
        arr[i] = arr[i + 1];
    }
    arr[5 - 1] = 0;

    // Displaying Array
    cout << "Displaying Array Using For Loop: " << endl;
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int size;
    cout << "Enter array size: ";
    cin >> size;
    int array[size];

    cout << "Enter " << size << " integers: " << endl;
    for(int i = 0; i < size; i++){
        cout << "Element at " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << endl;

    cout << "Displaying Array: " << endl;
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
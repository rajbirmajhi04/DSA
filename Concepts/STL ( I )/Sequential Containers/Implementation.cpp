#include <forward_list>
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <list>
using namespace std;

// function prototypes
void display_flist(forward_list <int> &fl);
void display_array(int *array, int size);
void display_vector(vector <int> &v);
void display_list(list <int> &l);
void initializer();
void array_operations(int *array, int size);
void fli_operations(forward_list <int> &fl);
void vector_operations(vector <int> &v);
void list_operations(list <int> &l);

int main()
{   
    initializer();

    return 0;
}

// display functions
void display_array(int *array, int size){
    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
    array = nullptr;
}
void display_vector(vector <int> &v){
    for(const int &i: v){
        cout << i << " ";
    }
    cout << endl;
}
void display_list(list <int> &l){
    for(const int &i: l){
        cout << i << " ";
    }
    cout << endl;
}
void display_flist(forward_list <int> &fl){
    for(const int &i: fl){
        cout << i << " ";
    }
    cout << endl;
}

// init function
void initializer(){
    int choice;
    cout << "Initialize (1. Array, 2. Vector, 3. List, 4. Flist): ";
    cin >> choice;

    int size;
    cout << "Enter size: ";
    cin >> size;

    if (choice == 1) {
        int *array = new int[size]();
        cout << "Array initialized successfully!" << endl;
        display_array(array, size);
        array_operations(array, size);
    }
    else if (choice == 2){
        vector <int> vec(size, 0);
        cout << "Vector initialized successfully!" << endl;
        display_vector(vec);
    }
    else if (choice == 3){
        list <int> li(size, 0);
        cout << "List initialized successfully!" << endl;
        display_list(li);
    }
    else if (choice == 4){
        forward_list <int> fli;
        fli.assign(size, 0);
        cout << "Flist initialized successfully!" << endl;
        display_flist(fli);
    }
    else {
        cout << "Invalid choice!" << endl;
    }
}

// operations function
void array_operations(int *array, int size){
    int choice;
    cout << "Operation Choice: " << endl;
    cout << "(1). Add, (2). Display, (3). Modify, (4). Sort" << endl;
    cin >> choice;

    if (choice == 1){
        cout << "Enter " << size << " elements: " << endl;
        for(int i = 0; i < size; i++){
            cout << "Element at index [" << i << "]: ";
            cin >> array[i];
        }
        display_array(array, size);
        array_operations(array, size);
    }
    else if (choice == 2){
        cout << "Displaying Array: " << endl;
        display_array(array, size);
        array_operations(array, size);
    }
    else if (choice == 3){
        int key;
        int index;

        cout << "Enter element: ";
        cin >> key;
        cout << "Enter index: ";
        cin >> index;

        if(index < 0 || index > size){
            cout << "Invalid Index" << endl;
        }
        else {
            for(int i = size; i > index; --i){
                array[i] = array[i - 1];
            }
            array[index] = key;
            ++ size;

            cout << "Array after modifying: " << endl;
            display_array(array, size);
        }
        array_operations(array, size);
    }
    else if (choice == 4){
        cout << "Original Array: " << endl;
        display_array(array, size);

        sort(array, array + size);

        cout << "Sorted Array: " << endl;
        display_array(array, size);

        array_operations(array, size);
    }
    else {
        cout << "Invalid Choice!" << endl; 
    }
    initializer();
}


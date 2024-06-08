#include <iostream>
using namespace std;

// Function takes 1-D array as parameter
void displayArray(int aSize, int m[]);
// Function takes 2-D array as parameter
void displayTwoDarray(int **arr, int r, int c );
// Function that takes 2-D array as parameter 
void display(int n[][2]) {
    cout << "Displaying Values: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << "num[" << i << "][" << j << "]: " << n[i][j] << endl;
        }
    }
}

int main()
{

    // Take the size of array as input
    int arraySize;
    cout << "Enter size of array: ";
    cin >> arraySize;

    
    // Declaration of array
    char grade[5];
    // An array can be initialized without specifying the size but cant be declare
    // Declare and initialize an array
    double marks[5] = {10, 20, 30, 40, 50};
    // Array with empty members
    string Fruits[5] = {"Apple", "Banana", "Cherry"}; // Empty spaces will be filled with zeros
   
  
    
    // Declare array
    string Animal[arraySize];

    // store the amount of data in the array
    cout << "Enter " << arraySize << " names: ";
    for (int i = 0; i < arraySize; ++i){
        cin >> Animal[i];
    }

    // display the array
    // ranged based loop method
    cout << "Animal array is: ";
    for (string a: Animal){
        cout << a << " ";
    }

    double numbers[arraySize];
    double sum = 0;
    double count = 0;
    double average;

    cout << "Enter " << arraySize << " numbers: ";
    for (int i = 0; i < arraySize; i++){
        cin >> numbers[i];
    }

    for (double num: numbers){
        cout << num << " ";
        sum += num;
        ++count;
    }
    cout << "The sum is: " << sum << endl;

    average = sum / count;
    cout << "The average is: " << average << endl;
    
    
    // Passing 1-D array to function
    cout << "Enter " << arraySize << " numbers: ";
    int numberArray[arraySize];
    for (int i = 0; i < arraySize; i++){
        cin >> numberArray[i];
    }

    // 2-D array size input
    int row, column;
    cout << "Enter rows and columns respectively: ";
    cin >> row >> column;
    cout << "Order: " << "[" << row << "] [" << column << "]" << endl;

    // Passing Multidimensional Array to function
    /*
        Its not mandetory to specify the number of rows in the 
        array but the number of column should always be specified
    */
   
            int twoDarray[row][column];
            cout << "Enter elements for the " << row << " x " << column << " array: " << endl;
            for (int i = 0; i < row; i++){
                for (int j = 0; j < column; j++){
                    cout << "Enter element at position (" << i << ", " << j << "): ";
                    cin >> twoDarray[i][j];
                }
            }
   


   int num[3][2] = {
    {3, 4},
    {9, 2},
    {7, 1}
    
   };


    // Calling Functions
    displayArray(arraySize, numberArray);
    displayTwoDarray(reinterpret_cast<int**>(twoDarray), row, column);
    display(num);
    return 0;
}

// Function 1
void displayArray(int aSize, int m[]){
    cout << "Display number array: " << endl;
    for (int i = 0; i < aSize; ++i){
        cout << "Number " << i + 1 << ": " << m[i] << endl;
    }
}

// Function 2
void displayTwoDarray(int **arr, int r, int c){
    cout << "The 2D array is: " << endl;
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}




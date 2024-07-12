#include <iostream>
using namespace std;
int main()
{
    // Multidimensional Array
    int arr[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;

    int row, column;
    cout << "Enter rows: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> column;
    
    int two_dArray[row][column];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            two_dArray[i][j] = (i + 1) * (j + 1); 
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cin >> two_dArray[i][j];
        }
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << two_dArray[i][j] << " ";
        }
    }
    return 0;
}
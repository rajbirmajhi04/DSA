#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int array[], int size){
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < (size - i - 1); j++){
			if (array[j] >= array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int binarySearch(int array[], int key, int low, int high){
	while(low <= high){
		int mid = low + (high - low) / 2;
		if (array[mid] == key){
			return mid;
		} 
		else if(array[mid] < key){
			low	= mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}
int main() {

	int array[] = {7, 8, 5, 4, 2, 3, 1, 9, 10};
	int size = sizeof(array)/ sizeof(array[0]);
	int key = 7;

	cout << "Unsorted Array: " << endl;
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;

	bubbleSort(array, size);

	cout << "Sorted Array: "<< endl;
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;

	int result = binarySearch(array, key, 0, size - 1);
	if(result == -1){
		cout << "Element does not exist!"<< endl;
	}
	else {	
		cout << "Element found at index: " << result << endl;

	}




  return 0;
}
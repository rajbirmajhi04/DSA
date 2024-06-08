#include <iostream>
using namespace std;

int linearSearch(int array[], int size, int key){
	for(int i = 0; i < size; i++){
		if(array[i] == key){
			return i;
		}
	}
	return -1;
}

int main() {

	int array[] = {2,3,6,7,8,9,1};
	int size = sizeof(array)/sizeof(array[0]);
	int result = linearSearch(array, size, 1);
	(result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;

	return 0;
}
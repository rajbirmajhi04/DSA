#include <iostream>
#include <vector>
using namespace std;

// Function to maintain the max heap property for a given subtree
void maxHeapify(vector <int> &maxHeap, int n, int i){
    int largest = i; // Init the largest as root
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    // Check if LC > Root
    if(leftChild < n && maxHeap[leftChild] > maxHeap[largest]){
        largest = leftChild;
    }

    // Check if RC > Root
    if (rightChild < n && maxHeap[rightChild] > maxHeap[largest]){
        largest = rightChild;
    }

    // Check if root is largest
    if(largest != i){
        swap(maxHeap[i], maxHeap[largest]);

        // Recursively heapify the affected sub tree
        maxHeapify(maxHeap, n, largest);
    }
}

// Function to make root node, the largest element
void buildMaxHeap(vector <int> &maxHeap){
    int n = maxHeap.size();

    // Build Heap (Rearrange Array)
    for(int i = n / 2 - 1; i >= 0; i--){
        maxHeapify(maxHeap, n, i);
    }
}

// Function to maintain the min heap property for a given subtree
void minHeapify(vector <int> &minHeap, int n, int i){
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && minHeap[leftChild] < minHeap[smallest]){
        smallest = leftChild;
    }

    if(rightChild < n && minHeap[rightChild] < minHeap[smallest]){
        smallest = rightChild;
    }

    if(smallest != i){
        swap(minHeap[i], minHeap[smallest]);
        minHeapify(minHeap, n, smallest);
    }
}

// Function to make the root node, the smallest element
void buildMinHeap(vector <int> &minHeap){
    int n = minHeap.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        minHeapify(minHeap, n, i);
    }
}

// Insert into Max Heap
void maxHeapInsert(vector <int> &heap, int key){
    heap.push_back(key); // Add the new key to the end

}

// Insert into Min Heap
void minHeapInsert(vector <int> &heap, int key){
    heap.push_back(key); // Add the new key to the end
}
int main()
{
    // Init Heap
    vector <int> heap = {4, 10, 3, 5, 1};

    // Build Max Heap
    buildMaxHeap(heap);
    cout << "Max Heap: ";
    for(int i : heap){
        cout << i << " ";
    }
    cout << endl;

    // Build Min Heap
    buildMinHeap(heap);
    cout << "Min Heap: ";
    for(int i: heap){
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
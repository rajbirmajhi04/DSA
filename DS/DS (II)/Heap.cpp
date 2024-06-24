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
    int i = heap.size() - 1; // index of the new key

    // percolate up
    // loop continues as long as i is not the root idnex 
    // and the parent node is less tha the current node
    while(i != 0 && heap[(i - 1) / 2] < heap[i]){
        swap(heap[i], heap[(i - 1) / 2]);
        // index i updated to parent index
        i = (i - 1) / 2;
    }
}

// Insert into Min Heap
void minHeapInsert(vector <int> &heap, int key){
    heap.push_back(key); // Add the new key to the end
    int i = heap.size() - 1; // index of the new key

    // percolate up
    // loop continues as long as i is not the root idnex 
    // and the parent node is less tha the current node
    while(i != 0 && heap[(i - 1) / 2] > heap[i]){
        swap(heap[i], heap[(i - 1) / 2]);
        // index i updated to parent index
        i = (i - 1) / 2;
    }
}

// Node delete function
void deleteNode(vector <int> &heap, int index){
    int n = heap.size();

    if(index >= n){
        cout << "Index out of bounds! " << endl;
        return;
    }

    // if we just removed the last element we are done
    if (index == n - 1){
        heap.pop_back();
        return;
    }
    else {
        // replace the element to be deleted with the last element 
        heap[index] = heap[n - 1];
        heap.pop_back();
    }

    // heapify the node at the given index to maintain the heap property
    maxHeapify(heap, n - 1, index);
    minHeapify(heap, n - 1, index);

    // check if percolate up is needed
    while(index != 0 && heap[(index - 1)/ 2] < heap[index]){
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// peeking functions
int peek(vector <int> &heap){
    if(heap.empty()){
        throw runtime_error("Heap is empty!");
    }
    return heap[0]; // the max or min element is at the root
}

// extract functions
int extract(vector <int> &heap){
    if(heap.empty()){
        throw runtime_error("Heap is empty!");
    }

    int elem = heap[0]; // the min or max element is at root
    heap[0] = heap.back(); // replace root with the last element
    heap.pop_back(); // remove the last elements
    return elem;
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
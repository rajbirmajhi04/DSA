#include <iostream>
using namespace std;

// Table Sizes:- 
    const int table_size1 = 10;
    const int table_size2 = 100;


// Structures:- 
    struct Node {
        int key;
        int value;
        bool isOccupied;
        Node *next;
    };

// Hash Tables:-
    Node *hashTable1[table_size1];

// Table Initializer:-
void initializeHashTable(struct Node *table){
    // Iterate over each slot in the hash table
    for(int i = 0; i < table_size2; i++){
        // setting default values
        table[i].key = -1;
        table[i].value = 0;
        table[i].isOccupied = false;
    }
}

// Hash Functions:-
    unsigned int ModuloHashFunction(int key){
        return (key % table_size1);
    }
    unsigned int MultiplyHashFunction(int key){
        const double const_var = 0.6180339887;
        return int(key * const_var) % table_size2;
    }
    unsigned int FoldingHashFunction(int key){
        int sum = 0;
        int temp = key;

        // sum the digits of the key
        while(temp > 0){
            sum += temp % 10; // add the last digit of temp to sum 
            temp /= 10; // remove the last digit from temp
        }
        return sum % table_size2;
    }
    
// Insert Functions:-
    void ChainingInsert(int key, int value){
        // Calculate Hash index and allocate memory for new node
        unsigned int hashIndex;
        hashIndex = ModuloHashFunction(key);
        Node *newnode = (Node*)malloc(sizeof(Node));

        // Init new node
        if(!newnode){cout<<"Memory Allocation Failed!"<<endl; return;}
        newnode->key = key;
        newnode->value = value;
        newnode->next = nullptr;

        if(hashTable1[hashIndex] == nullptr)
        {
            // If null then set to new node
            hashTable1[hashIndex] = newnode;
        }
        else 
        {
            // Handling Collision (Chaining Method) 
            Node *temp = hashTable1[hashIndex];
            // Traverse the Linked List till end node
            while(temp->next != nullptr){
                temp = temp->next;
            }
            // Insert the new node when found empty node
            temp->next = newnode;
        }
    }

    void LinearInsert(struct Node *table, int key, int value){
        unsigned int hashIndex = MultiplyHashFunction(key);
        unsigned int originalIndex = hashIndex;

        // Handle collision with Linear Probing
        while(table[hashIndex].isOccupied){
            // increment the index by 1
            hashIndex = (hashIndex + 1) % table_size2;
            if(hashIndex == originalIndex){
                cout << "Hash Table Full!" << endl;
                return;
            }
            // Insert Key-Value pair
            table[hashIndex].key = key;
            table[hashIndex].value = value;
            table[hashIndex].isOccupied = true;
        }
    }

    void QuadraticInsert(struct Node *&table, int key, int value){
        int hashIndex = MultiplyHashFunction(key);

        // Init quadratic probing counter
        int i = 0;

        // Check if the slot at the calculated index is occupied
        while (table[(hashIndex + i * i) % table_size2].isOccupied) {
            i++;
            if (i == table_size2) {
                std::cout << "Hash table is full!" << std::endl;
                return;
            }
        }
    
        // Calculate the final index for insertion
        hashIndex = (hashIndex + i * i) % table_size2;
        // Insert the key-value pair
        table[hashIndex].key = key;
        table[hashIndex].value = value;
        table[hashIndex].isOccupied = true;
    }


























int main()
{
    return 0;
}
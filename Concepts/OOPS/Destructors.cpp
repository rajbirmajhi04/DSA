#include <iostream>
using namespace std;

class test {
    private:
        int count = 0;
    public:
    
        test(){
            cout << "Constructor called!" << endl;
            count ++;
            cout << "No. of object created: " << count << endl;
            
        }
        ~test(){
            cout << "Destructor called!" << endl;
            cout << "Number of object destroyed: " << count << endl;
            count --;
        }
};

// when a class has a private destructor only dynamic objects of that class can be created
class buffer {
    private:
        ~buffer(){
            cout << "Buffer deallocated!" << endl;
        }
    public:
        buffer(){
            cout << "Buffer created!" << endl;
        }
        // only this function cn destruct obejct of test
        friend void destructorBuffer(buffer*);
};
void destructorBuffer(buffer* ptr){
    delete ptr;
}



int main()
{
    // test t, t1, t2, t3, t4, t5;

    // create a new object
    buffer *b = (buffer*)malloc(sizeof(buffer));
    buffer *ptr = new buffer;

    // destruct an object
    destructorBuffer(ptr);

    return 0;
}
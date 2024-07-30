#include <iostream>
using namespace std;

class test {
    public:
        test(){
            cout << "constructor called" << endl;
        }
        ~test(){
            cout << "destructor called" << endl;
        }
};

/*
* Private Destructors: Whenever we want to control the destruction of objects of a class.
* Only dynamic objects of that class can be created.
* Only friend functions can delete the objects
*/

class Sample {
    private:
        ~Sample(){
            cout << "private destructor called" << endl;
        }
    public:
        Sample(){
            cout << "constructor called" << endl;
        }
        friend void destructSample(Sample *ptr);
};

void destructSample(Sample *ptr){
    delete ptr;
}

int main()
{   
    // throws error
    // Sample s1; 
    // delete s1;

    // this works because there is no object being constructed, the program just creates a pointer of type "Sample *", so nothing is destructed
    Sample *s2;

    // this also works because when something is created using dynamic memory allocation, it is the programmers responsibility to delete it.
    Sample *s3 = new Sample;
    Sample *s4 = (Sample*)malloc(sizeof(Sample));

    // destruct 
    destructSample(s2);
    destructSample(s3);
    destructSample(s4);

    return 0;
}
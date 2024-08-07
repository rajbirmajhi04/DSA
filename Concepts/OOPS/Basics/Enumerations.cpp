#include <iostream>
using namespace std;

//* Enum is a collection of named integer constant means it's each element is assigned by integer value
enum rollNo {
    student1 = 5,
    student2 = 50,
    student3 = 40,
    student4 = 1,
    student5 = 10,
};

//* Two enumerations cannot share the same values.
//* No variable can have a name which is already in some enumeration



int main()
{
    enum rollNo rollObject;
    rollObject = student3;
    cout << "The roll number of student 3: " << rollObject << endl;
    
    return 0;
}
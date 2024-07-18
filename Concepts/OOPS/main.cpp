#include <iostream>
using namespace std;

//* class: are the user-defined data type that has data members and member functions.
//* Data Member: data variables
//* Member Functions: are the functions that are used to manipulate these variables
//* Object: is an instance of a class. Means when a class is defined no memory is allocated but when it is instantiated memory is allocated.

/*
 *Public: all the class members decalred inside public can be accessed from everywhere by other classes and function too. Can be accessed from anywhere using direct member operator (.) with the object of that class

 *Private: private members can only be accessed within the class and by the friend function members.

 *Protected: protected members can only be accessed within the class and from the derived class

 ! if we dont specify the access modifier then by default the access modifiers for the members is set to private 
*/

class Room{
    private:
        double radius;
    protected:
        double circumference;
    public:
        double length;
        double width;
        double height;
        
        double area(){
            return length * width;
        }
        double volume(){
            return length * width * height;
        }
        // function using priavte variable
        double circle_area(double r){
            // member function can access private member within the class
            radius = r;
            return 3.141 * radius * radius;
        }
        // function to access the protected member within the class
        double circle_circumference(double c){
            circumference = c;
            return 2 * 3.141 * circumference;
        }
        // function not defined inside class defination
        double perimeter();
};

// to define a member function outside the class, use resolution::operator
// function return type + Class name :: function()
double Room::perimeter(){
    return 2 * (length + width);
}

// derived class to access the protected member of parent class
class child_room: public Room{
    public:
        double calculate_circumference(double c)
        {
            circumference = c;
            return 2 * 3.141 * circumference;
        }
};

int main()
{
    Room room1;
    child_room childroom1;

    room1.length = 67.56;
    room1.width = 34.22;
    room1.height = 90.0;
    
    // accessing the public members
    cout << "Area: " << room1.area() << endl; 
    cout << "Volume: " << room1.volume() << endl; 
    cout << "Perimeter: " << room1.perimeter() << endl;   

    // trying to access private and protected members
    cout << "Circle Area: " << room1.circle_area(1.5) << endl;
    cout << "Circle Circumference: " << room1.circle_circumference(2.5) << endl;
    cout << "New Circumference: " << childroom1.calculate_circumference(10) << endl;
    
    return 0;
}
#include <iostream>
using namespace std;

/*
? Cosntructors(): is a special type of member function that is used to initialize the data members for an object of a class automatically when a object of the same class is created.
? do not return any value.
? can be overloaded and cannot be declared virtual
*/

class Cars{
    string name;
    string color;
    double topSpeed;
    double hp;

    public:
        // defining constructor within the class
        Cars();
        // {
        //     cout << "Enter car name: ";
        //     cin >> name; 
        //     cout << "Enter color: ";
        //     cin >> color;
        //     cout << "Enter top speed: ";
        //     cin >> topSpeed;
        //     cout << "Enter horse power: ";
        //     cin >> hp;
        // }
        // member function 
        void display();
};

// defining constructor outside the class
Cars::Cars(){
    cout << "Enter car name: ";
    cin >> name; 
    cout << "Enter color: ";
    cin >> color;
    cout << "Enter top speed: ";
    cin >> topSpeed;
    cout << "Enter horse power: ";
    cin >> hp;
}

void Cars::display(){
    cout << "The car is " << name << " and it's color is " << color << " equipped with " << hp << " hp engine that can achieve a top speed of " << topSpeed << endl;
}

int main()
{
    Cars c1; 
    c1.display();
    return 0;
}
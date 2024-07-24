#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }

        void setName(string name){
            this->name = name;
        }

        void setAge(int age){
            this->age = age;
        }

        string getName(){
            return name;
        }

        int getAge(){
            return age;
        }
};

class Circle {
    private:
        double radius;
        double area;

    public:
        Circle(double radius){
            this->radius = radius;
        }

        void getRaius(){
            cout << "Enter radius: ";
            cin >> radius;
        }

        void getArea(){
            double area = 3.141 * radius * radius;
            cout << "Area of circle: " << area << endl;
        }

        ~Circle(){
            cout << "DESTRUCTOR CALLED!" << endl;
        }
};

int main()
{
    Person p("John", 22);
    cout << "Name: " << p.getName() << endl;
    cout << "Age: " << p.getAge() << endl;

    p.setName("Emil");
    p.setAge(25);

    cout << "Setted name: " << p.getName() << endl;
    cout << "Setted age: " << p.getAge() << endl;


    return 0;
}
#include <iostream>
using namespace std;

struct dimensions{
    int length, breadth, height, base;
};

struct square{
    struct dimensions l;
    struct dimensions b;
};

struct triangle{
    struct dimensions b;
    struct dimensions h;
};

void area(struct square s, struct triangle t){
    int a1 = (s.l.length) * (s.b.breadth);
    cout << "Area of square: " << a1 << endl;

    int a2 = 1/2 * (t.b.base) * (t.h.height);
    cout << "Area of triangle: " << a2 << endl;
}

struct Distance{
    int feet;
    int inch;

    void display(){
        cout << feet;
        cout << inch;
    }
};

int main()
{
    struct Distance d;
    struct Distance *ptr = &d;

    cout << "Feet: ";
    cin >> (*ptr).feet;

    cout << "Inch: ";
    cin >> (*ptr).inch;

    cout << "Enter Feet: ";
    cin >> ptr -> feet;

    cout << "Enter Inch: ";
    cin >> ptr -> inch;

    ptr -> display();
    (*ptr).display();

    return 0;
}
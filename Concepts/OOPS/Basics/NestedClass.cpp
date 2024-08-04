#include <iostream>
using namespace std;

class Enclosing {
    private:
        int x;
    
    class Nested {
        int y;
        void NestedFunction(Enclosing *e){
            cout << e->x << endl;
        }
    };
};

int main()
{
    return 0;
}
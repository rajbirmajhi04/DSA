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





int main()
{
    test t, t1, t2, t3, t4, t5;
    return 0;
}
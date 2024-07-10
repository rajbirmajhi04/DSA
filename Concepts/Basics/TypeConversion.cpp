    #include <iostream>
    using namespace std;
    /*
    ? Implicit type conversion: (Automatically) When cast from large data type to small data type there is data loss
    ? Explicit type conversion: (Manually) Using C-Style, Function Style and Cast Operator
     */
    int main()
    {
        // Implicit Casting
        int num_int = 9;
        double num_double = num_int;

        // C-Style Casting
        float num_float = (float)num_int;

        // Cast Operator
        int num = 56;
        double a = static_cast<double>(num);

        // Function Style Casting
        int b = int(a);

        /*
        ? const_cast(): used to modify the const or volatile qualifier 
        ? of a variable. It allows to temporarily remove the constancy
        ? of an object and make modifications. Modifying const variable
        ? can lead to some undefined behaviour
        */
        const int number = 5;
        const int* ptr = &number;
        int* nonConstPtr = const_cast<int*>(ptr);
        *nonConstPtr = 10;
        cout << "Modified number: " << *nonConstPtr << endl;

        /*
        ? reinterpret_cast(): used to cast a pointer of one type to 
        ? a pointer of anotehr type. It does noy perform any check 
        ?? whether the pointer converted is of the same type or not
        */
       
        int n = 78;
        int *p = &n;
        char *charPointer = reinterpret_cast<char*>(p);
        cout << "Character Address: " << charPointer << endl;




        return 0;
    }
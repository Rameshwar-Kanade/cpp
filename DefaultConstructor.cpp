 #include <iostream>
using namespace std;

class Employee{
public:
    Employee(){
        cout << "It is Default Constructor" << endl;
    }
};

int main()
{
    // creating object of employee
    Employee e1;
    Employee e2;
    return 0;
}

#include <iostream>
using namespace std;
class Encapsulation3
{
private:
    int salary;
public:
    void setSalary(int Fulltime, int Overtime)
    {
          salary=Fulltime+Overtime;
    }

    int getSalary()
    {
        return salary;

    }


};

int main()
{
    Encapsulation3 obj;
    obj.setSalary(30000,2000);
    cout << "Total Salary :" <<endl;
    cout << obj.getSalary();
     

}
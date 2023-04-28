#include<iostream>
using namespace std;
class Adder
{
    public:
    Adder(int i=0)
    {
       total=i;
    }

//interface to outside world
    void addnum(int number)
    {
        total=total+number;
    }

    int getTotal()
    {
        return total;
    };

    private:
    // hidden data from outside world
    int total;

};

int main()
{
    Adder a;
    a.addnum(10);
    a.addnum(40);
    a.addnum(60);

     cout << "Total :" << a.getTotal() << endl;
    return 0;
}
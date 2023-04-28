#include <iostream>
using namespace std;

class Account {
private:
    long acc_no;
    string name, email;
    float amount;

public:
    void setacc_no(long acc_no) {
        this->acc_no = acc_no;
    }

    long getacc_no() {
        return acc_no;
    }

    void setname(string name) {
        this->name = name;
    }

    string getname() {
        return name;
    }

    void setemail(string email) {
        this->email = email;
    }

    string getemail() {
        return email;
    }

    void setamount(float amount) {
        this->amount = amount;
    }

    float getamount() {
        return amount;
    }
};

int main() {
    Account obj;
    obj.setacc_no(05443210);
    obj.setname("Rameshwar");
    obj.setemail("ram@gmail.com");
    obj.setamount(250000);
    
    cout << obj.getacc_no();
    cout << obj.getname();
    cout << obj.getemail();
    cout << obj.getamount();
    return 0;
}

#include<iostream>
using namespace std;

class plane
{
    public:
    virtual void takeoff() = 0;
    virtual void fly() = 0;
    virtual void land() = 0;

};

class Cargo: public plane
{
   void takeoff() override
   {
    cout << "Cargo plane is taking off from along size run away" << endl;
   }
   void fly() override
   {
    cout << "Cargo plane is flying at low height" << endl;
   }
   void land() override
   {
    cout << "Cargo plane is landing on long size runway" << endl;
   }

};
class PassengerPlane: public plane
{
 void takeoff() override
   {
    cout << "PassengerPlane is taking off from along size run away" << endl;
   }
   void fly() override
   {
    cout << "PassengerPlane is flying at low height" << endl;
   }
   void land() override
   {
    cout << "PassengerPlane is landing on long size runway" << endl;
   }
};
class Airport
{
    public: 
    void premit(plane & ref)
    {
        ref.fly();
        ref.land();
        ref.takeoff();

    }
};


int main()
{
    Cargo cp;
    PassengerPlane pp;
    Airport a;
 
    a.premit(cp);
    a.premit(pp);

    return 0;
    

}
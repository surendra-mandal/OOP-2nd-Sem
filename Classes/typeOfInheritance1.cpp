//Multiple inheritance in C++
// Create a class name personalInfo that stores name and id of a person. Create another class id that 
//stores NIN and citizenship no.  Now derive a class name location that is derived from two classes definable'
//1.Only define data members in protected if required.
//2. All the base and derived classes should have display function. And, display information of base classes from derived class.
//Also create all the required functions and constructor and destructor and show that 
//base class constructor are always called before derived class and vice versa in case of destructor.

#include<iostream>
using namespace std;
class personalInfo;
class id;
class location;
class personalInfo
{
    protected:
    string name;
    long int id;
    public:
    personalInfo()   //Default constructor
    {
        cout<<"Default constructor of base class personalInfo is called."<<endl;
        this->name=name;
        this->id=id;
    }
    personalInfo(string n, long int a):name(n), id(a)   //Parametrized constructor
    {
        cout<<"Parametrized constructor of base class personalInfo is called."<<endl;
    }
    void show()
    {
        cout<<"Name: "<<name<<" id: "<<id<<endl;
    }
    ~personalInfo()
    {
        cout<<"Donstructor of base class personalInfo is called."<<endl;
    }

};
class id
{
    protected:
    long int citizenship, NIN; 
    public:
    id()   //Default constructor
    {
        cout<<"Default constructor of base class id is called."<<endl;
        this->citizenship=citizenship;
        this->NIN=NIN;
    }
    id(long int c, long int n):citizenship(c), NIN(n)    //Parametrized constructor
    {
        cout<<"Parametrized constructor of base class id is called."<<endl;
    }
    void show()
    {
        cout<<"Citizenship No.: "<<citizenship<<" NIN: "<<NIN<<endl;
    }
    ~id()  //Destructor
    {
        cout<<"Donstructor of base class id is called."<<endl;
    }
};
class location: public personalInfo, public id
{
    double longi, lati;
    public:
    location()  //Default constructor
    {
        longi=lati=0.0;
    }
    location(string name, long int id, long int citizenship, long int NIN, float x, float y):longi(x), lati(y)   //Parametrized constructor
    {
        cout<<"Parametrized constructor of derived class location is called."<<endl;
    }
    void show()
    {
        personalInfo::show();
        id::show();
        cout<<"Longitude: "<<longi<<" Latitude: "<<lati<<endl;
    }
};
int main()
{
    location l("Surendra", 8289, 01332, 6758, 2788, 2677);
    l.show();
    return 0;
}
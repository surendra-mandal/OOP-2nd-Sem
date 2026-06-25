// Create a class name dist that represents dist in feet and inch.
//Now we should have all regualr class properties.
//Write a friend funcion that adds two objects.

#include<iostream>
using namespace std;
class dist
{
    private:
    float feet;
    float inch;
    public:
    // dist()  //Default constructor
    // {
    // }
    dist()  //Default constructor
    {
        cout<<"Default constructor called"<<endl;
        this->feet=0.0;
        this->inch=0.0;
    }
    dist(float feet, float inch)
    {
        cout<<"Constructor called"<<endl;
        this->feet=feet;
        this->inch=inch;
    }
    float getFeet()
    {
        return feet;
    }
    float getInch()
    {
        return inch;
    }
    friend dist add(dist , dist);
    dist add(dist);
    void display();
    ~dist()
    {
        cout<<"Destructor called"<<endl;
    }
    
};
dist dist::add(dist d)
{
    float f,i;
    i=this->inch+d.inch;
    f=this->feet+d.feet+i/12;
    i=(int)i/12;
    return dist(f,i); //We are returning temp object
}
dist add(dist d1, dist d2)
{
    float f,i;
    f=d1.getFeet()+d2.getFeet(); //Using get method to get value of private variable
    i=d1.getInch()+d2.getInch(); // 
    return dist(f,i);
}
void dist::display()
{
    cout<<"The sum is: "<<feet<<" Feets "<<inch<<" Inches"<<endl;
}
int main()
{
    dist d1, d2(2,3), d3(4,5), d4, d5;
    d1=d2.add(d3);
    d4=add(d2,d3);
    d5=add(d2,d3);
    d1.display();
    d4.display();
    d5.display();
    return 0;
}
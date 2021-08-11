// GROCERY MANAGEMENT SYSTEM - classes program. SAVE THIS AND THE MAIN IN THE SAME FOLDER
// ANIMESH KUMAR SINGH (4NI19CS023)
// ARPITHA PRAKASH (4NI19SC026)
#include<iostream>
#include<vector>
#include<conio.h>
using namespace std;

class Item                                                                                  // base class
{
    protected:
    Item():category(0),price(0),quantity(0){}                                               // constructors
    public:
    int category;
    string product,brand;
    double price,quantity;  
    virtual void initialise()=0;                                                             // polymorphism
    virtual ~Item(){};                                                                       // destructors
    friend ostream &operator<<(ostream &os,const vector<Item *> &item);     // friend function, operator overloading
};

class Dairy:public Item                                                                      // derived class
{
    public:
    virtual void initialise()
    {
        cout<<"\nENTER DETAILS :\n";
        cout<<"Product : ";
        cin>>product;
        cout<<"Brand : ";
        cin>>brand;
        cout<<"Price(per unit) : ";
        cin>>price;
        cout<<"Quantity : ";
        cin>>quantity;
    }
    virtual ~Dairy(){};
};

class Produce:public Item                                                                     // derived class
{
    public:
    virtual void initialise()
    {
        cout<<"\nENTER DETAILS :\n";
        cout<<"Product : ";
        cin>>product;
        cout<<"Brand : ";
        cin>>brand;
        cout<<"Price(per unit) : ";
        cin>>price;
        cout<<"Quantity(in kg) : ";
        cin>>quantity;
    }
    virtual ~Produce(){};
};

class Grains:public Item                                                                      // derived class
{
    public:
    virtual void initialise()
    {
        cout<<"\nENTER DETAILS :\n";
        cout<<"Product : ";
        cin>>product;
        cout<<"Brand : ";
        cin>>brand;
        cout<<"Price(per unit) : ";
        cin>>price;
        cout<<"Quantity(in kg) : ";
        cin>>quantity;
    }
    virtual ~Grains(){};
};

template <class type>                                                                        // template class
class Owner:public Item
{
    type passcode;
    public:
    bool owner_flag=false;                    // to check if the owner is logging in for the first time
    Owner(type temp="admin")                  // default function arguments, parameterized constructor
    {
        this->passcode=temp;                                                     // this pointer
    }
    virtual void initialise()
    {
        cout<<"\n*** SET PASSWORD ***"<<endl;
        cout<<"Enter new password : ";
        string temp="";
        char b;
        while((b=getch()) != '\r')
        {
            cout<<'*';
            temp.push_back(b);
        }
        passcode=temp;
        cout<<"\nPassword set succesfully"<<endl;
        cout<<"Your password is : "<<passcode<<endl;
        owner_flag=true;
    }
    bool passcheck()
    {
        string temppass="";
        cout<<"Enter password : ";
        char b;
        while((b=getch()) != '\r')
        {
            cout<<'*';
            temppass.push_back(b);
        }
        cout<<endl;
        if(temppass==passcode)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }   
};

template<class t=Item*>
bool compareptr(t a, t b)                                                                 // template sort
{
    return(a->price < b->price);
}

void remove_item(vector<Item *> &v)                                                         
{
    int position;
    if(v.empty()==0)
    {
        std::cout<<"\nThe number of items : "<<v.size()<<endl;
        std::cout<<"Enter the position of the item to be removed : ";
        cin>>position;
        if(position<=v.size())
        {
            v.erase(v.begin()+position-1);
            std::cout<<"The item at position "<<position<<" has been removed\n";
        }
        else
            std::cout<<"No item is present at position "<<position<<endl;
    }
    else
    {
        std::cout<<"Cart is empty!"<<endl;
    }
}

ostream &operator<<(ostream &os, const vector<Item*> &item)         // friend function declaration
{
    for(int i=0;i<item.size();i++)
    {
        os<<endl<<"Item "<<i+1<<":"<<endl;
        if(item[i]->category==1)
        {
            os<<"Category : Dairy";
        }    
        else if(item[i]->category==2)
        {
            os<<"Category : Produce";
        }
        else
        {
            os<<"Category : Grains";
        }
        os<<endl
          <<"Brand : "<<item[i]->brand<<endl
          <<"Product : "<<item[i]->product<<endl
          <<"Price(per unit) : "<<item[i]->price<<endl
          <<"Quantity : "<<item[i]->quantity<<endl;
    }
    return os;
}
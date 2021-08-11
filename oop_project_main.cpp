// GROCERY MANAGEMENT SYSTEM - main program. RUN THIS
// ANIMESH KUMAR SINGH (4NI19CS023)
// ARPITHA PRAKASH (4NI19SC026)
#include "oop_project_classes.cpp"
#include<algorithm>

int main()
{
    std::cout<<endl
             <<"\t\t\t\t\t\t\tGrocery Management"<<endl;
    std::cout<<"___________________________________________________________________________________________________________"<<endl;
    Owner<string> owner;                                                                    // owner object
    vector<Item *> dclassholder;                                          // vector of Item pointers
    Item  *item;
    int login;
    int id1,id2;                                        // to compare the products with index id1 and id2
    bool exitchoice_1{0},exitchoice_2{0};
    int no_of_tries{3};                                                                     // password tries                                                   
    int pov,owner_choice,shopper_choice,item_choice;                                                                
    do
    {
        std::cout<<"\n\n1. Owner\n2. Shopper\n3. Exit\n";
        cin>>pov;
        switch(pov)
        {
            case 1:
            cout<<"WELCOME OWNER"<<endl;
            if(!owner.owner_flag)
            {
                cout<<"\nInitializing owner's account..... ";
                owner.initialise();
            }
            do
            {
                std::cout<<"\nOwner's options : ";
                std::cout<<"\n1. View inventory\n2. Add an item\n3. Remove an item\n4. Log out"<<endl;
                cin>>owner_choice;
                switch(owner_choice)
                {
                    case 1:
                    sort(dclassholder.begin(),dclassholder.end(),compareptr<Item *>);  // vector template function
                    if(dclassholder.size()!=0)
                    {
                        std::cout<<"\nDisplaying all items sorted according price\n";
                        std::cout<<dclassholder;
                    }
                    else
                    {
                        std::cout<<"\nCart is empty!"<<endl;
                    }
                    break;

                    case 2:
                    no_of_tries=3;
                    while(no_of_tries--)
                    {
                        if(!owner.passcheck())
                        {
                             std::cout<<"Incorrect password! "<<no_of_tries<<" tries remaining"<<endl;
                        }
                        else
                        {
                            std::cout<<"\n1. Dairy\n2. Produce\n3. Grains"<<endl;
                            cin>>item_choice;
                            switch(item_choice)
                            {
                                case 1:
                                Dairy *dairy;
                                item=new Dairy;
                                dairy=dynamic_cast<Dairy *>(item);                                      // rtti
                                if(dairy)
                                {
                                    dairy->category=1;  
                                    dairy->initialise();
                                    dclassholder.push_back(dairy);
                                }
                                break;

                                case 2:
                                Produce *produce;
                                item=new Produce;
                                produce=dynamic_cast<Produce*>(item);                                   // rtti
                                if(produce)
                                {
                                    produce->category=2;
                                    produce->initialise();
                                    dclassholder.push_back(produce);
                                }
                                break;

                                case 3:
                                Grains *grains;
                                item=new Grains;
                                grains=dynamic_cast<Grains*>(item);                                     // rtti
                                if(grains)
                                {
                                    grains->category=3;
                                    grains->initialise();
                                    dclassholder.push_back(grains);
                                }
                                break;                                
                            }
                            break;
                        }
                        if(no_of_tries<=0)
                        {
                            std::cout<<"Login Failed\nBack to Menu"<<endl;
                            std::cout<<"___________________________________________________________________________________________________________";
                        }
                    }
                    break;

                    case 3:
                    no_of_tries=3;
                    while(no_of_tries--)
                    {
                        if(!owner.passcheck())
                        {
                            std::cout<<"Incorrect password! "<<no_of_tries<<" tries remaining"<<endl;
                        }
                        else
                        {
                            remove_item(dclassholder);
                            break;
                        }
                        if(no_of_tries<=0)
                        {
                            std::cout<<"Login failed\nBack to Menu"<<endl;
                            std::cout<<"___________________________________________________________________________________________________________";
                        }
                    }
                    break;

                    case 4:
                    std::cout<<"Thank you. Owner has been logged out successfully."<<endl;
                    std::cout<<"___________________________________________________________________________________________________________";
                    exitchoice_1=1;
                    
                    default:
                    break;
                }
            }while(!exitchoice_1);
            break;

            case 2:
            cout<<"WELCOME SHOPPER"<<endl;
            do
            {
                std::cout<<"\nShopper's options :";
                std::cout<<"\n1. View all items in inventory\n2. Compare 2 items\n3. Log out\n";
                int shopper_choice;
                cin>>shopper_choice;
                switch(shopper_choice)
                {
                    case 1:
                    if(dclassholder.empty()==0)
                    {
                        sort(dclassholder.begin(),dclassholder.end(),compareptr<Item *>);
                        std::cout<<"Displaying items in increaing order of price\n";
                        std::cout<<dclassholder;
                    }
                    else
                    {
                        cout<<"\nCart is empty!"<<endl;
                    }
                    break;

                    case 2:
                    if(dclassholder.empty()==0)
                    {
                        std::cout<<"\nEnter the the unique ids (item nos.) of the 2 items"<<endl;
                        cin>>id1;
                        cin>>id2;
                        id1-=1;
                        id2-=1;
                        if(id1>dclassholder.size() || id2>dclassholder.size())
                        {
                            std::cout<<"Enter correct IDs"<<endl;
                            break;
                        }
                        else
                        {
                            if(compareptr(dclassholder[id1],dclassholder[id2]))
                            {
                                std::cout<<dclassholder[id1]->brand
                                <<" "<<dclassholder[id1]->product<<" is cheaper than "
                                <<dclassholder[id2]->brand<<" "<<dclassholder[id2]->product<<" by Rs "
                                <<dclassholder[id2]->price-dclassholder[id1]->price<<" (per unit)"<<endl;
                            }
                            else
                            {
                                std::cout<<dclassholder[id2]->brand
                                <<" "<<dclassholder[id2]->product<<" is cheaper than "
                                <<dclassholder[id1]->brand<<" "<<dclassholder[id1]->product<<" by Rs "
                                <<dclassholder[id1]->price-dclassholder[id2]->price<<" (per unit)"<<endl;
                            }
                        }
                        break;
                    }
                    else
                    {
                        cout<<"\nCart is empty!"<<endl;
                    }
                    break;

                    case 3:
                    std::cout<<"\nThank you. Shopper has been logged out successfully."<<endl;
                    std::cout<<"___________________________________________________________________________________________________________";
                    exitchoice_2=1;
                    break;
                }
            }while(!exitchoice_2);
            break;

            case 3:
            std::cout<<"\nTHANK YOU\n";
            std::cout<<"___________________________________________________________________________________________________________";
            return 0;
        }
    } while(true);
}
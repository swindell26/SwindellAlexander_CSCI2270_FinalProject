/*
Created by Alexander Swindell April 2015
alexander.swindell@colorado.edu
For CSCI2270 final project

*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "HashTable.h"
#include <ctype.h>
using namespace std;

int main(int argc,char* argv[])
{
    /*
    The first part of main reads in the the message board as a command line argument (1)
    It then declares an instance of HashTable, and calls the function parseFile.
    */
    HashTable table= HashTable(10);


    if(argc >1)
       {
           table.parseFile(argv[1]);
       }
       else
       {
           cout<<"Please enter CLA"<<endl;
       }


    string userInput;
    userInput="0";
    while(userInput != "5")
    {
        cout<<"-----Welcome to Alex's List---"<<endl;
        cout<<"-----Menu Options:"<<endl;
        cout<<"1. Display Contents"<<endl;
        cout<<"2. Resort Table"<<endl;
        cout<<"3. Make Posting"<<endl;
        cout<<"4. Delete Posting"<<endl;
        cout<<"5. Quit"<<endl;
        cin>>userInput;
        if (userInput =="1")
        {
            table.printInventory();
        }
        else if(userInput == "2")
        {
            cout<<" What parameter would you like to sort by?"<<endl;
            cout<<"----1.Name (default)"<<endl;
            cout<<"----2.Price"<<endl;
            cout<<"----3.Location"<<endl;
            cin>>userInput;
            if(userInput=="1")
            {
                table.sortName();
            }
            else if(userInput=="2")
                    {
                        table.sortPrice();
                    }
            else if(userInput =="3")
            {
                table.sortLocation();
                table.sortLocation();//There is a bug in the code, that leaves two items unsorted, unless called twice.
            }
        }
        else if(userInput=="3")
        {
            cout<<"Please enter the name of the item: ";
            cin>>userInput;
            cout<<endl;
            string name=userInput;

            cout<<"Please enter the price of the item: ";
            cin>>userInput;
            cout<<endl;
            int price=0;
            std::string::const_iterator it = userInput.begin();
            while (it != userInput.end() && std::isdigit(*it)) ++it;
            bool isNum=!userInput.empty() && it == userInput.end();
            if(!isNum)
            {
                 while(!isNum)
                 {
                    cout<<"Please enter the price of the item as a number: ";
                    cin>>userInput;
                    cout<<endl;

                    std::string::const_iterator it = userInput.begin();
                    while (it != userInput.end() && std::isdigit(*it)) ++it;
                    isNum=!userInput.empty() && it == userInput.end();
                 }
            }
            else
                price=stoi(userInput);


            cout<<"Is the item (1) for sale? or (2) wanted? ";
            cin>>userInput;
            cout<<endl;

            bool isForSale;
            if(userInput=="1")
                isForSale=true;
            else if(userInput=="2")
                isForSale=false;
            else
            {
                while(userInput != "1" && userInput != "2" )
                {
                cout<<"Please enter (1) or (2).";
                cin>>userInput;
                cout<<endl;
                }
            }
            cout<<"Where is the item located?";
            cin>>userInput;
            cout<<endl;
            string location =userInput;

            table.sortName();
            table.createItem(name,price,isForSale,location);
            cout<<"Item Created"<<endl;
        }
        else if(userInput=="4")
        {
            cout<<"Please enter the name of the item: ";
            cin>>userInput;
            cout<<endl;
            string name=userInput;

            cout<<"Please enter the price of the item: ";
            cin>>userInput;
            cout<<endl;

            int price=0;
            std::string::const_iterator it = userInput.begin();
            while (it != userInput.end() && std::isdigit(*it)) ++it;
            bool isNum=!userInput.empty() && it == userInput.end();
            if(!isNum)
            {
                 while(!isNum)
                 {
                    cout<<"Please enter the price of the item as a number: ";
                    cin>>userInput;
                    cout<<endl;

                    std::string::const_iterator it = userInput.begin();
                    while (it != userInput.end() && std::isdigit(*it)) ++it;
                    isNum=!userInput.empty() && it == userInput.end();
                 }
            }
            else
                price=stoi(userInput);




            cout<<"Was the item (1) for sale? or (2) wanted? ";
            cin>>userInput;
            cout<<endl;

            bool isForSale;
            if(userInput=="1")
                isForSale=true;
            else if(userInput=="2")
                isForSale=false;
            else
            {
                while(userInput != "1" && userInput != "2" )
                {
                cout<<"Please enter (1) or (2).";
                cin>>userInput;
                cout<<endl;
                }
            }

           if(table.deleteItem(name,price,isForSale))
            cout<<"Item Deleted"<<endl;
            else
                cout<<"Item not found."<<endl;
        }

    }

    return 0;
}

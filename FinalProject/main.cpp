#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "HashTable.h"
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
        cin>>userInput;
        if (userInput =="1")
        {
            table.printInventory();
        }

    }

    return 0;
}

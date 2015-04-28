#include "HashTable.h"
#include <vector>
#include <fstream>
#include <iostream>
#include<sstream>
HashTable::HashTable(int x)
{
    arrSize=x;
}
HashTable::~HashTable()
{
    //dtor
}

/*
bool HashTable::parseFile(char* name);
Takes in the 2nd command line argument.
Parses the file line by line and splits comma-separated-values into a vector.
Takes each element from that vector and places that data into the "createItem" function.
*/
bool HashTable::parseFile(char* name)
{
    std::cout<<"Parsing input file: "<<name<<std::endl;
  std::fstream board(name);

        if(board.is_open())
        {
            std::string line;

            while(getline(board,line))
            {
                std::cout<<line<<std::endl;
                std::stringstream sline(line); //convert line to stringstream, to use getline and parse by commas
                std::vector<std::string> contents;
                while(sline.good())
                {
                    std::string element;
                    getline(sline,element,',');
                    contents.push_back(element);
                }
                std::string title =contents[0];
                bool forSale;
                if(contents[1]==" for sale")
                    forSale=true;
                else
                    forSale=false;
                int price =stoi(contents[2]);
                createItem(title,price,forSale,"none");
            }
        }
        else
        {
            std::cout<<"Could not open given file"<<std::endl;
        }
}
/*
Item* HashTable::createItem(std::string title1, int price1,bool forSale1,std::string  location1)
Takes all input arguments for parts of an Item. It then creates an instance of an "Item" and populates it.
Calls "insertItem" to place the new item in the hashTable.
Returns a pointer to the new item.

*/
Item* HashTable::createItem(std::string title1, int price1,bool forSale1,std::string  location1)
{
    Item* newItem= new Item;
    newItem->title=title1;
    newItem->location=location1;
    newItem->price=price1;
    newItem->isForSale=forSale1;
    newItem->visited=false;
    insertItem(newItem);
    return newItem;
}

/*
int HashTable::hashSum(std::string x, int s)
Takes a string to be sized, and the size of the hash table.
Returns appropriate value where the string should be inserted.
*/
int HashTable::hashSum(std::string x, int s)
{
    int sum=0;
    for(int i=0; i<x.length();i++)
    {
        sum =sum+ x[i];
    }
    sum = sum % s;
    return sum;
}

/*
Creates a hash value for an integer.
Divides that integer by 1000, to create the correct value.


*/
int HashTable::hashIntSum(int x, int s)
{
    int sum=x;
    if(sum < 10000)
    {
       sum=sum / 1000;
    }
    else{
        sum=9;
    }

    return sum;
}
/*
void HashTable::insertItem(Item* nItem)
Takes a pointer to the item to be inserted.
Compares that value's title to other titles in the table.
It then inserts the pointer into the appropriate slot.
*/
Item* HashTable::insertItem(Item* nItem)
{
    int arrPos=hashSum(nItem->title,10);

    if(ItemArray[arrPos].empty())
    {
       ItemArray[arrPos].push_back(nItem);

    }

   else if(ItemArray[arrPos][0]->title >= nItem->title)
    {
        ItemArray[arrPos].insert(ItemArray[arrPos].begin(),nItem);
    }
    else if(nItem->title > ItemArray[arrPos][ItemArray[arrPos].size()-1]->title )
            {
                ItemArray[arrPos].push_back(nItem);
            }


    else
    {
            for(int i=0;i< ItemArray[arrPos].size();i++)
            {
                if(nItem->title <= ItemArray[arrPos][i]->title || i == ItemArray[arrPos].size()-1)
                {
                     ItemArray[arrPos].insert(ItemArray[arrPos].begin()+i,nItem);
                     break;
                }
            }
    }
    return nItem;
}
/*
Works similarly to insertItem.
However it uses the price to determine location in the hashTable.

*/
void HashTable::insertPrice(Item* nItem)
{
   int arrPos=hashIntSum(nItem->price,10);

    if(ItemArray[arrPos].empty())
    {
       ItemArray[arrPos].push_back(nItem);
    }
/*
   else if(ItemArray[arrPos][0]->price>= nItem->price)
    {
        ItemArray[arrPos].insert(ItemArray[arrPos].begin(),nItem);
    }
    else if(nItem->price > ItemArray[arrPos][ItemArray[arrPos].size()-1]->price )
            {
                ItemArray[arrPos].push_back(nItem);
            }
*/
    else
    {
            for(int i=0;i< ItemArray[arrPos].size();i++)
            {
                if(nItem->price <= ItemArray[arrPos][i]->price || i == ItemArray[arrPos].size()-1)
                {
                     ItemArray[arrPos].insert(ItemArray[arrPos].begin()+i,nItem);
                     break;
                }
            }
    }
    //return nItem;
}

/*
void HashTable::printInventory()
Follows the hash table and prints out the contents in alphabetical order.

*/
void HashTable::printInventory()
{
    int totalNodes=0;
    bool isArrayEmpty =true;
    for(int i=0;i<arrSize;i++)
    {
        if (!ItemArray[i].empty())
            isArrayEmpty=false;
    }

    if(!isArrayEmpty)
    {
        for(int i=0; i<arrSize;i++)
        {
            for(int j=0;j<ItemArray[i].size();j++)
            {

                if(ItemArray[i][j]->isForSale)
                {std::cout<<"FOR SALE: ";}
                else
                {
                    std::cout<<"WANTED: ";
                }

                std::cout<<ItemArray[i][j]->title;
                std::cout<<"   Price: "<<ItemArray[i][j]->price <<" Location: "<<ItemArray[i][j]->location<<std::endl;
                totalNodes++;
            }
        }
    }
    else
    {
        std::cout<<"empty"<<std::endl;
    }
    std::cout<<"Total Items: "<<totalNodes<<std::endl;
}

void HashTable::deleteItem(std::string in_title, int in_price, bool forSale)
{
    sortName();
   int arrPos=hashSum(in_title,arrSize);
   for(int i=0; i<ItemArray[arrPos].size();i++)
   {
       if(ItemArray[arrPos][i]->title==in_title && ItemArray[arrPos][i]->price == in_price && ItemArray[arrPos][i]->isForSale == forSale )
            ItemArray[arrPos].erase(ItemArray[arrPos].begin()+i);
   }
}

/*
Searches the hash table for a specific title, then prints the values.
*/

Item* HashTable::findItem(std::string in_title)
{
    bool found =false;
    Item* target=NULL;
    int arrPos=hashSum(in_title,arrSize);
       for(int i=0; i<ItemArray[arrPos].size();i++)
   {
       if(ItemArray[arrPos][i]->title==in_title)
       {
            std::cout<<arrPos<<":"<<ItemArray[arrPos][i]->title<< ":"<<ItemArray[arrPos][i]->price<<std::endl;
            found =true;
            target = ItemArray[arrPos][i];
       }
   }
    if(!found)
    {
        std::cout<<"not found"<<std::endl;
    }
    return target;
}
/*
void sortName()
This function takes in no values.
It is a fairly inefficient. algorithm, having multiple nested for loops.
Starts by visiting each node in the hash table, and sets "visited" equal to false.
Then in runs through each node again. If the item has not been visited, then temp is set to that node.
The element of the vector is then deleted, and temp is re-inserted into the table. This avoids duplicates.
*/

void HashTable::sortName()
{
    //Set visited equal to zero.
    for(int i=0; i<10;i++)
    {
        if (!ItemArray[i].empty())
        {
            for(int j=0; j< ItemArray[i].size();j++)
            {
                ItemArray[i][j]->visited =false;
            }
        }
    }
//Visit each node once, create temp and delete old pointer.
//Insert temp into the table.
//
     for(int i=0; i<10;i++)
    {
        if (!ItemArray[i].empty())
        {
            for(int j=0; j< ItemArray[i].size();j++)
            {
                if(ItemArray[i][j]->visited==false)
                {
                    ItemArray[i][j]->visited=true;
                    Item* temp=ItemArray[i][j];
                    ItemArray[i].erase(ItemArray[i].begin()+j);
                    j=0;
                    insertItem(temp);
                }
            }
        }
    }

}

void HashTable::sortPrice()
{
        //Set visited equal to zero.
    for(int i=0; i<10;i++)
    {
        if (!ItemArray[i].empty())
        {
            for(int j=0; j< ItemArray[i].size();j++)
            {
                ItemArray[i][j]->visited =false;
            }
        }
    }
//Visit each node once, create temp and delete old pointer.
//Insert temp into the table.
//
     for(int i=0; i<10;i++)
    {
        if (!ItemArray[i].empty())
        {
            for(int j=0; j< ItemArray[i].size();j++)
            {
                if(ItemArray[i][j]->visited==false)
                {
                    ItemArray[i][j]->visited=true;
                    Item* temp=ItemArray[i][j];
                    ItemArray[i].erase(ItemArray[i].begin()+j);
                    j=0;
                    insertPrice(temp);
                }
            }
        }
    }
}

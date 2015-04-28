/*
Created by Alexander Swindell April 2015
alexander.swindell@colorado.edu
For CSCI2270 final project

*/
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
struct Item{
    std::string title;
    int price;
    bool isForSale;
    std::string location;
    bool visited;
};

class HashTable
{
    public:
        HashTable(int);
        ~HashTable();
        Item* createItem(std::string title, int,bool,std::string location);
        Item* insertItem(Item*);
        Item* findItem(std::string in_title);
        void deleteItem(std::string in_title, int price, bool forSale);
        void printInventory();
        int hashSum(std::string, int);
       // void restructureTable(int);
        bool parseFile(char*);
        //Sorting Functions
        void sortName();
        void sortPrice();
        void insertPrice(Item*);
        int hashIntSum(int, int);
        void insertLocation(Item*);
        void sortLocation();
    protected:
    private:
        Item *hashTable;
        int arrSize;
        std::vector<Item*> ItemArray[10];
};

#endif // HASHTABLE_H

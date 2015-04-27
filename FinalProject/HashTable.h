#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
struct Item{
    std::string title;
    int price;
    bool isForSale;
    std::string location;
};

class HashTable
{
    public:
        HashTable(int);
        ~HashTable();
        Item* createItem(std::string title, int,bool,std::string location);
        void insertItem(Item*);
        Item* findItem(std::string in_title);
        void deleteItem(std::string in_title);
        void printInventory();
        int hashSum(std::string, int);
        void restructureTable(int);
        bool parseFile(char*);
    protected:
    private:
        Item *hashTable;
        int arrSize;
        std::vector<Item*> ItemArray[10];
};

#endif // HASHTABLE_H

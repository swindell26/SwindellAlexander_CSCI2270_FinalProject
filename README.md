# SwindellAlexander_CSCI2270_FinalProject

This project is an expansion on the first craigslist project for 2270. 
This program will be able to read in information from a txt file to create entries, as well as take direct user input. 
The data in the project will be stored in a hash table, using vectors for collision resolution.

The user will be able to search in inventory for what he/she wants, and will be able to determine their own search criteria. 
To do this, the program will re-organize the hash table based on the option selected by the user. 
For example, if the user wishes to organize results by price, item, or location. 
Finally, there will also be an option to view items for sale, or items wanted, or both. 

HOW TO RUN:
To run this program, a command line argument may be used to open a txt file, and read in an initial list of entries.
I have used the messageBoard.txt file from the first assignment.
Include that file in the program folder and use the filename as a command line argument.

This program requires user interaction. As of 4/28/15, the user can sort te list by price, or by name.
The user can also add an entry maually, or delete and entry maunually.

DEPENDENCIES:
C++ Libraries used in this program:
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
Uses C++ 11.

SYSTEM REQUIREMENTS:
There are no specific system requirements to run this program, other than being able to compile and run a c++ program.
Uses 

NO ADDITIONAL CONTRIBUTERS

OPEN ISSUES/BUGS:
The location resort is not complete.
The display contents formatting needs editing.
The .txt file and read-in function need to be updated with "locations".
Current read-in location is "none".


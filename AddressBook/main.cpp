/*
   File: main.cpp
   Description: Reads name and address date from a file. Puts the names and addresses into a vector of class objects Person. Allows the user to search for names
            and change the names or addresses in the vector of Person objects. Allows the user to write out the vector of Person objects to a different, comma delmited file.
   Created: 4/7/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.h"

/**
@param vector of Person pointers, contents of file are put into vector
*/
void read_file(std::vector<Person*> &p);

/**
provides the user interface for the program
@param vector of Person pointers
*/
void user_interface(std::vector<Person*> &p);

/**
allows user to search and edit the vector
@param vector of Person pointers to be searched through
*/
void search(std::vector<Person*> p);

/**
allows the user to change an entry
@param Person pointer to be edited
*/
void change_entry(Person* p);

/**
writes the vector of Person pointers to a new file
@param vector of Person pointers to be copied to txt file
*/
void new_book(const std::vector<Person*> &p);

int main()
{
    std::vector<Person*> people;
    
    read_file(people);
    
    user_interface(people);
    
    new_book(people);

    for (auto element : people) //since new is used in readfile(), the vector elements are deleted. redundant since program ends immeditately anyways.
    {
        delete element;
    }
    people.clear();

    return 0;
}

void read_file(std::vector<Person*> &p)
{
    std::ifstream book("addressBook.txt");
    int i = 0;

    while (!book.eof())
    {
        p.push_back(new Person);

        std::string temp;

        getline(book, temp);
        p[i]->set_name(temp);

        getline(book, temp);
        p[i]->set_address(temp);

        i++;
    }

    for (int i = 0; i < p.size(); i++)
    {
        std::cout << *p[i];
        std::cout << std::endl;
    }

    book.close();

}

void user_interface(std::vector<Person*>& p)
{
    char answer;
    std::string name_to_search;
    std::cout << std::endl << "Would you like to edit an entry? (y/n)" << std::endl;

    std::cin >> answer;

    while (answer == 'y')
    {
        search(p);
        std::cout << "Would you like to search and edit again? (y/n)" << std::endl;
        std::cin >> answer;
    }
}

void search(std::vector<Person*> p)
{
    std::cout << "Enter the name of the person whose entry you would like to edit." << std::endl;
    
    std::string name;
    std::cin.ignore();
    getline(std::cin, name);
    
    int i;
    bool found = false; //checks whether a name was found

    for (i = 0; i < p.size(); i++)
    {
        if (name == p[i]->get_name())
        {
            change_entry(p[i]);

            found = true;
        }
    }

    //triggers if a name wasn't found
    if (found == false) 
    {
        std::cout << "There is no one by that name in the address book." << std::endl;
    }
}

void change_entry(Person* p)
{
    char answer;
    std::string new_name;
    
    std::cout << std::endl << p->get_name() << ", " << p->get_address() << std::endl;

    do {
        
        std::cout << std::endl << "Enter 'n' to change the name and 'a' to change the address" << std::endl;

        std::cin >> answer;

        if (answer == 'n')
        {
            std::cout << "Enter the new name: ";

            std::string new_name;
            std::cin.ignore();
            getline(std::cin, new_name);
            p->set_name(new_name);

            std::cout << "the name is now: " << p->get_name() << std::endl;
        }
        if (answer == 'a')
        {
            std::cout << "Enter the new address: ";

            std::string new_address;

            std::cin.ignore();
            getline(std::cin, new_address);
            p->set_address(new_address);

            std::cout << "the address is now: " << p->get_address() << std::endl;
        }
    } while (answer != 'n' && answer != 'a');
}

void new_book(const std::vector<Person*> &p)
{
    char answer;
    std::cout << "Would you like to copy these addresses into a new file? (y/n)" << std::endl;
    std::cin >> answer;

    if (answer == 'y')
    {
        std::fstream updated_book("updatedBook.txt");

        for (int i = 0; i < p.size(); i++)
        {
            updated_book << p[i]->get_name();
            updated_book << ", ";
            updated_book << p[i]->get_address();
            updated_book << std::endl;
        }

        updated_book.clear();
        updated_book.seekg(0);

        while (!updated_book.eof())
        {
            std::string line;
            getline(updated_book, line);
            std::cout << line << std::endl;
        }

        updated_book.close();
    }
}
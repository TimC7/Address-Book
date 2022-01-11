/*
   File: person.h
   Description: header file for the Person class. contains two strings: a name and an address. 
   Created: 4/7/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
private:
    std::string name, address;

public:
    Person();
    Person(std::string _name, std::string _address);

    /**
    @param sets the name
    */
    void set_name(std::string _name);
    
    /**
    @param sets the address
    */
    void set_address(std::string _address);

    /**
    gets the name
    */
    std::string get_name() const;

    /**
    gets the string
    */
    std::string get_address() const;

    /**
    operator overload for a Person object
    */
    friend std::ostream& operator<<(std::ostream& out, const Person& p); 
};

#endif
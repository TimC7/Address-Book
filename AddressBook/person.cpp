/*
   File: person.cpp
   Description: implementation for the Person class
   Created: 4/7/2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include "person.h"

Person::Person()
{

}

Person::Person(std::string _name, std::string _address)
{
	name = _name;
	address = _address;
}


void Person::set_name(std::string _name)
{
    name = _name;
}

void Person::set_address(std::string _address)
{
    address = _address;
}

std::string Person::get_name() const
{
    return name;
}

std::string Person::get_address() const
{
    return address;
}


std::ostream& operator<<(std::ostream& out, const Person& p)
{
    out << p.get_name() << ", " << p.get_address();
    return out;
}
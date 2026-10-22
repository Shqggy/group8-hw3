//code for person class here
#include "person.h"
#include <sstream>

using namespace std;



//constructor. this constructor is different:
//in cpp, if a class member has parametrized 
//constructors, cpp will not build the 
//default constructor for you (not generated if you declare another constructor)
Person::Person(string input_name, string input_phone, address a, credit_card cc)
    : name_(input_name), phone_(input_phone), person_address_(a), person_credit_card_(cc)
{
    //empty constructor body
}

//default constructor for Person: 
Person::Person() 
    : name_(""), phone_(""), person_address_("", "", "", "", ""), person_credit_card_(0, 0.0, 0.0)
{
    //empty constructor body
}

//setter: set the name
void Person::name(string input_name)
{
    name_ = input_name;
}

//getter: get the name
string Person::name()
{
    return name_;
}

//setter: set phone number
void Person::phone(string input_number)
{
    phone_ = input_number;
}

//getter: get phone number 
string Person::phone()
{
    return phone_;
}

//setter: set address object
void Person::person_address(address a)
{
    person_address_ = a;
}

//getter: get address object
address Person::person_address()
{
    return person_address_;
}

//setter: set credit card object
void Person::person_credit_card(credit_card cc)
{
    person_credit_card_ = cc;
}

//getter: get credit card object
credit_card Person::person_credit_card()
{
    return person_credit_card_;
}

//output the information
string Person::person_info()
{
    ostringstream output; 

    output << "Customers: " << "\n";
    output << "Name: " << name_ << "\n";
    output << "Phone: " << phone_ << "\n";
    output << person_address_.address_info() << "\n";
    output << person_credit_card_.credit_card_info() << "\n";

    return output.str();

}
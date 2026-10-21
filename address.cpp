//implementation code for address struct here
#include "address.h"
#include <string>
#include <sstream>


//constructor
address::address(string line1, string line2, string city_name, string state_name, string zip_code)
{
    address_line1 = line1;
    address_line2 = line2;
    city = city_name;
    state = state_name;
    zip = zip_code;
}

//print address information for customer 
std::string address::address_info()
{
    std::ostringstream output; 


    output << "Address: " << "\n"; 
    output << address_line1 << "\n";
    output << address_line2 << "\n";
    output << city << "\n";
    output << state << "\n";
    output << zip;

    return output.str();
}
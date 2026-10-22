//code for product struct here
#include "product.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

std::string product::product_info() {
  std::ostringstream info;
  info << std::fixed << std::setprecision(2) << "Name: " << name << "\n"
       << "Description: " << description << "\n" //EDITED TO SAY DESCRIPTION
       << "Price: $" << price << "\n";

  return info.str();
}
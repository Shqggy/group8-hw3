#include "product.h"
#include <iomanip>
#include <sstream>
#include <string>

std::string product::product_info() {
  std::ostringstream info;
  info << std::fixed << std::setprecision(2) << "Name: " << name << "\n"
       << "Desc: " << description << "\n"
       << "Price: $" << price << "\n";

  return info.str();
}

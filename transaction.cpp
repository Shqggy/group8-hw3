#include "transaction.h"
#include <iomanip>
#include <sstream>
#include <string>

std::string transaction::transaction_info() {
  std::ostringstream info;
  info << std::fixed << std::setprecision(2)
       << "Transaction #: " << transaction_number << "\n"
       << "Items: " << quantity << " " << purchased_item.name << "(s)\n"
       << "Price: $" << quantity * purchased_item.price << "($"
       << purchased_item.price << " per item)\n"
       << "Bought by: " << customer.name() << "\n";

  return info.str();
}

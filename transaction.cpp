//code for transaction struct here
#include "transaction.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"

#include <iomanip>
#include <sstream>
#include <string>

std::string transaction::transaction_info() {
  std::ostringstream info;
  info << std::fixed << std::setprecision(2)
       << "Transaction #: " << transaction_number + 1 << "\n"
       << "Customer:\n"
       << customer.person_info() //COULD PRINT CREDIT INFO TWICE, AS PERSON.INFO HANDLES THAT 
       << "Product:\n"
       << purchased_item.product_info() << "Quantity: " << quantity << "\n";

  return info.str();
}

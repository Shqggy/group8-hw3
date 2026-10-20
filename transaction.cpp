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
       << "Transaction #: " << transaction_number << "\n"
       << "Customer:\n"
       << customer.person_info() << "Credit Card:\n"
       << customer.person_credit_card.credit_card_info() << "Product:\n"
       << purchased_item.product_info() << "Quantity: " << quantity << "\n";

  return info.str();
}

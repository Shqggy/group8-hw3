//code for store class here
#include "store.h"
#include <string>
#include <sstream>
#include <iostream>


Store::Store() {
    num_customers_ = 0;
    num_products_ = 0;
    num_transactions_ = 0;
}

void Store::num_customers(int customer_count) {
    num_customers_ = customer_count;
}

int Store::num_customers() {
    return num_customers_;
}

void Store::num_products(int product_count) {
    num_products_ = product_count;
}

int Store::num_products() {
    return num_products_;
}

void Store::num_transactions(int transaction_count) {
    num_transactions_ = transaction_count;
}

int Store::num_transactions() {
    return num_transactions_;
}

bool Store::add_customer(Person customer) {
    int i = num_customers();
    if (i >= 100) {
        // Customer limit reached
        return false;
    }
    customers_[i] = customer;
    num_customers(i + 1);
    return true;
}

bool Store::update_customer(int index, Person customer) {
    Person current_customer = customers_[index];
    if (current_customer.name() == customer.name()) {
        customers_[index] = customer;
        return true;
    }
    return false;
}

Person Store::get_customer(int index) {
    return customers_[index];
}

bool Store::add_product(product item) {
    int frontier = num_products();
    if (frontier >= 100) {
        // product limit reached
        return false;
    }
    products_[frontier] = item;
    num_products(frontier + 1);
    return true;
}

product Store::get_product(int index) {
    return products_[index];
}

bool Store::add_transaction(transaction ntransaction) {
    int frontier = num_transactions();
    if (frontier >= 100) {
        // transaction limit reached
        return false;
    }
    transactions_[frontier] = ntransaction;
    num_transactions(frontier + 1);
    return true;
}

transaction Store::get_transaction(int index) {
    return transactions_[index];
}

bool Store::make_purchase(Person customer, product item, int amount) {
    credit_card card = customer.person_credit_card();
    if (card.current_balance < item.price * amount) {
        // card declined, customer cannot afford the item(s)
        std::cout << "Unsuccessful transaction.";
        return false;
    } else {
        // purchase successful, charge the balence
        std::cout << "Successful transaction!";
        card.current_balance -= item.price * amount;
        customer.person_credit_card(card);
    }

    int customer_idx = find_customer(customer);
    if (customer_idx == -1) {
        // new customer, add to system
        add_customer(customer);
    } else {
        // old customer, make sure info is up to date
        update_customer(customer_idx, customer);
    }

    transaction current_transaction;
    current_transaction.transaction_number = num_transactions();
    current_transaction.customer = customer;
    current_transaction.purchased_item = item;
    current_transaction.quantity = amount;

    add_transaction(current_transaction);
    std::cout << current_transaction.transaction_info();

    return true;
}

std::string Store::product_info() {
    std::stringstream output;
    for (int i = 0; i < num_products(); i++) {
        output << get_product(i).product_info();
    }
    return output.str();
}

std::string Store::transaction_info() {
    std::stringstream output;
    for (int i = 0; i < num_transactions(); i++) {
        output << get_transaction(i).transaction_info();
    }
    return output.str();
}

std::string Store::customer_info() {
    std::stringstream output;
    std::cout << "Customers: " << std::endl;
    for (int i = 0; i < num_customers(); i++) {
        output << get_customer(i).person_info();
    }
    return output.str();
}

std::string Store::store_info() {
    std::stringstream output;

    

    output << "Products:\n"; //EDITED TO SAY PRODUCTS
    output << product_info() << "\n"; //ADDED A NEWLINE

    output << "All transactions:\n"; //EDITED TO SAY ALL TRANSACTIONS
    output << transaction_info();    // MOVED BELOW TO MATCH OUTPUT ORDER

    return output.str();
}

std::string Store::purchase_history(Person customer) {
    std::stringstream output;
    for (int i = 0; i < num_transactions(); i++) {
        transaction to_check = get_transaction(i);
        if (to_check.customer.name() == customer.name()) {
            output << to_check.transaction_info();
        }
    }
    return output.str();
}

int Store::find_customer(Person cust) {
    for (int i = 0; i < num_customers(); i++) {
        if (get_customer(i).name() == cust.name()) {
            return i;
        }
    }
    return -1;
}
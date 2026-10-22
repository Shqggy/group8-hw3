//implementation code for credit_card struct here

#include "credit_card.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

//constructor 
credit_card::credit_card(int cc, double lim, double bal) 
{
	cc_number = cc;
	limit = lim;
	current_balance = bal;
}
//tests if purchase from store can be made and is within credit crard limit 
bool credit_card::make_purchase(double purchase_amount) 
{
	if (current_balance + purchase_amount <= limit) 
	{
		current_balance += purchase_amount;
		return true;
	}

	else 
	{
		return false; 
	}

}
//make a payment on the credit card (paying off credit)
bool credit_card::make_payment(double payment_amount)  
{
	if (payment_amount > 0 && payment_amount <= current_balance) 
	{
		current_balance -= payment_amount;

		return true;
	}

	else 
	{
		return false;
	}
}
//print the credit card info 
std::string credit_card::credit_card_info()
{

	std::ostringstream output; 

	output << "Credit Card: " << "\n";
	output << "Credit card number: " << cc_number << "\n";
	output << "Credit Card Limit: $" << std::fixed << std::setprecision(2) << limit << "\n";
	output << "Current Balance: $" << std::fixed << std::setprecision(2) << current_balance << "\n";

	return output.str();


}


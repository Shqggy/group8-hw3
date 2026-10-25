#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;
using std::rand;


//temp struct for matchin credit cards to people
struct PersonData {
    string name;
    string phone;
    string line1;
    string line2;
    string city;
    string state;
    string zip;

	int card_number;
	double credit_limit;
	double current_balance;
};


int main()
{

	Person people[10];
	PersonData temp_people[10];

	product products[10];
	//credit_card cards[10];

	ifstream people_file("people.txt");

	//if person.txt doesn't open...
	if (!people_file) 
	{
		std::cerr << "Error: couldn't open people.txt" << endl;
		return 1;
	}

	int num_people; 
	people_file >> num_people;
	//consume leftover newline from above >>
	people_file.ignore();

	//read person object requirements into temp person struct from people.txt
	for (int i = 0; i < num_people; i++) 
	{
		
		getline(people_file, temp_people[i].name);
		getline(people_file, temp_people[i].phone);
		getline(people_file, temp_people[i].line1);
		getline(people_file, temp_people[i].line2);
		getline(people_file, temp_people[i].city);
		getline(people_file, temp_people[i].state);
		getline(people_file, temp_people[i].zip);

		//cout << temp_people[i].name << " | " << temp_people[i].city << endl;
	}

	

	ifstream card_file("credit_card.txt");

	if (!card_file)
	{
		std::cerr << "Error: couldn't open credit_card.txt" << endl;
		return 1;
	}

	int num_cards;
	card_file >> num_cards;
	card_file.ignore();

	//read person object requirements into temp person struct from credit_card.txt
	for (int i = 0; i < num_cards; i++) 
	{
		string card_name;  //because this file incldues names
		int card_num;
		double credit_lim;
		double current_bal; 

		getline(card_file, card_name);
		
		card_file >> card_num >> credit_lim >> current_bal;
		card_file.ignore(); //ignire newline from >>

		for (int j = 0; j < num_people; j++)
		{
			if (temp_people[j].name == card_name) 
			{
				temp_people[j].card_number = card_num;
				temp_people[j].credit_limit = credit_lim; 
				temp_people[j].current_balance = current_bal;

				//cout << temp_people[j].name << " | " << temp_people[j].card_number << endl;

				break;
			}
		}
		
		

	}

	for (int i = 0; i < num_people; i++) 
	{
		address person_address(temp_people[i].line1, temp_people[i].line2, temp_people[i].city, temp_people[i].state, temp_people[i].zip);

		credit_card person_card(temp_people[i].card_number, temp_people[i].credit_limit, temp_people[i].current_balance);

		people[i] = Person(temp_people[i].name, temp_people[i].phone, person_address, person_card);
	}

	

	people_file.close();
	card_file.close();

	ifstream product_file("products.txt");

	if (!product_file) 
	{
		std::cerr << "Error: couldn't open products.txt" << endl;
		return 1;
	}

	int num_products; 
	product_file >> num_products; 
	product_file.ignore();

	for (int i = 0; i < num_products; i++) 
	{
		string product_name;
		string description_input;
		double price_input; 

		getline(product_file, product_name);
		getline(product_file, description_input);

		product_file >> price_input; 
		product_file.ignore();

		products[i].name = product_name;
		products[i].description = description_input;
		products[i].price = price_input;

		//cout << products[i].product_info();


	}

	product_file.close();

	//add to store and other variables

	Store store1;


	for (int i = 0; i < num_people; i++)
	{
		store1.add_customer(people[i]);
	}
    for (int i = 0; i < num_products; i++) 
    {
        store1.add_product(products[i]);
    }


	//print store info after you finish importing info
	//from text files and add them to your store
	cout << "Store info: " << endl << endl;
	cout << store1.customer_info() << endl;
	cout << store1.store_info() << endl << endl;

	//make random number of random transactions
    srand(time(0));

    int num_transactions = 11 + rand() % 89;

    for (int t = 0; t < num_transactions; t++)
    {
        int cust_idx = rand() % num_people;
        int prod_idx = rand() % num_products;
        int quantity = 1 + rand() % 5;

        Person& customer = people[cust_idx];
        product& item = products[prod_idx];

        if (store1.make_purchase(customer, item, quantity))
        {
            cout << "Successfull transaction!" << endl;
            cout << "Transaction Details: " << endl;
            cout << store1.get_transaction(store1.num_transactions() - 1).transaction_info() << endl;
        }
        else {
            cout << "Unsuccessfull transaction!" << endl;
            cout << "Transaction Details: " << endl;
            cout << "Person:\n" << customer.person_info();
		    cout << "Product:\n" << item.product_info();
		    cout << "Purchase Quantity: " << quantity << endl << endl;
        }
    }

	//print store info at the end
	cout << "Store info: " << endl << endl;
    cout << store1.customer_info() << endl;
	cout << store1.store_info() << endl << endl;
}

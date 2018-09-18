#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "core.h"

void menu();
BankAccount create_new_account();
void get_all_accounts();
void insert_ammount();
void withdraw_ammount();
void get_account_handlers_with_more_than_one();
void get_account_with_same();

list<BankAccount> accounts = BankAccount::get_all_accounts();

int main() {

	menu();

	return 0;
}

void menu() {
	cout << "-- MAIN MENU --" << endl << "Pick up an option: " << endl;
	cout << "1) Create new account" << endl;
	cout << "2) Get all accounts" << endl;
	cout << "3) Insert amount in account by ID" << endl;
	cout << "4) Withdraw amount in account by ID" << endl;
	cout << "5) Get account handlers that have more than one account" << endl;
	cout << "6) Get all bank accounts with same amount of withdraw/income amounts in text format" << endl;
	cout << "0) For Exit." << endl;

	int option; // Used for user choice
	while (1) {
		cout << "Enter option (0 for exit): ";
		cin >> option;

		if (option == 0) {
			break;
		}

		switch (option) {
			case 1: create_new_account(); break;
			case 2: get_all_accounts(); break;
			case 3: insert_ammount(); break;
			case 4: withdraw_ammount(); break;
			case 5: get_account_handlers_with_more_than_one(); break;
			case 6: get_account_with_same(); break;
			default : cout << "Wrong option!\n"; break;
		}
	}
}

BankAccount create_new_account() {
	char holder_name[24];

	cout << "Enter holder name (max 24 symbols): ";

	cin.ignore();
	cin.getline(holder_name, sizeof(holder_name));

	BankAccount acc(holder_name);
	accounts = BankAccount::get_all_accounts(); // Update the data from the file

	return acc;
}

void get_all_accounts() {
	for (list<BankAccount>::iterator acc = accounts.begin(); acc != accounts.end(); acc++) {
		printf("ID:%s - Holder: %s\nTotal Debit: %lf\nTotal Credit:%lf\n\n",
			acc->get_unique_code(), acc->get_holder_name(), acc->get_total_debit(), acc->get_total_credit());
	}
}

void insert_ammount() {
	char unique_code[7];
	double amount;

	// Get the account ID from the stdin
	cout << "Enter ID:";
	cin.ignore();
	cin.get(unique_code, 7);

	// Get the amount from stdin
	cout << "Enter Amount:";
	cin >> amount;

	for (list<BankAccount>::iterator acc = accounts.begin(); acc != accounts.end(); acc++) {
		if (strcmp(unique_code, acc->get_unique_code()) == 0) {
			acc->insert_amount(amount);
		}
	}
}

void withdraw_ammount() {
	// TODO ...
}

void get_account_handlers_with_more_than_one() {
	// TODO ..
}
void get_account_with_same() {
	// TODO ...
}

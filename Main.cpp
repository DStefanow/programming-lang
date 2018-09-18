#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include "core.h"

void menu();
BankAccount create_new_account();
void get_all_accounts();
void insert_ammount();
void withdraw_ammount();
void get_account_balance();
void get_account_handlers_with_more_than_one();

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
	cout << "5) Get account balance by ID" << endl;
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
			case 5: get_account_balance(); break;
			case 6: get_account_handlers_with_more_than_one(); break;
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
	cout << "-- INSERT --\nEnter ID:";
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
	char unique_code[7];
	double amount;

	// Get the account ID from the stdin
	cout << "-- WITHDRAW --\nEnter ID:";
	cin.ignore();
	cin.get(unique_code, 7);

	// Get the amount from stdin
	cout << "Enter Amount:";
	cin >> amount;

	for (list<BankAccount>::iterator acc = accounts.begin(); acc != accounts.end(); acc++) {
		if (strcmp(unique_code, acc->get_unique_code()) == 0) {
			acc->withdraw_amount(amount);
		}
	}
}

void get_account_balance() {
	char unique_code[7];
	double balance = 0.0;

	// Get the account ID from the stdin
	cout << "Enter ID:";
	cin.ignore();
	cin.get(unique_code, 7);

	for (list<BankAccount>::iterator acc = accounts.begin(); acc != accounts.end(); acc++) {
		if (strcmp(unique_code, acc->get_unique_code()) == 0) {
			balance = acc->get_total_debit() - acc->get_total_credit();

			printf("\nTotal Debit: %lf\nTotal Credit: %lf\nBalance: %lf\n\n",
				acc->get_total_debit(), acc->get_total_credit(), balance);
		}
	}
}

void get_account_handlers_with_more_than_one() {
	map<string, int> acc_info;

	// Populate the info Hash Map
	for (list<BankAccount>::iterator acc = accounts.begin(); acc != accounts.end(); acc++) {
		acc_info[acc->get_holder_name()] = acc_info[acc->get_holder_name()] + 1; // Increase the number
	}

	for (map<string, int>::iterator it = acc_info.begin(); it != acc_info.end(); ++it) {
		if (it->second > 1) { // Compare by value
			printf("Holder: %s has %d bank accounts!\n", it->first.c_str(), it->second);
		}
	}
}

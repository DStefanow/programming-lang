#include<iostream>
#include <fstream>
#include <string>
#include "core.h"

#define ACC_FILE "accounts.txt"

void create_unique_code();
void menu();
void create_new_account();
void insert_ammount();
void withdraw_ammount();
void get_account_handlers_with_more_than_one();
void get_account_with_same();

int main() {

	menu();

	return 0;
}

void menu() {
	cout << "-- MAIN MENU --" << endl << "Pick up an option: " << endl;
	cout << "1) Create new accout" << endl;
	cout << "2) Insert amount in account by ID" << endl;
	cout << "3) Withdraw amoount in account by ID" << endl;
	cout << "4) Get account handlers that have more than one account" << endl;
	cout << "5) Get all bank accounts with same amount of witdraw/income ammounts in text format" << endl;
	cout << "0) For Exit." << endl;

	int option; // Used for user choice
	while (1) {
		cout << "Option (0 for exit): ";
		cin >> option;

		if (option == 0) {
			break;
		}

		switch (option) {
			case 1: create_new_account(); break;
			case 2: insert_ammount(); break;
			case 3: withdraw_ammount(); break;
			case 4: get_account_handlers_with_more_than_one(); break;
			case 5: get_account_with_same(); break;
		}
	}
}

void create_new_account() {
	char holder_name[24];

	cout << "Enter holder name (max 24 symbols): ";

	cin.ignore();
	cin.getline(holder_name, sizeof(holder_name));

	BankAccount *acc = new BankAccount(holder_name);

	// Write the information about the current account in accounts file
	ofstream out_file;
	out_file.open(ACC_FILE, ofstream::out | ofstream::app);
	out_file << *acc;
	out_file.close();
}

void insert_ammount() {
	// TODO ..
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

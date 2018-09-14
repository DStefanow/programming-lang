#include<iostream>
#include <fstream>
#include "core.h"

void create_unique_code();
void menu();
void create_new_account();
void insert_ammount();
void withdraw_ammount();
void get_account_handlers_with_more_than_one();
void get_account_with_same();

int main() {

	menu();

	char *name = "Dobromir Stefanov";
	BankAccount acc(name);

	ofstream out_file("accounts.txt");
	out_file<<acc;
	out_file.close();

	BankAccount acc1;
	ifstream in_file("accounts.txt");
	in_file>>acc1;
	in_file.close();

	cout << "Account ID: " << acc1.get_unique_code() << endl;

	return 0;
}

void menu() {
	cout << "-- MAIN MENU --" << endl << "Pick up option: " << endl;
	cout << "1) Create new accout" << endl;
	cout << "2) Insert amoount in account by ID" << endl;
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
	// TODO ..
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

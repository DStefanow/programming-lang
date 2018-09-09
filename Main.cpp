#include<iostream>
#include <fstream>
#include "core.h"

void create_unique_code();

int main() {

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

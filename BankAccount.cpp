#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
using namespace std;

/**
	-- Task number 24 --
	BankAccount class store information about:
		- unique_code with validation;
		- holder pointer;
		- information about income and outcome;
		- validation functions and etc.;
*/

class BankAccount {
	// Bank Account properties
	private:
		char *unique_code = new char[6];
		char *holder_name;
		list<double> income;
		list<double> outcome;

	void create_unique_code() {
		srand(time(0));
		this->unique_code[0] =(char)(65 + rand() % 25); // Get unique letter from A to Z

		// Set unique digit from 0 to 9
		for (char i = 1; i < 6; i++) {
			this->unique_code[i] =(char)(48 + rand() % 9);
		}
	}

	void set_holder_name(char *holder_name) {
		if (sizeof(holder_name)/sizeof(char) < 5) {
			cout << "Holder name must be at least 5 symbols. Insert new data." << endl;
			delete this;
			return;
		}

		this->holder_name = holder_name;
	}

	public:
		// Initialize empty construct
		BankAccount() {
			cout << "Created new account wih empty data." << endl;
		}

		BankAccount(char *holder_name) {
			create_unique_code();
			set_holder_name(holder_name);

			cout << "Holder: " << this->holder_name << " has new Bank Account with ID: " << this->unique_code << endl;
		}

		~BankAccount() {
			cout << "Current account is destroyed!" << endl;
		}

		char *get_holder_name() {
			return this->holder_name;
		}

		char *get_unique_code() {
			return this->unique_code;
		}

	// Ovveride << to serialize and write Bank Account object in file
	friend std::ostream & operator << (std::ostream &out_file, BankAccount &acc) {
		out_file << acc.get_unique_code() << " - " << acc.get_holder_name() << endl;
		return out_file;
	}

	// Ovveride >> to read Bank Account object from file
	friend std::istream & operator >> (std::istream &in_file, BankAccount &acc) {
		in_file >> acc.unique_code;
		in_file >> acc.holder_name;
		return in_file;
	}
};

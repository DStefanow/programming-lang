#include <iostream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <cstring>
#include <string>

#define ACC_FILE "accounts.txt"

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
		char unique_code[6];
		char *holder_name;
		double total_debit;
		double total_credit;
		list<double> debit;
		list<double> credit;

		void create_unique_code() {
			srand(time(0));
			this->unique_code[0] =(char)(65 + rand() % 25); // Get unique letter from A to Z

			// Set unique digit from 0 to 9
			for (char i = 1; i < 6; i++) {
				this->unique_code[i] =(char)(48 + rand() % 9);
			}
		}

		bool is_valid_holder_name(char *holder_name) {
			if (strlen(holder_name) < 5) {
				cout << "Holder name must be at least 5 symbols. Insert new data." << endl;
				return false;
			}

			return true;
		}

	public:
		// Initialize empty construct
		BankAccount() {
			cout << "Created new account wih empty data." << endl;
		}

		BankAccount(char *holder_name) {
			if (is_valid_holder_name(holder_name)) {
				this->holder_name = holder_name;
				this->total_debit = 0;
				this->total_credit = 0;
				create_unique_code();

				cout << "Holder: " << this->holder_name << " has new Bank Account with ID: " << this->unique_code << endl;

				// Write the information about the current account in accounts file
				ofstream out_file;
				out_file.open(ACC_FILE, ofstream::out | ofstream::app);
				out_file << *this;
				out_file.close();

			} else {
				delete this;
			}
		}

		BankAccount(string *tokens) {
			copy(tokens[0].begin(), tokens[0].end(), this->unique_code);
			//this->unique_code = (char*)(tokens[0].substr(0,6)).c_str();
			this->holder_name = (char*)tokens[1].c_str();
			this->total_debit = atof(tokens[2].c_str());
			this->total_credit = atof(tokens[3].c_str());
		}

		~BankAccount() { }

		char *get_holder_name() {
			return this->holder_name;
		}

		char *get_unique_code() {
			return this->unique_code;
		}

		bool create_transaction(string option, double amount) {
			if (amount <= 0.0) {
				return false;
			}

			if (option == "insert") {
				debit.push_back(amount);
				return true;
			}
			else if (option == "withdraw") {
				credit.push_back(amount);
				return true;
			}

			return false;
		}

		double get_all_debit() {
			list<double>::iterator curr;
			for (curr = debit.begin(); curr != debit.end(); ++curr) {
				this->total_debit += *curr;
			}

			return this->total_debit;
		}

		double get_all_credit() {
			list<double>::iterator curr;
			for (curr = credit.begin(); curr != credit.end(); ++curr) {
				this->total_credit += *curr;
			}

			return this->total_credit;
		}

		// Ovveride << to serialize and write Bank Account object in file
		friend std::ostream & operator << (std::ostream &out_file, BankAccount &acc) {
			out_file << acc.get_unique_code() << " - " << acc.get_holder_name() <<
			" - " <<  acc.get_all_debit() << " - " << acc.get_all_credit() <<endl;
			return out_file;
		}

		static list<BankAccount> get_all_accounts() {
			list<BankAccount> accounts;
			int pos = 0; // Position for the current line
			int i = 0; // Used by the token array
			string line = "";
			string tokens[4];
			string delimiter = " - "; // Delimiter in the file

			ifstream in_file(ACC_FILE);
			while (getline(in_file, line)) {
				istringstream iss(line); // get the line as string

				i = 0;
				while ((pos = line.find(delimiter)) != string::npos) {
					tokens[i] = line.substr(0, pos); // Add every part
					line.erase(0, pos + delimiter.length()); // Erase to the next delimiter

					i++;
				}

				tokens[i] = line; // Add the last part
				accounts.push_back(*(new BankAccount(tokens)));
			}

			return accounts;
		}
};

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
			// Copy the holder name - it's a little bit difficult procedure
			char *ch = new char[tokens[1].length() + 1];
			strcpy(ch, tokens[1].c_str());
			this->holder_name = ch;
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

		bool insert_amount(double amount) {
			if (amount <= 0.0) {
				return false;
			}

			debit.push_back(amount);
			this->total_debit += amount;
			insert_data_for_transaction(1, amount);

			return true;
		}

		bool withdraw_amount(double amount) {
			if (amount <= 0.0) {
				return false;
			}

			credit.push_back(amount);
			this->total_credit += amount;
			insert_data_for_transaction(2, amount);

			return true;
		}

		// Type is used for debit/credit 1 - debit, other value - credit
		void insert_data_for_transaction(int type, double amount) {
			string file_ext = ".txt"; // Used for file extension
			string transaction_type = (type == 1) ? "Debit: " : "Credit: ";

			// Write info in the text file with filename - the ID of the holder
			string file_name = file_ext.insert(0, this->get_unique_code());
			ofstream log(file_name.c_str(), ofstream::out | ofstream::app);
			log << transaction_type << amount << endl;

			return;
		}

		double get_total_debit() {
			return this->total_debit;
		}

		double get_total_credit() {
			return this->total_credit;
		}

		// Ovveride << to serialize and write Bank Account object in file
		friend std::ostream & operator << (std::ostream &out_file, BankAccount &acc) {
			out_file << acc.get_unique_code() << " - " << acc.get_holder_name() <<
			" - " <<  acc.total_debit << " - " << acc.total_credit <<endl;
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
				accounts.push_back(BankAccount(tokens));
			}

			return accounts;
		}

		void print_info() {
			printf("Account with ID: %s\nHolder:%s\nTotal Debit: %lf\nTotal Credit:%lf\n\n",
				this->get_unique_code(), this->get_holder_name(),
				this->total_debit, this->total_credit);
		}
};

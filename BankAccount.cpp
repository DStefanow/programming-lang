#include <iostream>
#include <list>
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
		list<double> income;
		list<double> outcome;

	public:
		// Initialize empty construct
		BankAccount() {
			// TODO ...
		}
};

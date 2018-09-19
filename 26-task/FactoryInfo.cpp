#include <iostream>

#define ACC_FILE "accounts.txt"

using namespace std;

class FactoryInfo {
	private:
		char *country;
		double price;

	public:
		FactoryInfo() {
			cout << "Created empty object from class FactoryInfo" << endl;
		}

		FactoryInfo(char *country, double price) {
			this->country = country;
			this->price = price;
		}

		~FactoryInfo() {}
};

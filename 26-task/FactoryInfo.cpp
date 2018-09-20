#include <iostream>

using namespace std;

class FactoryInfo {
	private:
		char *country;
		double price;

	public:
		FactoryInfo() {}

		FactoryInfo(char *country, double price) {
			this->country = country;
			this->price = price;
		}

		~FactoryInfo() {}

		char *get_country() {
			return this->country;
		}

		double get_price() {
			return this->price;
		}
};

#include <iostream>

#include "fact.h"

using namespace std;

class ComponentInfo {
	private:
		char *nomenclature_number;
		char *name;
		double value;
		char *unit;
		FactoryInfo factory_info;

	public:
		ComponentInfo() {
			cout << "Create empty object from class Component" << endl;
		}

		ComponentInfo(char *nomenclature_number, char *name, double value, char *unit, char *country, double price) {
			this->nomenclature_number = nomenclature_number;
			this->name = name;
			this->value = value;
			this->unit = unit;
			FactoryInfo fi(country, price);
			this->factory_info= fi;
		}

		~ComponentInfo() {}

		char *get_nomenclature_number() {
			return this->nomenclature_number;
		}

		char *get_name() {
			return this->name;
		}

		double get_value() {
			return this->value;
		}

		char *get_unit() {
			return this->unit;
		}

		FactoryInfo get_factory_info() {
			return this->factory_info;
		}
};

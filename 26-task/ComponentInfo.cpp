#include <iostream>
#include <sstream>
#include "fact.h"

#define COMP_FILE "components.txt"

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

			// Write the information about the current account in accounts file
			ofstream out_file;
			out_file.open(COMP_FILE, ofstream::out | ofstream::app);
			out_file << *this;
			out_file.close();

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

		// Ovveride << to serialize and write Bank Account object in file
		friend std::ostream & operator << (std::ostream &out_file, ComponentInfo &component) {
			out_file << component.get_nomenclature_number() << " - " << component.get_name() <<
			" - " <<  component.get_value() << " - " << component.get_unit() << endl;
			return out_file;
		}

};

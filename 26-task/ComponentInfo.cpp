#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <cstdlib>
#include <string>
#include <cstring>
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

		ComponentInfo(string *tokens) {
			// Copy the nomenclature number
			char *nom = new char[tokens[0].length() + 1];
			strcpy(nom, tokens[0].c_str());
			this->nomenclature_number = nom;

			// Copy the name
			char *name = new char[tokens[1].length() + 1];
			strcpy(name, tokens[1].c_str());
			this->name = name;

			this->value = atof(tokens[2].c_str());

			// Copy the unit
			char *unit = new char[tokens[3].length() + 1];
			strcpy(unit, tokens[3].c_str());
			this->unit = unit;

			// Copy the country and price
			char *country = new char[tokens[4].length() + 1];
			strcpy(country, tokens[4].c_str());
			double price = atof(tokens[5].c_str());

			FactoryInfo fi(country, price);
			this->factory_info = fi;

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
			" - " <<  component.get_value() << " - " << component.get_unit() << " - " <<
			component.get_factory_info().get_country() << " - " << component.get_factory_info().get_price()
			<< endl;
			return out_file;
		}


		static list<ComponentInfo> get_all_components() {
			list<ComponentInfo> components;
			int pos = 0; // Position for the current line
			int i = 0; // Used by the token array
			string line = "";
			string tokens[6];
			string delimiter = " - "; // Delimiter in the file

			ifstream in_file(COMP_FILE);
			while (getline(in_file, line)) {
				istringstream iss(line); // get the line as string

				i = 0;
				while ((pos = line.find(delimiter)) != string::npos) {
					tokens[i] = line.substr(0, pos); // Add every part
					line.erase(0, pos + delimiter.length()); // Erase to the next delimiter

					i++;
				}

				tokens[i] = line; // Add the last part
				components.push_back(ComponentInfo(tokens));
			}

			return components;
		}

		static void delete_component_by_nomenclature(char *nomenclature) {
			string tmp_path = "tmp.txt";
			int pos = 0; // Position for the current line
			string line = "";
			string element;
			string delimiter = " - "; // Delimiter in the file

			ifstream in_file(COMP_FILE);
			std::ofstream tmp_file;
			tmp_file.open(tmp_path);

			while (getline(in_file, line)) {
				istringstream iss(line); // get the line as string

				pos = line.find(delimiter);
				element = line.substr(0, pos);

				// Add the line to the tmp file
				if (strcmp(nomenclature, element.c_str()) != 0) {
					tmp_file << line << endl;
				}
			}

			in_file.close();
			tmp_file.close();

			// Replace the file
			const char *path = COMP_FILE;
			remove(path);
			rename(tmp_path, path);
		}

		void print_info() {
			printf("Component with nomenclature: %s\nName:%s\nProperties:%lf - %s\nCountry:%s\nPrice:%lf\n\n\n",
				this->get_nomenclature_number(), this->get_name(), this->get_value(), this->get_unit(),
				this->factory_info.get_country(), this->factory_info.get_price());
		}
};

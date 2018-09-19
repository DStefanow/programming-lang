#include <iostream>
#include <fstream>
#include "core.h"

using namespace std;

void menu();
ComponentInfo create_new_component();
void get_all_components();
void delete_component();
void get_all_capacitors_in_given_range();

list<ComponentInfo> components = ComponentInfo::get_all_components();

int main() {
	menu();

	return 0;
}

void menu() {
	cout << "-- MAIN MENU --" << endl << "Pick up an option: " << endl;
	cout << "1) Create new component" << endl;
	cout << "2) Get all components" << endl;
	cout << "3) Delete component by nomenclature" << endl;
	cout << "4) Get all capacitors in given range" << endl;
	cout << "0) For Exit." << endl;

	int option; // Used for user choice
	while (1) {
		cout << "Enter option (0 for exit): ";
		cin >> option;

		if (option == 0) {
			break;
		}

		switch (option) {
			case 1: create_new_component(); break;
			case 2: get_all_components(); break;
			case 3: delete_component(); break;
			case 4: get_all_capacitors_in_given_range(); break;
			default : cout << "Wrong option!\n"; break;
		}
	}
}

ComponentInfo create_new_component() {
	// Properties
	char nomenclature_number[10];
	char name[24];
	double value;
	char unit[24];
	char country[24];
	double price;

	cout << "Enter nomenclature number (max 10 symbols): ";
	cin.ignore();
	cin.get(nomenclature_number, sizeof(nomenclature_number));

	cout << "Enter name (max 24 symbols): ";
	cin.ignore();
	cin.get(name, sizeof(name));

	cout << "Enter value: ";
	cin >> value;

	cout << "Enter unit (max 24 symbols): ";
	cin.ignore();
	cin.get(unit, sizeof(unit));

	cout << "Enter country (max 24 symbols): ";
	cin.ignore();
	cin.get(country, sizeof(country));

	cout << "Enter price: ";
	cin >> price;

	ComponentInfo component(nomenclature_number, name, value, unit, country, price);
	components = ComponentInfo::get_all_components(); // Update list

	return component;
}

void get_all_components() {
	for(list<ComponentInfo>::iterator component = components.begin(); component != components.end(); component++) {
		component->print_info();
	}
}

void delete_component() {
	// TODO ...
}

void get_all_capacitors_in_given_range() {
	// TODO ...
}

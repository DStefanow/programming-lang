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
	// TODO ...
}

void get_all_components() {
	// TODO ...
}

void delete_component() {
	// TODO ...
}

void get_all_capacitors_in_given_range() {
	// TODO ...
}

#include "Addresses.h"
#include "Person.h"

#include <iostream>
#include <fstream>

int main() {
	string addresses1[] = { "Sofia", "Krivodol", "Gorno Iznanadolnishte", "Vakarel", "Vraca"};
	string addresses2[] = {"Patalenica", "Dolno Iznanagornishte", "Pleven", "Belovo", "Burgas"};
	
	Addresses persons[] =
					  {
							  Addresses("Mitio Teslata", "9412345678", "Krivodol", addresses1),
							  Addresses("Chicho Bogdan", "9387654321", "Vraca", addresses2)
					  };
	
	int personsCount = sizeof(persons) / sizeof(persons[0]);

	std::ofstream file;
	file.open("Addresses.txt");
	if (!file)
	{
		std::cout << "File cannot be opened.";
	}
	else
	{
		for (int i = 0; i < personsCount; i++)
		{
			std::cout << persons[i];
			file << persons[i];
		}
		file.close();
	}
	
	string egn;
	bool doesEgnMatch = false;
	
	std::cout << "\nEnter EGN:\n";
	std::cin >> egn;
	
	for (int i = 0; i < personsCount; i++) {
		if (egn == persons[i].getEgn()) {
			doesEgnMatch = true;
			std::cout << "\nFound user with that EGN:";
			persons[i].showAddresses();
		}
	}
	if (!doesEgnMatch)
	{
		std::cout << "\nPerson with that EGN does not exist" << endl;
	}
	return 0;
}
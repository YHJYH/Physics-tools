// Yuheng Jia 10/02/2021
// Program to calculate transition energy using simple Bohr formula


#include<iostream>
#include<cmath>
#include<iomanip>

int main() {
	const double ground_state_energy_of_hydrogen_atom{ 13.6 }; // Define the ground state energy of hydrogen atom in eV.
	const double elementary_charge{ 1.602e-19 }; // Define the elementary charge value in Coulomb.
	double initial_state;
	double final_state;
	double atomic_number;
	bool convert_joule_to_eV;
	char response;

	std::cout << "This project allows you to calculate the photon energy of electron transition in the Bohr model." << std::endl;
	start:
	std::cout << "Please enter the atomic number: " << std::endl;
	std::cin >> atomic_number;
	while (std::cin.fail()) { // To avoid a non-numerical input. Similar in brlow for initial and final states.
		std::cout << "Please enter an integer value for the atomic number: " << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin >> atomic_number;
	}
	if (atomic_number - int(atomic_number) > 0) { // To avoid a non-integer input. Similar in below for initial and final states.
		std::cout << "Please enter a positive integer for the atomic number." << std::endl;
		goto start;
	}

	if (atomic_number > 0) {
		n_initial:
		std::cout << "Please enter the initial state: " << std::endl;
		std::cin >> initial_state;
		while (std::cin.fail()) {
			std::cout << "Please enter an integer value for the initial state: " << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> initial_state;
		}

		if (initial_state - int(initial_state) > 0) {
			std::cout << "Please enter a positive integer for the initial state." << std::endl;
			goto n_initial;
		}

		if (initial_state >= 0) {
			n_final:
			std::cout << "Please enter the final state: " << std::endl;
			std::cin >> final_state;
			while (std::cin.fail()) {
				std::cout << "Please enter an integer value for the final state: " << std::endl;
				std::cin.clear();
				std::cin.ignore();
				std::cin >> final_state;
			}

			if (final_state - int(final_state) > 0) {
				std::cout << "Please enter a positive integer for the final state." << std::endl;
				goto n_final;
			}

			if (initial_state > final_state && final_state >= 0) { // Only consider decay.
				std::cout << "Please enter 1 to get the photon energy in eV or 0 in J: " << std::endl;
				std::cin >> convert_joule_to_eV;
				if (convert_joule_to_eV) { 
					// Only keep 2 decimal places for precision.
					std::cout.setf(std::ios::fixed, std::ios::floatfield);
					std::cout << "The photon energy of electron transition for an atom of atomic number " << int(atomic_number)
						<< " from initial state " << int(initial_state)
						<< " to final state " << int(final_state)
						<< " is " <<std::setprecision(2)
						<< ground_state_energy_of_hydrogen_atom * pow(atomic_number, 2) * (1 / (pow(final_state, 2)) - 1 / (pow(initial_state, 2)))
						<< " eV." << std::endl;
				}
				else {
					std::cout.setf(std::ios::fixed, std::ios::floatfield);
					std::cout << "The photon energy of electron transition for an atom of atomic number " << int(atomic_number)
						<< " from initial state " << int(initial_state)
						<< " to final state " << int(final_state)
						<< " is " <<std::setprecision(2)
						<< (ground_state_energy_of_hydrogen_atom * pow(atomic_number, 2) * (1 / (pow(final_state, 2)) - 1 / (pow(initial_state, 2)))) * elementary_charge * 10e18
						<< " aJ (atto Joule, where 1 atto = 10e-18)." << std::endl;
				}
			}
			else {
				std::cout << "Please enter a non-negative interger smaller than the initial state for the final state: " << std::endl;
				std::cout << "Go back? [y/n]" << std::endl;
				std::cin >> response;
				if (response == 'y' || response == 'Y') {
					goto n_final;
				}
				else if (response == 'n' || response == 'N') {
					std::cout << "Please press any key to close the program." << std::endl;
				}
			}

		}
		else {
			std::cout << "Please enter a non-negative interger for the initial state." << std::endl; 
			std::cout << "Go back? [y/n]" << std::endl;
			std::cin >> response;
			if (response == 'y' || response == 'Y') {
				goto n_initial;
			}
			else if (response == 'n' || response == 'N') {
				std::cout << "Please press any key to close the program." << std::endl;
			}
		}
		
	}
	else {
		std::cout << "Please enter an integer greater than 0 for the atomic number. " << std::endl;
		std::cout << "Go back? [y/n]" << std::endl;
		std::cin >> response;
		if (response == 'y' || response == 'Y') {
			goto start;
		}
		else if (response == 'n' || response == 'N') {
			std::cout << "Please press any key to close the program." << std::endl;
		}
		
	}

	std::cout << "Do you want to repeat the program? [y/n]: " << std::endl;
	std::cin >> response;
	if (response == 'y' || response == 'Y') {
		goto start;
	}
	else if(response == 'n' || response == 'N'){
		std::cout << "Please press any key to close the program." << std::endl;
	}


	return 0;
}

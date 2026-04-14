#include <iostream>
#include <string>
#include "utils.hpp"

int main(){
	std::string email;
	bool valid = false;

	while(!valid){
		std::cout << "Enter your email: ";
		std::cin >> email;

		try{
			check_email(email);
			std::cout << "The email is valid!" << std::endl;
			valid = true;
		}
		catch(const std::invalid_argument& e){
			std::cout << "An error is found! The error: " << e.what() << "Please try again." << std::endl;
		}
	}
	return 0;
}

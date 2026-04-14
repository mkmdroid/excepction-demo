#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"

int main(){
	std::map<std::string, std::string> users;
	std::string current_user = "";
	int choice;

	while(true){
		if(current_user.empty()){
			std::cout << "1. Signup \n" << "2. Login \n";
		} else {
			std::cout << "Logged in as: " << current_user << "\n3.Logout \n";
		}
		std::cout << "4.Exit \n" << "Choice: ";
		std::cin >> choice;

		try{
			if(choice == 1 && current_user.empty()){
				std::string email, password;

				std::cout << "Enter email: ";
				std::cin >> email;
				check_email(email);

				std::cout << "Enter password: ";
				std::cin >> password;
				users[email] = password;

				std::cout << "Signup complete \n";

			} else if(choice == 2) {
				std::string email, password;

				std::cout << "Enter email: ";
				std::cin >> email;
				check_email(email);

				std::cout << "Enter password: ";
				std::cin >> password;

				if(users.count(email) && users[email] == password){
					current_user = email;
					std::cout << "Login complete \n";
				} else {
					std::cout << "Email or password is incorrect \n";
				}

			} else if(choice == 3 && !current_user.empty()) {
				current_user = "";
				std::cout << "Logout complete \n";

			} else if(choice == 4) {
				break;
			}
		}
		catch(const std::invalid_argument& e){
			std::cout << "Error: " << e.what() << "\n";
		}
	}

	return 0;
}

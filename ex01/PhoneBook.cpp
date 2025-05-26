/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:30:02 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/22 11:05:52 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

static void			print_input_hint();
static std::string	get_valid_string_input(std::string const &prompt);
static std::string	col_format(std::string str);
static unsigned		get_index_from_user(unsigned i);
static void			print_contact_info(Contact const &contact);

// -------------------------------------------------------------- public methods

void PhoneBook::	run() {

	std::string	input;

	std::cout <<	"************************\n"
					"* PhonyBooker V042.420 *\n"
					"************************\n"
					<< std::endl;

	print_input_hint();

	while (std::cin) {
		std::cout << "Enter command > " << std::flush;
		std::getline(std::cin, input);
		if (!std::cin || input == "EXIT")
			break;
		else if (input == "ADD")
			this->_add();
		else if (input == "SEARCH")
			this->_search();
		else {
			std::cout << "\n";
			if (!input.empty())
				std::cout << "ERROR: command not found\n\n";
			print_input_hint();
		}
	}
	if (input != "EXIT")
		std::cout << "\n";

	std::cout <<"\nThank you for using PhonyBooker V042.420! \\^o_o^/" << std::endl;
}

// ------------------------------------------------------------- private methods

void PhoneBook::	_add() {

	std::string	input;

	std::cout << "\n";
	input = get_valid_string_input("Enter first name: ");
	this->_contacts[this->_index].set_first_name(input);
	input = get_valid_string_input("Enter last name: ");
	this->_contacts[this->_index].set_last_name(input);
	input = get_valid_string_input("Enter nickname: ");
	this->_contacts[this->_index].set_nickname(input);
	input = get_valid_string_input("Enter phone number: ");
	this->_contacts[this->_index].set_phone_number(input);
	input = get_valid_string_input("Enter darkest secret: ");
	this->_contacts[this->_index].set_darkest_secret(input);

	if (!std::cin)
		return;

	this->_index = (this->_index + 1) % 8;
	std::cout << "\n";
}

void PhoneBook::	_search() {

	std::string	str;
	unsigned	index;
	unsigned	i;

	std::cout << "\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index|First name| Last name|  Nickname|\n";
	std::cout << "---------------------------------------------\n";
	i = 0;
	while (i < 8 && !this->_contacts[i].get_first_name().empty()) {
		std::cout << "|" << std::right << std::setw(10) << std::to_string(i);
		str = col_format(this->_contacts[i].get_first_name());
		std::cout << "|" << std::right << std::setw(10) << str;
		str = col_format(this->_contacts[i].get_last_name());
		std::cout << "|" << std::right << std::setw(10) << str;
		str = col_format(this->_contacts[i].get_nickname());
		std::cout << "|" << std::right << std::setw(10) << str << "|\n";
		++i;
	}
	std::cout << "---------------------------------------------" << std::endl;

	if (i == 0) {
		std::cout << "\nPhonebook is empty\n";
		std::cout << std::endl;
		return;
	}

	index = get_index_from_user(i);
	if (!std::cin)
		return;
	print_contact_info(_contacts[index]);
}

// ---------------------------------------------------------------- constructors

PhoneBook:: PhoneBook() {
	_index = 0;
}

// ------------------------------------------------------------------ destructor

PhoneBook:: ~PhoneBook() {};

// ------------------------------------------------------------ static functions

static void	print_input_hint() {
	std::cout << "Recognized commands:\n";
	std::cout << "--------------------\n";
	std::cout << std::right << std::setw(10) << "ADD";
	std::cout << " -> save a new contact\n";
	std::cout << std::right << std::setw(10) << "SEARCH";
	std::cout << " -> search for a contact\n";
	std::cout << std::right << std::setw(10) << "EXIT";
	std::cout << " -> exit PhonyBooker\n";
	std::cout << std::endl;
}

static std::string	get_valid_string_input(std::string const &prompt) {

	std::string	input("");

	if (!std::cin)
		return input;

	while (std::cin) {
		std::cout << prompt << std::flush;
		std::getline(std::cin, input);
		if (!std::cin)
			return input;
		if (input.empty()) {
			std::cout << "ERROR: field must be non empty\n";
			continue;
		}
		break;
	}
	return input;
}

static std::string	col_format(std::string str) {
	if (str.size() > 10)
		str[9] = '.';
	str = str.substr(0, 10);
	return (str);
}

static unsigned	get_index_from_user(unsigned entries) {

	int			index;
	std::string	str;

	while (std::cin) {
		std::cout << "\nEnter index > " << std::flush;
		std::getline(std::cin, str);
		if (!std::cin)
			return -1;
		try {
			index = std::stoi(str);
		} catch (...) {
			std::cout << "\nERROR: bad input\n";
			continue;
		}
		if (index < 0 || index >= static_cast<int>(entries)) {
			std::cout << "\nERROR: index is out of range\n";
			continue;
		}
		break;
	}
	return (index);
}

static void	print_contact_info(Contact const &contact) {
	std::cout << "\n";
	std::cout << std::right << std::setw(20) << "First name: ";
	std::cout << contact.get_first_name() << "\n";
	std::cout << std::right << std::setw(20) << "Last name: ";
	std::cout << contact.get_last_name() << "\n";
	std::cout << std::right << std::setw(20) << "Nickname: ";
	std::cout << contact.get_nickname() << "\n";
	std::cout << std::right << std::setw(20) << "Phone number: ";
	std::cout << contact.get_phone_number() << "\n";
	std::cout << std::right << std::setw(20) << "Darkest secret: ";
	std::cout << contact.get_darkest_secret() << "\n";
	std::cout << std::endl;
}

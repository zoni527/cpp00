/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 10:55:28 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/22 11:02:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact:: get_first_name() const {
	return this->_first_name;
}

std::string Contact:: get_last_name() const {
	return this->_last_name;
}

std::string Contact:: get_nickname() const {
	return this->_nickname;
}

std::string Contact:: get_phone_number() const {
	return this->_phone_number;
}

std::string Contact:: get_darkest_secret() const {
	return this->_darkest_secret;
}

// -----------------------------------------------------------------------------

void	Contact:: set_first_name(std::string const &str) {
	this->_first_name = str;
}

void	Contact:: set_last_name(std::string const &str) {
	this->_last_name = str;
}

void	Contact:: set_nickname(std::string const &str) {
	this->_nickname = str;
}

void	Contact:: set_phone_number(std::string const &str) {
	this->_phone_number = str;
}

void	Contact:: set_darkest_secret(std::string const &str) {
	this->_darkest_secret = str;
}

// -----------------------------------------------------------------------------

Contact:: Contact() {}
Contact:: ~Contact() {}

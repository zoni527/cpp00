/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 09:59:19 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/22 10:26:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

#define NUM_CONTACTS	8

class PhoneBook {

public:
	void	run( void );

	PhoneBook( void );

private:
	Contact		_contacts[NUM_CONTACTS];
	unsigned	_index;

	void	_add( void );
	void	_search( void );
};

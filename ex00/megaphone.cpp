/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:52:46 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/20 10:00:04 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( int argc, char *argv[] ) {

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	// Comments within functions, extra whitescpace, no brackets for return statements... (also a line that goes over 80 characters)
	// Welcome to C++ without the norm!

	std::string message;

	// Can't use a range loop with argv, thus the for loop.
	// argv is NULL terminated, thus I can use it as a condition.
	for (int i = 1; argv[i]; ++i)
	{
		// C strings can be used to assign C++ strings
		message = argv[i];

		// Range loop, don't need an index.
		// Read as: for each character in message -> do operation.
		// Uses a reference so that the string gets updated, otherwise only a
		// temporary copy of the character would be affected.
		for (char &c : message)
			c = std::toupper(c);
		std::cout << message;
	}
	std::cout << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:54:39 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/06 18:39:52 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <cstdlib>
#include <string.h>

std::string getInputSafely(const std::string &prompt)
{
	std::string input;
	std::cout << prompt;
	if (!std::getline(std::cin, input))
	{
		std::cout << "\nEOF detected, exiting program." << std::endl;
		exit(0);
	}
	return (input);
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected, exiting program." << std::endl;
			break ;
		}

		if (command == "ADD")
		{
			Contact contact;

			contact.setFirstName(getInputSafely("Enter first name: "));
			contact.setLastName(getInputSafely("Enter last name: "));
			contact.setNickname(getInputSafely("Enter nickname: "));
			contact.setPhoneNumber(getInputSafely("Enter phone number: "));
			contact.setDarkestSecret(getInputSafely("Enter darkest secret: "));

			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Enter index to view details: ";
			std::string indexStr;
			if (!std::getline(std::cin, indexStr))
			{
				std::cout << "\nEOF detected, exiting program." << std::endl;
				break ;
			}

			int index = 0;
			bool valid = true;

			for (size_t i = 0; i < indexStr.length(); i++)
			{
				if (!isdigit(indexStr[i]))
				{
					valid = false;
					break ;
				}
			}

			if (valid && indexStr.length() > 0)
			{
				index = atoi(indexStr.c_str());
				phoneBook.displayContactDetails(index);
			}
			else
			{
				std::cout << "Invalid index" << std::endl;
			}
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}

	return (0);
}
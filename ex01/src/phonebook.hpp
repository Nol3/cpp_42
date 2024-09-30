/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:49:17 by alcarden          #+#    #+#             */
/*   Updated: 2024/09/30 16:49:40 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>

class Contact
{
	public:
		Contact(void);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void Create(void);
		~Contact(void);
};

class Phonebook
{
  public:
	Phonebook(void);
	Contact contacts[8];
	void Search(void);
	~Phonebook(void);
};

#endif
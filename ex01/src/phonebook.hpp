/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:21:46 by alcarden          #+#    #+#             */
/*   Updated: 2024/11/07 13:24:24 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();
    void addContact(const Contact &contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
};

#endif

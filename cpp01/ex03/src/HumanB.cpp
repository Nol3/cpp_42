/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:15:21 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:17:04 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/violence.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack( void )
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	return;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:15:15 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:16:54 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/violence.hpp"

void HumanA::attack( void )
{
	std::cout << this->name << " attacks with their ";
	std::cout << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	return;
}

HumanA::~HumanA()
{
	return ;
}

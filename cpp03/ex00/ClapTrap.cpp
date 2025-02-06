/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:54:51 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/06 13:56:11 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "Default constructor called" << std::endl;
    _hitpoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
    else if(_energyPoints <= 0)
        std::cout << "ClapTrap " << _name << " is out of energy and cannot attack" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", dealing ";
        std::cout << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
    else if (amount >= _hitpoints)
    {
        if(amount > _hitpoints)
            amount = _hitpoints;
        _hitpoints = 0;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage and died" << std::endl;
    }
    else
    {
        _hitpoints -= amount;
        std::cout << "ClapTrap " << _name << " took " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitpoints == 0)
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
    else if (_energyPoints == 0)
        std::cout << "ClapTrap " << _name << " is out of energy and cannot repair itself" << std::endl;
    else
    {
        _hitpoints += amount;
        std::cout << "ClapTrap " << _name << " was repaired for " << amount << " hit points!" << std::endl;
        _energyPoints -= 1;
    }
}

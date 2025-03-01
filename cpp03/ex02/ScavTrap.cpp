/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:56:36 by alcarden          #+#    #+#             */
/*   Updated: 2025/03/01 13:56:44 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(str name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap *" << _name << "* constructed with special values" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap *" << _name << "* destructed" << std::endl;
}

void ScavTrap::attack(str const &target)
{
    if(_hitPoints == 0)
        std::cout << "ScavTrap *" << _name << "* is too damaged to fight!" << std::endl;
    else if(_energyPoints <= 0)

        std::cout << "ScavTrap *" << _name << "* has no energy left to fight!" << std::endl;
    else
    {
        std::cout << "ScavTrap *" << _name << "* viciously attacks *" << target
                 << "* causing *" << this->_attackDamage << "* points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap *" << _name << "* is now in Gate keeper mode" << std::endl;
}

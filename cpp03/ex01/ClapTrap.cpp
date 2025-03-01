/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:54:51 by alcarden          #+#    #+#             */
/*   Updated: 2025/03/01 13:51:42 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << std::setw(15) << "ClapTrap \033[0m*" << _name << "* is born with default constructors\033[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[46m----------------------------\033[0m" << std::endl;
    std::cout << "\033[46m-\033[0m" << std::setw(27) << "\033[35mHit Points: \033[0m" << this->_hitPoints << std::setw(16) << "\033[46m-\033[0m" << std::endl;
    std::cout << "\033[46m-\033[0m" << std::setw(27) << "\033[35mEnergy Points: \033[0m" << this->_energyPoints << std::setw(16) << "\033[46m-\033[0m" << std::endl;
    std::cout << "\033[46m-\033[0m" << std::setw(27) << "\033[35mAttack Damage: \033[0m" << this->_attackDamage << std::setw(17) << "\033[46m-\033[0m" << std::endl;
    std::cout << "\033[46m----------------------------\033[0m" << std::endl;
    std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap unit '" << _name << "' has been decommissioned." << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    if(_hitPoints == 0)
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* is too damaged to fight!" << std::endl;
    else if(_energyPoints <= 0)
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* has no energy left to fight!" << std::endl;
    else
    {
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* attacks *" << target << "* causing *"
                 << this->_attackDamage << "* points of damage!" << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if(_hitPoints == 0)
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* is already out of commission!" << std::endl;
    else
    {
        if (amount >= (unsigned int)_hitPoints)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* has taken *" << amount << "* points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(_hitPoints == 0)
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* is too damaged for repairs!" << std::endl;
    else if (_energyPoints == 0)
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* lacks energy for repairs!" << std::endl;
    else
    {
        _hitPoints += amount;
        std::cout << std::setw(10) << "ClapTrap *" << _name << "* has been repaired for *" << amount << "* points!" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(80) << "\033[1;35mTOTAL Hit Points: \033[0m" << this->_hitPoints << std::endl;
        _energyPoints--;
    }
}

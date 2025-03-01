/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:56:29 by alcarden          #+#    #+#             */
/*   Updated: 2025/03/01 14:54:35 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap claptrap("Cyndaquil");
    ScavTrap scavtrap("Typhlosion");

    claptrap.attack("Wild Pokemon");
    scavtrap.attack("Wild Pokemon");

    claptrap.takeDamage(5);
    scavtrap.takeDamage(30);

    claptrap.beRepaired(3);
    scavtrap.beRepaired(20);

    scavtrap.guardGate();

    FragTrap fragtrap("Quilava");

    fragtrap.attack("Wild Pokemon");
    fragtrap.takeDamage(20);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys();

    return 0;
}

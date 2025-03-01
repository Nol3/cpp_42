/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:56:29 by alcarden          #+#    #+#             */
/*   Updated: 2025/03/01 13:56:30 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    return 0;
}

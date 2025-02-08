/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:12:44 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:20:23 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/violence.hpp"

int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA Alex("Alex", club);
		Alex.attack();
		club.setType("some other type of club");
		Alex.attack();
	}
	{
		Weapon club = Weapon("Unnecessary long club");
		HumanB Dani("Dani");
		Dani.setWeapon(club);
		Dani.attack();
		club.setType("some other type of club");
		Dani.attack();
	}
}

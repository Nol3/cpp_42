/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:30:46 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:34:18 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug ( void )
{
	std::cout << "Probando, Probando, si, si..." << std::endl;
}

void Harl::info ( void )
{
	std::cout << "Harl funciona correctamente" << std::endl;
}

void Harl::warning ( void )
{
	std::cout << "CUIDADO! posible problema" << std::endl;
}

void Harl::error ( void )
{
	std::cout << "Hay un error, desalojen inmediatamente!" << std::endl;
}

void Harl::complain( std::string level )
{
	std::map<std::string, void (Harl::*)()> map;

	map["DEBUG"] = &Harl::debug;
	map["INFO"] =  &Harl::info;
	map["WARNING"] = &Harl::warning;
	map["ERROR"] = &Harl::error;

	if(map.find(level) != map.end())
		(this->*map[level])();
	else
		std::cout << "Nivel introducido incorrecto, intentelo de nuevo." << std::endl;
}

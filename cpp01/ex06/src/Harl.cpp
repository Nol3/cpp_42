/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:30:46 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:41:29 by alcarden         ###   ########.fr       */
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

	if (map.find(level) == map.end())
	{
		std::cout << "[ERROR] log levels are: ";
		std::cout << "DEBUG, INFO, WARNING, ERROR" << std::endl;
		return ;
	}
	switch(level[0])
	{
		case 'D':
			(this->*map["DEBUG"])();
			(this->*map["INFO"])();
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'I':
			(this->*map["INFO"])();
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'W':
			(this->*map["WARNING"])();
			(this->*map["ERROR"])();
			break;
		case 'E':
			(this->*map["ERROR"])();
			break;
	}
}

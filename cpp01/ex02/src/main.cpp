/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:08:55 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:09:04 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "String Memory Address:	  " << &str << std::endl;
	std::cout << "StringPTR Memory Address: " << strPTR << std::endl;
	std::cout << "StringREF Memory Address: " << &strREF << std::endl;
	std::cout << "String Value:		" << str << std::endl;
	std::cout << "StringPTR Value:	" << *strPTR << std::endl;
	std::cout << "StringREF Value:	" << strREF << std::endl;
	return (0);
}

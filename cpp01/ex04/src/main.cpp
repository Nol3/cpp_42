/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:22:03 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:28:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <string>
#include "replace.hpp"

std::string replace_string(std::string buffer, const std::string search,
	const std::string replace)
{
	size_t	erase_length;
	size_t	replace_length;
	size_t	pos_search;

	erase_length = search.length();
	replace_length = replace.length();
	pos_search = 0;
	pos_search = buffer.find(search);
	while (pos_search != std::string::npos)
	{
		buffer.erase(pos_search, erase_length);
		buffer.insert(pos_search, replace);
		pos_search = buffer.find(search, pos_search + replace_length);
	}
	return (buffer);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	std::ifstream file_in(filename.c_str());
	std::ofstream file_out;
	std::string buffer;
	if (!file_in.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
	std::string replace_filename = filename + ".replace";
	file_out.open(replace_filename.c_str());
	if (!file_out.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		return (1);
	}
	else
	{
		while (std::getline(file_in, buffer))
		{
			buffer = replace_string(buffer, search, replace);
			file_out << buffer << std::endl;
			if (file_in.peek() != EOF)
				file_out << std::endl;
		}
		file_out.close();
		file_in.close();
	}
	return (0);
}

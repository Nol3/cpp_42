/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:48:36 by alcarden          #+#    #+#             */
/*   Updated: 2024/09/30 16:51:18 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	char buff[512];

	Phonebook phone;
	while (exit)
	{
		std::cin >> buff;
		if ()
		{
			/* code */
		}
		ft_strncmp(buff, "ADD", 3);
		ft_strncmp(buff, "EXIT", 4);
		ft_strncmp(buff, "SEARCH", 6);

	}
	return 0;
}
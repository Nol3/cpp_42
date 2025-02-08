/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:04:22 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:06:59 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main(void)
{
	int N;

	std::cout << "Enter the number of zombies: ";
	std::cin >> N;

	Zombie *zombie = zombieHorde(N, "José Manuel");

	for (int i = 0; i < N; i++)
		zombie[i].announce();

	for (int i = 0; i < N; i++)
		zombie[i].~Zombie();
}

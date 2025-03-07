/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:17 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/08 16:01:18 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Crear zombie en el heap (memoria dinámica)
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();

    // Crear zombie en el stack (memoria estática)
    randomChump("Stack Zombie");

    // Liberar la memoria del zombie del heap
    delete heapZombie;

    return 0;
}

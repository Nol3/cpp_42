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
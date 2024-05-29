#include "EnemigoFinal.h"

// Constructor del Boss Final
EnemigoFinal::EnemigoFinal(string nombre, int vida, int ataque, int x, int y, int superAtaque1, int superAtaque2)
    : Personaje(nombre, vida, ataque, x, y), superAtaque1(superAtaque1), superAtaque2(superAtaque2) {}

// Con esto podre lanzar los super ataques  dandole un numero aleatorio de daño al super ataque para que este mas fuerte el boss.
int EnemigoFinal::ejecutarSuperAtaque1() {
    return (rand() % 10) + 35; 
}

int EnemigoFinal::ejecutarSuperAtaque2() {
    return (rand() % 15) + 40; 
}


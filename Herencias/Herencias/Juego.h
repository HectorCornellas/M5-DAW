#ifndef JUEGO_H
#define JUEGO_H

#include "Personaje.h"
#include "EnemigoFinal.h"
#include <vector>

class Juego {
private:
    static const int FILAS = 5; // Cuento las filas que hay en el tablero.
    static const int COLUMNAS = 5; // Hago lo mismo pero con las columnas.
    char tablero[FILAS][COLUMNAS];
    Personaje heroe;
    vector<Personaje> enemigos;
    EnemigoFinal enemigoFinal;
    void inicializarTablero(); // Los voids se ejecutaran.
    void mostrarTablero();
    void moverHeroe(char direccion);
    void batalla(Personaje& enemigo);
    void batallaFinal();

public:
    Juego(); // Iniciara el juego con este constructor.
    void jugar();
};

#endif

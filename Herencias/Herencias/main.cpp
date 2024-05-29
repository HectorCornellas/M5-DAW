#include <iostream>
#include "Juego.h"

using namespace std;

// Mensaje de bienvenida.
void mostrarPantallaInicio() {
    cout << "******************************************" << endl;
    cout << "*            BIENVENIDO AL JUEGO         *" << endl;
    cout << "*           DERROTA A LOS ENEMIGOS       *" << endl;
    cout << "*       Y INTENTA ESCAPAR DE LA CUEVA!   *" << endl;
    cout << "******************************************" << endl;
    cout << "Enter para comenzar..." << endl;
    cin.ignore();
}

int main() {
    mostrarPantallaInicio();

    Juego juego;
    juego.jugar();

    return 0;
}

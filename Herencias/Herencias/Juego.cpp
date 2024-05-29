#include "Juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

//Constructor
Juego::Juego()
    : heroe("Caballero", 200, 30, 0, 0), //Personaje heroe con Vida y Daño.
    enemigoFinal("Final Boss", 250, 20, FILAS - 1, rand() % COLUMNAS, 35, 40) { // Boss final con Vida, Daño, posicion aleatoria y el daño de los superAtaques.
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < 4; ++i) {
        int x = rand() % FILAS; // Posiciones aleatorias para los enemigos.
        int y = rand() % COLUMNAS;
        enemigos.push_back(Personaje("Fantasma", 100, 15, x, y)); //Enemigos con Vida y daño.
    }
    inicializarTablero();
}

void Juego::inicializarTablero() {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            tablero[i][j] = '.'; //Puntos del tablero.
        }
    }
    tablero[heroe.getPosicionX()][heroe.getPosicionY()] = 'C'; //Colocar heroe tablero.
    for (const auto& enemigo : enemigos) {
        tablero[enemigo.getPosicionX()][enemigo.getPosicionY()] = 'F'; //Colocar Fantasmas tablero.
    }
    tablero[enemigoFinal.getPosicionX()][enemigoFinal.getPosicionY()] = 'B'; // Colocar Boss Final tablero.
}

void Juego::mostrarTablero() {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << tablero[i][j] << ' '; //Printea todo lo que hay en el tablero.
        }
        cout << endl;
    }
}

void Juego::moverHeroe(char direccion) {
    int nuevaX = heroe.getPosicionX();
    int nuevaY = heroe.getPosicionY();

    switch (direccion) { // Movimiento con teclas del tablero.
    case 'w': if (nuevaX > 0) nuevaX--; break;
    case 's': if (nuevaX < FILAS - 1) nuevaX++; break;
    case 'a': if (nuevaY > 0) nuevaY--; break;
    case 'd': if (nuevaY < COLUMNAS - 1) nuevaY++; break;
    default: break;
    }

    if (tablero[nuevaX][nuevaY] == '.') {
        tablero[heroe.getPosicionX()][heroe.getPosicionY()] = '.';
        heroe.setPosicion(nuevaX, nuevaY);
        tablero[nuevaX][nuevaY] = 'C';
    }
    else if (tablero[nuevaX][nuevaY] == 'F') { // Si el heroe y el fantasma se encuentran inicia una pelea.
        for (auto& enemigo : enemigos) {
            if (enemigo.getPosicionX() == nuevaX && enemigo.getPosicionY() == nuevaY) {
                batalla(enemigo);
                break;
            }
        }
    }
    else if (tablero[nuevaX][nuevaY] == 'B') { // Si el heroe y el Boss se encuentran incian una pelea.
        batallaFinal();
    }
}

void Juego::batalla(Personaje& enemigo) { // Pelea con el Fantasma.
    cout << "Lucha con honor contra un " << enemigo.getNombre() << "!" << endl; 
    while (heroe.Alive() && enemigo.Alive()) {
        cout << "Turno del heroe (" << heroe.getNombre() << "): Atacas con " << heroe.getAtaque() << " de damage." << endl;
        enemigo.gDamage(heroe.getAtaque());
        if (!enemigo.Alive()) {
            cout << "Has vencido al peligroso " << enemigo.getNombre() << "!" << endl;
            tablero[enemigo.getPosicionX()][enemigo.getPosicionY()] = '.';
            heroe.setPosicion(enemigo.getPosicionX(), enemigo.getPosicionY());
            return;
        }
        cout << "Turno del enemigo (" << enemigo.getNombre() << "): Ataca con " << enemigo.getAtaque() << " de damage." << endl;
        heroe.gDamage(enemigo.getAtaque());
    }

    if (!heroe.Alive()) {
        cout << "Has sido vencido por el " << enemigo.getNombre() << "!" << endl;
    }
}

void Juego::batallaFinal() { // Pelea con el Boss Final.
    cout << "Lucha final contra " << enemigoFinal.getNombre() << "!" << endl;

    bool turnoHeroe = true;

    while (heroe.Alive() && enemigoFinal.Alive()) {
        if (turnoHeroe) {
            int ataqueHeroe = heroe.getAtaque();
            enemigoFinal.gDamage(ataqueHeroe);

            cout << "Turno del héroe (" << heroe.getNombre() << "): Ataca al jefe final con " << ataqueHeroe << " de damage!" << endl;
        }
        else {
            int ataqueEnemigo;
            int opcionSuperAtaque = rand() % 3;
            if (opcionSuperAtaque == 0) {
                ataqueEnemigo = enemigoFinal.ejecutarSuperAtaque1();
                cout << "Turno del Final Boss (" << enemigoFinal.getNombre() << "): Ejecuta un superataque 1 de " << ataqueEnemigo << " de damage!" << endl;
            }
            else if (opcionSuperAtaque == 1) {
                ataqueEnemigo = enemigoFinal.ejecutarSuperAtaque2();
                cout << "Turno del Final Boss (" << enemigoFinal.getNombre() << "): Ejecuta un superataque 2 de " << ataqueEnemigo << " de damage!" << endl;
            }
            else {
                ataqueEnemigo = enemigoFinal.getAtaque();
                cout << "Turno del Final Boss (" << enemigoFinal.getNombre() << "): Ataca al heroe con " << ataqueEnemigo << " de damage." << endl;
            }
            heroe.gDamage(ataqueEnemigo);
        }
        turnoHeroe = !turnoHeroe;
    }
    if (!heroe.Alive()) {
        cout << "******************************************" << endl;
        cout << "*********** ERES TERRIBLE! ***************" << endl;
        cout << "****** TE FALTABA ENTRENAMIENTO **********" << endl;
        cout << "******************************************" << endl;
    }
    else {
        cout << "******************************************" << endl;
        cout << "*************** MUY BUENA! ***************" << endl;
        cout << "****** HAS VENCIDO AL ENEMIGO FINAL ******" << endl;
        cout << "******************************************" << endl;
    }
}

void Juego::jugar() {
    while (heroe.Alive() && enemigoFinal.Alive()) { // Mensaje para explicar como mover al heroe cuando se printea el tablero.
        mostrarTablero();
        char movimiento;
        cout << "Mueve al persona con las teclas (w para mover arriba, s: para mover abajo, a: para mover a la izq, d: para mover a la der): ";
        cin >> movimiento;
        moverHeroe(movimiento);
    }
}

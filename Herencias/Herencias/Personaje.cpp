#include "Personaje.h"

// Constructor del Personaje.
Personaje::Personaje(string nombre, int vida, int ataque, int x, int y)
    : nombre(nombre), vida(vida), ataque(ataque), posicionX(x), posicionY(y) {}

int Personaje::getVida() const { return vida; }
int Personaje::getAtaque() const { return ataque; }
string Personaje::getNombre() const { return nombre; }
int Personaje::getPosicionX() const { return posicionX; }
int Personaje::getPosicionY() const { return posicionY; }

void Personaje::setPosicion(int x, int y) {
    posicionX = x;
    posicionY = y;
}

bool Personaje::Alive() const { return vida > 0; }

void Personaje::gDamage(int damage) { // Con esto el personaje ira perdiendo vida segun le quiten en la pelea.
    vida -= damage;
    if (vida < 0) vida = 0;
}

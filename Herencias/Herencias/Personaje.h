#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <string>

using namespace std;

class Personaje {
protected:
    int vida;
    int ataque;
    string nombre;
    int posicionX;
    int posicionY;

public:
    Personaje(string nombre, int vida, int ataque, int x, int y);

    int getVida() const;
    int getAtaque() const;
    string getNombre() const;
    int getPosicionX() const;
    int getPosicionY() const;

    void setPosicion(int x, int y);
    bool Alive() const;
    void gDamage(int damage);
};

#endif

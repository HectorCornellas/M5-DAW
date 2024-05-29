#ifndef ENEMIGOFINAL_H
#define ENEMIGOFINAL_H

#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    int superAtaque1;
    int superAtaque2;

public:
    EnemigoFinal(string nombre, int vida, int ataque, int x, int y, int superAtaque1, int superAtaque2);

    int ejecutarSuperAtaque1();
    int ejecutarSuperAtaque2();
};

#endif

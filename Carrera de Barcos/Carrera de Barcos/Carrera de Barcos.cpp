#include <iostream>
#include "Barco.h"
#include "Barco.cpp"
using namespace std;
void lanzarDado() {
    int lanzar = rand() % 6 + 1;
    int pVel = pVel + lanzar;
}

void nitroRandom() {
    int nitroRandom = rand() % 2;
    int pVel = barco.getVel();
    if (nitroRandom == 0) {
        pVel /= 2;
    }
    else {
        pVel *= 2;
    }
    barco.setVel(pVel);
    barco.setNit(0);
}

int main()
{
        Barco barco1("Mi Barco");

        barco1.setNombre("Barco1");
        barco1.setVel(0);
        barco1.setDis(1000);
        barco1.setNit(1);

        cout << "Nombre del barco: " << barco1.getNombre() << endl;
        cout << "Velocidad del barco: " << barco1.getVel() << endl;
        cout << "Distancia recorrida: " << barco1.getDis() << endl;
        cout << "Nitro restante: " << barco1.getNit() << endl;

        Barco barco2("Mi Barco");

        barco2.setNombre("Barco2");
        barco2.setVel(0);
        barco2.setDis(1000);
        barco2.setNit(1);

        cout << "Nombre del barco: " << barco2.getNombre() << endl;
        cout << "Velocidad del barco: " << barco2.getVel() << endl;
        cout << "Distancia recorrida: " << barco2.getDis() << endl;
        cout << "Nitro restante: " << barco2.getNit() << std::endl;
}


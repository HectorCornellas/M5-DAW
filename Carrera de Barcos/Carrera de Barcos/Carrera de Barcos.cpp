#include <iostream>
#include "Barco.h"

int main()
{
        Barco barco1("Mi Barco");

        barco1.setNombre("Barco1");
        barco1.setVel(0);
        barco1.setDis(1000);
        barco1.setNit(1);

        std::cout << "Nombre del barco: " << barco1.getNombre() << std::endl;
        std::cout << "Velocidad del barco: " << barco1.getVel() << std::endl;
        std::cout << "Distancia recorrida: " << barco1.getDis() << std::endl;
        std::cout << "Nitro restante: " << barco1.getNit() << std::endl;

        Barco barco2("Mi Barco");

        barco2.setNombre("Barco2");
        barco2.setVel(0);
        barco2.setDis(1000);
        barco2.setNit(1);

        std::cout << "Nombre del barco: " << barco2.getNombre() << std::endl;
        std::cout << "Velocidad del barco: " << barco2.getVel() << std::endl;
        std::cout << "Distancia recorrida: " << barco2.getDis() << std::endl;
        std::cout << "Nitro restante: " << barco2.getNit() << std::endl;
}


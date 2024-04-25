#pragma once
#include <iostream>
#include <string>
using namespace std;

class Barco {
private:
    string nombre;
    int velocidad;
    int distancia;
    int nitro;

public:
    string getNombre();
    void setNombre(string pNombre);
    int getVel();
    void setVel(int pVel);
    int getDis();
    void setDis();
    int getNit();
    void setNit();


    Barco();
    Barco(string n) : nombre(n), velocidad(0), distancia(0), nitro(1) {}

    
};




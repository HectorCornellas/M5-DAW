#pragma once
#include <iostream>
#include <string>
#include "Barco.cpp"
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
    void setDis(int pDis);
    int getNit();
    void setNit(int pNit);


    Barco();
    Barco(string n) : nombre(n), velocidad(0), distancia(0), nitro(1) {}

    
};




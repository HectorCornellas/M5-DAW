#include <iostream>
#include "prediccion.h"

using namespace std;

int main() {
    srand(time(0));

    prediccion pred; // Crear un objeto de la clase prediccion
    pred.Bienvenida();

    int opcion = rand() % 7; // Mover la declaración de 'opcion' aquí

    string prediccion = pred.ObtenerPrediccion(opcion);
    pred.MostrarMensajeSegunEdad(prediccion);

    return 0;
}



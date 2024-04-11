#include "prediccion.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

string nombre;
int edad;

void prediccion::Bienvenida() {
    cout << "Hola! Cual es tu nombre?: ";
    cin >> nombre;

    cout << "Ahora, introduce tu edad: ";
    cin >> edad;
}

string prediccion::ObtenerPrediccion(int opcion) {
    string prediccion;

    switch (opcion) {
    case 0:
        prediccion = "Te espera una gran aventura.";
        break;
    case 1:
        prediccion = "Vas a descubrir nuevas oportunidades.";
        break;
    case 2:
        prediccion = "Confía en tu intuición para tomar decisiones.";
        break;
    case 3:
        prediccion = "Pronto recibirás una noticia emocionante.";
        break;
    case 4:
        prediccion = "Una nueva amistad transformará tu perspectiva.";
        break;
    case 5:
        prediccion = "Evita los conflictos y mantente positivo.";
        break;
    case 6:
        prediccion = "Una experiencia cultural en un viaje te enriquecerá.";
        break;
    default:
        prediccion = "El futuro es incierto, pero tu actitud hace la diferencia.";
        break;
    }

    return prediccion;
}

void prediccion::MostrarMensajeSegunEdad(string prediccion) {
    if (edad >= 18 && edad <= 30) {
        cout << "Por tu edad puedo decir que pronto alguien te contactara para ofrecerte un trabajo que no debes rechazar";
    }
    else if (edad >= 31 && edad <= 40) {
        cout << "Segun veo, algo malo va a suceder";
    }
    else if (edad >= 41 && edad <= 70) {
        cout << "El dinero llama a la puerta";
    }
    else if (edad >= 71 && edad <= 100) {
        cout << "Buenas cosas sucederan";
    }

    cout << "\nHola " << nombre << ", como el mejor adivino que soy, esto es lo que veo en tu futuro:\n";
    cout << prediccion << endl;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0));

    cout << " Quieres comenzar una partida de Blackjack (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta != 's') {
        cout << "Fin." << endl;
        return 0;
    }

    cout << " Empieza tu partida de BlackJack" << endl;

    auto generarCarta = []() {
        string palos[] = { "Picas", "Rombos", "Treboles", "Corazones" };
        string palo = palos[rand() % 4];
        int valor = rand() % 9 + 2;
        return make_pair(valor, palo);
        };

    auto cartaToString = [](pair<int, string> carta) {
        if (carta.first >= 2 && carta.first <= 10) {
            return to_string(carta.first) + " de " + carta.second;
        }
        else if (carta.first == 1) {
            return "AS de " + carta.second;
        }
        else {
            string nombres[] = { "", "", "J", "Q", "K" };
            return nombres[carta.first] + " de " + carta.second;
        }
        };

    pair<int, string> cartaJugador1 = generarCarta();
    pair<int, string> cartaCroupier = generarCarta();

    cout << " Tu mano: " << cartaToString(cartaJugador1) << endl;
    cout << " Carta del croupier: " << cartaToString(cartaCroupier) << endl;

    int sumaJugador = 0;
    int sumaCroupier = cartaCroupier.first;

    char opcion;
    if (cartaJugador1.first == 1) {
        cout << " Qué valor deseas para el AS (1/11): ";
        int valorAs;
        cin >> valorAs;
        sumaJugador = (cartaJugador1.first == 1);
    }
    else {
        sumaJugador = cartaJugador1.first;
    }

    while (sumaJugador < 21) {
        cout << " Deseas pedir una carta adicional (s/n): ";
        cin >> opcion;

        if (opcion == 's') {
            pair<int, string> cartaAdicional = generarCarta();
            cout << " Carta adicional: " << cartaToString(cartaAdicional) << endl;
            if (cartaAdicional.first == 1 && sumaJugador + 11 <= 21) {
                cout << " Qué valor deseas para el AS (1/11): ";
                int valorAs;
                cin >> valorAs;
                sumaJugador += valorAs;
            }
            else {
                sumaJugador += cartaAdicional.first;
            }
        }
        else {
            break;
        }
    }

    if (sumaJugador > 21) {
        cout << " Te has pasado de 21 puntos. Has perdido la partida." << endl;
    }
    else {
        while (sumaCroupier < 17) {
            pair<int, string> cartaAdicional = generarCarta();
            sumaCroupier += cartaAdicional.first;
        }

        cout << " Suma del croupier: " << sumaCroupier << endl;

        if (sumaCroupier > 21 || sumaJugador > sumaCroupier) {
            cout << " Has ganado la partida." << endl;
        }
        else if (sumaJugador == sumaCroupier) {
            cout << " Has empatado la partida." << endl;
        }
        else {
            cout << " Has perdido la partida." << endl;
        }
    }

    return 0;
}

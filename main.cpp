#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// ------------------ CLASE JUGADOR ------------------
class Jugador {
private:
    string nombre;
    string apellido;
    int numero;
    int goles;
    int tarjetasAmarillas;

public:
    Jugador() {
        nombre = "nombre";
        apellido = "apellido";
        numero = 0;
        goles = 0;
        tarjetasAmarillas = 0;
    }

    void setJugador(string n, string a, int num) {
        nombre = n;
        apellido = a;
        numero = num;
    }

    void anotarGol() {
        goles++;
    }

    void mostrar() {
        cout << numero << " - " << nombre << " " << apellido
             << " | Goles: " << goles << endl;
    }
};

// ------------------ CLASE EQUIPO ------------------
class Equipo {
private:
    string nombre;
    int ranking;
    Jugador* jugadores; // memoria dinámica
    int numJugadores;

public:
    Equipo() {
        nombre = "";
        ranking = 0;
        numJugadores = 26;
        jugadores = new Jugador[numJugadores];
    }

    void setEquipo(string n, int r) {
        nombre = n;
        ranking = r;

        // crear jugadores automáticamente
        for (int i = 0; i < numJugadores; i++) {
            jugadores[i].setJugador("nombre" + to_string(i+1),
                                    "apellido" + to_string(i+1),
                                    i + 1);
        }
    }

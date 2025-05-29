#ifndef JUGADOR_H
#define JUGADOR_H

#include "carta.h"
#include "color_defs.h"
#include <string>
#include <vector>

using namespace std;

class Tablero;

class Jugador {
public:
    string nombre;
    vector<Carta> mano;
    int puntos = 0;
    int vagones = 18;

    Jugador(string nombre);
    void agregarCarta(Carta& carta);
    void mostrarMano();
    bool hacerRuta(Tablero& tablero, string ruta);
    void arrastrarCarta(Tablero& tablero);
};

#endif
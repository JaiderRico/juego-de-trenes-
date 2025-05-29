// juego.h
#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"
#include "jugador.h"
#include <vector>
#include <iostream>

using namespace std;

class Juego {
public:
    Tablero tablero;
    vector<Jugador> jugadores;
    
    Juego();
    void iniciarJuego();
    void jugarRondas();
    void finalizarJuego();
};

#endif
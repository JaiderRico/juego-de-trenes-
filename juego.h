#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "tablero.h"
#include "mazo.h"
#include "carta.h"
#include "jugador.h"

using namespace std;


class Juego{
    public:
        Tablero tablero;
        Mazo mazo;
        vector<Jugador> jugadores;
        

        Juego();
        void iniciarJuego();
        void jugarRondas();
        void finalizarJuego();

};

#endif
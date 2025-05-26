#ifndef MAZO_H
#define MAZO_H

#include "carta.h"
#include "jugador.h"

class Tablero; 


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

#define RESET   "\033[0m"
#define BG_ROJO    "\033[41m"
#define BG_AZUL    "\033[44m"
#define BG_NARANJA "\033[48;5;208m"  
#define BG_MARRON  "\033[48;5;94m"   
#define BG_VERDE   "\033[42m"
#define BG_MORADO  "\033[45m"

class Mazo{

    public:
        int cantidadCartas = 72;
        vector<Carta> mazo;
        vector<string> colores = {BG_ROJO, BG_AZUL, BG_NARANJA, BG_MARRON, BG_VERDE, BG_MORADO};

        Mazo();

        void crearMazo();
        void Barajar();
        void AgregarCarta(Carta carta);
        void repartirCartas(Tablero& tablero);
        void repartirCartasInciales(Tablero& tablero);
};

#endif
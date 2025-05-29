#ifndef MAZO_H
#define MAZO_H

#include "carta.h"
#include "color_defs.h"
#include <vector>
#include <string>

using namespace std;

class Tablero; 

class Mazo {
public:
    int cantidadCartas = 72;
    vector<Carta> mazo;
    vector<string> colores = {
        BG_ROJO, BG_AZUL, BG_NARANJA, 
        BG_MARRON, BG_VERDE, BG_MORADO
    };

    Mazo();
    void crearMazo();
    void Barajar();
    void AgregarCarta(Carta carta);
    void repartirCartas(Tablero& tablero);
    void repartirCartasInciales(Tablero& tablero);
};

#endif
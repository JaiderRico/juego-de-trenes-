#include "mazo.h"
#include "tablero.h"
#include "carta.h"
#include <random>   
#include <algorithm> 
#include <iostream>

using namespace std;

Mazo::Mazo() {}

void Mazo::crearMazo() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 12; ++j) {
            mazo.push_back(Carta(colores[i]));
        }
    }
    Barajar();
}

void Mazo::Barajar() {
    random_device rd;               
    mt19937 generador(rd());              
    shuffle(mazo.begin(), mazo.end(), generador);
}

void Mazo::AgregarCarta(Carta carta) {
    mazo.push_back(carta);
}

void Mazo::repartirCartas(Tablero &tablero)
{
    vector<Carta> cartasrepartidas;
    for (int i = 0; i < 2; ++i) {
        cartasrepartidas.push_back(mazo[i]);
        mazo.erase(mazo.begin());
        tablero.ponercartas(cartasrepartidas[i]);
    }
    
}

void Mazo::repartirCartasInciales(Tablero& tablero) {
    for (int i = 0; i < 4; ++i) {
        if (!mazo.empty()) {
            Carta carta = mazo.back();
            tablero.ponercartas(carta);
            mazo.pop_back();
        }
    }
}

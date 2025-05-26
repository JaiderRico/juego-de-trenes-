#include "mazo.h"
#include "tablero.h"

Mazo::Mazo()
{
}

void Mazo::crearMazo()
{
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 12; ++j) {
            mazo.push_back(Carta(colores[i]));
        }
    }
}

void Mazo::Barajar()
{
    random_device rd;               
    mt19937 generador(rd());              
    shuffle(mazo.begin(), mazo.end(), generador);

}


void Mazo::AgregarCarta(Carta carta)
{
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

void Mazo::repartirCartasInciales(Tablero &tablero)
{
    for (int i = 0; i < 4; ++i) {
        Carta carta = mazo[i];
        tablero.ponercartas(carta);
        mazo.erase(mazo.begin());
    }
}

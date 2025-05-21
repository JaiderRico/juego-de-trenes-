#include "mazo.h"

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

void Mazo::MostrarMazo()
{
    for (int i = 0; i < mazo.size(); ++i) {
        cout << mazo[i].color << " ";
        if ((i + 1) % 12 == 0) {
            cout << endl;
        }
    }
    cout << RESET;
}

void Mazo::AgregarCarta(Carta carta)
{
    mazo.push_back(carta);
}

vector<Carta> Mazo::repartirCartas(Tablero &tablero)
{
    vector<Carta> cartasrepartidas;
int espaciovacio = tablero.contarEspaciosVacios();
    for (int i = 0; i < espaciovacio; ++i) {
        cartasrepartidas.push_back(mazo[i]);
        mazo.erase(mazo.begin());
        tablero.ponercartas(cartasrepartidas[i]);
    }
    
    return cartasrepartidas;
}


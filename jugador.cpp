#include "jugador.h"
#include "tablero.h"
#include "carta.h"

Jugador::Jugador(string nombre)
{
    this->nombre = nombre;
}   

void Jugador::agregarCarta(Carta& carta)
{
    mano.push_back(carta);
}

void Jugador::mostrarMano()
{
    cout<< "Mano de " << nombre << ": ";
    for (int i = 0; i < mano.size(); ++i) {
        cout<< mano[i].color << "[" << i+1 << "]" << RESET;
    }
    cout<< endl;
}

bool Jugador::hacerRuta(Tablero& tablero, string ruta){
        if (tablero.verificarVagones(ruta, *this) && 
            tablero.verificarCartas(ruta, *this)) {
        char letra = nombre[0]; // Usar inicial del jugador, por ejemplo
        tablero.asignarRutaLetra(ruta, letra);
        puntos += tablero.puntosRuta(ruta); // o los puntos reales de la ruta
        cout<< "¡Ruta " << ruta << " reclamada con éxito!" << endl;
        return true;
    } else {
        cout<< "No puedes reclamar la ruta " << ruta << "." << endl;
        return false;
    }
}

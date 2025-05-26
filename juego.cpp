#include "juego.h"

Juego::Juego()
{
    // Inicializar el tablero y el mazo
    tablero = Tablero();
    mazo = Mazo();
    string nombre;
    for(int i = 0; i < 4; ++i) {
        cout << "Ingrese el nombre del jugador " << (i + 1) << ": ";
        cin >> nombre;
        Jugador jugador(nombre);
        jugadores.push_back(jugador);
    }
    
    // Iniciar el juego
    iniciarJuego();
}

void Juego::iniciarJuego()
{
}

void Juego::jugarRondas()
{
    
}

void Juego::finalizarJuego()
{
}

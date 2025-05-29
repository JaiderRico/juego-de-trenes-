#include "jugador.h"
#include "tablero.h"
#include "carta.h"
#include <limits>
#include <iostream>

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
    for (size_t i = 0; i < mano.size(); ++i) {
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

void Jugador::arrastrarCarta(Tablero& tablero) {
    // Verificar inicialización del mazo
    if (tablero.mazo == nullptr) {
        cout << "Error: Mazo no inicializado." << endl;
        return;
    }

    // Tomar 2 cartas por turno
    for (int cartasTomadas = 0; cartasTomadas < 2; cartasTomadas++) {
        // Verificar cartas disponibles
        if (tablero.cartasdisponibles.empty()) {
            cout << "No hay cartas disponibles para arrastrar." << endl;
            break;
        }

        // Mostrar cartas disponibles
        tablero.mostrarCartasDisponibles();

        // Selección de carta con validación
        int indice = -1;
        bool entradaValida = false;
        while (!entradaValida) {
            cout << "Ingrese el índice de la carta " << (cartasTomadas + 1) 
                 << " de 2 (1 a " << tablero.cartasdisponibles.size() << "): ";
            
            if (!(cin >> indice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Ingrese un número.\n";
                continue;
            }

            if (indice < 1 || indice > static_cast<int>(tablero.cartasdisponibles.size())) {
                cout << "Índice fuera de rango. Intente nuevamente.\n";
                continue;
            }
            entradaValida = true;
        }

        // Tomar la carta seleccionada
        indice--;
        Carta cartaSeleccionada = tablero.cartasdisponibles[indice];
        agregarCarta(cartaSeleccionada);
        tablero.cartasdisponibles.erase(tablero.cartasdisponibles.begin() + indice);

        // Sistema de reposición
        bool cartaRepuesta = false;
        
        // 1. Intentar reponer desde mazo principal
        if (!tablero.mazo->mazo.empty()) {
            Carta nuevaCarta = tablero.mazo->mazo.back();
            tablero.ponercartas(nuevaCarta);
            tablero.mazo->mazo.pop_back();
            cartaRepuesta = true;
        } 
        // 2. Si el mazo principal está vacío, usar descartes
        else if (!tablero.mazoDescartes.mazoDescartes.empty()) {
            cout << "Barajando y usando cartas de descartes..." << endl;
            tablero.mazoDescartes.barajar();
            tablero.mazoDescartes.entregarmazo(*(tablero.mazo));
            
            if (!tablero.mazo->mazo.empty()) {
                Carta nuevaCarta = tablero.mazo->mazo.back();
                tablero.ponercartas(nuevaCarta);
                tablero.mazo->mazo.pop_back();
                cartaRepuesta = true;
            }
        }

        if (!cartaRepuesta) {
            cout << "No se pudo reponer carta (ambos mazos vacíos)." << endl;
        }
    }
    cout << "Cartas arrastradas exitosamente." << endl;
}
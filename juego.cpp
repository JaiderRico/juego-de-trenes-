#include "juego.h"

Juego::Juego() {
    string nombre;
    for(int i = 0; i < 4; ++i) {
        cout << "Ingrese el nombre del jugador " << (i + 1) << ": ";
        cin >> nombre;
        jugadores.push_back(Jugador(nombre));
    }
    iniciarJuego();
}

void Juego::iniciarJuego() {
    jugarRondas();  
}

void Juego::jugarRondas() {
    bool juegoActivo = true;

    while (juegoActivo) {
        for (auto& jugador : jugadores) {
            system("clear");
            system("cls");
            cout << "\n--- Turno de " << jugador.nombre << " ---" << endl;
            tablero.MostrarTablero();
            cout << "Puntos: " << jugador.puntos << " | Vagones: " << jugador.vagones << endl;

            bool turnoCompletado = false;
            while (!turnoCompletado) {
                int opcion;
                cout << "1. Tomar cartas\n2. Reclamar ruta\n3. Ver mano\nOpcion: ";
                cin >> opcion;

                switch (opcion) {
                    case 1:
                        jugador.arrastrarCarta(tablero);
                        turnoCompletado = true;
                        break;
                    case 2: {
                        string ruta;
                        cout << "Ingresa la ruta (ej. AB, GC): ";
                        cin >> ruta;

                        bool exito = jugador.hacerRuta(tablero, ruta);
                        if (exito) {
                            turnoCompletado = true;

                        } else {
                            turnoCompletado = false;

                        }
                        break;
                    }
                    case 3:
                        jugador.mostrarMano();
                        break; // se queda en el turno
                    default:
                        cout << "Opción invalida." << endl;
                        break;
                }
            }

            if (jugador.vagones < 5) {
                cout << "\n¡" << jugador.nombre << " tiene menos de 5 vagones!" << endl;
                juegoActivo = false;
                break;
            }
        }
    }

    finalizarJuego();
}

void Juego::finalizarJuego() {
    cout << "\n--- Juego finalizado ---" << endl;

    int maxPuntos = -1;
    string ganador;

    for (auto& jugador : jugadores) {
        cout << jugador.nombre << ": " << jugador.puntos << " puntos" << endl;
        if (jugador.puntos > maxPuntos) {
            maxPuntos = jugador.puntos;
            ganador = jugador.nombre;
        }
    }

    cout << "\n🏆 El ganador es: " << ganador << " 🏆" << endl;
}


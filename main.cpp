#include "juego.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== INICIANDO JUEGO DE RUTAS DE TREN ===" << endl;
    cout << "Creando juego con 4 jugadores..." << endl;
    
    // Crear una instancia del juego (esto pedirá los nombres de los jugadores)
    Juego juego;
    
    // Mostrar el tablero inicial
    cout << "\n=== TABLERO INICIAL ===" << endl;
    juego.tablero.MostrarTablero();
    
    // Mostrar cartas disponibles
    cout << "\n=== CARTAS DISPONIBLES ===" << endl;
    juego.tablero.mostrarCartasDisponibles();
    
    // Probar reclamar una ruta (simulación)
    cout << "\n=== PRUEBA DE RECLAMAR RUTA ===" << endl;
    Jugador& jugador1 = juego.jugadores[0];
    string ruta = "AB";
    
    cout << "Intentando reclamar ruta " << ruta << " para " << jugador1.nombre << endl;
    if(jugador1.hacerRuta(juego.tablero, ruta)) {
        cout << "¡Ruta reclamada con éxito!" << endl;
        cout << "Puntos actuales de " << jugador1.nombre << ": " << jugador1.puntos << endl;
        cout << "Vagones restantes: " << jugador1.vagones << endl;
        
        // Mostrar el tablero actualizado
        cout << "\n=== TABLERO ACTUALIZADO ===" << endl;
        juego.tablero.MostrarTablero();
    }
    
    cout << "\n=== PRUEBA COMPLETADA ===" << endl;
    return 0;
}
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace std;


#define RESET   "\033[0m"
#define BG_ROJO    "\033[41m"
#define BG_AZUL    "\033[44m"
#define BG_NARANJA "\033[48;5;208m"  
#define BG_MARRON  "\033[48;5;94m"   
#define BG_VERDE   "\033[42m"
#define BG_MORADO  "\033[45m"

class Carta;
class Tablero;

class Jugador{
    public:
        string nombre;
        int puntos = 0;
        int vagones = 18;
        vector<Carta> mano;

        Jugador(string nombre );
        void agregarCarta(Carta& carta);
        void mostrarMano();
        bool hacerRuta(Tablero& tablero, string ruta);
        void arrastrarCarta(Carta carta);


};

#endif
#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Jugador{
    public:
        string nombre;
        int puntos = 0;
        int vagones = 18;
        vector<string> mano;

        Jugador(string nombre );
        void agregarCarta(Carta carta);
        void mostrarMano();
        void hacerRuta(string ruta);
        void arrastrarCarta(Carta carta);
        

};

#endif
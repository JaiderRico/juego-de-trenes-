#ifndef TABLERO_H
#define TABLERO_H

#include "mazo.h"
#include "mazo_descartes.h"
#include "color_defs.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Jugador;
class Carta;

class Tablero {
public:
    Mazo* mazo;
    MazoDescartes mazoDescartes;
    vector<vector<char>> tablero;
    map<string, vector<pair<int, int>>> rutas;
    map<string, pair<int, int>> rutasletras;
    map<string, string> coloresRutas;
    vector<vector<string>> coloresFondo;
    vector<Carta> cartasdisponibles;

    Tablero();
    ~Tablero(); 
    
    void CrearTablero();
    void MostrarTablero(); 
    void AsignarRuta();
    void AsignarLetraRuta();
    void AsignarLetrasATablero();
    void AsignarColoresRutas();
    void ponercartas(Carta& carta);
    void mostrarCartasDisponibles();
    bool verificarCartas(string ruta, Jugador& jugador);
    bool verificarVagones(string ruta, Jugador& jugador);
    void asignarRutaLetra(string ruta, char letra);
    int puntosRuta(string ruta);
};

#endif
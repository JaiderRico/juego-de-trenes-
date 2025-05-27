#ifndef TABLERO_H
#define TABLERO_H


#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "mazo_descartes.h"

using namespace std;

class Mazo;
class Jugador;
class Carta;

#define RESET   "\033[0m"
#define BG_ROJO    "\033[41m"
#define BG_AZUL    "\033[44m"
#define BG_NARANJA "\033[48;5;208m"  
#define BG_MARRON  "\033[48;5;94m"   
#define BG_VERDE   "\033[42m"
#define BG_MORADO  "\033[45m"

class Tablero {
private:
    Mazo* mazo;
    MazoDescartes mazoDescartes;
    vector<vector<char>> tablero;
    map<string, vector<pair<int, int>>> rutas;
    map<string, pair<int, int>> rutasletras;
    map<string, string> coloresRutas;
    vector<vector<string>> coloresFondo;
    vector<Carta> cartasdisponibles;


public:
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

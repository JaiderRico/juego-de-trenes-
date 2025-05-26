#include "tablero.h"


Tablero::Tablero() {
    CrearTablero();
}

void Tablero::CrearTablero() {

    tablero = vector<vector<char>>(15, vector<char>(19, ' '));
    coloresFondo = vector<vector<string>>(15, vector<string>(19, ""));
    mazo.crearMazo();
    mazo.repartirCartasInciales(*this);
    AsignarRuta();
    AsignarLetraRuta();
    AsignarLetrasATablero();
    AsignarColoresRutas();
    mostrarCartasDisponibles();
}

void Tablero::MostrarTablero() {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 19; ++j) {
            char contenido = tablero[i][j];
            string color = coloresFondo[i][j];
            
            if (contenido != ' ') { 
                cout << "[" << contenido << "]";
            } else if (!color.empty()) { 
                cout << color << "[ ]" << RESET;
            } else { 
                cout << "[ ]";
            }
        }
        cout << endl;
    }
}

void Tablero::AsignarRuta() {

    rutas["AB"] = {{5,0}, {5,1}, {6,0}, {7,0}};
    rutas["AF"] = {{8,1}, {8,2}, {8,3}, {8,4}};
    rutas["FG"] = {{9,5}, {10,5}, {11,5}};
    rutas["GC"] = {{13,2}, {12,2}, {12,3}, {12,4}};
    rutas["FE"] = {{5,5}, {6,5}, {7,5}};
    rutas["ED"] = {{1,4}, {1,5}, {2,5}, {3,5}};
    rutas["FH"] = {{8,6}, {8,7}};
    rutas["HK"] = {{8,9}, {8,10}};
    rutas["HL"] = {{12,8}, {12,9}, {12,10}, {9,8}, {10,8}, {11,8}};
    rutas["KL"] = {{9,11}, {10,11}, {11,11}};
    rutas["KI"] = {{6,9}, {6,10}, {6,11}, {7,11}};
    rutas["KP"] = {{8,12}, {8,13}, {8,14}};
    rutas["PQ"] = {{9,15}, {10,15}, {11,15}};
    rutas["PO"] = {{5,15}, {6,15}, {7,15}};
    rutas["IO"] = {{4,9}, {4,10}, {4,11}, {4,12}, {4,13}, {4,14}};
    rutas["ON"] = {{2,14}, {2,15}, {3,15}};
    rutas["NJ"] = {{2,11}, {2,12}};
    rutas["OR"] = {{4,16}, {4,17}, {4,18}, {5,18}};
    rutas["QS"] = {{12,16}, {12,17}, {12,18}, {11,18}};
    rutas["QM"] = {{14,13}, {14,14}, {14,15}, {13,15}};
}

void Tablero::AsignarLetraRuta() {

    rutasletras["A"] = {8, 0};
    rutasletras["B"] = {5, 2};
    rutasletras["C"] = {14, 2};
    rutasletras["D"] = {1, 3};
    rutasletras["E"] = {4, 5};
    rutasletras["F"] = {8, 5};
    rutasletras["G"] = {12, 5};
    rutasletras["H"] = {8, 8};
    rutasletras["I"] = {5, 9};
    rutasletras["J"] = {2, 10};
    rutasletras["K"] = {8, 11};
    rutasletras["L"] = {12, 11};
    rutasletras["M"] = {14, 12};
    rutasletras["N"] = {2, 13};
    rutasletras["O"] = {4, 15};
    rutasletras["P"] = {8, 15};
    rutasletras["Q"] = {12, 15};
    rutasletras["S"] = {10, 18};
    rutasletras["R"] = {6, 18};
}

void Tablero::AsignarLetrasATablero() {
    for (const auto& par : rutasletras) {
        int fila = par.second.first;
        int col = par.second.second;
        if (fila >= 0 && fila < 15 && col >= 0 && col < 19) {
            tablero[fila][col] = par.first[0];
        }
    }
}

void Tablero::AsignarColoresRutas() {

    coloresRutas["AB"] = BG_ROJO;
    coloresRutas["AF"] = BG_AZUL;
    coloresRutas["FG"] = BG_NARANJA;
    coloresRutas["GC"] = BG_MARRON;
    coloresRutas["FE"] = BG_VERDE;
    coloresRutas["ED"] = BG_MARRON;
    coloresRutas["FH"] = BG_NARANJA;
    coloresRutas["HK"] = BG_AZUL;
    coloresRutas["HL"] = BG_ROJO;
    coloresRutas["KL"] = BG_NARANJA;
    coloresRutas["KI"] = BG_MORADO;
    coloresRutas["KP"] = BG_VERDE;
    coloresRutas["PQ"] = BG_VERDE;
    coloresRutas["PO"] = BG_NARANJA;
    coloresRutas["IO"] = BG_AZUL;
    coloresRutas["ON"] = BG_VERDE;
    coloresRutas["NJ"] = BG_ROJO;
    coloresRutas["OR"] = BG_MORADO;
    coloresRutas["QS"] = BG_MARRON;
    coloresRutas["QM"] = BG_MORADO;

    for (const auto& ruta : rutas) {
        const string& nombre = ruta.first;
        const vector<pair<int, int>>& coordenadas = ruta.second;
        const string& color = coloresRutas[nombre];

        for (const auto& coord : coordenadas) {
            int fila = coord.first;
            int columna = coord.second;
            if (fila >= 0 && fila < 15 && columna >= 0 && columna < 19) {
                coloresFondo[fila][columna] = color;
            }
        }
    }
}

void Tablero::ponercartas(Carta& carta)
{
    cartasdisponibles.push_back(carta); 


}

void Tablero::mostrarCartasDisponibles()
{
    cout << "Cartas disponibles:" << endl;
    for (int i = 0; i < cartasdisponibles.size(); i++) {
        Carta carta = cartasdisponibles[i]; 
        cout << carta.color << "[" << i+1 << "]" << RESET << " ";
    }
    cout << endl;
}


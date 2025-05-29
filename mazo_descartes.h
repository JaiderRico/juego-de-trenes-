#ifndef CARTADESCARTES_H
#define CARTADESCARTES_H

#include "carta.h"
#include <vector>

using namespace std;

class Mazo;  

class MazoDescartes {
public:
    vector<Carta> mazoDescartes;

    void agregarCarta(Carta carta);
    void barajar();
    void entregarmazo(Mazo& mazo);
};

#endif
#ifndef CARTADESCARTES_H
#define CARTADESCARTES_H

#include "mazo.h"
#include "carta.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class CartaDescartes {
    public:
        vector<Carta> mazoDescartes;

        void agregarCarta(Carta carta);
        void barajar();
        void entregarmazo(Mazo& mazo);

};

#endif
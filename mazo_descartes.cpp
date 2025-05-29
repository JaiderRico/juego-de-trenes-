#include "mazo_descartes.h"
#include "mazo.h"
#include <random>    
#include <algorithm> 

void MazoDescartes::agregarCarta(Carta carta)
{
    mazoDescartes.push_back(carta);
}

void MazoDescartes::barajar()
{
    random_device rd;               
    mt19937 generador(rd());              
    shuffle(mazoDescartes.begin(), mazoDescartes.end(), generador);
}

void MazoDescartes::entregarmazo(Mazo& mazo) {
    while (!mazoDescartes.empty()) {
        mazo.AgregarCarta(mazoDescartes.back());
        mazoDescartes.pop_back();
    }
}

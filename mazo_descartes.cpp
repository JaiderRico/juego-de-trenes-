#include "mazo_descartes.h"

void CartaDescartes::agregarCarta(Carta carta)
{
    mazoDescartes.push_back(carta);
}

void CartaDescartes::barajar()
{
    random_device rd;               
    mt19937 generador(rd());              
    shuffle(mazoDescartes.begin(), mazoDescartes.end(), generador);
}

void CartaDescartes::entregarmazo(Mazo& mazo)
{
    for (int i = 0; i < mazoDescartes.size(); ++i) {
        mazo.AgregarCarta(mazoDescartes[i]);
        mazoDescartes.erase(mazoDescartes.begin());
    }
    cout << RESET;
}

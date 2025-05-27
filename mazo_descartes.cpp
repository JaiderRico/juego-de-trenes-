#include "mazo_descartes.h"

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

void MazoDescartes::entregarmazo(Mazo& mazo)
{
    for (int i = 0; i < mazoDescartes.size(); ++i) {
        mazo.AgregarCarta(mazoDescartes[i]);
        mazoDescartes.erase(mazoDescartes.begin());
    }
    cout << RESET;
}

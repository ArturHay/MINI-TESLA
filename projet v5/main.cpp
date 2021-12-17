#include "CVehicule.h"
#include "CProximite.h"


#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

int main()
{

    CVehicule *vehicule1=new CVehicule();

    vehicule1->deplacer(ARRET, -1, 15000);

    vehicule1->start();

    return (0);
}

#include "CVehicule.h"

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

int main()
{

    CVehicule *v1 = new CVehicule();
    v1->deplacer(AVANT, 5, 5000);
    v1->deplacer(ARRIERE, 12, 7500);

    return 0;
}

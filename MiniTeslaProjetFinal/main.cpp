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

    // creation objet en dynamique 
    CVehicule *vehicule1=new CVehicule();

    // arrete le vehicule pendant 15 seconde
    vehicule1->deplacer(ARRET, -1, 15000);

   // lancement du programme d'autonomie
    vehicule1->start();

    return (0);
}

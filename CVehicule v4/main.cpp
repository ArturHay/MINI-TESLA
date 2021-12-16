#include "CVehicule.h"
#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5
#include "cgps.h"


double lattitude =0;
double longitude =0;
int coordonnes;

int main()
{
    CVehicule *v1 = new CVehicule();

    CGPS *GPS=new CGPS();

    double DataCP[10][5];
    GPS->getData( DataCP,10);

    int coordones= longitude , lattitude;
    coordonnes = 47.334598,5.067191;



    if(GPS->getLastPositionMoy()[0] > lattitude )
    {
        v1->deplacer(AVANT, 10, 5000);
    }

    if(GPS->getLastPositionMoy()[0] > lattitude )
    {
        v1->deplacer(ARRIERE, 10, 5000);
    }


    if(GPS->getLastPositionMoy()[1]> longitude)
    {
        v1->deplacer(DROITE, 1 , 1);
        v1->deplacer(AVANT, 10, 5000);
    }

    if(GPS->getLastPositionMoy()[1] < longitude)
    {
        v1->deplacer(GAUCHE,1,1);
        v1->deplacer(AVANT, 10, 5000);
    }



    return 0;
}


#include "Cvehicule.h"

int main(int argc, char *argv[])
{

      Cvehicule *vehicule1=new Cvehicule();
      vehicule1->avancer(20,5000);
      vehicule1->tournerAvantDroite(20,5000);
      vehicule1->tournerAvantGuauche(30,5000);
      vehicule1->arreter(5000);
      vehicule1->reculer(19,5000);
      vehicule1->tournerArriereDroite(10,5000);
      vehicule1->tournerArriereGuauche(10,5000);
      vehicule1->arreter(10000000);

    return (0);
}

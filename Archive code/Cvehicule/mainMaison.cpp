#include "CProximite.h"
#include "Cvehicule.h"
int main(int argc, char *argv[])
{

       Cvehicule *vehicule1=new Cvehicule();

          vehicule1->avancer(50,3600);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,6200);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,4200);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,6200);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,1600);

    return (0);
}


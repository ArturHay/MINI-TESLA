#include "CProximite.h"
#include "Cvehicule.h"
int main(int argc, char *argv[])
{

      CProximite *distance1=new CProximite();

      Cvehicule *vehicule1=new Cvehicule();

      /*vehicule1->arreter(3000);

          vehicule1->avancer(50,3600);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,6200);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,4000);
          vehicule1->tournerGuauche();
          vehicule1->avancer(50,6200);
          vehicule1->tournerGuauche();
         vehicule1->avancer(50,1600);*/



         vehicule1->arreter(15000);
         vehicule1->reculer(20, 5000);
         vehicule1->demitourSlide();
         vehicule1->avancer(60,5000);
         vehicule1->arreter(250000);


    return (0);
}

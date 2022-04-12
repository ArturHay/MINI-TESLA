#include <QCoreApplication>
#include "Cvehicule.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



      Cvehicule *vehicule1=new Cvehicule();

      vehicule1->avancer(20,5000);
      vehicule1->tournerAvantDroite(10,1000);
      vehicule1->tournerAvantGuauche(10,1000);
      vehicule1->arreter(3000);
      vehicule1->reculer(15,5000);
      vehicule1->tournerArriereDroit(5,3000);
      vehicule1->tournerArriereGuauche(5,3000);
      vehicule1->arreter(100000000);






    return a.exec();
}

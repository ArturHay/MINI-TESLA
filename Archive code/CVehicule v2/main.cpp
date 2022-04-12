#include "CProximite.h"
#include "Cvehicule.h"
int main(int argc, char *argv[])
{

      CProximite *distance1=new CProximite();

      Cvehicule *vehicule1=new Cvehicule();


      while(1)
      {
        double distance = distance1->getDistance();
        //printf("distance=%lf\n",distance);
        printf("distance=%lf cm.\t", distance);
        if(distance < 20 && distance > 1)
        {
            printf("Entrer IF\n\n");
            delay(50);
            vehicule1->demitourSlide();
            printf("Fin demiTour\nDebut arreter...\n");
            printf("\nDistance apres le demitour= %lf cm.\n",distance1->getDistance());
            vehicule1->arreter(2000);
        }
        else
        {
            printf("ELSE %lf\n",distance);
            vehicule1->avancer(30,50);
        }
        delay(50);
        printf("fin des conditions\n");
      }


    return (0);
}
*/

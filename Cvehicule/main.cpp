#include "CProximite.h"
#include "Cvehicule.h"
int main(int argc, char *argv[])
{

      CProximite *distance1=new CProximite();

      Cvehicule *vehicule1=new Cvehicule();


      while(1)
        {
        double distance = distance1->getDistance();
        printf("distance=%lf\n",distance);
        if(distance < 25 && distance > 17){
                delay(50);
        vehicule1->arreter(50);

      }
      else{
          vehicule1->avancer(20,50);
      }
      delay(50);
      }


    return (0);
}

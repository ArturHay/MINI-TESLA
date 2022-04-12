#include "Cvehicule.h"
Cvehicule::Cvehicule()
{
}
Cvehicule::~Cvehicule()
{
}

int Cvehicule::avancer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PING, vitesse+20);
    softPwmWrite (PIND, vitesse+20);
    delay(duree);

    return 1;
}

int Cvehicule::reculer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PING, 20-vitesse);
    softPwmWrite (PIND, 20-vitesse);
    delay(duree);

    return 1;
}

int Cvehicule::arreter(unsigned int duree)
{
    softPwmWrite (PING, 20);
    softPwmWrite (PIND, 20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerAvantGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIND, vitesse+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerAvantDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60 || vitesse==0){
        return -1;
    }
    softPwmWrite (PING, vitesse+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerArriereGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PING, 20-vitesse);
    delay(duree);
    return 1;
}
int Cvehicule::tournerArriereDroit(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIND, 20-vitesse);
    delay(duree);
    return 1;
}


return(0);
}

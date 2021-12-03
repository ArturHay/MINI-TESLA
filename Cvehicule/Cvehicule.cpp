#include "Cvehicule.h"
Cvehicule::Cvehicule()
{
    wiringPiSetup();
	pinMode(PIN_DROITE,OUTPUT);
	pinMode(PIN_GAUCHE,OUTPUT);
	softPwmCreate(PIN_DROITE,1,200);
	softPwmCreate(PIN_GAUCHE,0,200);
}
Cvehicule::~Cvehicule()
{
}

int Cvehicule::avancer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
    softPwmWrite (PIN_DROITE, vitesse+20);
    delay(duree);

    return 1;
}

int Cvehicule::reculer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
    softPwmWrite (PIN_DROITE, 20-vitesse);
    delay(duree);

    return 1;
}

int Cvehicule::arreter(unsigned int duree)
{
    softPwmWrite (PIN_GAUCHE, 20);
    softPwmWrite (PIN_DROITE, 20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerAvantGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIN_DROITE, vitesse+20);
    softPwmWrite (PIN_GAUCHE, (vitesse*0.4)+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerAvantDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60 || vitesse==0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
     softPwmWrite (PIN_DROITE, (vitesse*0.4)+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerArriereGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
     softPwmWrite (PIN_DROITE, 20-(vitesse*0.7));
    delay(duree);
    return 1;
}
int Cvehicule::tournerArriereDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_DROITE, 20-vitesse);
     softPwmWrite (PIN_GAUCHE, 20-(vitesse*0.7));
    delay(duree);
    return 1;
}


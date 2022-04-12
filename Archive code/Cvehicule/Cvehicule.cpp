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
    if(vitesse>20){
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
    softPwmWrite (PIN_GAUCHE, (vitesse*0.2)+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerAvantDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60 || vitesse==0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
     softPwmWrite (PIN_DROITE, (vitesse*0.2)+20);
    delay(duree);
    return 1;
}

int Cvehicule::tournerArriereGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
     softPwmWrite (PIN_DROITE, 20-(vitesse*0.2));
    delay(duree);
    return 1;
}
int Cvehicule::tournerArriereDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_DROITE, 20-vitesse);
     softPwmWrite (PIN_GAUCHE, 20-(vitesse*0.2));
    delay(duree);
    return 1;
}

int Cvehicule::demitour()
{
    tournerArriereDroite(12,4200);
    tournerAvantDroite(60,4200);
    arreter(2000);
    return 1;
}

int Cvehicule::demitourSlide()
{
    printf("entrer DemiTourSLide\n\n");
    reculer(10,500);
    softPwmWrite (PIN_DROITE,56);
    softPwmWrite (PIN_GAUCHE,8);
    delay(2130);
    return 1;
}

int Cvehicule::tournerGuauche()
{
    softPwmWrite (PIN_DROITE,22);
    softPwmWrite (PIN_GAUCHE,80);
    delay(1800);
    return 1;
}

int Cvehicule::tournerDroite()
{
    softPwmWrite (PIN_DROITE,80);
    softPwmWrite (PIN_GAUCHE,22);
    delay(1840);
    return 1;
}




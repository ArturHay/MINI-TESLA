#ifndef CVEHICULE_H
#define CVEHICULE_H

#include<string.h>
#include<stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#define PIND 1
#define PING 0

class Cvehicule
{
private:

public:
    //Constructeur par défaut car pas de paramètre
    Cvehicule();
    //Destructeur
    ~Cvehicule();
    //
    int avancer(unsigned char vitesse,unsigned int duree);
    //
    int reculer(unsigned char vitesse,unsigned int duree);
    //
    int arreter(unsigned int duree);
    //
    int tournerAvantGuauche(unsigned char vitesse,unsigned int duree);
    //
    int tournerAvantDroite(unsigned char vitesse,unsigned int duree);
    //
    int tournerArriereGuauche(unsigned char vitesse,unsigned int duree);
    //
    int tournerArriereDroit(unsigned char vitesse,unsigned int duree);


};

#endif // CVEHICULE_H

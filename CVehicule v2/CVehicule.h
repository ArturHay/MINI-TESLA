#ifndef CVEHICULE_H
#define CVEHICULE_H

#include<string.h>
#include<stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#include "CProximite.h"
#include "CLogs.h"
#include "cgps.h"

#define PIN_DROITE 1
#define PIN_GAUCHE 0

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define AVANT_GAUCHE 3
#define AVANT_DROITE 4
#define ARRIERE_GAUCHE 5
#define ARRIERE_DROITE 6

class CVehicule
{
private:
    //
    int avancer(unsigned char vitesse,unsigned int duree);
    //
    int reculer(unsigned char vitesse,unsigned int duree);
    //
    int arreter(unsigned int duree);
    //
    int tournerAvantGauche(unsigned char vitesse,unsigned int duree);
    //
    int tournerAvantDroite(unsigned char vitesse,unsigned int duree);
    //
    int tournerArriereGauche(unsigned char vitesse,unsigned int duree);
    //
    int tournerArriereDroite(unsigned char vitesse,unsigned int duree);

    //Objet pour les Logs
    CLogs *myLogs;
    //Objet pour le capteur de proximite
    CProximite *proximite;
    //Objet pour le GPS
    CGPS *gps;
    double DataCP[][5];
public:
    //Constructeur par défaut car pas de paramètre
    CVehicule();
    //Destructeur
    ~CVehicule();
    //
    int deplacer(int p_idMouvement, unsigned char p_vitesse, unsigned int p_duree);

};

#endif // CVEHICULE_H

#ifndef CVEHICULE_H
#define CVEHICULE_H

#include<string.h>
#include<stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>
#include <time.h>

#include "CProximite.h"
#include "CLogs.h"
#include "cgps.h"

#define PIN_DROITE 1
#define PIN_GAUCHE 0

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

class CVehicule
{
private:
    //
    int avancer(unsigned char vitesse, int duree);
    //
    int reculer(unsigned char vitesse, int duree);
    //
    int arreter( int duree);
    //
    int demiTour();
    //
    int tournerGauche();
    //
    int tournerDroite();

    //Objet pour les Logs
    CLogs *myLogs;
    //Objet pour le capteur de proximite
    CProximite *proximite;
    //Objet pour le GPS
    CGPS *gps;
    //Objet timer
    time_t start;

    double DataCP[][3];
public:
    //Constructeur par défaut car pas de paramètre
    CVehicule();
    //Destructeur
    ~CVehicule();
    //
    int deplacer(int p_idMouvement, unsigned char p_vitesse, int p_duree);

    double getTime();

};

#endif // CVEHICULE_H

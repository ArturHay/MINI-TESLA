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
#include "timerClass.h"

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
    int avancer(unsigned char vitesse,unsigned int duree);
    //
    int reculer(unsigned char vitesse,unsigned int duree);
    //
    int arreter(unsigned int duree);
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
    Timer *timer;

    double DataCP[][3];
public:
    //Constructeur par défaut car pas de paramètre
    CVehicule();
    //Destructeur
    ~CVehicule();
    //
    int deplacer(int p_idMouvement, unsigned char p_vitesse, unsigned int p_duree);

};

#endif // CVEHICULE_H

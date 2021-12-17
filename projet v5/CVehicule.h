#ifndef CVEHICULE_H_INCLUDED
#define CVEHICULE_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#include "CProximite.h"

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
    bool avancer(unsigned char p_vitesse, int p_duree);
    //
    bool reculer(unsigned char p_vitesse, int p_duree);
    //
    bool arreter(unsigned int p_duree);
    //
    bool demiTour();
    //
    bool demiTourSlide();
    //
    bool tournerGauche();
    //
    bool tournerDroite();

    CProximite *distanceGauche;
    CProximite *distanceDroite;
public:
    //Constructeur par défaut car pas de paramètre
    CVehicule();
    //Destructeur
    ~CVehicule();

    bool deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree);

    void start();


};

#endif // CVEHICULE_H_INCLUDED

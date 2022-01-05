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
    // Fait avancer le vehivule en avant selon une vitesse et une duree
    bool avancer(unsigned char p_vitesse, int p_duree);
    // Fait reculer le vehicule en arrière selon une vitesse et une duree
    bool reculer(unsigned char p_vitesse, int p_duree);
    // Arrête le vehicule selon une duree
    bool arreter(unsigned int p_duree);
    // Le vehicule fait un demi-tour
    bool demiTour();
    // Fait tourner le vehicule à Gauche
    bool tournerGauche();
    // Fait tourner le vehicule à Droite
    bool tournerDroite();

    CProximite *distanceGauche;

    CProximite *distanceDroite;

public:
    //Constructeur
    CVehicule();
    //Destructeur
    ~CVehicule();
    // Fait deplacer le vehicule selon le mouvement la vitesse et la durée 
    bool deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree);
    // Lancement du vehicule
    void start();
};

#endif // CVEHICULE_H_INCLUDED

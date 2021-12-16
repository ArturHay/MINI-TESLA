#ifndef CVEHICULE_H_INCLUDED
#define CVEHICULE_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

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
    int avancer(unsigned char p_vitesse, int p_duree);
    //
    int reculer(unsigned char p_vitesse, int p_duree);
    //
    int arreter(unsigned int p_duree);
    //
    int demitour();
    //
    int demiTour();
    //
    int tournerGauche();
    //
    int tournerDroite();
public:
    //Constructeur par défaut car pas de paramètre
    CVehicule();
    //Destructeur
    ~CVehicule();

    int deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree);



};

#endif // CVEHICULE_H_INCLUDED

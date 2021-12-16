#include "CVehicule.h"
CVehicule::CVehicule()
{
    wiringPiSetup();
	pinMode(PIN_DROITE,OUTPUT);
	pinMode(PIN_GAUCHE,OUTPUT);
	softPwmCreate(PIN_DROITE,1,200);
	softPwmCreate(PIN_GAUCHE,0,200);
}
CVehicule::~CVehicule()
{
}

/*

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

*/

int CVehicule::deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree)
{
    switch(p_mouvement) {
        case AVANT:
            avancer(p_vitesse, p_duree);
            break;
        case ARRIERE:
            reculer(p_vitesse, p_duree);
            break;
        case ARRET:
            arreter(p_duree);
            break;
        case DEMI_TOUR:
            demiTour();
            break;
        case DROITE:
            tournerDroite();
            break;
        case GAUCHE:
            tournerGauche();
            break;
        default:
            return -1;
    }
    return 1;
}


int CVehicule::avancer(unsigned char vitesse, int p_duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
    softPwmWrite (PIN_DROITE, vitesse+20);
    delay(p_duree);

    return 1;
}

int CVehicule::reculer(unsigned char vitesse, int p_duree)
{
    if(vitesse>20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
    softPwmWrite (PIN_DROITE, 20-vitesse);
    delay(p_duree);

    return 1;
}

int CVehicule::arreter(unsigned int p_duree)
{
    softPwmWrite (PIN_GAUCHE, 20);
    softPwmWrite (PIN_DROITE, 20);
    delay(p_duree);
    return 1;
}

int CVehicule::demiTour()
{
    printf("entrer DemiTourSLide\n\n");
    reculer(10,500);
    softPwmWrite (PIN_DROITE,56);
    softPwmWrite (PIN_GAUCHE,8);
    delay(2130);
    return 1;
}

int CVehicule::tournerGauche()
{
    softPwmWrite (PIN_DROITE,22);
    softPwmWrite (PIN_GAUCHE,80);
    delay(1620);
    return 1;
}

int CVehicule::tournerDroite()
{
    softPwmWrite (PIN_DROITE,80);
    softPwmWrite (PIN_GAUCHE,22);
    delay(1620);
    return 1;
}

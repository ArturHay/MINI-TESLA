#include "CVehicule.h"
CVehicule::CVehicule()
{
    wiringPiSetup();
	pinMode(PIN_DROITE,OUTPUT);
	pinMode(PIN_GAUCHE,OUTPUT);
	softPwmCreate(PIN_DROITE,1,200);
	softPwmCreate(PIN_GAUCHE,0,200);

	distanceDroite = new CProximite(1);
	distanceGauche = new CProximite(2);

}
CVehicule::~CVehicule()
{
}

//automatisation du vehicule 
void CVehicule::start()
{
    int mvGD = -1;
    int nbrGauche = 0;
    int compteur;
    double distanceD = 0;
    double distanceG = 0;
    bool condition;

    while(1)
    {
        compteur = 0;
        distanceD = distanceDroite->getDistance();
        distanceG = distanceGauche->getDistance();

        condition = ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)) ? 1 : 0;
        while(condition)
        {
            distanceD = distanceDroite->getDistance();
            distanceG = distanceGauche->getDistance();
            printf("Distance>1 && distance <21\ndistance= %.2lfcm\n", distanceD);
            if(mvGD == -1 && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                reculer(12, 1000);
                tournerDroite();
                mvGD = DROITE;
                nbrGauche = 0;
            }
            else if(mvGD == DROITE && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                demiTour();
                printf("\n\nDEMI TOUR\n%.2lf cm.\n", distanceD);
                mvGD = GAUCHE;
                nbrGauche = 0;
            }
            else if(mvGD == GAUCHE && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                tournerGauche();
                mvGD = GAUCHE;
                nbrGauche++;
                if(nbrGauche == 2) for(int i=0; i<1; i++) demiTourSlide();
            }
            printf("FIN MV:%d\n", mvGD);
            distanceD = distanceDroite->getDistance();
            distanceG = distanceGauche->getDistance();
            condition = ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)) ? 1 : 0;
            arreter(1250);
        }
        while(!condition)
        {
            printf("ON AVANCE: distanceD = %.2lf cm\n", distanceD);
            avancer(30, 50);
            compteur++;
            if(compteur == 10) mvGD = -1;
            distanceD = distanceDroite->getDistance();
            distanceG = distanceGauche->getDistance();
            condition = ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)) ? 1 : 0;
        }
        arreter(1250);
    }
}

/*

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

*/


// Fait deplacer le vehicule selon le mouvement la vitesse et la durée 
bool CVehicule::deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree)
{
    //double distance;
    //bool etat = 0;
    //bool verifDeplacement = 0;
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
            return 0;
    }

    return 1;
}

// Fait avancer le vehivule en avant selon une vitesse et une duree
bool CVehicule::avancer(unsigned char vitesse, int p_duree)
{
    if(vitesse>60 || vitesse == 0){
        return 0;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
    softPwmWrite (PIN_DROITE, vitesse+20);
    delay(p_duree);

    return 1;
}

// Fait reculer le vehicule en arrière selon une vitesse et une duree
bool CVehicule::reculer(unsigned char vitesse, int p_duree)
{
    if(vitesse>20){
        return 0;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
    softPwmWrite (PIN_DROITE, 20-vitesse);
    delay(p_duree);

    return 1;
}

// Arrête le vehicule selon une duree
bool CVehicule::arreter(unsigned int p_duree)
{
    softPwmWrite (PIN_GAUCHE, 20);
    softPwmWrite (PIN_DROITE, 20);
    delay(p_duree);
    return 1;
}
// Le vehicule fait un demi-tour
bool CVehicule::demiTour()
{
    softPwmWrite (PIN_DROITE,56);
    softPwmWrite (PIN_GAUCHE,8);
    delay(2450);
    return 1;
}

 // Le vehicule fait un demi-tour rapide
bool CVehicule::demiTourSlide()
{
    softPwmWrite (PIN_DROITE,200);
    softPwmWrite (PIN_GAUCHE,0);
    delay(1750);
    return 1;
}

// Fait tourner le vehicule à Gauche
bool CVehicule::tournerGauche()
{
    softPwmWrite (PIN_DROITE,22);
    softPwmWrite (PIN_GAUCHE,80);
    delay(2075);
    return 1;
}


 // Fait tourner le vehicule à Droite
bool CVehicule::tournerDroite()
{
    softPwmWrite (PIN_DROITE,80);
    softPwmWrite (PIN_GAUCHE,22);
    delay(2075);
    return 1;
}

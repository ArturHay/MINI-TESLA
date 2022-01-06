#include "CVehicule.h"
//constucteur
CVehicule::CVehicule()
{
	wiringPiSetup();

	pinMode(PIN_DROITE,OUTPUT);
	pinMode(PIN_GAUCHE,OUTPUT);
	softPwmCreate(PIN_DROITE,1,200);
	softPwmCreate(PIN_GAUCHE,0,200);

	//Initialisation des deux capteurs de proximite
	distanceDroite = new CProximite(1);
	distanceGauche = new CProximite(2);

}
// destructeur
CVehicule::~CVehicule()
{
}

//Lancement du vehicule - Evite les obstacles
void CVehicule::start()
{
    int mvGD = -1;
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
            if(mvGD == -1 && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                printf("Obstacle detecte a: %.2lf cm, on tourne a droite.\n", (distanceD>1 && distanceD<21) ? distanceD : distanceG);
                reculer(12, 1000);
                tournerDroite();
                mvGD = DROITE;
            }
            else if(mvGD == DROITE && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                printf("Obstacle detecte a: %.2lf cm, on fait demi tour.\n", (distanceD>1 && distanceD<21) ? distanceD : distanceG);
                demiTour();
                mvGD = GAUCHE;
            }
            else if(mvGD == GAUCHE && ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)))
            {
                printf("Obstacle detecte a: %.2lf cm, on tourne a gauche.\n", (distanceD>1 && distanceD<21) ? distanceD : distanceG);
                tournerGauche();
                mvGD = GAUCHE;
            }
            distanceD = distanceDroite->getDistance();
            distanceG = distanceGauche->getDistance();
            condition = ((distanceD>1 && distanceD<21) || (distanceG>1 && distanceG<21)) ? 1 : 0;
            arreter(1250);
        }
        while(!condition)
        {
            if(compteur%3 == 0) printf("Aucun obstacle en vue, on avance.\n");
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


// Methode qui permet de deplacer le vehicule
bool CVehicule::deplacer(int p_mouvement, unsigned char p_vitesse, int p_duree)
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

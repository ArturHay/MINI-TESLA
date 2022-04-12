#include "CVehicule.h"
CVehicule::CVehicule()
{
    wiringPiSetup();
	pinMode(PIN_DROITE,OUTPUT);
	pinMode(PIN_GAUCHE,OUTPUT);
	softPwmCreate(PIN_DROITE,1,200);
	softPwmCreate(PIN_GAUCHE,0,200);

	myLogs = new CLogs;
	proximite = new CProximite;
	gps = new CGPS();
	start = time (NULL);
	printf("Construction de l'objet\n");
}

CVehicule::~CVehicule()
{
}

double CVehicule::getTime()
{
    return((double) (time (NULL) - start) + 1);
}

int CVehicule::avancer(unsigned char p_vitesse, int p_duree)
{
    printf("Entrer fonction avancer\n");
    if(p_vitesse>60 || p_vitesse == 0){
        return -1;
    }
    //printf("p_duree/1000=%d\n",p_duree/1000);
    for(int i=0; i< (p_duree/1000); i++)
    {
        softPwmWrite (PIN_GAUCHE, p_vitesse+20);
        softPwmWrite (PIN_DROITE, p_vitesse+20);
        gps->getData(DataCP, 1);
        printf("Temps:%lf secondes\n", getTime());
    }
    //printf("Sortie boucle for\n");
    delay(p_duree%1000);
    return 1;
}

int CVehicule::reculer(unsigned char p_vitesse, int p_duree)
{
    if(p_vitesse > 20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-p_vitesse);
    softPwmWrite (PIN_DROITE, 20-p_vitesse);
    delay(5000);
    gps->getData(DataCP, p_duree);

    return 1;
}

int CVehicule::arreter( int p_duree)
{
    printf("Entree fonction arreter\n");
    for(int i=0; i<(p_duree/1000); i++)
    {
        printf("entree for\t");
        softPwmWrite (PIN_GAUCHE, 20);
        softPwmWrite (PIN_DROITE, 20);
        gps->waiting(DataCP ,1);
        printf("Temps:%lf secondes\n", getTime());
    }
    printf("sorite boucle for arreter\n");
    delay(p_duree%1000);
    return 1;
}

int CVehicule::demiTour()
{
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


/*

double p_mouvement, double p_vitesse, double p_duree, double p_distance, double p_latitude,
                    double p_longitude, double p_lat, double p_lon, double p_state, double p_timer)

*/

int CVehicule::deplacer(int p_idMouvement, unsigned char p_vitesse,  int p_duree)
{
    printf("entrer deplacement: %d\n", p_idMouvement);
    double distance = proximite->getDistance();
    switch(p_idMouvement) {
        case AVANT:
            if(avancer(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        case ARRIERE:
            if(reculer(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        case ARRET:
            if(arreter(p_duree))
                myLogs->addLogs(p_idMouvement, -1, p_duree, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        case DEMI_TOUR:
            if(demiTour())
                myLogs->addLogs(p_idMouvement, -1, -1, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        case DROITE:
            if(tournerDroite())
                myLogs->addLogs(p_idMouvement, -1, -1, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        case GAUCHE:
            if(tournerGauche())
                myLogs->addLogs(p_idMouvement, -1, -1, distance, gps->getLastPositionMoy()[0],
                        gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1],
                        distance < 25 && distance > 1 ? 1 : 0, getTime());
            break;
        default:
            return -1;
    }
	return 1;
}

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
}
CVehicule::~CVehicule()
{
}

int CVehicule::avancer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
    softPwmWrite (PIN_DROITE, vitesse+20);
    gps->getData(DataCP, duree);

    return 1;
}

int CVehicule::reculer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
    softPwmWrite (PIN_DROITE, 20-vitesse);
    gps->getData(DataCP, duree);

    return 1;
}

int CVehicule::arreter(unsigned int duree)
{
    softPwmWrite (PIN_GAUCHE, 20);
    softPwmWrite (PIN_DROITE, 20);
    gps->getData(DataCP, duree);
    return 1;
}

int CVehicule::tournerAvantGauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIN_DROITE, vitesse+20);
    softPwmWrite (PIN_GAUCHE, (vitesse*0.4)+20);
    gps->getData(DataCP, duree);
    return 1;
}

int CVehicule::tournerAvantDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60 || vitesse==0){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, vitesse+20);
    softPwmWrite (PIN_DROITE, (vitesse*0.4)+20);
    gps->getData(DataCP, duree);
    return 1;
}

int CVehicule::tournerArriereGauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_GAUCHE, 20-vitesse);
    softPwmWrite (PIN_DROITE, 20-(vitesse*0.7));
    gps->getData(DataCP, duree);
    return 1;
}
int CVehicule::tournerArriereDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIN_DROITE, 20-vitesse);
    softPwmWrite (PIN_GAUCHE, 20-(vitesse*0.7));
    gps->getData(DataCP, duree);
    return 1;
}
/*

double p_mouvement, double p_vitesse, double p_duree, double p_distance, double p_latitude, double p_longitude,
                 double p_lat, double p_lon, double p_state, double p_timer

*/

int CVehicule::deplacer(int p_idMouvement, unsigned char p_vitesse, unsigned int p_duree)
{
    switch(p_idMouvement) {
        case AVANT:
            if(avancer(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        case ARRIERE:
            if(reculer(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        case AVANT_GAUCHE:
            if(tournerAvantGauche(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        case AVANT_DROITE:
            if(tournerAvantDroite(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        case ARRIERE_GAUCHE:
            if(tournerArriereGauche(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        case ARRIERE_DROITE:
            if(tournerArriereDroite(p_vitesse, p_duree))
                myLogs->addLogs(p_idMouvement, p_vitesse, p_duree, proximite->getDistance(), gps->getLastPositionMoy()[0], gps->getLastPositionMoy()[1], gps->getLocData()[0], gps->getLocData()[1], 10, 15);
            break;
        default:
            return -1;
    }
    return 1;
}

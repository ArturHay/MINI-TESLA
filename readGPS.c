/*
 * readGPS.c:
 *	Programme simple pour tester le module RPI-GPS
 *      - initialisation du port série 38400 8N1
 *      - lecture trame GPS
 *      - affichage lattitude et longitude
 *  Utilisation de la librairie wiringSerial
 *
 * Pascal Dub - Lycée Eiffel Dijon - 06/02/2015
 *
 * Merci à:
 * http://wiringpi.com/reference/serial-library/
 * http://walterdalmut.com/2013/11/23/raspberry-pi-c-gps-nmea-library-global-positioning-system/
 * https://github.com/wdalmut/libgps
 ***********************************************************************
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#include "gps.h"

int main ()
{
    /* Déclaration des variables */
    int fd=-1;  /*descripteur port série*/
    loc_t data; /*structure de données gps*/
    /* Initialisation de la librairie wiringPi
       ATTENTION: il faut être root */
    /*if (wiringPiSetup () == -1)
    {
        fprintf (stdout, "Incapable de démarrer wiringPi: %s\n", strerror (errno)) ;
        return 1 ;
    }*/
    /* Initialisation du GPS*/
    fd = gps_init();
    /* Traitement principal */
    /* Vidage du buffer de réception série */
    serialFlush(fd);

    int i;
    double preDonnees[15][3] = {0};
    double dplDonnees[15][3] = {0};
    double nvlDonnees[15][3] = {0};

    double preMoyenne[3] = {0};
    double nvlMoyenne[3] = {0};



    printf("---------------------------------------------\n");
    printf("Debut des mesures\n");
    printf("---------------------------------------------\n\n");


    //Mesure des premieres données
    printf("            / Latitude / Longitude / Altitude\n");
    printf("---------------------------------------------\n");
    for(i=0; i<15; i++)
    {
        gps_location(fd,&data);
        preDonnees[i][0] = data.latitude;
        preDonnees[i][1] = data.longitude;
        preDonnees[i][2] = data.altitude;
        printf("preDonnees[%d]=%lf / %lf / %lf\n", i, preDonnees[i][0], preDonnees[i][1], preDonnees[i][2]);
    }

    printf("\n---------------------------------------------\n");
    printf("Fin des premieres mesures\n");
    printf("Deplacer le GPS\n");
    printf("---------------------------------------------\n\n");


    //10 secondes de pause pour déplacer le module gps
    for(i=10; i>0; i--)
    {
        printf("Reprise des mesures dans: %d secondes\n", i);
        delay(1000);
        gps_location(fd,&data);
        dplDonnees[i][0] = data.latitude;
        dplDonnees[i][1] = data.longitude;
        dplDonnees[i][2] = data.altitude;
    }

    printf("\n---------------------------------------------\n");
    printf("Reprise des mesures\n");
    printf("---------------------------------------------\n\n");


    printf("            / Latitude / Longitude / Altitude\n");
    printf("---------------------------------------------\n");
    //Mesure des nouvelles données
    for(i=0; i<15; i++)
    {
        gps_location(fd,&data);
        nvlDonnees[i][0] = data.latitude;
        nvlDonnees[i][1] = data.longitude;
        nvlDonnees[i][2] = data.altitude;
        printf("nvlDonnees[%d]=%lf / %lf / %lf\n", i, nvlDonnees[i][0], nvlDonnees[i][1], nvlDonnees[i][2]);
    }

    printf("\n---------------------------------------------\n");
    printf("Fin des mesures\n");
    printf("---------------------------------------------\n\n");


    // double preMoyenne[1][3] = {0};
    // double nvlMoyenne[1][3] = {0};

    for(i=0; i<15; i++)
    {
        preMoyenne[0] += preDonnees[i][0];
        preMoyenne[1] += preDonnees[i][1];
        preMoyenne[2] += preDonnees[i][2];

        nvlMoyenne[0] += nvlDonnees[i][0];
        nvlMoyenne[1] += nvlDonnees[i][1];
        nvlMoyenne[2] += nvlDonnees[i][2];
    }
    preMoyenne[0] /= 15;
    preMoyenne[1] /= 15;
    preMoyenne[2] /= 15;

    nvlMoyenne[0] /= 15;
    nvlMoyenne[1] /= 15;
    nvlMoyenne[2] /= 15;

    printf("\n---------------------------------------------\n");
    printf("         / Latitude / Longitude / Altitude\n");
    printf("preMoyenne=%lf / %lf / %lf\n", preMoyenne[0], preMoyenne[1], preMoyenne[2]);
    printf("nvlMoyenne=%lf / %lf / %lf\n", nvlMoyenne[0], nvlMoyenne[1], nvlMoyenne[2]);
    printf("---------------------------------------------\n\n");
    printf("Debut du calcul de distance\n");

    double resultat[3] = {0};
    resultat[0] = nvlMoyenne[0] - preMoyenne[0];
    resultat[1] = nvlMoyenne[1] - preMoyenne[1];
    resultat[2] = nvlMoyenne[2] - preMoyenne[2];

    printf("\n---------------------------------------------\n");
    printf("       / Latitude / Longitude / Altitude\n");
    printf("resultat=%lf / %lf / %lf\n", resultat[0], resultat[1], resultat[2]);
    printf("---------------------------------------------\n\n");

    /* Affichage coordonnées GPS */
     /*while (1) {
        gps_location(fd,&data);
        printf("%lf %lf %lf\n", data.latitude, data.longitude, data.altitude);
    }*/
    /* Arret du GPS */
    gps_off(fd);

    return 0;
}

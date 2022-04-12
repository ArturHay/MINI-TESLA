#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <inttypes.h>
#include <math.h>

#include "gps.h"
#include "nmea.h"

#include <wiringPi.h>
#include <wiringSerial.h>

/* Initialisation du GPS */
extern int gps_init(void){
    /* Descripteur liaison série */
    int fd=-1;
    /* Ouverture de la liaison série */
    if ((fd = serialOpen (PORTNAME, 38400)) < 0)
    {
        fprintf (stderr, "Impossible d'ouvrir le port série: %s\n", strerror (errno)) ;
        return -1 ;
    }
    /* Configuration de la liaison série */
    serialConfig(fd);
    return(fd);
}

extern void gps_on(void){
    //Write on
}

// Compute the GPS location using decimal scale
extern void gps_location(int fd, loc_t *coord){
    /* Déclaration des variables */
    uint8_t status = _EMPTY;
    gpgga_t gpgga;
    gprmc_t gprmc;
    char buffer[256];
    /* Traitement principal */
    while(status != _COMPLETED)
    {
        serialReadln(fd,buffer);
        switch (nmea_get_message_type(buffer))
        {
            case NMEA_GPGGA:
                nmea_parse_gpgga(buffer, &gpgga);


                gps_convert_deg_to_dec(&(gpgga.latitude), gpgga.lat, &(gpgga.longitude), gpgga.lon);


                coord->latitude = gpgga.latitude;
                coord->longitude = gpgga.longitude;
                coord->altitude = gpgga.altitude;
                coord->lat = gpgga.lat;
                coord->lon = gpgga.lon;

                status |= NMEA_GPGGA;
                break;
            case NMEA_GPRMC:
                nmea_parse_gprmc(buffer, &gprmc);

                coord->speed = gprmc.speed;
                coord->course = gprmc.course;

                status |= NMEA_GPRMC;
                break;
        }
    }
}

extern void gps_off(int fd){
    serialClose(fd);
}

/* Fonction configuration de la liaison série */
extern void serialConfig(int fd){
    /* Déclaration des variables */
    struct termios term;
    /* Configuration de la liaison série */
    /* -- Lecture configuration courante */
    tcgetattr (fd, &term);
    /* -- Pas de contrôle de flux XON/XOFF */
    term.c_iflag &= ~(IXON | IXOFF | IXANY);
    /* 8 bits de données, pas de parité*/
    term.c_cflag &= ~(PARENB | CSIZE);
    term.c_cflag |= CS8;
    /* -- Sauvegarde nouvelle configuration */
    tcsetattr (fd, TCSANOW, &term);
}

// Lecture d'une ligne sur le port série.
extern void serialReadln(int fd, char *buffer){
    /* Déclaration des variables */
    char c;
    char *b = buffer;
    int rx_length = -1;
    /* Traitement */
    while(1)
    {
        rx_length = serialDataAvail(fd);
        if (rx_length <= 0)
        {
            /* Attente d'un message*/
            delay(1);
        }
        else
        {
            c = serialGetchar(fd);
            if (c == '\n')
            {
                *b++ = '\0';
                break;
            }
            *b++ = c;
        }
    }
}

/* Conversion coordonnées gps vers degrés décimaux*/
void gps_convert_deg_to_dec(double *latitude, char ns,  double *longitude, char we){
    double lat = (ns == 'N') ? *latitude : -1 * (*latitude);
    double lon = (we == 'E') ? *longitude : -1 * (*longitude);

    *latitude = gps_deg_dec(lat);
    *longitude = gps_deg_dec(lon);
}

double gps_deg_dec(double deg_point){
    double ddeg;
    double sec = modf(deg_point, &ddeg)*60;
    int deg = (int)(ddeg/100);
    int min = (int)(deg_point-(deg*100));

    double absdlat = round(deg * 1000000.);
    double absmlat = round(min * 1000000.);
    double absslat = round(sec * 1000000.);

    return round(absdlat + (absmlat/60) + (absslat/3600)) /1000000;
}

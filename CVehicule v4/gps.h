#ifndef _GPS_H_
#define _GPS_H_

#ifndef PORTNAME
#define PORTNAME "/dev/ttyAMA0"
#endif

/* Structure données GPS*/
struct location {
    double latitude;
    double longitude;
    double speed;
    double altitude;
    double course;
    char lat;
    char lon;
};
typedef struct location loc_t;

/* Déclarations des fonctions externes*/
extern void serialConfig(int);

extern void serialReadln(int, char *);

extern int gps_init(void);

extern void gps_on(void);

extern void gps_location(int, loc_t *);

extern void gps_off(int);

/* Déclarations des fonctions internes */
void gps_convert_deg_to_dec(double *, char, double *, char);

double gps_deg_dec(double);

#endif

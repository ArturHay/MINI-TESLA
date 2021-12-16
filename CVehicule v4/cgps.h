#ifndef CGPS_H_INCLUDED
#define CGPS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#include "gps.h"

class CGPS
{

private:
    int fd;
    loc_t data;
    double lastPositionMoy[5];

public:
    CGPS();
    ~CGPS();

    //double *getData(double p_dataCP[][3], int nData);


    double *getData(double DataCP[][5], int nData);

    double *getMoyenneData(double DataCP[][5], int nData);

    void waiting(int p_delay);

    double *getLastPositionMoy();

    char* getLocData();
};

#endif // CGPS_H_INCLUDED

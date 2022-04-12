#include "cgps.h"

CGPS::CGPS()
{
    /* Initialisation du GPS*/
    fd = gps_init();
    /* Traitement principal */
    //printf("Test lecture module GPS.\n");
    /* Vidage du buffer de réception série */
    serialFlush(fd);
    //printf("fd=%d\n",fd);
}

CGPS::~CGPS()
{
/* Arret du GPS */
    gps_off(fd);
}

double* CGPS::getData(double DataCP[][3], int nData)
{

    for(int i=0; i<nData; i++)
    {
        gps_location(fd,&data);
        DataCP[i][0] = data.latitude;
        DataCP[i][1] = data.longitude;
        DataCP[i][2] = data.altitude;
        printf("[%d] = %lf\t%lf\t%lf\t%c\t%c\n",i, DataCP[i][0], DataCP[i][1], DataCP[i][2], data.lat, data.lon);
    }

    getMoyenneData(DataCP, nData);

    //Renvoie le tableau
    return reinterpret_cast<double *>(DataCP);
}

void CGPS::waiting(int p_delay)
{
    double tabWaiting[p_delay][5];
    for(int i=p_delay; i>0; i--)
    {
        printf("Reprise des mesures dans: %d secondes\n", i);
        gps_location(fd,&data);
        tabWaiting[p_delay-i][0] = data.latitude;
        tabWaiting[p_delay-i][1] = data.longitude;
        tabWaiting[p_delay-i][2] = data.altitude;
    }
}

double* CGPS::getMoyenneData(double DataCP[][3], int nData)
{
    lastPositionMoy[0] = 0;
    lastPositionMoy[1] = 0;
    lastPositionMoy[2] = 0;
    for(int i=0; i < nData; i++)
    {
        lastPositionMoy[0] += DataCP[i][0];
        lastPositionMoy[1] += DataCP[i][1];
        lastPositionMoy[2] += DataCP[i][2];
    }
    lastPositionMoy[0] /= nData;
    lastPositionMoy[1] /= nData;
    lastPositionMoy[2] /= nData;



    return lastPositionMoy;
}

double* CGPS::getLastPositionMoy()
{
    return lastPositionMoy;
}

char* CGPS::getLocData()
{
    char tabLocData[2] = {data.lat, data.lon};

    return tabLocData;
}

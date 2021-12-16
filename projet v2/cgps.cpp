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
    printf("entre getdata\t");
    for(int i=0; i<nData; i++)
    {
        printf("entre boucle for getdata\n");
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

void CGPS::waiting(double DataCP[][3], int p_delay)
{
    printf("entre waiting\n");
    if(p_delay > 10)
    {
        printf("1ere condition\n");
        for(int i=1; i<10; i++)
        {
            gps_location(fd,&data);
            DataCP[p_delay-i][0] = data.latitude;
            DataCP[p_delay-i][1] = data.longitude;
            DataCP[p_delay-i][2] = data.altitude;
            printf("[%d] = %lf\t%lf\t%lf\n",i, DataCP[i][0], DataCP[i][1], DataCP[i][2]);
        }
        for(int i=1; i<(p_delay%10); i++)
        {
            gps_location(fd,&data);
            DataCP[p_delay-i][0] = data.latitude;
            DataCP[p_delay-i][1] = data.longitude;
            DataCP[p_delay-i][2] = data.altitude;
            printf("[%d] = %lf\t%lf\t%lf\n",i, DataCP[i][0], DataCP[i][1], DataCP[i][2]);
        }
    }
    else
    {
        printf("2eme condition\n");
        for(int i=1; i<p_delay; i++)
        {
            printf("entre boucle for\t");
            gps_location(fd,&data);
            printf("apres gps loc\n");
            DataCP[p_delay-i][0] = data.latitude;
            DataCP[p_delay-i][1] = data.longitude;
            DataCP[p_delay-i][2] = data.altitude;
            printf("[%d] = %lf\t%lf\t%lf\n",i, DataCP[i][0], DataCP[i][1], DataCP[i][2]);
        }
    }

    printf("Fin waiting\n");
    getMoyenneData(DataCP, 10);
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

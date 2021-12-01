#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#ifndef CVEHICULE_H
#define CVEHICULE_H

#define MAX_LOGS 256

class CLogs
{

private:
    double logs[MAX_LOGS][7];

    int addLogsFile(double logs[][7]);
    bool launch;

public:
    CLogs();

    void addLogs(double p_mouvement, double p_vitesse, double p_duree, double p_latitude,
                 double p_longitude, double p_state, double p_timer);

};

#endif // CVEHICULE_H

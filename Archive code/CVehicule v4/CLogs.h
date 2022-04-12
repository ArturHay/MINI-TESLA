#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#ifndef CLOGS_H
#define CLOGS_H

#define MAX_LOGS 256

using std::string;

class CLogs
{

private:
    bool launch;
    double logs[MAX_LOGS][9];

    int addLogsFile(double logs[][9]);

    char* toDirection(double p_char);
    string toMouvement(double p_mouvement);

public:
    CLogs();
    ~CLogs();

    void addLogs(double p_mouvement, double p_vitesse, double p_duree, double p_distance, double p_latitude, double p_longitude,
                 double p_lat, double p_lon, double p_state, double p_timer);

    double *getLogs(double logs[][9], int nData);
};

#endif // CLOGS_H

#include <QCoreApplication>
#include "cvehicule.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CVehicule *v1 = new CVehicule();

    /*
    addLogs(double p_mouvement, double p_vitesse, double p_duree,
                            double p_latitude, double p_longitude, double p_state, double p_timer)
    */

    double fLogs[7][7] = {1.0};

    double duree = 3.50;

    for(int i=0; i<7; i++)
    {
            fLogs[i][0] = 1 * (i%6); // mvt
            fLogs[i][1] = 25 * (i % 2); // vitesse
            fLogs[i][2] += i*10; // Duree
            fLogs[i][3] += i*5;
            fLogs[i][4] = i%2;
            fLogs[i][5] = duree * (i+1);
            fLogs[i][6] = 10.0;
            v1->addLogs(fLogs[i][0],fLogs[i][1],fLogs[i][2],fLogs[i][3],fLogs[i][4],fLogs[i][5],fLogs[i][6]);
    }



    return a.exec();
}

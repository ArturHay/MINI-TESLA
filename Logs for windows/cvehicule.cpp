#include "cvehicule.h"

CVehicule::CVehicule()
{
    for(int i=0; i<MAX_LOGS-1; i++)
    {
        for(int y=0; y<7; y++){
            logs[i][y] = 0;
        }
    }
    launch = false;

}


// Fonction pour ajouter à l'historique des mouvements
void CVehicule:: addLogs(double p_mouvement, double p_vitesse, double p_duree,
                        double p_latitude, double p_longitude, double p_state, double p_timer)
{

    // Décalage des valeurs aux cases suivantes
    printf("Decalage des logs...\n");
    for(int i=MAX_LOGS-1; i>1; i--)
    {
        for(int y=0; y<7; y++){
            logs[i][y] = logs[i-1][y];
        }
    }

    // Ajout des dernieres informations de mouvement
    logs[0][0] = p_mouvement;
    logs[0][1] = p_vitesse;
    logs[0][2] = p_duree;
    logs[0][3] = p_latitude;
    logs[0][4] = p_longitude;
    logs[0][5] = p_state;
    logs[0][6] = p_timer;

    addLogsFile(logs);
}



int CVehicule::addLogsFile(double logs[][7])
{
    printf("Debut fonction addLogsFile...\n");

    using namespace std;

    //Déclaration du flux - Ouvrir en écriture - Écrire à la fin du fichier
    ofstream flux("D:/mini projet/Code/CLogs/logs.txt", ios::out | ios::app);


    if(flux.is_open()) // Si le fichier est bien ouvert
    {
        //Écriture des données dans le fichier logs.txt
        if(!launch){
            flux << "-------------------" << endl;
            flux << "Nouveau lancement" << endl;
            flux << "-------------------" << endl;
            launch = true;
        }

        for(int y=0; y<5; y++){
            flux << logs[0][y] << ";";
        }
        flux << logs[0][6] << endl;
        printf("Ajout d'une ligne dans logs.txt...\n");
    }
    else
    {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
        return -1;
    }

    flux.close();

    return 1;
}

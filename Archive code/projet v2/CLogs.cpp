#include "clogs.h"

#define NORD 0
#define SUD 1
#define EST 2
#define OUEST 3

#define AVANT 0
#define ARRIERE 1
#define ARRET 2
#define DEMI_TOUR 3
#define DROITE 4
#define GAUCHE 5

CLogs::CLogs()
{
    for(int i=0; i<MAX_LOGS-1; i++)
    {
        for(int y=0; y<10; y++){
            logs[i][y] = 0;
        }
    }
    launch = false;

}

CLogs::~CLogs()
{
}

// Fonction pour ajouter à l'historique des mouvements
void CLogs::addLogs(double p_mouvement, double p_vitesse, double p_duree, double p_distance, double p_latitude,
                    double p_longitude, double p_lat, double p_lon, double p_state, double p_timer)
{

    // Décalage des valeurs aux cases suivantes
    //printf("Decalage des logs...\n");
    for(int i=MAX_LOGS-1; i>1; i--)
    {
        for(int y=0; y<10; y++){
            logs[i][y] = logs[i-1][y];
        }
    }

    // Ajout des dernieres informations de mouvement
    //Information sur le mouvement
    logs[0][0] = p_mouvement;
    logs[0][1] = p_vitesse;
    logs[0][2] = p_duree;

    logs[0][2] = p_distance;

    //Information GPS
    logs[0][4] = p_latitude;
    logs[0][5] = p_longitude;
    logs[0][6] = p_lat;
    logs[0][7] = p_lon;

    //Information divers
    logs[0][8] = p_state;
    logs[0][9] = p_timer;

    for(int i=0; i<10;i++)
    {
        printf("%.2lf;",logs[0][i-1]);
    }
    printf("\n");

    addLogsFile(logs);
}



int CLogs::addLogsFile(double  logs[][10])
{
    //printf("Debut fonction addLogsFile...\n");

    using namespace std;

    //Déclaration du flux - Ouvrir en écriture - Écrire à la fin du fichier
    ofstream flux("/home/pi/Documents/MiniProjet_MiniTesla/mathieu/logs.txt", ios::out | ios::app);


    if(flux.is_open()) // Si le fichier est bien ouvert
    {
        //Écriture des données dans le fichier logs.txt
        if(!launch){
            flux << "-------------------" << endl;
            flux << "Nouveau lancement" << endl;
            flux << "-------------------" << endl;
            launch = true;
        }

        flux << toMouvement(logs[0][0]) << ";";
        for(int i=1; i<5; i++) flux << logs[0][i] << ";";
        for(int i = 6; i<7; i++) flux << toDirection(logs[0][i]) << ";";
        flux << logs[0][8] << ";";
        flux << logs[0][9] << endl;


        //PRINT F
        /*printf("%s;",toMouvement(logs[0][0]));
        for(int i = 1; i<5; i++) printf("%lf;",logs[0][i]);
        for(int i=6; i<7; i++) printf("%s;",toDirection[0][i]);
        printf("%lf;", logs[0][8]);
        printf("%lf\n\n", logs[0][8]);*/


        /*for(int y=0; y<9; y++){
            if(y!=0 && y!=6 && y!=7)
            {
                flux << logs[0][y] << ";";
            }
            else if(y == 0)
            {
                flux << toMouvement(logs[0][0]) << ";";
            }
            else
            {
                printf("\n\nESLE: %lf %lf\n\n", logs[0][6], logs[0][7]);
                flux << toDirection(logs[0][y]) << ";";
            }
        }
        flux << endl;*/

        //printf("Ajout d'une ligne dans logs.txt...\n");
    }
    else
    {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
        return -1;
    }

    flux.close();

    return 1;
}


string CLogs::toDirection(double p_char)
{
    if(p_char == NORD)  return "N";
    if(p_char == SUD)   return "S";
    if(p_char == EST)   return "E";
    if(p_char == OUEST) return "W";

    return "\0";
}

string CLogs::toMouvement(double p_mouvement)
{
    if(p_mouvement == AVANT)        return "AVANT";
    if(p_mouvement == ARRIERE)      return "ARRIERE";
    if(p_mouvement == ARRET)        return "ARRET";
    if(p_mouvement == DEMI_TOUR)    return "DEMI_TOUR";
    if(p_mouvement == DROITE)       return "DROITE";
    if(p_mouvement == GAUCHE)       return "GAUCHE";

    return "ERREUR";
}

double* CLogs::getLogs(double logs[][10])
{
    return reinterpret_cast<double *>(logs);
}

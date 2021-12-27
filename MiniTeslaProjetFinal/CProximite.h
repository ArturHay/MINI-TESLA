#ifndef CPROXIMITE_H
#define CPROXIMITE_H
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8591.h>
#include <math.h>

#define ADRESS 0x48
#define A_CONVERSION 38.2
#define PUISSANCE_CONVERSION -0.879
#define LIMITVOLT 0.4
#define BITS 8
#define VOLT_MAX 5

class CProximite
{
private:
    int fd;
    // conversion de Bit en volts
    double conversionBitToVolts(int voltsBit);
    //conversion des volts en distance
    double conversionVoltToDistance(double volts);
    int m_port;


public:
    //Constructeur par defaut car pas de parametre
    CProximite();
    //Constructeur avec parametre
    CProximite(int p_port);
    //Destructeur
    ~CProximite();
    //Recupere la distance calculer avec le capteur 
    double getDistance();

};

#endif // CPROXIMITE_H

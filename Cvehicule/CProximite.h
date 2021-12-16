#ifndef CPROXIMITE_H
#define CPROXIMITE_H
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8591.h>
#include <math.h>

#define A_CONVERSION 38.2
#define PUISSANCE_CONVERSION -0.879
#define LIMITVOLT 0.4
#define BITS 8
#define VOLT_MAX 5
#define ADRESS 0x48

class CProximite
{
private:
    int fd;
    double conversionBitToVolts(int voltsBit);
    //conversion des volts en distance
    double conversionVoltToDistance(double volts);


public:
    //Constructeur par défaut car pas de paramètre
    CProximite();
    //Destructeur
    ~CProximite();
    //
    double getDistance();

};

#endif // CPROXIMITE_H

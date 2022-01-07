#include"CProximite.h"

CProximite::CProximite()
{
}

//Constructeur avec parametre
CProximite::CProximite(int p_port)
{
    m_port = p_port;
    wiringPiSetup();
    m_fd = wiringPiI2CSetup(ADRESS);
}

//Destructeur
CProximite::~CProximite()
{

}

 // Conversion nombre sur 8 bits a volts
double CProximite::conversionBitToVolts(int voltsBit)
{
    double volts = (VOLT_MAX * voltsBit) / pow(2,BITS);
    return(volts);
}

//conversion des volts en distance
double CProximite::conversionVoltToDistance(double volts)
{
    if(volts < LIMITVOLT){
        return 0;
    }
    //Calcul de la distance: 63,1 * volts^-1,13 
    double distance = A_CONVERSION * pow(volts, PUISSANCE_CONVERSION);
    return(distance);
}

//Renvoie la distance detectée par le capteur
double CProximite::getDistance()
{
    //Lecture en volt
    int voltsBit = wiringPiI2CReadReg8(m_fd,m_port);
    //Conversion nombre sur 8 bits a volts
    double voltage = conversionBitToVolts(voltsBit);
    //Conversion de volt a cm
    double distance = conversionVoltToDistance(voltage);
    return distance;
}

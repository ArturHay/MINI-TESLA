#include"CProximite.h"

 //Constructeur par defaut car pas de parametre
CProximite::CProximite()
{
}

//Constructeur avec parametre
CProximite::CProximite(int p_port)
{
    m_port = p_port;
    wiringPiSetup();
    fd = wiringPiI2CSetup(ADRESS);
}

//Destructeur
CProximite::~CProximite()
{

}

 // conversion de Bit en volts
double CProximite::conversionBitToVolts(int voltsBit)
{
    double volts = (VOLT_MAX * voltsBit) / pow(2,BITS);
    return(volts);
}

//conversion des volts en distance
double CProximite::conversionVoltToDistance(double volts)
{
    //distance = 63,1 * volts^-1,13
    if(volts < LIMITVOLT){
        return 0;
    }
    double distance = A_CONVERSION * pow(volts, PUISSANCE_CONVERSION);
    return(distance);
}

//Recupere la distance calculer avec le capteur 
double CProximite::getDistance()
{
    //Lecture en volt
    int voltsBit = wiringPiI2CReadReg8(fd,m_port);
    //Conversion nombre sur 8 bits a volts
    double voltage = conversionBitToVolts(voltsBit);
    //Conversion de volt a cm
    double distance = conversionVoltToDistance(voltage);
    return distance;
}

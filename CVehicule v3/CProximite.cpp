#include"CProximite.h"

CProximite::CProximite()
{
    wiringPiSetup();
    fd = wiringPiI2CSetup(ADRESS);
}
CProximite::~CProximite()
{

}

double CProximite::conversionBitToVolts(int voltsBit)
{
    double volts = (VOLT_MAX * voltsBit) / pow(2,BITS);
    return(volts);
}


double CProximite::conversionVoltToDistance(double volts)
{
    //distance = 63,1 * volts^-1,13
    if(volts < LIMITVOLT){
        return 0;
    }
    double distance = A_CONVERSION * pow(volts, PUISSANCE_CONVERSION);
    return(distance);
}

double CProximite::getDistance()
{
    //Lecture en volt
    int voltsBit = wiringPiI2CReadReg8(fd,1);
    //Conversion nombre sur 8 bits a volts
    double voltage = conversionBitToVolts(voltsBit);
    //Conversion de volt a cm
    double distance = conversionVoltToDistance(voltage);
    return distance;
}

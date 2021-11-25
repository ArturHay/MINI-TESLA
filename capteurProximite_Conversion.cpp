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


double conversionBitToVolts(double voltsBit)
{
    double volts = (VOLT_MAX * voltsBit) / pow(2,BITS);
    return(volts);
}


double conversionVoltToDistance(double volts)
{
    //distance = 63,1 * volts^-1,13
    if(volts < LIMITVOLT){
        return 0;
    }
    double distance = A_CONVERSION * pow(volts, PUISSANCE_CONVERSION);
    return(distance);
}

int main()
{
    int fd;
    int voltsBit = 0;
    double voltage = 0;
    double distance = 0;
    wiringPiSetup();
    fd = wiringPiI2CSetup(ADRESS);

    while (1)
    {
        //Lecture en volt
        voltsBit = wiringPiI2CReadReg8(fd,1);
        //Conversion nombre sur 8 bits à volts
        voltage = conversionBitToVolts(voltsBit);
        //Conversion de volt à cm
        distance = conversionVoltToDistance(voltage);


        printf("nombre=%d\tvoltage=%.2lf V\tdistance=%.2lf cm\n",voltsBit,voltage,distance);
        delay(500);
    }
    return 0;
}

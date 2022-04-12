#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8591.h>

int main()
{
    int fd;
    wiringPiSetup();
    fd = wiringPiI2CSetup(0x48);

    while (1)
    {
        //printf("read=%d\n",wiringPiI2CRead(fd));
        printf("read=%d\n",wiringPiI2CReadReg8(fd,1));
        delay(500);
    }
    return 0;
}

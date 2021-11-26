#include <wiringPi.h> /* include wiringPi library */
#include <stdio.h>
#include <softPwm.h>  /* include header file for software PWM */
#define PIND 1
#define PING 0

int avancer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PING, vitesse+20);
    softPwmWrite (PIND, vitesse+20);
    delay(duree);

    return 1;
}

int reculer(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PING, 20-vitesse);
    softPwmWrite (PIND, 20-vitesse);
    delay(duree);

    return 1;
}

int arreter(unsigned int duree)
{
    softPwmWrite (PING, 20);
    softPwmWrite (PIND, 20);
    delay(duree);
    return 1;
}

int tournerAvantGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60|| vitesse == 0){
        return -1;
    }
    softPwmWrite (PIND, vitesse+40);
    softPwmWrite (PING, vitesse+20);

    delay(duree);
    return 1;
}

int tournerAvantDroite(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>60 || vitesse==0){
        return -1;
    }
    softPwmWrite (PING, vitesse+20);
    delay(duree);
    return 1;
}

int tournerArriereGuauche(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PING, 20-vitesse);
    delay(duree);
    return 1;
}
int tournerArriereDroit(unsigned char vitesse,unsigned int duree)
{
    if(vitesse>=20){
        return -1;
    }
    softPwmWrite (PIND, 20-vitesse);
    delay(duree);
    return 1;
}

int main(){
	wiringPiSetup();
	pinMode(PIND,OUTPUT);
	pinMode(PING,OUTPUT);
	softPwmCreate(PIND,1,200);
	softPwmCreate(PING,0,200);

	if(avancer(1,5000)!= 1)
    {
        printf("erreur\n");
    }

	if(reculer(3,5000)!= 1)
    {
        printf("erreur\n");
    }
    	if(arreter(10000)!= 1)
    {
        printf("erreur\n");
    }
    tournerAvantGuauche(30,5000);
    arreter(1500);
    tournerAvantDroite(60,5000);
    arreter(1500);
    tournerArriereDroit(5,5000);
    arreter(1500);
    tournerArriereGuauche(5,5000);
    arreter(1505451540);



return(0);
}


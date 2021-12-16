#include <wiringPi.h> /* include wiringPi library */
#include <stdio.h>
#include <softPwm.h>  /* include header file for software PWM */

int main(){
	int PWM_pinD = 1;
	int PWM_pinG = 0;		/* GPIO1 as per WiringPi,GPIO18 as per BCM */
	int intensity;
	wiringPiSetup();		/* initialize wiringPi setup */
	pinMode(PWM_pinD,OUTPUT);
	pinMode(PWM_pinG,OUTPUT);	/* set GPIO as output */
	softPwmCreate(PWM_pinD,1,200);
	softPwmCreate(PWM_pinG,0,200);	/* set PWM channel along with range*/
	for (int i = 0; i<1 ; i++)
	  {
		for (intensity = 20; intensity < 80; intensity++)
		{
		  softPwmWrite (PWM_pinD, intensity);
		  softPwmWrite (PWM_pinG, intensity); /* change the value of PWM */
		  delay (10) ;
		}
		delay(1);

		for (intensity = 20; intensity >= 0; intensity--)
		{
		  softPwmWrite (PWM_pinD, intensity);
		  softPwmWrite (PWM_pinG, intensity);
		  delay (70);
		}
		delay(1);
	}
	 while(1){
     softPwmWrite (PWM_pinD, 20);
     softPwmWrite (PWM_pinG, 20);
     delay (5000000);
	}
}

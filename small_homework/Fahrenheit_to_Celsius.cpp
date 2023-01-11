#include<stdio.h>
#include<stdlib.h>
int main(){
 	float Celsius,Fahrenheit;
 	printf("Please enter the temperature in Fahrenheit:\n"); 
 	scanf("%f",&Fahrenheit);
 	Celsius=5.0/9.0*(Fahrenheit-32);
 	printf("The temperature in Celsius is %f\n",Celsius);
	system("Pause");
 }
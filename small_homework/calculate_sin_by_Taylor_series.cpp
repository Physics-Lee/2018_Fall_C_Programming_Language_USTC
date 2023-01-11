#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long double factorial(double n){
	double t=1,i=1;
	for(double i=1;i<=n;i++){
		t *= i;
	}
	return t;
}

double user_define_sin(double x){
	double m=2;
	double sin_now=0,sin_pre=0;
	for(int i=1;;i+=2){
		sin_now += pow(-1,m)*pow(x,i)/factorial(i);
		if(fabs(sin_now-sin_pre)<=1e-15){
			return sin_now;
		}
		else{
			m++;
			sin_pre=sin_now;	
		}
	}
}

// In Taylor series, you can get any precision at any point as long as the number of terms is large enough.
// I knew Taylor expansion but didn't know Taylor series in 2018 Fall, so I was confused.

int main(){
	double x;
	printf("Please enter the angle x in radian measure:\n"); 
	scanf("%lf",&x);
	printf("user's sin:\t%.20f\n",user_define_sin(x));
	printf("system's sin:\t%.20f\n",sin(x));
	system("Pause");
}


  






















/*
long double pow(long double a,long double b){
	long double m=1;
	for(int i=1;i<=b;i++)m*=a;
	return m;
}

long double fabs(long double x){
	return x<0?-x:x;
}
*/

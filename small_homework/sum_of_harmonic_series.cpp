#include<stdio.h>
#include<stdlib.h>
int main(){
	int i=1;
	float sum=0;
	printf("How many terms do you want to calculate the sum of?\n");
	int N = 1;
	scanf("%d",&N);
	while(i <= N){
		sum=sum+1.0/i;
		i++;
	}
	printf("sum=%6.2f\n",sum);
	system("Pause");
}
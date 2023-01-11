#include<stdio.h>
#include<stdlib.h>

int perfect_number(int n){
	int sum=0;
	for(int i=1;i<=n/2+1;i++){
		if(n%i==0){
			sum+=i;
		}
	}
	if(sum==n){
		return 1;
	}       
	return 0;
}

int main(){
	printf("I will print the perfect numbers below N for you:\n"); 
	int N;
	printf("Please enter N:\n");
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		if(perfect_number(i)){
			printf("%d\t",i);
		}
	}
	printf("\n");
	system("Pause");
}

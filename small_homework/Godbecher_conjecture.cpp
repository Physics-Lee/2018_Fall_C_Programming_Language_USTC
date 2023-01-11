#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int IsPrime(int n){
	for(int i=2;i<=sqrt((double)n);i++){
		if( n % i == 0 ){
			return 0;
		}
	}
	return 1;                                    
}

int main(){
	printf("I will prove Godbecher conjecture below N for you:\n"); 
	int N;
	printf("Please enter N:\n");
	scanf("%d",&N);
	int count = 0;
	for(int i=6;i<=N;i+=2,count++){
		for(int t=3;t<=i/2;t+=2){
			if(IsPrime(t)&&IsPrime(i-t)){
				printf("%d=%d+%d\t\t",i,t,i-t);
				break;
			}
		}
		if((count+1)%5==0){
			printf("\n");
		}
	}
	system("Pause");
}	

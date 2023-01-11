#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
 	int a,b,c;
 	float p,s;
 	printf("input a,b,c\n");
 	scanf("%d %d %d",&a,&b,&c);
 	if((a+b)>c&&(a-b)<c){
 		p=(a+b+c)/2;
 		s=sqrt(p*(p-a)*(p-b)*(p-c));
 		printf("s=%f \n ",s);
	}
 	else{
 		printf("The triangle doesn't exist!!!\n");
	} 
	system("Pause");
 }  

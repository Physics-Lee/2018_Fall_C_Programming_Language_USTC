#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int m,n;
	printf("我会为您打印一个空心菱形框，请输入m和n的值：m为外框“半径”，n为内框“半径”\n"); 
	scanf("%d%d",&m,&n);
	
	for(int x=0;x<=2*m;x++){
		for(int y=0;y<=2*m;y++){
			int d=fabs(x-m)+fabs(y-m);    
			if(d>m||d<n) printf("  ");
			else printf("* ");
		}
		printf("\n");
	}
	system("pause");
}

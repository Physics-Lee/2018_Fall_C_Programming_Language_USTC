#include<stdio.h>
#include<stdlib.h>
#define N 100

void magic(int a[][N],int n){
	int i,j,il,jl,x;
	i=0;j=n/2;
	x=1;
	while(x<=n*n){
		a[i][j]=x++;
		il=i;
		jl=j;
		i=i-1;                   //����45��Խ������� 
		j=j+1;
		if(i<0)i=n-1;
		if(j>n-1)j=0;
		if(a[i][j]!=0){                    //�Ѿ����������� 
			i=il+1;
			j=jl;
		}
	}
}

void outputmat(int a[][N],int m,int n){         //��ӡ���� 
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("%4d",a[i][j]);
		}
		printf("\n"); 
	}
	 
}

int main(){
	int a[N][N]={0},n;
	printf("���������׻÷��Ľ�������ż���÷����㷨�Ƚϸ��ӣ�\n");
	scanf("%d",&n);
	magic(a,n);
	outputmat(a,n,n); 
	system("Pause");
}

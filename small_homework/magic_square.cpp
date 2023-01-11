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
		i=i-1;                   //沿着45°对角线填数 
		j=j+1;
		if(i<0)i=n-1;
		if(j>n-1)j=0;
		if(a[i][j]!=0){                    //已经有其他数据 
			i=il+1;
			j=jl;
		}
	}
}

void outputmat(int a[][N],int m,int n){         //打印矩阵 
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
	printf("输入奇数阶幻方的阶数：（偶数幻方的算法比较复杂）\n");
	scanf("%d",&n);
	magic(a,n);
	outputmat(a,n,n); 
	system("Pause");
}

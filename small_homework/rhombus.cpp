#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int m,n;
	printf("�һ�Ϊ����ӡһ���������ο�������m��n��ֵ��mΪ��򡰰뾶����nΪ�ڿ򡰰뾶��\n"); 
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

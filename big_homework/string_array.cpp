//�ַ�������������
#include<stdio.h>
#include<stdlib.h>
     
#define PC printf("CHEERS!!!\n") 
#define PH printf("HELLO!!!\n")
#define longitude 8                      
#define latitude 20
char a[longitude][latitude];                                          //���Ҿ���γ��    �����˶�ά�ַ����飬��Щ�˷ѿռ� 




void write(){
	FILE *fp;
	
	if(  (fp=fopen("string_array.txt","w")) ==NULL   ) {
		printf("��ʧ�ܣ�");
		exit(0);
	}
	
	printf("�������ַ���\n");
	for(int i=0;i<=longitude-1;i++){
		printf("�������%d���ַ���",i);
		scanf("%s",a[i]);
		fprintf(fp,"%s\n",a[i]);
		
	}
	
	fclose(fp);
}

void read(){
	printf("��װ��+��ʾ�ַ����鿴�ɣ�����\n\n\n");
}

void zhuangru(){                                                        

	FILE *fp;

	fp=fopen("string_array.txt","r");
	if(!fp) {
		printf("��ʧ�ܣ�����\n");
		return ;
	}
	
	for(int i=0;i<=longitude-1;i++){
	fscanf(fp,"%s",a[i]);
	} 
	

}

void wenjian(){                                                         //1 �����ļ��Ӳ˵� 
	int menu;
	FILE*fp;
	while(1){
		printf("0�����˳�\n");
		printf("1�����Ӽ��̼������ݣ�д���ı��ļ�\n");
		printf("2�������ı��ļ��ж�������,��Ļ��ʾ\n");
		printf("3��������ı��ļ�\n");
		printf("4�������ı��ļ�װ���Ѵ��ڵĶ�ά�ַ�������\n");
		printf("��ѡ��\n");
		int menu;
		scanf("%d",&menu);
		switch(menu){
			case 0:{
				return;
				break;
			}
			case 1:{
				write();
				break;
			}
			case 2:{
				read();
				break;
			}
			case 3:{
				FILE *fp; 
				fp=fopen("string_array.txt","w");fclose(fp);
				break;
			}
			case 4:{
				zhuangru();
				printf("��װ�룡����\n\n\n");
				break;
			} 
		}
		return;
	}
}
void scanf(){                                                         //��scanf+%s���룬���ÿ��ǿո� 
	printf("�����룺\n"); 
	for(int i=0;i<=longitude-1;i++){
		printf("�������%d���ַ���",i);
		scanf("%s",a[i]);
	} 
}
void gets(){                                                         //��gets���룬�Կո������ 
	printf("gets�����Կո�̫�����ˣ�������scanf+�ٷֺ�c��������scanf+�ٷֺ�s����ɣ�����\n");
	printf("������֣�������1\n");
	printf("�����룺\n");
	int menu;
	scanf("%d",&menu);
	switch(menu){
		case 1:{
			getchar();
			for(int i=0;i<=longitude-1;i++){
		    printf("�������%d���ַ���",i);
		    gets(a[i]); 
	        }  
			break;
		}
		
		
	} 
	
	
}
void inputmenu(){                                                       //1�����Ӳ˵� 
	printf("\n\n**    �����ַ����Ӳ˵�    **\n\n");
	printf("0�����������˵�\n");
	printf("1������scanf����\n");
	printf("2������gets����(������ø�)\n");
	printf("3�������ļ����루lazyboy��\n");
	printf("\n��ѡ��\n");
	int menu;
	scanf("%d",&menu);
	if(menu<0||menu>3){
		printf("Խ�磡����\n");
		return;
	}
	switch(menu){
		case 0:{
			return;
			break;
		}
		case 1:{
			scanf();
			break;
		}
		case 2:{
			gets();
			break;
		}
		case 3:{
			wenjian();
			break;
		} 
	}
}

int udf_strlen(char *a){                                                //3�󴮳� 
	int i=0;
	for(;a[i]!='\0';i++); 
	return  i;
}

char *udf_strcat(char *a,char *b){                                   // 4������   ����a��
    int n1=udf_strlen(a); 
    int i=n1;
    for(int j=0;b[j]!='\0';i++,j++){
    	a[i]=b[j];
	}
	printf("%d",a[i]);
	return a;
}

int udf_strcmp(char*a,char*b){                                      //5 ���Ƚ�    aС��b���ظ��� ���ڷ���0 a����b��������
    int i=0;
    int n1=udf_strlen(a),n2=udf_strlen(b);
    if(n1>n2){
    	int t;
    	t=n1;n1=n2;n2=t;
	}
	for(   ;a[i]==b[i]&&i<=n2;i++) ;  
	return  (a[i]-b[i]);
} 

char *udf_strcpy(char*a,char*b){                                  //6  ������  �� b���Ƶ�a��
    int i;
    
	for(i=0;b[i]!='\0';i++){
    	a[i]=b[i];
	} 
	a[i]='\0'; 
	return a;
} 

void insert(char *a,int pos, char *t){                           //7 ��tǡ�ò��뵽pos�±�֮ǰ 
    int n1=udf_strlen(a),n2=udf_strlen(t);
    if(pos<n2){
    	printf("λ�ò��㣬���ܲ��룡����\n");
		return; 
	}
    int i;
    for(i=n1;i>=pos-n2   ;i--){
    	a[i+n2]=a[i];
	}
	i=pos-n2;
	for(int j=0;t[j]!='\0'    ;i++,j++){
		a[i]=t[j];
	}
	
}

void substring(char *a, int pos, int n, char sub[]){              //8 ��a����posλ�ÿ�ʼ��n���ַ�װ��sub���� 
	int i=pos,j; 
	for( j=0 ; i<=pos+n-1;i++,j++){
		
		sub[j]=a[i];
	} 
	sub[j]='\0';
	
}
int search(char s[],char t[]){                                   //9 ���ص�һ���Ӵ�t������s�е�λ�ã��������򷵻�-1
    int i,j,pos;
	PC;
	for(i=0;s[i]!='\0' ;i++){
		if(s[i]==t[0]){
			pos=i;
			for(j=0;t[j]!='\0';j++,i++){
				if(t[j]!=s[i]) break;
			}
		}
		if(t[j]=='\0') return pos;
	} 
	if(t[j]!='\0') return -1;
}
void replace (char s[],char v[],char t[]){                        //10 ������s�����в��ص���v��t�û� 
	int i=search(s,v); int flag=0,j;
	int n1=udf_strlen(v),n2=udf_strlen(t);
	if(n1!=n2) printf("���Ǵ�������ȣ��޷����㣡����\n"); 
	if(i==-1) printf("������û�и��Ӵ�������\n"); 
	
	
	for(j=0;j<=n1-1;i++,j++){
		s[i]=t[j];
	}
    flag++;
	printf("%s\n",s);
	printf("%d\n",i);
	
	replace(s+i,v,t); 
/*	for(  i=search(p,v);PH ,i!=-1   ; i=search(s+i+n1,v)   ){
	    PH;
		for(j=0;i<=i+n1-1  ;i++,j++){
		s[i]=t[j];
	    }
	    flag++;
	}  */
	
}
void hannuo (int n, char A,char B,char C){
	if(n==1){
		printf("��1���� %c����%c\n",A,C);
	}
	else{
		hannuo(n-1,A,C,B);
		printf("��%d���� %c����%c\n",n,A,C);
		hannuo(n-1,B,A,C);
	}	
}
void othermenu(){                                                      //11�����Ӳ˵� 
	printf("\n\n**    �����Ӳ˵�    **\n\n");
	printf("0�����������˵�\n");
	printf("1��������һ��ӡ��ά����İ취�����͵ķ�ʽ��ӡĿǰ����\n");
	printf("2��������һ��ӡ��ά����İ취���ַ��͵ķ�ʽ��ӡĿǰ����\n");
	printf("3����ӡ���񻰡�����ŵ��\n");
	printf("\n��ѡ��\n");
	int menu;
	scanf("%d",&menu);
	if(menu<0||menu>3){
		printf("Խ�磡����\n");
		return;
	}
	switch(menu){
		case 0:{
			return;
			break;
		}
		case 1:{
			int i,j;
			for(i=0;i<=longitude-1;i++){
				for(j=0;j<=latitude-1;j++){
					printf("%3d",a[i][j]);
				}
				printf("\n");
			}
			break;
		}
		case 2:{
			int i,j;
			a[1][10]=65;
			for(i=0;i<=longitude-1;i++){
				for(j=0;j<=latitude-1;j++){
					printf("%3c",a[i][j]);
				}
				printf("\n");
			}
			break;
		}
		case 3:{
			int n;
			printf("����������Ҫ��ĺ�ŵ���Ľ�����>=1����\n");
			scanf("%d",&n);
			hannuo(n,'a','b','c');
			break;
		} 
		default:break; 
	} 
}
main(){
	int menu;
	for(;;){
		printf("\n                ************     �ַ�������������     *************\n");
		printf("                  0���������ַ���          1������ʾ�ַ���\n");
	    printf("                  2���������Ļ            3�����󴮳�\n");
	    printf("                  4����������              5�������Ƚ�\n");
	    printf("                  6����������              7����������\n");
	    printf("                  8�������Ӵ�              9����������\n");
	    printf("                  10�������û�             11��������\n");
	    printf("                  12�����˳�\n");
	    printf("\n                *********************************************\n\n");
	    printf("                  ѡ�����˵���\n");
	    printf("             ����ܰ��ʾ���������ֺ󰴻س���������ЧŶ����       \n");
	    printf("             ����ܰ��ʾ������Խ�����ֻ������ַ��᷵�����˵�Ŷ!��\n");
		scanf("%d",&menu); 
		if(menu<0||menu>12) printf("�ף������������Խ����Ŷ������������\n") ;
		switch(menu){
			case 2:
				system("cls");  break;                                    //���� 
		    case 0:{
		    	inputmenu();
				break;
			}
		    	
			case 1:{
				for(int i=0;i<=longitude-1;i++){
					printf("��%d���ַ���Ϊ(��puts���)��",i);
					puts(a[i]);
				}
				break;
			}
			case 3:{
				int length,i;
				printf("������ڼ����ַ�����Ĵ����������룺\n");
				scanf("%d",&i);
				length=udf_strlen(a[i]);
				printf("���еĴ���Ϊ%d",length);
				break;   
			}
				
			case 4:{
				int i,j;
				printf("����ѵڼ������ӵ��ڼ��еĺ�ߣ���ֱ����룬�ÿո����\n");
				scanf("%d%d",&i,&j);
			    udf_strcat(a[j],a[i]);
				break;
			} 
		    case 5:{
		    	int i,j;
		    	printf("����Ƚϵڼ��к͵ڼ��У���ֱ����룬�ÿո������\n");
				scanf("%d%d",&i,&j); 
				printf("���Ϊ��%d\n",udf_strcmp(a[i],a[j])   );
				break;
			}    
			case 6:{
				int i,j;
				printf("����ѵڼ����ַ����鸴�Ƶ��ڼ����ַ����飿��ֱ����룬�ÿո����\n");
				scanf("%d%d",&i,&j);
			    udf_strcpy(a[j],a[i]);                                    
				break;
			}
			case 7:  {
				int i,j,pos;
				printf("����ѵڼ����ַ�������뵽�ڼ����ַ�������ĸ��±�֮ǰ����ֱ����룬�ÿո����\n");
				scanf("%d%d%d",&i,&j,&pos);
			    insert(a[j],pos,a[i]);   
				break;
			}
			case 8:{
				int i,n,pos;
				printf("������ڼ����ַ�������ĸ��±꿪ʼװ������ַ����Ӵ��У���ֱ����룬�ÿո����\n");
				scanf("%d%d%d",&i,&pos,&n);
				char sub[100];                              //?????Ұָ�� 
			    substring(a[i],pos,n,sub); 
			     PC;                
			    printf("�Ӵ�Ϊ %s",sub);                //����*��[] ����ô���� 
				break;
			}
		    case 9:{
		    	int i,j;
		    	printf("�����ڵڼ����ַ������ֲ��ҵڼ����ַ����飿��ֱ����룬�ÿո����\n");
		    	scanf("%d%d",&i,&j);
		    	if   (search(a[i],a[j])==-1  ){
		    		printf("���޴˴�������\n");
				}
				else printf("�Ӵ����������±�Ϊ%d",search(a[i],a[j])  );
				break;
			}
			case 10:{
				char s[100]="abcdabcdabcdabcd";
				char v[100]="abc";
				char t[100]="xyz";
			    replace(s,v,t);
				break;
			}             
			case 11:{
				
			    othermenu();break;    
				break;
			}         
			case 12:                    
				 return 0;
		    default:break; 
		}                    
		
		                                           
    }                                                  //end for
}                           


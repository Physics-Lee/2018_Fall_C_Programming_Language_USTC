//字符穿数组运算器
#include<stdio.h>
#include<stdlib.h>
     
#define PC printf("CHEERS!!!\n") 
#define PH printf("HELLO!!!\n")
#define longitude 8                      
#define latitude 20
char a[longitude][latitude];                                          //看我经天纬地    定义了二维字符数组，有些浪费空间 




void write(){
	FILE *fp;
	
	if(  (fp=fopen("string_array.txt","w")) ==NULL   ) {
		printf("打开失败！");
		exit(0);
	}
	
	printf("请输入字符串\n");
	for(int i=0;i<=longitude-1;i++){
		printf("请输入第%d行字符串",i);
		scanf("%s",a[i]);
		fprintf(fp,"%s\n",a[i]);
		
	}
	
	fclose(fp);
}

void read(){
	printf("用装入+显示字符串查看吧！！！\n\n\n");
}

void zhuangru(){                                                        

	FILE *fp;

	fp=fopen("string_array.txt","r");
	if(!fp) {
		printf("打开失败！！！\n");
		return ;
	}
	
	for(int i=0;i<=longitude-1;i++){
	fscanf(fp,"%s",a[i]);
	} 
	

}

void wenjian(){                                                         //1 ——文件子菜单 
	int menu;
	FILE*fp;
	while(1){
		printf("0——退出\n");
		printf("1——从键盘键入数据，写入文本文件\n");
		printf("2——从文本文件中读出数据,屏幕显示\n");
		printf("3——清空文本文件\n");
		printf("4——将文本文件装入已存在的二维字符数组中\n");
		printf("请选择：\n");
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
				printf("已装入！！！\n\n\n");
				break;
			} 
		}
		return;
	}
}
void scanf(){                                                         //用scanf+%s输入，不用考虑空格 
	printf("请输入：\n"); 
	for(int i=0;i<=longitude-1;i++){
		printf("请输入第%d行字符串",i);
		scanf("%s",a[i]);
	} 
}
void gets(){                                                         //用gets输入，对空格很敏感 
	printf("gets函数对空格太敏感了！，堪比scanf+百分号c，请您用scanf+百分号s输入吧！！！\n");
	printf("若您坚持，请输入1\n");
	printf("请输入：\n");
	int menu;
	scanf("%d",&menu);
	switch(menu){
		case 1:{
			getchar();
			for(int i=0;i<=longitude-1;i++){
		    printf("请输入第%d行字符串",i);
		    gets(a[i]); 
	        }  
			break;
		}
		
		
	} 
	
	
}
void inputmenu(){                                                       //1输入子菜单 
	printf("\n\n**    输入字符串子菜单    **\n\n");
	printf("0——返回主菜单\n");
	printf("1——用scanf输入\n");
	printf("2——用gets输入(这个不好搞)\n");
	printf("3——用文件输入（lazyboy）\n");
	printf("\n请选择：\n");
	int menu;
	scanf("%d",&menu);
	if(menu<0||menu>3){
		printf("越界！！！\n");
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

int udf_strlen(char *a){                                                //3求串长 
	int i=0;
	for(;a[i]!='\0';i++); 
	return  i;
}

char *udf_strcat(char *a,char *b){                                   // 4串联接   返回a串
    int n1=udf_strlen(a); 
    int i=n1;
    for(int j=0;b[j]!='\0';i++,j++){
    	a[i]=b[j];
	}
	printf("%d",a[i]);
	return a;
}

int udf_strcmp(char*a,char*b){                                      //5 串比较    a小于b返回负数 等于返回0 a大于b返回正数
    int i=0;
    int n1=udf_strlen(a),n2=udf_strlen(b);
    if(n1>n2){
    	int t;
    	t=n1;n1=n2;n2=t;
	}
	for(   ;a[i]==b[i]&&i<=n2;i++) ;  
	return  (a[i]-b[i]);
} 

char *udf_strcpy(char*a,char*b){                                  //6  串复制  把 b复制到a中
    int i;
    
	for(i=0;b[i]!='\0';i++){
    	a[i]=b[i];
	} 
	a[i]='\0'; 
	return a;
} 

void insert(char *a,int pos, char *t){                           //7 将t恰好插入到pos下标之前 
    int n1=udf_strlen(a),n2=udf_strlen(t);
    if(pos<n2){
    	printf("位置不足，不能插入！！！\n");
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

void substring(char *a, int pos, int n, char sub[]){              //8 将a串从pos位置开始的n个字符装到sub串中 
	int i=pos,j; 
	for( j=0 ; i<=pos+n-1;i++,j++){
		
		sub[j]=a[i];
	} 
	sub[j]='\0';
	
}
int search(char s[],char t[]){                                   //9 返回第一个子串t在主串s中的位置，不存在则返回-1
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
void replace (char s[],char v[],char t[]){                        //10 将主串s中所有不重叠的v用t置换 
	int i=search(s,v); int flag=0,j;
	int n1=udf_strlen(v),n2=udf_strlen(t);
	if(n1!=n2) printf("它们串长不相等，无法计算！！！\n"); 
	if(i==-1) printf("主串中没有该子串！！！\n"); 
	
	
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
		printf("第1号盘 %c——%c\n",A,C);
	}
	else{
		hannuo(n-1,A,C,B);
		printf("第%d号盘 %c——%c\n",n,A,C);
		hannuo(n-1,B,A,C);
	}	
}
void othermenu(){                                                      //11其他子菜单 
	printf("\n\n**    其他子菜单    **\n\n");
	printf("0——返回主菜单\n");
	printf("1——用逐一打印二维数组的办法以整型的方式打印目前数组\n");
	printf("2——用逐一打印二维数组的办法以字符型的方式打印目前数组\n");
	printf("3——印度神话——汉诺塔\n");
	printf("\n请选择：\n");
	int menu;
	scanf("%d",&menu);
	if(menu<0||menu>3){
		printf("越界！！！\n");
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
			printf("请输入你想要玩的汉诺塔的阶数（>=1）：\n");
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
		printf("\n                ************     字符串数组运算器     *************\n");
		printf("                  0——输入字符串          1——显示字符串\n");
	    printf("                  2——清空屏幕            3——求串长\n");
	    printf("                  4——串连接              5——串比较\n");
	    printf("                  6——串复制              7——串插入\n");
	    printf("                  8——求子串              9——串查找\n");
	    printf("                  10——串置换             11——其它\n");
	    printf("                  12——退出\n");
	    printf("\n                *********************************************\n\n");
	    printf("                  选择主菜单：\n");
	    printf("             （温馨提示：输入数字后按回车键才能生效哦！）       \n");
	    printf("             （温馨提示：输入越界数字或其它字符会返回主菜单哦!）\n");
		scanf("%d",&menu); 
		if(menu<0||menu>12) printf("亲，您输入的数字越界了哦！请重新输入\n") ;
		switch(menu){
			case 2:
				system("cls");  break;                                    //清屏 
		    case 0:{
		    	inputmenu();
				break;
			}
		    	
			case 1:{
				for(int i=0;i<=longitude-1;i++){
					printf("第%d行字符串为(用puts输出)：",i);
					puts(a[i]);
				}
				break;
			}
			case 3:{
				int length,i;
				printf("你想求第几行字符数组的串长？请输入：\n");
				scanf("%d",&i);
				length=udf_strlen(a[i]);
				printf("该行的串长为%d",length);
				break;   
			}
				
			case 4:{
				int i,j;
				printf("你想把第几行链接到第几行的后边？请分别输入，用空格隔开\n");
				scanf("%d%d",&i,&j);
			    udf_strcat(a[j],a[i]);
				break;
			} 
		    case 5:{
		    	int i,j;
		    	printf("你想比较第几行和第几行？请分别输入，用空格隔开？\n");
				scanf("%d%d",&i,&j); 
				printf("结果为：%d\n",udf_strcmp(a[i],a[j])   );
				break;
			}    
			case 6:{
				int i,j;
				printf("你想把第几行字符数组复制到第几行字符数组？请分别输入，用空格隔开\n");
				scanf("%d%d",&i,&j);
			    udf_strcpy(a[j],a[i]);                                    
				break;
			}
			case 7:  {
				int i,j,pos;
				printf("你想把第几行字符数组插入到第几行字符数组的哪个下标之前？请分别输入，用空格隔开\n");
				scanf("%d%d%d",&i,&j,&pos);
			    insert(a[j],pos,a[i]);   
				break;
			}
			case 8:{
				int i,n,pos;
				printf("你想求第几行字符数组从哪个下标开始装入多少字符到子串中？请分别输入，用空格隔开\n");
				scanf("%d%d%d",&i,&pos,&n);
				char sub[100];                              //?????野指针 
			    substring(a[i],pos,n,sub); 
			     PC;                
			    printf("子串为 %s",sub);                //加上*或[] 会怎么样？ 
				break;
			}
		    case 9:{
		    	int i,j;
		    	printf("你想在第几行字符数组种查找第几行字符数组？请分别输入，用空格隔开\n");
		    	scanf("%d%d",&i,&j);
		    	if   (search(a[i],a[j])==-1  ){
		    		printf("查无此串！！！\n");
				}
				else printf("子串在主串中下标为%d",search(a[i],a[j])  );
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


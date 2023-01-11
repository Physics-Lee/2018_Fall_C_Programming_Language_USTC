#include<stdio.h> 
#include<stdlib.h> 

#define PF printf	
#define NL "\n"
#define PN PF(NL) 
#define PC PF("CHEERS!\n")
#define SF scanf 
#define STS struct student 


STS{                                                                    //定义一个结构类型 
	int num;
	float score;
	STS *next;
}; 
STS *lianbiao;
//声明部分
STS *ascendinglistinsert(STS*head,STS*ps);
STS *searchlist(STS*head,int k );

 

//函数定义部分 
STS *makenode(int num,float score){                                //返回指针p 
	STS *p;
	p= (struct student *)   (  malloc(sizeof(STS)   )) ;
	p->num=num;
	p->score=score;
	p->next=NULL;
	return p;
} 
//1 制造 
STS *weicha(void){                                       //尾插法           返回头指针 
	STS *head;
	STS *rear;
	STS *p;
	int num;float score;
	head=NULL;rear=NULL; 
	for(;;){
		printf("输入一个学生学号(输入0时结束)：\n");
		scanf("%d",&num);
		if(num==0) break; 
		printf("输入一个学生成绩：\n");
		scanf("%f",&score);
		p=makenode(num,score);
		
		if(head==NULL) head=p;
		else rear->next=p;
		
		rear=p;
	} 
	if(rear!=NULL) rear->next=NULL;
	printf("尾插法建立链表结束！！！\n");
	return head;
}

STS *toucha(void){                                             //头插法         返回头指针 
	STS *head;  
	STS *p;
	head=NULL;
	for(int no=1;no!=0;head=p){
		p=(STS *)malloc(sizeof(STS));
		printf("输入一个学生学号：\n");
		scanf("%d",&p->num);
		printf("输入一个学生成绩：\n");
		scanf("%f",&p->score);
		p->next=head;
		
		printf("终止输入请输入0，继续输入请输入其它数字\n");
		scanf("%d",&no); 
	} 
	printf("头插法建立链表结束！！！\n");
	return head;
}

STS *createascendinglist(void){                                          //创造递增链表 
	STS *p=NULL,*head=NULL;
	int num;float score;
	for(;;){
		
		PF("请输入学号和成绩,输入的学号为0时结束\n");
		SF("%d %f",&num,&score);
		if(num==0) break;
		PC;
		p=makenode(num,score);
		PC;
		head=ascendinglistinsert(head,p);
		PC;
	}
	
	return head;
} 

void write(){
	FILE *fp;
	STS s;
	if(  (fp=fopen("linked_list","w")) ==NULL   ) {
		PF("打开失败！");
		exit(0);
	}
	while(1){
		PF("请输入学号和成绩，输入学号为0时结束\n");
		SF("%d%f",&s.num,&s.score);
		if(s.num==0) break;
		fprintf(fp,"%d %f\n",s.num,s.score);
	}
	fclose(fp);
}

void read(){
	FILE *fp;
	STS s;
	
	if( (fp=fopen("linked_list","r")) ==NULL  ) {
		printf("打开失败！！！\n");
		return;
	}
	while(1){
		fscanf(fp,"%d %f",&s.num,&s.score);
		
		if(feof(fp))  break;
		
		printf("%d        %f\n",s.num,s.score) ;
	}
	fclose(fp);
}

void zhuangru(){                                                        

	FILE *fp;

	fp=fopen("linked_list.txt","r");
	if(!fp) {
		printf("打开失败！！！\n");
		return ;
	}
	
	STS*p,*head=NULL;
	int num;float score;
	while(1){
		fscanf(fp,"%d   %f",&num,&score);
		if(feof(fp)) break;
		p=makenode(num,score);
		p->next=head;head=p;
	}

	lianbiao=head;	
}

void wenjian(){                                                         //文件子菜单 
	int menu;
	FILE*fp;
	while(1){
		PF("0——退出\n");
		PF("1——从键盘键入数据，写入文本文件\n");
		PF("2——从文本文件中读出数据,屏幕显示\n");
		PF("3——清空文本文件\n");
		PF("4——讲文本文件装入已存在的链表中\n");
		PF("请选择：\n");
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
				fp=fopen("linked_list.txt","w");
				fclose(fp);
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
//3 插入 
STS *insert(STS* head,int i){                                    //按照位次插入 
		STS *p,*q;
	int j;
	if(head==NULL) {
	PF("链表目前为空哦！！！\n"); return head; 
	}
	if(i==1){
		int num;float score;
		printf("输入一个学生学号(输入0时结束)：\n");
		scanf("%d",&num); 
		printf("输入一个学生成绩：\n");
		scanf("%f",&score);
		p=makenode(num,score);
		p->next=head;head=p;
	}
	else{
		for(q=p=head,j=1;p!=NULL&&j<=i-1;j++){
		  q=p;	p=p->next;                                    //如果p指向最后一个结点，p->next==NULL ，封NULL 
		}
		if(p!=NULL){
		   STS*ps;
		    
		   int num;float score;
		   printf("输入一个学生学号(输入0时结束)：\n");
		   scanf("%d",&num); 
		   printf("输入一个学生成绩：\n");
		   scanf("%f",&score);
		   ps=makenode(num,score);
		   q->next=ps;ps->next=p;
		}
		
		if(p!=head&&p->next==NULL){
		    printf("亲，你输入的位次超界了！"); 
		}
	}
	return head;
} 
STS *ascendinglistinsert(STS*head,STS*ps){                                //在递增链表中插入一个结点    两个指针同时跑 
	if(head==NULL||ps->num<=head->num){
		ps->next=head;
		head=ps;
		return head;
	//	ps=NULL;
	}
	STS *p=head,*q=head;
	for(   ; p!=NULL &&  p->num<=ps->num  ;    ){
		q=p;         p=p->next; 
	}
	q->next=ps;ps->next=p;                                   //插入 
	
	return head;
} 

//4 删除 
STS *mydelete(STS *head,int i){                               //4删除第i位 
	STS *p,*q;
	int j;
	if(head==NULL) {
	PF("链表目前为空哦！！！\n"); return head; 
	}
	if(i==1){
		p=head;head=head->next;
		free(p);
	}
	else{
		for(p=head,j=1;p->next&&j<=i-2;j++){                         //这是p是前驱节点 
		    if(p!=head&&p!=NULL&&p->next==NULL){
		    printf("亲，你输入的位次超界了！"); 
		    }
			p=p->next;                                    //如果p指向最后一个结点，p->next==NULL ，给链表封NULL 
		}
		if(p->next!=NULL){
			q=p->next;p->next=q->next;
			free(q) ;
		}
		
	
	}
	return head;
} 
STS *mydelete2(STS *head, int num){                         //按照学号删除 
	STS *p,*p1;
	p=searchlist(head,num);
	PC;
	if(p==NULL) {
		printf("未找到该学生！！！\n");
		return head;
		
	}
	else if(p==head){
		head=head->next;free(p); 
	}
	else{
		for(p1=head;p1->next!=p;p1=p1->next);
	    p1->next=p->next;
		free(p);
		
	}
	return head; 
}
//5 查找 
STS *searchlist(STS*head,int k ){                                               //5查找  返回指向该学号的指针。 
    STS *p=head; 
    for(;p!=NULL;p=p->next){
    	if(p->num==k) break;
	}
	if(p==NULL) printf("未找到该学号的学生！！！\n");
	return p;
}
//6 统计 
void tongji(STS*head,double *pmin,double *pmax,double *paver,int *pbukao){         //5种统计量 
	STS*p=head;
	double sum=0;int flag=0; 
	
	for(;p!=NULL;){
		*pmin=*pmax=head->score;
		sum+=p->score; flag++;
		if(p->score<*pmin) *pmin=p->score;
		if(p->score>*pmax) *pmax=p->score;
		if(p->score<60) ++*pbukao;
		p=p->next;
	}  
	
    if(head==NULL){
     	*paver=0;
	}                                               	
	else *paver=sum/flag;	
}  
//9 其它 
STS*sortlist(STS*head){                                                 //选择排序    降序 从大到小                                  
	STS* i,*j,*max;
	i=j=max=NULL;
	
	for(i=head;i!=NULL;i=i->next){
		max=i;
		for(j=i;j!=NULL;j=j->next){
			if(j->score   >     max->score) max=j;                       // 记录最大下标的位置 
		}
		if(max!=i){
			int nt;float st;
			
			st=i->score;i->score=max->score;max->score=st;
			nt=i->num;i->num=max->num;max->num=nt;
		}
	}
	return head;
}
STS*bubblesortlist(STS*head){                                           //冒泡排序     降序 从大到小 
	STS*i,*j;
	int flag=0;
	for(i=head;     i->next!=NULL;    i=i->next){
		for(j=i;       j->next!=NULL;      j=j->next){
			flag=0; 
			if(j->next->score   <   j->score) {                          
				int nt;float st;
			    st=j->score;j->score=j->next->score;j->next->score=st;
			    nt=j->num;j->num=j->next->num;j->next->num=nt;
			    flag=1;
			}
		}
		if(flag==0) return head;
	} 
	return head;
} 




//子菜单部分 
void createmenu(){                                             //1创建链表子菜单 
	printf("\n\n**    创建学生记录链表子菜单    **\n\n");
	printf("0——返回主菜单\n");
	printf("1——头插法\n");
	printf("2——尾插法\n");
	printf("3——有序插\n");
	printf("4——从文本文件（.txt或.cpp）中读入学生记录\n"); 
	printf("\n请选择：\n");
	int menu;
	SF("%d",&menu);
	if(menu<0||menu>4) {
		return ;
	}
	switch(menu){
		case 0: return;
		case 1: {
			lianbiao=toucha();
			break;
		}
		case 2:{
			lianbiao=weicha();
			break;
		}
		case 3:{
			lianbiao=createascendinglist();
			break;
		}
		case 4:{
			wenjian();
			break;
		}
	} 
	
	
} 
void printlist(STS *head){                                     //2遍历链表来打印链表   
	STS *p=head;
	for(;p!=NULL;p=p->next){
		printf("学生%d        成绩为%-+#8.2f\n",p->num,p->score);
		
	}
} 
void insertnodemenu(){                                             //3插入结点 
	printf("\n\n**    插入节点子菜单    **\n\n");
	printf("1——按位次顺序插入      2——按学号升序插入\n");
	printf("请选择：\n");
	int menu;
	SF("%d",&menu);
	switch(menu){
		case 1:{
			int i;
			printf("输入你想插入的位次。");
			scanf("%d",&i);
			lianbiao=insert(lianbiao,i);
			break;
		}
		case 2:{
			int n;float s;
			PF("亲，请输入你想插入的学生的学号和成绩\n");
			SF("%d%f",&n,&s);
			STS *p=makenode(n,s);
			lianbiao=ascendinglistinsert(lianbiao,p);
			PF("插入已完成！！！");
			break;
		}
	}
} 

void deletenodemenu(){                                                           //4删除结点子菜单 
	printf("\n\n**    删除节点子菜单    **\n\n");
	printf("1——删除某一位次      2——删除某一学号\n");
	printf("请选择：\n");
	int menu;
	SF("%d",&menu);
	switch(menu){
	    case 1:{
	    	int i;
	    	PF("亲，请输入你想删除的位次\n");
	    	SF("%d",&i);
	    	lianbiao=mydelete(lianbiao,i);
	    	
			break;
		}
		case 2:{
			printf("亲，请输入你想删除的学号\n");
			int num;
			scanf("%d",&num); 
			lianbiao=mydelete2(lianbiao,num);
			 
			break;
		}
	}     
} 

int renshu(STS*head){                                                            //6统计人数 
	STS*p=head;
	int flag=0;
	for(;p!=NULL ;){
		flag++;
		p=p->next;
	} 
	return(flag);
} 

void tongjimenu(){                                                       //7统计其它数字特征  
	int bukao=0,*pbukao=&bukao;
	double min=0.0,max=0.0,*pmin=&min,*pmax=&max;
	double aver,*paver=&aver;
	tongji(lianbiao,pmin,pmax,paver,pbukao);
	printf("平均成绩%4lf 最高分%4lf 最低分%4lf 不及格人数%d\n",*paver,*pmax,*pmin,*pbukao); 
}

void xiaohui(STS*head){                                             //8销毁链表 
     STS*p=head,*q=head;
     lianbiao=NULL;
	 for(; p!=NULL;){
	 	q=p;
	 	p=p->next;
	 	free(q);
	 }	
}

typedef struct node{
		int n;
		struct node *next;
	}Node;
Node* Make(int n){
		Node *head,*p;
		int i;
		head=p=(Node *)malloc(sizeof(Node));
		head->n=1;
		for(i=2;i<=n;i++){
			p->next=(Node *)malloc(sizeof(Node));
			p=p->next; p->n=i; 
		}
		p->next=head;
		return head;
	}
void yuesefuhuan(){
		Node *head,*p,*pre; 
		int m,n;
		printf("输入人数和报数："); 
		scanf("%d%d",&n,&m);
		head=Make(n);
		for(p=head;p->next!=p;){
			for(int i=1;i<m;i++){
				pre=p;p=p->next;
			}
			pre->next=p->next;
			free(p); // free(p) means this person is dead
			
			p=pre->next;
		}
		PF("最后一个人是：%d\n",p->n);
	}

void othermenu(){                                             //9 其他子菜单 
	int menu;  
	printf("\n\n**    其他功能    **\n\n");
	PF("****更多功能正在开发之中，敬请期待****\n\n") ; 
	printf("0--返回主菜单\n");
	printf("1--约瑟夫环\n");
	printf("2--对链表选择排序\n");
	printf("3--对链表冒泡排序\n");
	printf("\n请选择：");
	scanf("%d",&menu);
	switch(menu){
		case 1:{
			yuesefuhuan();
			break;
		}
		case 2:{
			lianbiao=sortlist(lianbiao);
			break;
		}
		case 3:{
			lianbiao=bubblesortlist(lianbiao);
			break;
		} 
	}
}










main(){
	int i,menu;
	for(;;){
		printf("\n                ************     字符串数组运算器     *************\n");
		printf("                  0——清屏                                1——创建学生记录链表\n");
	    printf("                  2——打印全部学生记录                    3——按学号或按位次插入一条新的学生记录\n");
	    printf("                  4——按学号或按位次删除一条学生记录      5——按学号查找一条学生记录\n");
	    printf("                  6——统计学生人数                        7——统计学生的平均成绩、最高分、不及格人数\n");
	    printf("                  8——销毁学生链表                        9——其他功能\n");
	    printf("                  10——退出\n");
	    printf("\n                *********************************************\n\n");
	    printf("                  选择主菜单：\n");
	    PF("             （温馨提示：输入数字后按回车键才能生效哦！）       \n");
	    PF("             （温馨提示：输入越界数字或其它字符会返回主菜单哦!）\n");
		scanf("%d",&menu); 
		if(menu<0||menu>10) {
		PF("亲，您输入的数字越界了哦！请重新输入\n") ;
		continue;
		}
		switch(menu){
			case 0:
				system("cls");  break;                                  //结束main 
		    case 1:
			    createmenu(); break;    
			case 2:
				printlist(lianbiao);break; 
			case 3:
				insertnodemenu();break;   
			case 4:
			    deletenodemenu();break;   
		    case 5:{
				
		    	int k;
		    	PF("亲，请输入你想要查找的学生的学号，我将帮你找到他的成绩\n");
		    	SF("%d",&k); 
				STS*p=searchlist(lianbiao,k);
				if(p==NULL) PF("未找到！！！");
				else PF("亲，该学生的成绩为%f",p->score); 
				break;  
				}     
			case 6:{
				int sum;
				sum=renshu(lianbiao);
				printf("总人数为%d\n",sum);
				break;
			}
			case 7:  
				tongjimenu();break;
			case 8:
				xiaohui(lianbiao);break;      
		    case 9:
		    	othermenu();break;           
			case 10:                    
				 return 0;
		    default:break; 
		}                    
		
		                                               // end switch 
    }                                                  //end for
}                           
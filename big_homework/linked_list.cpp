#include<stdio.h> 
#include<stdlib.h> 

#define PF printf	
#define NL "\n"
#define PN PF(NL) 
#define PC PF("CHEERS!\n")
#define SF scanf 
#define STS struct student 


STS{                                                                    //����һ���ṹ���� 
	int num;
	float score;
	STS *next;
}; 
STS *lianbiao;
//��������
STS *ascendinglistinsert(STS*head,STS*ps);
STS *searchlist(STS*head,int k );

 

//�������岿�� 
STS *makenode(int num,float score){                                //����ָ��p 
	STS *p;
	p= (struct student *)   (  malloc(sizeof(STS)   )) ;
	p->num=num;
	p->score=score;
	p->next=NULL;
	return p;
} 
//1 ���� 
STS *weicha(void){                                       //β�巨           ����ͷָ�� 
	STS *head;
	STS *rear;
	STS *p;
	int num;float score;
	head=NULL;rear=NULL; 
	for(;;){
		printf("����һ��ѧ��ѧ��(����0ʱ����)��\n");
		scanf("%d",&num);
		if(num==0) break; 
		printf("����һ��ѧ���ɼ���\n");
		scanf("%f",&score);
		p=makenode(num,score);
		
		if(head==NULL) head=p;
		else rear->next=p;
		
		rear=p;
	} 
	if(rear!=NULL) rear->next=NULL;
	printf("β�巨�����������������\n");
	return head;
}

STS *toucha(void){                                             //ͷ�巨         ����ͷָ�� 
	STS *head;  
	STS *p;
	head=NULL;
	for(int no=1;no!=0;head=p){
		p=(STS *)malloc(sizeof(STS));
		printf("����һ��ѧ��ѧ�ţ�\n");
		scanf("%d",&p->num);
		printf("����һ��ѧ���ɼ���\n");
		scanf("%f",&p->score);
		p->next=head;
		
		printf("��ֹ����������0������������������������\n");
		scanf("%d",&no); 
	} 
	printf("ͷ�巨�����������������\n");
	return head;
}

STS *createascendinglist(void){                                          //����������� 
	STS *p=NULL,*head=NULL;
	int num;float score;
	for(;;){
		
		PF("������ѧ�źͳɼ�,�����ѧ��Ϊ0ʱ����\n");
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
		PF("��ʧ�ܣ�");
		exit(0);
	}
	while(1){
		PF("������ѧ�źͳɼ�������ѧ��Ϊ0ʱ����\n");
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
		printf("��ʧ�ܣ�����\n");
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
		printf("��ʧ�ܣ�����\n");
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

void wenjian(){                                                         //�ļ��Ӳ˵� 
	int menu;
	FILE*fp;
	while(1){
		PF("0�����˳�\n");
		PF("1�����Ӽ��̼������ݣ�д���ı��ļ�\n");
		PF("2�������ı��ļ��ж�������,��Ļ��ʾ\n");
		PF("3��������ı��ļ�\n");
		PF("4�������ı��ļ�װ���Ѵ��ڵ�������\n");
		PF("��ѡ��\n");
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
				printf("��װ�룡����\n\n\n");
				break;
			} 
		}
		return; 
	}
}
//3 ���� 
STS *insert(STS* head,int i){                                    //����λ�β��� 
		STS *p,*q;
	int j;
	if(head==NULL) {
	PF("����ĿǰΪ��Ŷ������\n"); return head; 
	}
	if(i==1){
		int num;float score;
		printf("����һ��ѧ��ѧ��(����0ʱ����)��\n");
		scanf("%d",&num); 
		printf("����һ��ѧ���ɼ���\n");
		scanf("%f",&score);
		p=makenode(num,score);
		p->next=head;head=p;
	}
	else{
		for(q=p=head,j=1;p!=NULL&&j<=i-1;j++){
		  q=p;	p=p->next;                                    //���pָ�����һ����㣬p->next==NULL ����NULL 
		}
		if(p!=NULL){
		   STS*ps;
		    
		   int num;float score;
		   printf("����һ��ѧ��ѧ��(����0ʱ����)��\n");
		   scanf("%d",&num); 
		   printf("����һ��ѧ���ɼ���\n");
		   scanf("%f",&score);
		   ps=makenode(num,score);
		   q->next=ps;ps->next=p;
		}
		
		if(p!=head&&p->next==NULL){
		    printf("�ף��������λ�γ����ˣ�"); 
		}
	}
	return head;
} 
STS *ascendinglistinsert(STS*head,STS*ps){                                //�ڵ��������в���һ�����    ����ָ��ͬʱ�� 
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
	q->next=ps;ps->next=p;                                   //���� 
	
	return head;
} 

//4 ɾ�� 
STS *mydelete(STS *head,int i){                               //4ɾ����iλ 
	STS *p,*q;
	int j;
	if(head==NULL) {
	PF("����ĿǰΪ��Ŷ������\n"); return head; 
	}
	if(i==1){
		p=head;head=head->next;
		free(p);
	}
	else{
		for(p=head,j=1;p->next&&j<=i-2;j++){                         //����p��ǰ���ڵ� 
		    if(p!=head&&p!=NULL&&p->next==NULL){
		    printf("�ף��������λ�γ����ˣ�"); 
		    }
			p=p->next;                                    //���pָ�����һ����㣬p->next==NULL ���������NULL 
		}
		if(p->next!=NULL){
			q=p->next;p->next=q->next;
			free(q) ;
		}
		
	
	}
	return head;
} 
STS *mydelete2(STS *head, int num){                         //����ѧ��ɾ�� 
	STS *p,*p1;
	p=searchlist(head,num);
	PC;
	if(p==NULL) {
		printf("δ�ҵ���ѧ��������\n");
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
//5 ���� 
STS *searchlist(STS*head,int k ){                                               //5����  ����ָ���ѧ�ŵ�ָ�롣 
    STS *p=head; 
    for(;p!=NULL;p=p->next){
    	if(p->num==k) break;
	}
	if(p==NULL) printf("δ�ҵ���ѧ�ŵ�ѧ��������\n");
	return p;
}
//6 ͳ�� 
void tongji(STS*head,double *pmin,double *pmax,double *paver,int *pbukao){         //5��ͳ���� 
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
//9 ���� 
STS*sortlist(STS*head){                                                 //ѡ������    ���� �Ӵ�С                                  
	STS* i,*j,*max;
	i=j=max=NULL;
	
	for(i=head;i!=NULL;i=i->next){
		max=i;
		for(j=i;j!=NULL;j=j->next){
			if(j->score   >     max->score) max=j;                       // ��¼����±��λ�� 
		}
		if(max!=i){
			int nt;float st;
			
			st=i->score;i->score=max->score;max->score=st;
			nt=i->num;i->num=max->num;max->num=nt;
		}
	}
	return head;
}
STS*bubblesortlist(STS*head){                                           //ð������     ���� �Ӵ�С 
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




//�Ӳ˵����� 
void createmenu(){                                             //1���������Ӳ˵� 
	printf("\n\n**    ����ѧ����¼�����Ӳ˵�    **\n\n");
	printf("0�����������˵�\n");
	printf("1����ͷ�巨\n");
	printf("2����β�巨\n");
	printf("3���������\n");
	printf("4�������ı��ļ���.txt��.cpp���ж���ѧ����¼\n"); 
	printf("\n��ѡ��\n");
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
void printlist(STS *head){                                     //2������������ӡ����   
	STS *p=head;
	for(;p!=NULL;p=p->next){
		printf("ѧ��%d        �ɼ�Ϊ%-+#8.2f\n",p->num,p->score);
		
	}
} 
void insertnodemenu(){                                             //3������ 
	printf("\n\n**    ����ڵ��Ӳ˵�    **\n\n");
	printf("1������λ��˳�����      2������ѧ���������\n");
	printf("��ѡ��\n");
	int menu;
	SF("%d",&menu);
	switch(menu){
		case 1:{
			int i;
			printf("������������λ�Ρ�");
			scanf("%d",&i);
			lianbiao=insert(lianbiao,i);
			break;
		}
		case 2:{
			int n;float s;
			PF("�ף���������������ѧ����ѧ�źͳɼ�\n");
			SF("%d%f",&n,&s);
			STS *p=makenode(n,s);
			lianbiao=ascendinglistinsert(lianbiao,p);
			PF("��������ɣ�����");
			break;
		}
	}
} 

void deletenodemenu(){                                                           //4ɾ������Ӳ˵� 
	printf("\n\n**    ɾ���ڵ��Ӳ˵�    **\n\n");
	printf("1����ɾ��ĳһλ��      2����ɾ��ĳһѧ��\n");
	printf("��ѡ��\n");
	int menu;
	SF("%d",&menu);
	switch(menu){
	    case 1:{
	    	int i;
	    	PF("�ף�����������ɾ����λ��\n");
	    	SF("%d",&i);
	    	lianbiao=mydelete(lianbiao,i);
	    	
			break;
		}
		case 2:{
			printf("�ף�����������ɾ����ѧ��\n");
			int num;
			scanf("%d",&num); 
			lianbiao=mydelete2(lianbiao,num);
			 
			break;
		}
	}     
} 

int renshu(STS*head){                                                            //6ͳ������ 
	STS*p=head;
	int flag=0;
	for(;p!=NULL ;){
		flag++;
		p=p->next;
	} 
	return(flag);
} 

void tongjimenu(){                                                       //7ͳ��������������  
	int bukao=0,*pbukao=&bukao;
	double min=0.0,max=0.0,*pmin=&min,*pmax=&max;
	double aver,*paver=&aver;
	tongji(lianbiao,pmin,pmax,paver,pbukao);
	printf("ƽ���ɼ�%4lf ��߷�%4lf ��ͷ�%4lf ����������%d\n",*paver,*pmax,*pmin,*pbukao); 
}

void xiaohui(STS*head){                                             //8�������� 
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
		printf("���������ͱ�����"); 
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
		PF("���һ�����ǣ�%d\n",p->n);
	}

void othermenu(){                                             //9 �����Ӳ˵� 
	int menu;  
	printf("\n\n**    ��������    **\n\n");
	PF("****���๦�����ڿ���֮�У������ڴ�****\n\n") ; 
	printf("0--�������˵�\n");
	printf("1--Լɪ��\n");
	printf("2--������ѡ������\n");
	printf("3--������ð������\n");
	printf("\n��ѡ��");
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
		printf("\n                ************     �ַ�������������     *************\n");
		printf("                  0��������                                1��������ѧ����¼����\n");
	    printf("                  2������ӡȫ��ѧ����¼                    3������ѧ�Ż�λ�β���һ���µ�ѧ����¼\n");
	    printf("                  4������ѧ�Ż�λ��ɾ��һ��ѧ����¼      5������ѧ�Ų���һ��ѧ����¼\n");
	    printf("                  6����ͳ��ѧ������                        7����ͳ��ѧ����ƽ���ɼ�����߷֡�����������\n");
	    printf("                  8��������ѧ������                        9������������\n");
	    printf("                  10�����˳�\n");
	    printf("\n                *********************************************\n\n");
	    printf("                  ѡ�����˵���\n");
	    PF("             ����ܰ��ʾ���������ֺ󰴻س���������ЧŶ����       \n");
	    PF("             ����ܰ��ʾ������Խ�����ֻ������ַ��᷵�����˵�Ŷ!��\n");
		scanf("%d",&menu); 
		if(menu<0||menu>10) {
		PF("�ף������������Խ����Ŷ������������\n") ;
		continue;
		}
		switch(menu){
			case 0:
				system("cls");  break;                                  //����main 
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
		    	PF("�ף�����������Ҫ���ҵ�ѧ����ѧ�ţ��ҽ������ҵ����ĳɼ�\n");
		    	SF("%d",&k); 
				STS*p=searchlist(lianbiao,k);
				if(p==NULL) PF("δ�ҵ�������");
				else PF("�ף���ѧ���ĳɼ�Ϊ%f",p->score); 
				break;  
				}     
			case 6:{
				int sum;
				sum=renshu(lianbiao);
				printf("������Ϊ%d\n",sum);
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
#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct{                                  
   char num[15];/*ѧ��*/
   char name[10];/*����*/
   char gender[3];/*�Ա�*/
   int  score;/*�ɼ�*/
}DataType;

typedef struct LNode              
{
   DataType data;
   struct LNode  *next;
}LNode, *LinkList;

int menu_select()
{
	int sn;
	printf("\n           ѧ����Ϣ����ϵͳ\n");
	printf("=========================================\n");
	printf("        1.ѧ����Ϣ���Ա�Ľ���\n");
	printf("        2.�� �� ѧ �� ��  Ϣ\n");
	printf("        3.�� ѯ ѧ �� ��  Ϣ\n");
	printf("        4.ɾ �� ѧ �� ��  Ϣ\n");
	printf("        5.�� �� ����ѧ����Ϣ\n");
	printf("        0.�� �� �� �� ϵ  ͳ\n");
	printf("==========================================\n");
	printf("��ѡ��0-5:\n");
	for(;;)
	{
		fflush(stdin);
		scanf("%d",&sn);
		if (sn<0 || sn>5)
		   printf("\n\t���������ѡ0-5\n");
		else
		   break;
	}
	return sn;
}

void createList( LinkList L)
{
	int n,i;
    LNode *p;
	printf("�м�λѧ���������룺\n");
	fflush(stdin);
	scanf("%d",&n);
	printf("������������%dλѧ������Ϣ��\n",n);
	for(i=n;i>0;--i)
	{
	   printf("��%dλѧ����",i);
	   printf("\nѧ�ţ�15��  ������10�� �Ա�  �ɼ�\n");
	   fflush(stdin);
	   p=(LinkList)malloc(sizeof(LNode));
	   scanf("%s%s%s%d",p->data.num,p->data.name,p->data.gender,&p->data.score);
	   p->next=L->next;
	   L->next=p;
	}	
}

void printList(LinkList L)
{
	int i=1;
    LNode *p;
	if(L->next==NULL)
	{
		printf("��ǰ��Ϣ��Ϊ�գ����Ƚ�����Ϣ��\n");
	    return ;
	}
    printf("**************************************\n");
    printf("�������ѧ����Ϣ\n");
    printf("**************************************\n");
	printf("\nѧ�ţ�15��  ������10�� �Ա�  �ɼ�\n");
	printf("-------------------------------------------\n"); 
	p=L->next;
    while(p->next!=NULL)
	{ 
	   printf("��%dλѧ����",i);
	   printf("%s,%s,%s,%d\n",p->data.num,p->data.name,p->data.gender,p->data.score);
	   p=p->next; i++;
	   printf("------------------------------------------------------------------\n");
	}
}

int insert(LinkList L,DataType *student,int i)
{
	int j=0;
	LNode *p;
	p=L;
    while(p&&j<i-1)
	{
		p=p->next;++j;
	}
	if(!p||j>i-1)
	{
	   return 0;
	}
	LNode *s;
    s=(LinkList)malloc(sizeof(LNode));
	strcpy(s->data.num,student->num);
	strcpy(s->data.name,student->name);
	strcpy(s->data.gender,student->gender);
	s->data.score=student->score;
	s->next=p->next;
	p->next=s;
}

LNode* findList(LinkList L)
{   
	LNode *q;
    q=NULL;
   	char num[15];
	char name[10];
	int n ;
	printf("===========================\n");
	printf("1����ѧ�Ų�ѯ\n");
	printf("2����������ѯ\n");
	printf("===========================\n");
	printf("      ��ѡ��               ");
	fflush(stdin);
	scanf("%d",&n);
	if (n==1)
	{
	  printf("������Ҫ����ѧ����ѧ�ţ�");
	  scanf("%s",num);
	  q=L->next;
	  while(strcmp(q->data.num,num)!=0)
	  { 
		 q=q->next;
	     if(q==NULL)
		 break;
	  }
	}
		
	else if (n==2)
	{
	  q=L->next;
	  printf("������Ҫ����ѧ����������");
	  scanf("%s",name);
	 while(strcmp(q->data.name,name)!=0)
	  { 
		  q=q->next;
	      if(q==NULL)
		  break;
	  }
	}
	return q;
	

}

void delNode(LinkList L)
{
	LNode *p;
	LNode *q;
    LNode *m;
    if(L->next==NULL)
	{
		printf("��ǰ��Ϣ��Ϊ�գ����Ƚ�����Ϣ��\n");
	    return ;
	}
    printf("**************************************\n");
    printf("ɾ��ѧ����Ϣ\n");
    printf("**************************************\n");
	printf("���Ȳ�����Ҫɾ����ѧ����Ϣ��\n");
	m=findList(L);
	if(m==NULL)
	{
	  printf("û�в鵽Ҫɾ����ѧ����Ϣ");
	  return;
	}
	if(m==L->next)
	{
		L->next=NULL;
		printf("��ѧ����Ϣ�ѱ�ɾ����\n");
        return ;
	}
    p=L->next;
	while(p->next!=m)
	{  
		p=p->next;
	}
	q=p->next;
    p->next=q->next;
	printf("��ѧ����Ϣ�ѱ�ɾ����\n");
}

void main()
{
  LinkList L;
  L=(LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  DataType *student;
  int i;

  while(1){
  switch(menu_select())
  {
     case 1:
        printf("**************************************\n");
        printf("         ѧ����Ϣ���Ա�Ľ���            \n");
        printf("***************************************\n");
        createList(L);
        break;
     case 2:
        printf("**************************************\n");
        printf("���ѧ����Ϣ\n");
        printf("������Ҫ��ӵ�ѧ����Ϣ��\n");
	    printf("\nѧ�ţ�15��  ������10�� �Ա�  �ɼ�\n");
        printf("**************************************\n");
        student=(DataType *)malloc(sizeof(DataType));
        fflush(stdin);
        scanf("%s%s%s%d",student->num,student->name,student->gender,&student->score);
        printf("������Ҫ�����λ�ã�\n");
        fflush(stdin);
        scanf("%d",&i);
        insert(L,student,i);        
        break;
     case 3:
        if(L->next==NULL)
		{
			printf("��ǰ��Ϣ��Ϊ�գ����Ƚ�����Ϣ��\n");
	        break ;
		}
        printf("**************************************\n");
        printf("��ѯѧ����Ϣ\n");
        printf("**************************************\n");
        LNode *p;
		p=(LinkList)malloc(sizeof(LNode));
        p=findList(L);
        if(p!=NULL)
        {
			printf("��Ҫ���ѧ��Ϊ��\nѧ�ţ�15��  ������10�� �Ա�  �ɼ�\n");
	        printf("-------------------------------------------\n");
 	        printf("%s,%s,%s,%d\n",p->data.num,p->data.name,p->data.gender,p->data.score);
	        printf("------------------------------------------------------------------\n");          
        }
        else
        printf("û����Ҫ��ѯ��ѧ����Ϣ��");
        break;
     case 4:
        delNode(L);        
        break;
     case 5:
        printList(L);
        break;
     case 0:
	    printf("�ټ���\n");
        return ;
  }
}
}
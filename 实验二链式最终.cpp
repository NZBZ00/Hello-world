#include <stdio.h>
#include <string.h>
#include<stdlib.h>


typedef struct{                                  
   char num[15];/*学号*/
   char name[10];/*姓名*/
   char gender[3];/*性别*/
   int  score;/*成绩*/
}DataType;

typedef struct LNode              
{
   DataType data;
   struct LNode  *next;
}LNode, *LinkList;

int menu_select()
{
	int sn;
	printf("\n           学生信息管理系统\n");
	printf("=========================================\n");
	printf("        1.学生信息线性表的建立\n");
	printf("        2.插 入 学 生 信  息\n");
	printf("        3.查 询 学 生 信  息\n");
	printf("        4.删 除 学 生 信  息\n");
	printf("        5.输 出 所有学生信息\n");
	printf("        0.退 出 管 理 系  统\n");
	printf("==========================================\n");
	printf("请选择0-5:\n");
	for(;;)
	{
		fflush(stdin);
		scanf("%d",&sn);
		if (sn<0 || sn>5)
		   printf("\n\t输入错误，重选0-5\n");
		else
		   break;
	}
	return sn;
}

void createList( LinkList L)
{
	int n,i;
    LNode *p;
	printf("有几位学生？请输入：\n");
	fflush(stdin);
	scanf("%d",&n);
	printf("以下请输入这%d位学生的信息：\n",n);
	for(i=n;i>0;--i)
	{
	   printf("第%d位学生：",i);
	   printf("\n学号（15）  姓名（10） 性别  成绩\n");
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
		printf("当前信息表为空，请先建立信息表\n");
	    return ;
	}
    printf("**************************************\n");
    printf("输出所有学生信息\n");
    printf("**************************************\n");
	printf("\n学号（15）  姓名（10） 性别  成绩\n");
	printf("-------------------------------------------\n"); 
	p=L->next;
    while(p->next!=NULL)
	{ 
	   printf("第%d位学生：",i);
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
	printf("1、按学号查询\n");
	printf("2、按姓名查询\n");
	printf("===========================\n");
	printf("      请选择：               ");
	fflush(stdin);
	scanf("%d",&n);
	if (n==1)
	{
	  printf("请输入要查找学生的学号：");
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
	  printf("请输入要查找学生的姓名：");
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
		printf("当前信息表为空，请先建立信息表\n");
	    return ;
	}
    printf("**************************************\n");
    printf("删除学生信息\n");
    printf("**************************************\n");
	printf("请先查找您要删除的学生信息：\n");
	m=findList(L);
	if(m==NULL)
	{
	  printf("没有查到要删除的学生信息");
	  return;
	}
	if(m==L->next)
	{
		L->next=NULL;
		printf("该学生信息已被删除！\n");
        return ;
	}
    p=L->next;
	while(p->next!=m)
	{  
		p=p->next;
	}
	q=p->next;
    p->next=q->next;
	printf("该学生信息已被删除！\n");
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
        printf("         学生信息线性表的建立            \n");
        printf("***************************************\n");
        createList(L);
        break;
     case 2:
        printf("**************************************\n");
        printf("添加学生信息\n");
        printf("请输入要添加的学生信息：\n");
	    printf("\n学号（15）  姓名（10） 性别  成绩\n");
        printf("**************************************\n");
        student=(DataType *)malloc(sizeof(DataType));
        fflush(stdin);
        scanf("%s%s%s%d",student->num,student->name,student->gender,&student->score);
        printf("请输入要插入的位置：\n");
        fflush(stdin);
        scanf("%d",&i);
        insert(L,student,i);        
        break;
     case 3:
        if(L->next==NULL)
		{
			printf("当前信息表为空，请先建立信息表\n");
	        break ;
		}
        printf("**************************************\n");
        printf("查询学生信息\n");
        printf("**************************************\n");
        LNode *p;
		p=(LinkList)malloc(sizeof(LNode));
        p=findList(L);
        if(p!=NULL)
        {
			printf("您要查的学生为：\n学号（15）  姓名（10） 性别  成绩\n");
	        printf("-------------------------------------------\n");
 	        printf("%s,%s,%s,%d\n",p->data.num,p->data.name,p->data.gender,p->data.score);
	        printf("------------------------------------------------------------------\n");          
        }
        else
        printf("没有您要查询的学生信息！");
        break;
     case 4:
        delNode(L);        
        break;
     case 5:
        printList(L);
        break;
     case 0:
	    printf("再见！\n");
        return ;
  }
}
}
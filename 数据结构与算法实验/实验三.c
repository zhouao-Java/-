#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 0
#define NUM 1000
typedef struct book
{
	char Bname[100];//书名
	char Aname[20];//作者名
	int code;//书的编码
	float price;//书的价格
	int num;//书的号码
	struct book *next;//链式结构中的指针域
}book, *LinkList;

void luru(LinkList L,int n)//录入一个长度为i的链表;
{
	int i;
	LinkList p,r;
	L->next=NULL;
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(book));
		printf("请输入要录入的书名:\n");
		scanf("%s",&p->Bname);
		printf("请输入要录入的作者名:\n");
		scanf("%s",&p->Aname);
		printf("请输入要录入的书的编码:\n");
		scanf("%d",&p->code);
		printf("请输入要录入的书的价格:\n");
		scanf("%f",&p->price);
		printf("请输入要录入的书的号码:\n");
		scanf("%d",&p->num);
		p->next=NULL;r->next=p;
		r=p;
	}
}
void bianli(LinkList L)//显示所录入的数据
{
	LinkList p;
	for(p=L->next;p!=NULL;p=p->next)
	{
		printf("书名:%s\t",p->Bname);
		printf("作者名:%s\t",p->Aname);
		printf("书的编码:%d\t",p->code);
		printf("书的价格:%f\t",p->price);
		printf("书的号码:%d\t\n",p->num);
	}
}
void LocateElem(LinkList L,char* r)//根据书名进行查找
{
	int i=0;
	LinkList p;
	for(p=L->next;p!=NULL;p=p->next)
	{
		i++;
		if(strcmp(p->Bname,r)==0)
		{
			printf("你所查找的书是第%d个.\n",i);break;
		}
	}
	if(p==NULL)
		printf("未找到你所需查找的书.\n");
}

void ListInsert(LinkList L,int i)//插入一个新元素
{
	LinkList p=L,s;
	int j=0;
	while(p && (j<i-1))
	{
		p=p->next ;
		++j;
	}
	if(!p||j>i-1)
	{
		printf ("插入位置出错!\n");
		return ;
	}
		s=(LinkList)malloc(sizeof(book));
		printf("请输入要录入的书名:\n");
		scanf("%s",&s->Bname);
		printf("请输入要录入的作者名:\n");
		scanf("%s",&s->Aname);
		printf("请输入要录入的书的编码:\n");
		scanf("%d",&s->code);
		printf("请输入要录入的书的价格:\n");
		scanf("%f",&s->price);
		printf("请输入要录入的书的号码:\n");
		scanf("%d",&s->num);
		s->next =p->next;
		p->next=s;
}

void delet(LinkList L,int i)
{
	LinkList p=L,q;
	int j=0,n;
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1))
	{
		printf("删除位置出错!\n");
		printf("请输入要删除的位置:\n");
		scanf("%d",&n);
		delet(L,n);
	}
		q=p->next;
		p->next=q->next;
		free(q);
		printf("删除成功!\n");
}

void main()
{
	int i,n;
	LinkList L;
	char s[10];
	L=(LinkList)malloc(sizeof(book));
	printf("请输入你需要录入的书本的个数:\n");
	scanf("%d",&i);
	luru(L,i);
	system("cls");
	bianli(L);
	system("pause");
	system("cls");
	printf("请输入你要查找的书名:\n");
	gets(s);
	gets(s);
	system("cls");
	LocateElem(L,s);
	printf("请输入要插入的位置：\n");
	scanf("%d",&n);
	ListInsert(L,n);
	bianli(L);
	system("cls");
	printf("请输入要删除的位置:\n");
	scanf("%d",&n);
	delet(L,n);
	bianli(L);
	system("pause");

}

		
		
	
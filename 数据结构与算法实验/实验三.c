#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 0
#define NUM 1000
typedef struct book
{
	char Bname[100];//����
	char Aname[20];//������
	int code;//��ı���
	float price;//��ļ۸�
	int num;//��ĺ���
	struct book *next;//��ʽ�ṹ�е�ָ����
}book, *LinkList;

void luru(LinkList L,int n)//¼��һ������Ϊi������;
{
	int i;
	LinkList p,r;
	L->next=NULL;
	r=L;
	for(i=0;i<n;i++)
	{
		p=(LinkList)malloc(sizeof(book));
		printf("������Ҫ¼�������:\n");
		scanf("%s",&p->Bname);
		printf("������Ҫ¼���������:\n");
		scanf("%s",&p->Aname);
		printf("������Ҫ¼�����ı���:\n");
		scanf("%d",&p->code);
		printf("������Ҫ¼�����ļ۸�:\n");
		scanf("%f",&p->price);
		printf("������Ҫ¼�����ĺ���:\n");
		scanf("%d",&p->num);
		p->next=NULL;r->next=p;
		r=p;
	}
}
void bianli(LinkList L)//��ʾ��¼�������
{
	LinkList p;
	for(p=L->next;p!=NULL;p=p->next)
	{
		printf("����:%s\t",p->Bname);
		printf("������:%s\t",p->Aname);
		printf("��ı���:%d\t",p->code);
		printf("��ļ۸�:%f\t",p->price);
		printf("��ĺ���:%d\t\n",p->num);
	}
}
void LocateElem(LinkList L,char* r)//�����������в���
{
	int i=0;
	LinkList p;
	for(p=L->next;p!=NULL;p=p->next)
	{
		i++;
		if(strcmp(p->Bname,r)==0)
		{
			printf("�������ҵ����ǵ�%d��.\n",i);break;
		}
	}
	if(p==NULL)
		printf("δ�ҵ���������ҵ���.\n");
}

void ListInsert(LinkList L,int i)//����һ����Ԫ��
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
		printf ("����λ�ó���!\n");
		return ;
	}
		s=(LinkList)malloc(sizeof(book));
		printf("������Ҫ¼�������:\n");
		scanf("%s",&s->Bname);
		printf("������Ҫ¼���������:\n");
		scanf("%s",&s->Aname);
		printf("������Ҫ¼�����ı���:\n");
		scanf("%d",&s->code);
		printf("������Ҫ¼�����ļ۸�:\n");
		scanf("%f",&s->price);
		printf("������Ҫ¼�����ĺ���:\n");
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
		printf("ɾ��λ�ó���!\n");
		printf("������Ҫɾ����λ��:\n");
		scanf("%d",&n);
		delet(L,n);
	}
		q=p->next;
		p->next=q->next;
		free(q);
		printf("ɾ���ɹ�!\n");
}

void main()
{
	int i,n;
	LinkList L;
	char s[10];
	L=(LinkList)malloc(sizeof(book));
	printf("����������Ҫ¼����鱾�ĸ���:\n");
	scanf("%d",&i);
	luru(L,i);
	system("cls");
	bianli(L);
	system("pause");
	system("cls");
	printf("��������Ҫ���ҵ�����:\n");
	gets(s);
	gets(s);
	system("cls");
	LocateElem(L,s);
	printf("������Ҫ�����λ�ã�\n");
	scanf("%d",&n);
	ListInsert(L,n);
	bianli(L);
	system("cls");
	printf("������Ҫɾ����λ��:\n");
	scanf("%d",&n);
	delet(L,n);
	bianli(L);
	system("pause");

}

		
		
	
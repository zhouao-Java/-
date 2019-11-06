#include <stdio.h>
#include <stdlib.h>

typedef struct node //����������Ľ������
{
	char data;
	struct node  *lch;
	struct node  *rch;
}node, *bitree;
bitree CreatBiTree()//����������
{
	char ch;
	node *p;
	do{
		ch=getchar();
	}while(ch=='\n');
	if(ch=='#') return NULL;
	else
	{
		p=(node *) malloc(sizeof(node));
		p->data=ch;
		p->lch=CreatBiTree();
		p->rch=CreatBiTree();
		return (p);
	}
}
void PreOrder(bitree root)//�������������
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->lch);
		PreOrder(root->rch);
	}
}
void InOrder(bitree root)//�������������
{
	if(root!=NULL)
	{
		InOrder(root->lch);
		printf("%c",root->data);
		InOrder(root->rch);
	}
}
void PostOrder(bitree root)//�������������
{
	if(root!=NULL)
	{
		PostOrder(root->lch);
		PostOrder(root->rch);
		printf("%c",root->data);
	}
}
void main()
{
	bitree p;
	printf("�������������������չ����:\n");
	p=CreatBiTree();
	printf("\n�������������:");
	PreOrder(p);
	printf("\n�������������:");
	InOrder(p);
	printf("\n�������������:");
	PostOrder(p);
	printf("\n");
	system("pause");
}





		





 

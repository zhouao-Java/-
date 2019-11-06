#include <stdio.h>
#include <stdlib.h>

typedef struct node //定义二叉树的结点类型
{
	char data;
	struct node  *lch;
	struct node  *rch;
}node, *bitree;
bitree CreatBiTree()//创建二叉树
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
void PreOrder(bitree root)//先序遍历二叉树
{
	if(root!=NULL)
	{
		printf("%c",root->data);
		PreOrder(root->lch);
		PreOrder(root->rch);
	}
}
void InOrder(bitree root)//中序遍历二叉树
{
	if(root!=NULL)
	{
		InOrder(root->lch);
		printf("%c",root->data);
		InOrder(root->rch);
	}
}
void PostOrder(bitree root)//后序遍历二叉树
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
	printf("请输入二叉树的无序扩展序列:\n");
	p=CreatBiTree();
	printf("\n先序遍历二叉树:");
	PreOrder(p);
	printf("\n中序遍历二叉树:");
	InOrder(p);
	printf("\n后序遍历二叉树:");
	PostOrder(p);
	printf("\n");
	system("pause");
}





		





 

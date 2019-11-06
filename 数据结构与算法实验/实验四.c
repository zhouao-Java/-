#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;//����ջ�Ľṹ��

SqStack InitStack(SqStack s)//��ʼ��ջ
{
	s.base=(int *)malloc(N);
	if(!s.base) exit(0);
	s.top=s.base;
	s.stacksize=N;//��Ϊջ���������
	return s;	
}

SqStack Push(SqStack s,int e)//��ջ
{
	if(s.top-s.base==s.stacksize)
	{
		printf("ջ��!\n");
		exit(0); 
	}
	*(++s.top)=e;
	return s;
} 

SqStack Pop(SqStack s)//��ջ
{
	for(;s.top!=s.base;)
	{
		if(*s.top>10)
			printf("%X",*s.top);
		else
			printf("%d",*s.top);
		s.top--;
	}
	return s; 
}


void main()
{
	int n,p;
	SqStack s;
	s=InitStack(s);//��ջ���г�ʼ��
	printf("����������n(ʮ����):\n");
	scanf("%d",&n);
	printf("������Ҫת���Ľ���p(��,��,ʮ������):\n");
	scanf("%d",&p);
	switch(p)
	{
		case 2:	while(n)
				{
					s=Push(s,n%2);//������ת��
					n/=2;
				}
				break;
		case 8:while(n)
				{
					s=Push(s,n%8);//�˽���ת��
					n/=8;
				}
				break;
		case 16:while(n)
				{
					s=Push(s,n%16);//ʮ������ת��
					n/=16;
				}
				break;
	}
	printf("ת�����%d����Ϊ��\n",p);
	Pop(s);
	printf("\n");
	system("pause");
}



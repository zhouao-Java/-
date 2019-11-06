#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;//定义栈的结构体

SqStack InitStack(SqStack s)//初始化栈
{
	s.base=(int *)malloc(N);
	if(!s.base) exit(0);
	s.top=s.base;
	s.stacksize=N;//置为栈的最大容量
	return s;	
}

SqStack Push(SqStack s,int e)//入栈
{
	if(s.top-s.base==s.stacksize)
	{
		printf("栈满!\n");
		exit(0); 
	}
	*(++s.top)=e;
	return s;
} 

SqStack Pop(SqStack s)//出栈
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
	s=InitStack(s);//对栈进行初始化
	printf("请输入数据n(十进制):\n");
	scanf("%d",&n);
	printf("请输入要转换的进制p(二,八,十六进制):\n");
	scanf("%d",&p);
	switch(p)
	{
		case 2:	while(n)
				{
					s=Push(s,n%2);//二进制转换
					n/=2;
				}
				break;
		case 8:while(n)
				{
					s=Push(s,n%8);//八进制转换
					n/=8;
				}
				break;
		case 16:while(n)
				{
					s=Push(s,n%16);//十六进制转换
					n/=16;
				}
				break;
	}
	printf("转换后的%d进制为：\n",p);
	Pop(s);
	printf("\n");
	system("pause");
}



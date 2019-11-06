#include <stdio.h>
#include<stdlib.h>
#define N 50
int m=10;
void hs1(int a[])//显示顺序表中的元素。
{
	int i;	
	printf("当前元素有%d个;分别为:",m);
	for(i=0;i<m;i++)
	{
		printf(" %d",a[i]);	
	}
	printf("\n");
	//system("pause");
} 

void hs2(int a[])//按照序号查找。
{
	int i;
	printf("\n\n请输入要查找的第i个元素[1,%d]：",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("第%d个位置不存在\n",i);
	}
	else
	{
		printf("第%d个是元素是：%d\n\t",i,a[i-1]);
	}
	system("pause");
}

void hs3(int a[])//按照元素查找。
{
	int i,n;
	printf("\n\n请输入要查找元素：");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("没有找到%d这个元素\n\t",n);
	else
		printf("找到%d这个元素，第%d个\n\t",n,i+1);
	system("pause");
} 

void hs4(int a[])//在顺序表中插入新的元素。
{
	int i,j,e;
	printf("\n");
	hs1(a);
	printf("\n请输入要插入的元素（还可以插入%d个)：",N-m);
	scanf("%d",&e);
	printf("插入的位置[1,%d]：",m+1);
	scanf("%d",&i);
	if(i>m+1||i<1)
	{
		printf("第%d个位置不存在\n",i);
	}
	else
	{
		for(j=m-1;j>=i-1;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=e;
		m++;
		printf("插入成功\n\t",i);		
	} 
	system("pause");
}

void hs5(int a[])//删除表中的元素。
{
	int i,j;
	printf("请输入要删除的第i个元素：");
	scanf("%d",&i);
	if(i>m)
	{
		printf("第%d个元素不存在\n",i);
	}
	else
	{
		for(j=i-1;j<m;j++)
		{
			a[j]=a[j+1];
		}
		a[j]=0;
		m--;
	}
	hs1(a);
}
int main()
{	
	int a[N]={1,2,3,4,5,6,7,8,9,10};
	hs1(a);
	hs2(a);
	hs3(a);
	hs4(a);
	hs1(a);
	hs5(a);
	return 0;
}

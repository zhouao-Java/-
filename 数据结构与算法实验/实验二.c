#include <stdio.h>
#include<stdlib.h>
#define N 50
int m=10;
void hs1(int a[])//��ʾ˳����е�Ԫ�ء�
{
	int i;	
	printf("��ǰԪ����%d��;�ֱ�Ϊ:",m);
	for(i=0;i<m;i++)
	{
		printf(" %d",a[i]);	
	}
	printf("\n");
	//system("pause");
} 

void hs2(int a[])//������Ų��ҡ�
{
	int i;
	printf("\n\n������Ҫ���ҵĵ�i��Ԫ��[1,%d]��",m);
	scanf("%d",&i);
	if(i>m)
	{
		printf("��%d��λ�ò�����\n",i);
	}
	else
	{
		printf("��%d����Ԫ���ǣ�%d\n\t",i,a[i-1]);
	}
	system("pause");
}

void hs3(int a[])//����Ԫ�ز��ҡ�
{
	int i,n;
	printf("\n\n������Ҫ����Ԫ�أ�");
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==m)
		printf("û���ҵ�%d���Ԫ��\n\t",n);
	else
		printf("�ҵ�%d���Ԫ�أ���%d��\n\t",n,i+1);
	system("pause");
} 

void hs4(int a[])//��˳����в����µ�Ԫ�ء�
{
	int i,j,e;
	printf("\n");
	hs1(a);
	printf("\n������Ҫ�����Ԫ�أ������Բ���%d��)��",N-m);
	scanf("%d",&e);
	printf("�����λ��[1,%d]��",m+1);
	scanf("%d",&i);
	if(i>m+1||i<1)
	{
		printf("��%d��λ�ò�����\n",i);
	}
	else
	{
		for(j=m-1;j>=i-1;j--)
		{
			a[j+1]=a[j];
		}
		a[j+1]=e;
		m++;
		printf("����ɹ�\n\t",i);		
	} 
	system("pause");
}

void hs5(int a[])//ɾ�����е�Ԫ�ء�
{
	int i,j;
	printf("������Ҫɾ���ĵ�i��Ԫ�أ�");
	scanf("%d",&i);
	if(i>m)
	{
		printf("��%d��Ԫ�ز�����\n",i);
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

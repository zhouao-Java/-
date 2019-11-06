#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int hs1(double a,double b,double c)
{
	int flag=0;
	if(a==0)
	{
		printf("该函数不属于二次函数，请重新输入。\n");
		flag=1;
	}
	return flag;
}
void hs2(double a,double b,double c)
{
	printf(" 该函数有两个实数根.");
	printf("x1=%.2lf，\nx2=%.2lf;\n",(-b+sqrt(b*b-4*a*c))/(2*a),(-b-sqrt(b*b-4*a*c))/(2*a)); 
}
void hs3(double a,double b,double c)
{
	printf("该函数有两个相等的实数根.");
	printf("x1=x2=%.2lf.",-b/(2*a));
}
void hs4(double a,double b,double c)
{
	double s=(4*a*c-b*b);
	double h=2*a;

	printf("该函数有两个复数根.");
	printf("x1=%.2lf+%.2lfi，\nx2=%.2lf-%.2lfi;\n",-b/h,sqrt(s/h),-b/h,sqrt(s/h)); 
}
int main()
{
	double a,b,c;
	printf("二次函数的参数:\n");
	scanf("%lf %lf %lf",&a,&b,&c);
	printf("所得的方程是：%.2lfx^2+%.2lfx+%.2lf=0\n",a,b,c);
	if(hs1(a,b,c)==0)
	{
		if(b*b-4*a*c>0)
			hs2(a,b,c);
		if(b*b-4*a*c==0)
			hs3(a,b,c);
		if(b*b-4*a*c<0)
			hs4(a,b,c);
	}
	return 0;
}


    

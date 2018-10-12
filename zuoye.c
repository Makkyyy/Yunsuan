#include<time.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void opration(void);
char fuhao(int i);
float jiafa(float a,float b);//加法
float jianfa(float a,float b);//减法
float chenfa(float a,float b);//乘法
float chufa(float a,float b);//除法
float jisuan(int i,float a,float b);
int f = 0;//记录错了几题
double cc;//正确率
int yunsuan()
{
	float answer1;
	float x,y,z;
	int a,b,c;
	int p,d;
	char q1,q2;
	srand((unsigned)time(NULL));//传入一个空指针
	do{
		a=rand()%100;//按照题目要求产生100以内的随机数
		b=rand()%100;//按照题目要求产生100以内的随机数
		c=rand()%100;//0和1是加减，2和3是乘除
		p=rand()%4;//四个运算符随机
		d=rand()%4;//四个运算符随机
		if(p>1){
			y=(float)a;
			z=(float)b;
			x=jisuan(p,y,z);//求出前半段问题的答案 比如3 + 1 + 2 中的：3+ 1
			y=x;
			z=(float)c;
			x=jisuan(d,y,z);//求出前半段问题答案加上后半段问题的答案
		}
		else
		{
			if(d<2)
			{
				y=(float)a;
			    z=(float)b;
			    x=jisuan(p,y,z);
			    y=x;
			    z=(float)c;
			    x=jisuan(d,y,z);
			}
			else
			{
				y=(float)b;
			    z=(float)c;
		    	x=jisuan(d,y,z);
			    y=(float)a;
			    z=x;
		    	x=jisuan(p,y,z);
			}
		}
	}while(x<0.0);
	q1=fuhao(p);
	q2=fuhao(d);
	printf("%d %c %d %c %d = ",a,q1,b,q2,c);//输出题目
	scanf("%f",&answer1);
	if(p==3&&d==3)//除法运算
	{
		if((answer1-x)<0.01)
		{
			printf("恭喜你，回答正确噢！\n");
		}
		else
		{
			f++;//错误的题数
			printf("很遗憾，你的答案是错误的，正确答案是：%.1f\n",x);
		}
	}
	else
	{
		if((x-answer1)<0.01)
		{
			printf("恭喜你，回答正确噢！\n");
		}
		else
		{
			f++;
			printf("很遗憾，你的答案是错误的，正确答案是：%.1f\n",x);
		}
	}
	return f;

}
float jisuan(int i,float a,float b)
{
	float x;
	switch(i)
	{
	case 0:
		x=jiafa(a,b);
		break;
	case 1:
		x=jianfa(a,b);
		break;
	case 2:
		x=chenfa(a,b);
		break;
	case 3:
		x=chufa(a,b);
		break;
	default:
		break;
	}
	return x;
}
float jiafa(float a,float b)
{
	float x;
	x=a+b;
	return x;
}
float jianfa(float a,float b)
{
	float x;
	x=a-b;
	return x;
}
float chenfa(float a,float b)
{
	float x;
	x=a*b;
	return x;
}
float chufa(float a,float b)
{
	float x;
	x=a/b;
	return x;
}
char fuhao(int i)//判断符号
{
	char op;
	switch(i)
	{
	case 0:
		op='+';
		break;
	case 1:
		op='-';
		break;
	case 2:
		op='*';
		break;
	default:
		op='/';
		break;
	}
	return op;
}
int main()
{
    printf("\t\t\t\t*运算系统*\n");
    printf("\t\t\t      制作人：麦家滢\n");
	int i=0,n;
	printf("*请输入计算题目的个数：");//输入题目个数
	scanf("%d",&n);
	do{
		yunsuan();//调用函数
		i++;
	}while(i<n);
		printf("你的正确率为%.1lf%%\n",1.0*(n-f) / n * 100);//输出正确率
	system("pause");//冻结屏幕，用户按任意键结束
}

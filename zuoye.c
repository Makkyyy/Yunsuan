#include<time.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void opration(void);
char fuhao(int i);
float jiafa(float a,float b);//�ӷ�
float jianfa(float a,float b);//����
float chenfa(float a,float b);//�˷�
float chufa(float a,float b);//����
float jisuan(int i,float a,float b);
int f = 0;//��¼���˼���
double cc;//��ȷ��
int yunsuan()
{
	float answer1;
	float x,y,z;
	int a,b,c;
	int p,d;
	char q1,q2;
	srand((unsigned)time(NULL));//����һ����ָ��
	do{
		a=rand()%100;//������ĿҪ�����100���ڵ������
		b=rand()%100;//������ĿҪ�����100���ڵ������
		c=rand()%100;//0��1�ǼӼ���2��3�ǳ˳�
		p=rand()%4;//�ĸ���������
		d=rand()%4;//�ĸ���������
		if(p>1){
			y=(float)a;
			z=(float)b;
			x=jisuan(p,y,z);//���ǰ�������Ĵ� ����3 + 1 + 2 �еģ�3+ 1
			y=x;
			z=(float)c;
			x=jisuan(d,y,z);//���ǰ�������𰸼��Ϻ�������Ĵ�
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
	printf("%d %c %d %c %d = ",a,q1,b,q2,c);//�����Ŀ
	scanf("%f",&answer1);
	if(p==3&&d==3)//��������
	{
		if((answer1-x)<0.01)
		{
			printf("��ϲ�㣬�ش���ȷ�ޣ�\n");
		}
		else
		{
			f++;//���������
			printf("���ź�����Ĵ��Ǵ���ģ���ȷ���ǣ�%.1f\n",x);
		}
	}
	else
	{
		if((x-answer1)<0.01)
		{
			printf("��ϲ�㣬�ش���ȷ�ޣ�\n");
		}
		else
		{
			f++;
			printf("���ź�����Ĵ��Ǵ���ģ���ȷ���ǣ�%.1f\n",x);
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
char fuhao(int i)//�жϷ���
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
    printf("\t\t\t\t*����ϵͳ*\n");
    printf("\t\t\t      �����ˣ������\n");
	int i=0,n;
	printf("*�����������Ŀ�ĸ�����");//������Ŀ����
	scanf("%d",&n);
	do{
		yunsuan();//���ú���
		i++;
	}while(i<n);
		printf("�����ȷ��Ϊ%.1lf%%\n",1.0*(n-f) / n * 100);//�����ȷ��
	system("pause");//������Ļ���û������������
}

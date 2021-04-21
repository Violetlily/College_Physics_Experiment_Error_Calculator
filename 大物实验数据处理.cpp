#include<iostream>
#include <stdio.h>
#include<math.h>

using namespace std;
//*****************************************
//计算置信因子tp
//***************************************** 
double temporary_tp(double n_1)
{	
	double p=0.683,v,temporary_tp_1=0;
	v=n_1-1;
	if(p=0.683)
	{	
		if(v==1)
			temporary_tp_1=1.84;
		else if(v==2)
			temporary_tp_1=1.32;
		else if(v==3)
			temporary_tp_1=1.20;
		else if(v==4)
			temporary_tp_1=1.14;
		else if(v==5)
			temporary_tp_1=1.11;
		else if(v==6)
			temporary_tp_1=1.09;
		else if(v==7)
			temporary_tp_1=1.08;
		else if(v==8)
			temporary_tp_1=1.07;
		else if(v==9)
			temporary_tp_1=1.06;
		else if(v==10)
			temporary_tp_1=1.05;
	}
	else
		cout<<"暂不支持"<<endl;
	return temporary_tp_1;
}		
//*****************************************
//计算平均值 
//***************************************** 
double average(double data[],int n)
{
	int i=0;
	double sum=0;
	for(i=0;i<n;i++)
	{
		sum=sum+data[i];
	}
	return sum/n;
}

//*****************************************
//计算第一类不确定度 
//***************************************** 											//增加对置信因子tp的适配
double calculate_eror_1(double data[],int n)

{
	double tp=temporary_tp(n);
	int i=0;
	double avg=average(data,n);
	double error_square_sum=0;
	for(i=0;i<n;i++)
	{
		error_square_sum=error_square_sum+(data[i]-avg)*(data[i]-avg);
	}
	double eror_1=0;
	eror_1=tp*sqrt(error_square_sum/(n*(n-1)));
	return eror_1;
}

//*****************************************
//计算第二类不确定度
//***************************************** 
double calculate_eror_2(double delta_1)
{
	double temporary_eror_2=0;
	temporary_eror_2=delta_1/sqrt(3);
	return temporary_eror_2;
}



//***************************************** 
int main()
{
	int n;
	double E;
	double data[100];
	cout<<"v1.3"<<endl;
	cout<<"本软件以https://github.com/LoneWolfEric/College_Physics_Experiment_data_process 为框架进行改编，加入了其他数值的适配,如：置信因子tp（目前仅支持p=0.683，n&lt;=10的情况），b类不确定度的直接计算（Δ仪=sqrt3），尤其适用于hebuter们的实验数据处理"<<endl;
	cout<<"源代码https://github.com/Violetlily/College_Physics_Experiment_Error_Calculator"<<endl;
	cout<<"本软件用来计算大学物理实验中A,B及合成不确定度，相对不确定度的计算，来简化实验数据处理中对计算器的戳戳戳" <<endl;
	cout<<"之后有机会会提高交互性"<<endl;
	cout<<"仅供学习交流使用，禁止用于商业用途"<<endl;
	cout<<"adjust by Violetlily"<<endl;
	cout<<endl;
	cout<<"请输入Δ仪: ";
	double delta;
	cin>>delta;
	cout<<"输入你的数据的数量：";
	cin>>n;
	if(n>10||n<=0)							//增加鲁棒性 
	{
		cout<<"你丫的调戏我是吧，还让不让人好好抄实验报告了(╯‵□′)╯︵┻━┻"<<endl;
		system("pause");
		return 0;
	}
	else if(n==1)							//增加鲁棒性 
	{
		cout<<"就一个数据你还不手算，懒死了你～(TロT)σ放学别走！"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"依次输入你的数据："<<endl;
		int i=0;
		for(i=0;i<n;i++)
		{
			cin>>data[i];														//数组储存输入数据 
		}
		double tp=temporary_tp(n);												//调用函数输入置信因子tp
		double error_2=calculate_eror_2(delta);									//调用函数计算第二类不确定度															
		double avg=average(data,n);
		double error_1=calculate_eror_1(data,n);cout<<endl;						//调用函数计算第一类不确定度 
		cout<<endl;
//***************************************** 
//结果部分
//***************************************** 
		cout<<"tp="<<tp<<endl;
		cout<<"A不确定度:"<<error_1<<endl;
		cout<<"B类不确定度"<<error_2<<endl;cout<<endl;	
		cout<<"合成不确定度:"<<sqrt(error_1*error_1+error_2*error_2)<<endl;		//输出结果 
		cout<<"平均值="<<avg<<endl;	cout<<endl;
		E=sqrt(error_1*error_1+error_2*error_2)*100/avg;						//输出相对不确定度E
		cout<<"E="<<E<<"%"<<endl;
		system("pause");
	}
}




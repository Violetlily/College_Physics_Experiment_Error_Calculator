#include<iostream>
#include <stdio.h>
#include<math.h>

using namespace std;
//*****************************************
//������������tp
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
		cout<<"�ݲ�֧��"<<endl;
	return temporary_tp_1;
}		
//*****************************************
//����ƽ��ֵ 
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
//�����һ�಻ȷ���� 
//***************************************** 											//���Ӷ���������tp������
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
//����ڶ��಻ȷ����
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
	cout<<"�������https://github.com/LoneWolfEric/College_Physics_Experiment_data_process Ϊ��ܽ��иı࣬������������ֵ������,�磺��������tp��Ŀǰ��֧��p=0.683��n&lt;=10���������b�಻ȷ���ȵ�ֱ�Ӽ��㣨����=sqrt3��������������hebuter�ǵ�ʵ�����ݴ���"<<endl;
	cout<<"Դ����https://github.com/Violetlily/College_Physics_Experiment_Error_Calculator"<<endl;
	cout<<"��������������ѧ����ʵ����A,B���ϳɲ�ȷ���ȣ���Բ�ȷ���ȵļ��㣬����ʵ�����ݴ����жԼ������Ĵ�����" <<endl;
	cout<<"֮���л������߽�����"<<endl;
	cout<<"����ѧϰ����ʹ�ã���ֹ������ҵ��;"<<endl;
	cout<<"adjust by Violetlily"<<endl;
	cout<<endl;
	cout<<"�����릤��: ";
	double delta;
	cin>>delta;
	cout<<"����������ݵ�������";
	cin>>n;
	if(n>10||n<=0)							//����³���� 
	{
		cout<<"��Ѿ�ĵ�Ϸ���ǰɣ����ò����˺úó�ʵ�鱨����(�s�F����)�s��ߩ���"<<endl;
		system("pause");
		return 0;
	}
	else if(n==1)							//����³���� 
	{
		cout<<"��һ�������㻹�����㣬�������㡫(T��T)�ҷ�ѧ���ߣ�"<<endl;
		system("pause");
		return 0;
	}
	else
	{
		cout<<"��������������ݣ�"<<endl;
		int i=0;
		for(i=0;i<n;i++)
		{
			cin>>data[i];														//���鴢���������� 
		}
		double tp=temporary_tp(n);												//���ú���������������tp
		double error_2=calculate_eror_2(delta);									//���ú�������ڶ��಻ȷ����															
		double avg=average(data,n);
		double error_1=calculate_eror_1(data,n);cout<<endl;						//���ú��������һ�಻ȷ���� 
		cout<<endl;
//***************************************** 
//�������
//***************************************** 
		cout<<"tp="<<tp<<endl;
		cout<<"A��ȷ����:"<<error_1<<endl;
		cout<<"B�಻ȷ����"<<error_2<<endl;cout<<endl;	
		cout<<"�ϳɲ�ȷ����:"<<sqrt(error_1*error_1+error_2*error_2)<<endl;		//������ 
		cout<<"ƽ��ֵ="<<avg<<endl;	cout<<endl;
		E=sqrt(error_1*error_1+error_2*error_2)*100/avg;						//�����Բ�ȷ����E
		cout<<"E="<<E<<"%"<<endl;
		system("pause");
	}
}




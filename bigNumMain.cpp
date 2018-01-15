#include"bigNumQLQ.h"
#include <string>
#include <iostream>
using namespace std;//string 类型必须给出命名空间
int main()
{   
	void welcome();//欢迎界面
	int main_operation1();
	int main_operation2();
	int flag=1;	
	char ch;
	system("color F0");//背景为白色,字体为黑色
	welcome();
	cout<<"                                     目录\n\n";
	cout<<"                           一.不涉及文件的大整数计算\n\n";
	cout<<"                           二.涉及文件的大整数计算"<<endl;
	cout<<"请选择:"<<endl;
	char ah='0';
	ah=getchar();
	getchar();
	fflush(stdin);//清除缓存
	system("cls");
	while(ah>'2'||ah<'1')
	{
		cout<<"您的输入有误，请重新输入:";
		ah=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ah) 
	{
		case '1': 
			while (flag)
			{
				main_operation1();
				cout<<"\n继续?(Y/N)";
				fflush(stdin);//清除缓存
				ch=getchar();
				getchar();   	
				if(ch=='N'||ch=='n')
				flag=0;
				system("cls");
			}
			break;  
			case '2':
			while (flag)
			{
				main_operation2();
				cout<<"\n继续?(Y/N)";
				fflush(stdin);//清除缓存
				ch=getchar();
				getchar();   	
				if(ch=='N'||ch=='n')
				flag=0;
				system("cls");
			}
			break;
	}
	return 0;	
}
int main_operation1()//不涉及文件，有时间和取余操作
{
	linkedList B1,B2,B3,C;
	bigNum a;
	char ch='0';
	void title();//标题界面
	title();
	ch=getchar();
	getchar();
	fflush(stdin);
	while(ch>'6'||ch<'1')
	{
		cout<<"您的输入有误，请重新输入:";
		ch=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ch) 
	{
		case '1':  
			a.input_store(B1,B2,B3);
			cout<<"\n(B1+B2)%B3=";  
			a.add_bigNum(B1,B2,B3); 
			break; 
		case '2':   
			a.input_store(B1,B2,B3);
			cout<<"\n(B1-B2)%B3=";    
			a.sub_bigNum(B1,B2,B3); 
			break; 
		case '3':
			a.input_store(B1,B2,B3);        
			cout<<"\n(B1*B2)%B3=";     
			a.mul_bigNum(B1,B2,B3);  
			break; 
		case '4':   
			a.input_store(B1,B2,B3); 
			cout<<"\n(B1/B2)%B3="; 
			a.div_bigNum(B1,B2,B3);          
			break;
		case '5':
			a.input_store(B1,B2,B3); 
			cout<<"\n(B1^B2)%B3="; 
			a.ind_bigNum(B1,B2,B3);  
			break;
		case '6':   
			exit(0); 
	}
	return 0;
}
int main_operation2()//涉及文件,读出至文件中
{
	linkedList B1,B2,B3,C;
	string m;
	bigNum a;
	char ch='0';
	void ftitle();//文件标题界面
	ftitle();
	ch=getchar();
	getchar();
	fflush(stdin);
	while(ch>'7'||ch<'1')
	{
		cout<<"您的输入有误，请重新输入:";
		ch=getchar();
		getchar();
		fflush(stdin);
	}
	switch(ch) 
	{
		case '1':  
			a.finput_store(B1,B2);
			cout<<"\n相加的和为:"; 
			C=a.add_bigNum(B1,B2); 
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break; 
		case '2':   
			a.finput_store(B1,B2);
			cout<<"\n相减的差为:"; 
			a.sub_bigNum(B1,B2); 
			break; 
		case '3':   
			a.finput_store(B1,B2);
			cout<<"\n相乘的积为:";      
			C=a.mul_bigNum(B1,B2); 
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break; 
		case '4':   
			a.finput_store(B1,B2);
			cout<<"\n相除的商为:";  
			C=a.div_bigNum(B1,B2);
			//由于除数为0的情况返回的结果为仅有哑元节点的链表，故设此条件判断
			if(C.size()>0)
			{
				cout<<C;
				m=a.translation(C);
				a.fout_put(m); 
			}
			break;
		case '5':
			a.finput_store(B1,B2);
			cout<<"\n幂运算的结果为:";  
			C=a.ind_bigNum(B1,B2);
			cout<<C;
			m=a.translation(C);
			a.fout_put(m);
			break;
		case '6':
			a.fdisplay();//将硬盘内容输入到内存，显示于屏幕
			break;
		case '7':
			exit(0);
	}
	return 0;
}
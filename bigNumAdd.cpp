/*****************************
* 
*@file
*@author  Qian liqing 
*Modified at: 2016/12/14
*
*大数加，输入参加运算的个数，然后依次输入各个数，输出和，例如:
*Input:
*  2
*  222222
*  3333333333
*Output:
*  3333555555
*
*****************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

string bigNumAdd(string s1,string s2)
{
	if(s2.length()>s1.length())
		swap(s1,s2);
	int l1=s1.length(),l2=s2.length();
	int carry=0;
	string s;
	for(int i=0;i<l2;i++)
	{
		int result=(s1[l1-1-i]-'0')+(s2[l2-1-i]-'0')+carry;
		int bit=result%10;
		carry=result/10;
		s+=bit+'0';
	}
	for(int j=l2;j<l1;j++)
	{
		int result=(s1[l1-1-j]-'0')+carry;
		int bit=result%10;
		carry=result/10;
		s+=bit+'0';
	}
	if(carry>0)
		s+='1';
	reverse(s.begin(),s.end());
	return s;
}

/*int main()
{
	for(int n;cin>>n && n;)
	{
		string s1;cin>>s1;
		for(string s2;n>1 && cin>>s2 ;n--)
			s1=bigNumAdd(s1,s2);
		cout<<s1<<endl;
		
	}
	return 1;
}*/
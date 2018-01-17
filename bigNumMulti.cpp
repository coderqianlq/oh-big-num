/*****************************
* 
*@file
*@author  Qian liqing 
*Modified at: 2016/12/14
*
*大数乘，输入两个乘数，输出积，例如:
*Input:
*  123456
*  1234
*Output:
*  152344704
*
*****************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string multi(string& a,string& b)
{
	if(a=="0" ||b=="0")
		return "0";
	string aa,bb;
	int n=0;
	if(a[0]=='-')
	{
		aa=a.substr(1);
		n++;
	}
	else
		aa=a;
	if(b[0]=='-')
	{
		bb=b.substr(1);
		n++;
	}
	else
		bb=b;
	string s(aa.length()+bb.length(),'0');
	reverse(aa.begin(),aa.end());
	reverse(bb.begin(),bb.end());
	for(int j=0;j<bb.length();j++)
	{
		if(bb[j]=='0') continue;
		int temp=0;
		for(int i=0;i<aa.length();i++)
		{
			temp+=(aa[i]-'0')*(bb[j]-'0')+(s[j+i]-'0');
			s[j+i]=temp%10+'0';
			temp/=10;
		}
		s[aa.length()+j]+=temp;
	}	
	reverse(s.begin(),s.end());
	s=s.substr(s.find_first_not_of('0'));
	string sign;
	if(n==1)
		sign="-";
	return sign+s;
}

/*int main()
{
	for(string s1,s2;cin>>s1>>s2 && !(s1=="0" &&s2=="0");)
	{
		cout<<multi(s1,s2)<<endl;
	}
	return 1;
}*/
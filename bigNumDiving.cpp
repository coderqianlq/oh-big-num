/*****************************
* 
*@file
*@author  Qian liqing
*Modified at: 2016/12/14
*
*大数除，依次输入被除数和除数，输出商，例如:
*Input:
*  169
*  13
*Output:
*  13
*
*****************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool numLess(string a,string b)
{
	if(a.length()<b.length())
		return true;
	else if(a.length()>b.length())
		return false;
	else
	{
		if(a<b)
			return true;
		else
			return false;
	}
}
string subing2(const string &a,const string& b)
{
	if(a==b)
		return"0";
	string s=a;
	for(int bi=b.length()-1,si=s.length()-1;si>=0;si--,bi--)
	{
		if((s[si]-=(bi>=0?b[bi]-'0':0))<'0')
			s[si]+=10,s[si-1]--;
	}
	return s.substr(s.find_first_not_of('0'));
}

string diving(string a,string b)
{
	string s,c;
	c=a.substr(0,b.length()-1);
	for(int i=b.length()-1;i<a.length();i++)
	{
		int cnt=0;
		for(c=(c=="0"?string():c)+a[i];!numLess(c,b);cnt++)
			c=subing2(c,b);
		s+=char(cnt+'0');
	}
	return s[0]=='0'?s.substr(1):s;
}

/*int main()
{
	for(string s1,s2;cin>>s1>>s2 && !(s1=="0" &&s2=="0");)
	{
		cout<<diving(s1,s2)<<endl;
	}
	return 1;
}*/
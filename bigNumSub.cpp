/*****************************
* 
*@file
*@author  Qian liqing
*Modified at: 2016/12/14
*
*大数减，输入参加运算的个数，然后依次输入各个数，输出差，例如:
*Input:
*  2
*  4444
*  222
*Output:
*  4222
*
*****************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

string subing(const string &a,const string& b)
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


/*int main()
{
	for(int n;cin>>n && n;)
	{
		string s1;cin>>s1;
		for(string s2;n>1 && cin>>s2 ;n--)
			s1=subing(s1,s2);
		cout<<s1<<endl;
		
	}
	return 1;
}*/
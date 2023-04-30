#include<bits/stdc++.h>
using namespace std;

int arr[100005];// 用于存放大整数的数组 

string f(string a,string b)// 用string模拟a+b高精度算法 
{
	int len1=a.length();
	int len2=b.length();
	if(len1<len2)
	{
		for(int i=1;i<=len2-len1;i++) a="0"+a;
	} 
	else
	{
		for(int i=1;i<=len1-len2;i++) b="0"+b;
	}
	int len=a.length();
	int t;
	int c=0;
	string str;
	for(int i=len-1;i>=0;i--)
	{
		t=a[i]-'0'+b[i]-'0'+c;
		c=t/10;
		t=t%10;
		str=char(t+'0')+str;
	}
	if(c!=0) str=char(c+'0')+str;
	return str;
}

int main()
{
	string a[101];
	a[0]="0";
	a[1]="1";
	for(int i=2;i<=100;i++) a[i]=f(a[i-1],a[i-2]);// 递推公式 
	while(true)
	{
		cout<<"Please input the number to calculate:"<<endl;
		int input; 
		cin>>input;
		if(input==-1) return 0;
		else cout<<"the answer to item "<<input<<" is:"<<endl<<a[input]<<endl<<endl;
	} 
}

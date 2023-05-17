#include <bits/stdc++.h>
#define int long long
using namespace std;

int a,b,p;

int ks(int a,int b)// a为底数,b为幂次
{
	int ans=1;
	while(b)
	{
		if(b&1) 
		{
			ans*=a;
			ans%=p;
		}
		b>>=1;
		a=a*a%p;
	} 
	return ans;
} 

signed main()
{   
	cin>>a>>b>>p; 
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<ks(a,b);
}

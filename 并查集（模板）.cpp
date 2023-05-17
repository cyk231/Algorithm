#include <bits/stdc++.h>
using namespace std;

int f[100001];

int find(int x)// 查 
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

void combine(int a,int b)// 并 
{
	f[find(a)]=find(b);
}

signed main()
{
	int n,m,p;// n个人，m对关系，p次查询 
	cin>>n>>m;
	for(int i=0;i<n;i++) f[i]=i;
	int a,b; 
	for(int i=0;i<m;i++)
	{
		cin>>p>>a>>b;
		if(p==1) combine(a,b);
		else 
		{
			if(find(a)==find(b)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
		
	}
	return 0;
}

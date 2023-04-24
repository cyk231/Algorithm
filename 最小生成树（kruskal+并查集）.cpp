#include<bits/stdc++.h>
using namespace std;

int fa[1000005];// 并查集数组 
int n=8;// n个点 
int m;  // m条边 

struct edge// 边 
{
	int u,v,w;
}a[1000005];

bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
 
void read()// 为edge数组a初始化 
{
	int matrix[n][n]=
	{
		{0,2,8,1,0,0,0,0},
		{2,0,6,0,1,0,0,0},
		{8,6,0,7,5,1,2,0},
		{1,0,7,0,0,0,9,0},
		{0,1,5,0,0,3,0,8},
		{0,0,1,0,3,0,4,6},
		{0,0,2,9,0,4,0,3},
		{0,0,0,0,8,6,3,0},
	};
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(matrix[i][j]!=0)// 边的初始化 
			{
				a[m].u=i;
				a[m].v=j;
				a[m].w=matrix[i][j];
				m++; 
			}
		}
	} 
}

int find(int x)// 查 
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

int kruskal()
{
	int ans=0;
	int cnt=0;
	sort(a,a+m,cmp);//将边的权值排序
    for(int i=0;i<m;i++)
    {
        int eu=find(a[i].u);
		int ev=find(a[i].v);
        if(eu==ev) continue;// 若出现两个点已经联通了，则说明这一条边不需要了
        ans+=a[i].w;// 将此边权重计入答案
        fa[ev]=eu;// 并
        cnt++;
        if(cnt==n-1) break;// 循环结束的条件 
    }
    if(cnt==n-1) return ans;
    return -1;// 不连通 
}
int main()
{
	read();// 初始化 
	for(int i=0;i<n;i++) fa[i]=i;// 初始化并查集
	int ans=kruskal();
	if(ans==-1) cout<<"非连通图"<<endl;
	else cout<<"最小生成树的权值为："<<ans<<endl; 
	return 0;
	
}

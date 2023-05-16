#include<bits/stdc++.h>
using namespace std;

const int n=4;// 城市数 
int ans=INT_MAX;// 保存最佳权重，初始化为极大值 
int cost;// 当前的权重 
int path[n];// 当前的路径 
int best_path[n];// 最佳路径 
bool used[n];// 判断是否使用过 

int weight[n][n]=// 邻接矩阵表示边的权重 
{
	{0, 1, 2, 3},
    {1, 0, 9, 4},
    {2, 9, 0, 6},
    {3, 4, 6, 0}
};

void dfs(int k)
{
	if(n==k)// 访问完了，需要回到起点城市 
	{
		if(ans>cost+weight[path[k-1]][0])
		{
			ans=cost+weight[path[k-1]][0];
			for(int i=0;i<n;i++) best_path[i]=path[i]; 
		}
		return ;
	} 
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=true;
			path[k]=i;
			cost+=weight[path[k-1]][i];
			dfs(k+1);
			cost-=weight[path[k-1]][i];// 需注意，这里回溯时cost需要减掉 
			used[i]=false;
		}
	}
}

int main()
{
	used[0]=true;// 从下标为0的城市开始出发 
	dfs(1);
	
	cout<<"最佳路径为：";
	for(int i=0;i<n;i++) cout<<best_path[i]<<" ";
	cout<<endl<<"最佳权重为："<<ans<<endl;
}

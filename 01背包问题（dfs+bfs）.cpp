#include<bits/stdc++.h>
using namespace std;

int t;// 总时间  
int m;// 物品数 
int w[105];// 每个物品的时间 
int v[105];// 每个物品的价值 
int dp[105][105];
int ans;// 最佳价值 


void dfs(int k,int time,int value)// 深搜 
{
	if(k==m)
	{
		ans=max(ans,value);
		return ;
	}
	if(time>=w[k]) dfs(k+1,time-w[k],value+v[k]);
	dfs(k+1,time,value);
}


struct Node// 状态结构体 
{
	int k;
	int time;
	int value;	
};

void bfs()// 广搜 
{
	queue<Node> q;
    q.push({0, t, 0});// 初始状态
    while(!q.empty())
	{
        Node cur=q.front();
        q.pop();
        if(cur.k==m)// 已经选完了所有物品
		{
            ans=max(ans,cur.value);// 更新最大价值
            continue;
        }
        if(cur.time>=w[cur.k+1])// 可以选择第i+1个物品
		{
            q.push({cur.k+1, cur.time-w[cur.k+1], cur.value+v[cur.k+1]});// 选择第i+1个物品
        }
        q.push({cur.k+1, cur.time, cur.value});// 不选择第i+1个物品
    }
}

int main()
{
	cin>>t>>m;
	for(int i=0;i<m;i++) cin>>w[i]>>v[i];
	dfs(0,t,0);
//	bfs();
	cout<<ans; 
}

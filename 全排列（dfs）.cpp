// 按字典序输出字符的全排列，当然也可以用c++中的next_permutation函数（详见洛谷）
#include<bits/stdc++.h>
using namespace std;

char a[10];// 存输入的字符 
bool used[10];// 判断是否用过 
char path[10];// 本次排序 
int n;// 字符数 

void dfs(int k)// dfs,递归回溯 
{
    if(k==n)// 满了，输出 
	{
        for(int i=0;i<n;i++) cout<<path[i]<<" ";
        cout<<endl;
        return ;
    } 
	for(int i=0;i<n;i++)// 未满 
	{
        if(!used[i])// 如果当前数未被使用，则将其加入当前路径
		{  
            used[i]=true;
            path[k]=a[i];
            dfs(k+1);// 继续深度搜索
            used[i]=false;  // 回溯
        }
    }
} 

int main()
{
	cout<<"输入字符个数：";
	cin>>n;
	cout<<"输入字符：";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<endl<<"全排列的结果如下："<<endl;
	dfs(0); 
	return 0;
}

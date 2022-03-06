/***
 * @Author: Zi_Gao
 * @LastEditors: Zi_Gao
 * @Description: 优先队列 
 */
#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	bool operator < (const node & a) const
	{
		return x<a.x;
	}
}k;
priority_queue <node> q;
int main()
{
	k.x=10,k.y=100; q.push(k);
	k.x=12,k.y=60; q.push(k);
	k.x=14,k.y=40; q.push(k);
	k.x=6,k.y=80; q.push(k);
	k.x=8,k.y=20; q.push(k);
	while(!q.empty())
	{
		node m=q.top(); q.pop();
		printf("(%d,%d) ",m.x,m.y);
	}
}

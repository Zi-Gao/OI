#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int max_n=1000+10;
const int max_m=200000+10;
const int INF=0x3fffffff;

struct edge{
	int to,next;
	unsigned long long w;
	edge(){
		next=-1;
	}
}list[max_m];

int n,m,head[max_n],cntmin,p,_min;
int book[max_n];
int path[max_n];
int path_min[max_n];
int warr[max_n];

void dfs(int now,int step,int w){
	if(book[now]&&(step-book[now])>=3&&(w-warr[now])<_min){
		_min=w-warr[now];
		cntmin=step-book[now];
		memset(path_min,0,sizeof(path_min));
		int j=1;
		for(int i=book[now];i<step;i++){
			path_min[j++]=path[i];
		}
		return;
	}
	if(book[now]) return;

	book[now]=step;
	path[step]=now;
	warr[now]=w;
	
	for(int i=head[now];~i;i=list[i].next){
		dfs(list[i].to,step+1,w+list[i].w);
	}
	
	book[now]=0;
	path[step]=0;
	warr[now]=0;
}
/*
5 7
1 4 1
1 3 300
3 1 10
1 2 16
2 3 100
2 5 15
5 3 20 
*/
int main(){
	freopen("trip.in","r",stdin);
	freopen("trip.out","w",stdout);
	memset(head,-1,sizeof(head));
	_min=0x3fffffff;

	scanf("%d %d",&n,&m);
	int u,v,w;

	for(int i=1;i<=m*2;i+=2){
		scanf("%d %d %d",&u,&v,&w);
		list[i].to=v;
		list[i].w=w;
		list[i].next=head[u];
		head[u]=i;
		
		list[i+1].to=u;
		list[i+1].w=w;
		list[i+1].next=head[v];
		head[v]=i+1;
	}
	
	dfs(1,1,0);

	if(_min==0x3fffffff) printf("No solution."); 
	else for(int i=1;i<=cntmin;i++) printf("%d ",path_min[i]);

	return 0;
}

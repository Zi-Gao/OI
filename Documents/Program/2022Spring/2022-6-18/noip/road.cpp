/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
#define MAX_N 100+10
#define MAX_M 10000+10
#define INF 64
using namespace std;
inline int read();
int n,m,head[MAX_N];
struct edge{
	int to,next,w,t;
	edge(){
		next=-1;
	}
}e[MAX_M];
void addEdge(int u,int v,int w,int t,int nowm){
	e[nowm].to=v;
	e[nowm].w=w;
	e[nowm].t=t;
	e[nowm].next=head[u];
	head[u]=nowm;

	return;
}
int min=2147483647;
char book[MAX_N];
int booka[MAX_N];
void dfs(int cur,int w,int k){
	if(k<0){
		return;
	}
	if(cur==n){
		if(min>w){
			min=w;
		}
		return;
	}
	if(w>min){
		return;
	}
	if(booka[cur]<w){
		return;
	}
	booka[cur]=w;
	bool flag=false;
	for(int i=head[cur];~i;i=e[i].next){
		if(book[e[i].to]==0){
			book[e[i].to]=1;
			dfs(e[i].to,w+e[i].w,k-e[i].t);
			book[e[i].to]=0;
		}
	}

	return;
}
int main(){
	#ifdef file
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif

	int k=read();
	n=read();
	m=read();
	int u,v,w,t;
	for(int i=0;i<MAX_N;i++) head[i]=-1;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		t=read();
		addEdge(u,v,w,t,i);
	}
	
	for(int i=0;i<MAX_N;i++){
		booka[i]=2147483647;
	}
	
	int cnt=0;
	book[1]=1;
	
	dfs(1,0,k);
	
	if(min!=2147483647){
		printf("%d",min);
	}else{
		printf("-1");
	}
	

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

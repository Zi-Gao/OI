/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
#define MAX_N 20000+10
#define MAX_M 200000+10
#define INF 64
using namespace std;
inline int read();
int n,m,head[MAX_N];
struct edge{
	int to,next,w;
	edge(){
		next=-1;
	}
}e[MAX_M];
void addEdge(int u,int v,int w,int nowm){
	e[nowm].to=v;
	e[nowm].w=w;
	e[nowm].next=head[u];
	head[u]=nowm;
	return;
}
char book[MAX_N];
void dfs(int cur){
	book[cur]=1;
	for(int i=head[cur];~i;i=e[i].next){
		if(book[e[i].to]==0){
			dfs(e[i].to);
		}
	}
}
/*
11
9
1 2
4 5
3 4
1 3
5 6
7 10
5 10
6 10
8 9
*/
int main(){
	#ifdef file
	freopen("company.in", "r", stdin);
	freopen("company.out", "w", stdout);
	#endif

	n=read();
	m=read();
	int u,v;
	for(int i=0;i<MAX_N;i++) head[i]=-1;
	for(int i=1;i<=m*2;i++){
		u=read();
		v=read();
		addEdge(u,v,1,i);
		addEdge(v,u,1,++i);
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!book[i]){
			dfs(i);
			cnt++;
		}
		
	}
	
	printf("%d",cnt);

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

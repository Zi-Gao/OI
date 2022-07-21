/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
#define MAX_N 100000
#define MAX_M 100000
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
int book[MAX_N];
int arr[MAX_N];
void dfs(int cur){
	if(arr[cur]){
		return;
	}
	printf("%d ",cur);
	for(int i=head[cur];~i;i=e[i].next){
		if(arr[e[i].to]){
			book[arr[e[i].to]]=1;
			if(arr[cur]<arr[e[i].to])
				arr[cur]=arr[e[i].to];
		}else 
		if(book[e[i].to]==0){
			if(arr[cur]<e[i].to)
				arr[cur]=e[i].to;
			book[e[i].to]=1;
			dfs(e[i].to);
		}
	}
}
int main(){
	#ifdef file
	freopen("rank.in", "r", stdin);
	freopen("rank.out", "w", stdout);
	#endif

	n=read();
	m=read();
	int u,v;
	for(int i=0;i<MAX_N;i++) head[i]=-1;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		addEdge(v,u,1,i);
	}
	
	int cnt=0;
	for(int i=n;i>0;i--){
		if(arr[i]){
			continue;
		}
//		book[i]=1;
		dfs(i);
		for(int j=1;j<=n;j++){
//			if(!arr[j]&&book[j])
//				arr[j]=i;
//			book[j]=0;
		}
		int cnt=0;
	}
	
	for(int i=1;i<=n;i++){
//		printf("%d ",arr[i]);
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

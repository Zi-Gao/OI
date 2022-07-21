/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
#define MAX_N 1000+10
#define MAX_M 10000+10
#define INF 64
using namespace std;
inline int read();
int n,m,heada[MAX_N],headb[MAX_N];
struct edge{
	int to,next,w;
	edge(){
		next=-1;
	}
}ea[MAX_M],eb[MAX_M];
void addEdge(int u,int v,int w,int nowm){
	ea[nowm].to=v;
	ea[nowm].w=w;
	ea[nowm].next=heada[u];
	heada[u]=nowm;
	
	eb[nowm].to=u;
	eb[nowm].w=w;
	eb[nowm].next=headb[v];
	headb[v]=nowm;
	
	return;
}
char book_a[MAX_N];
char book_b[MAX_N];
void dfs_a(int cur){
	for(int i=heada[cur];~i;i=ea[i].next){
		if(book_a[ea[i].to]==0){
			book_a[ea[i].to]=1;
			dfs_a(ea[i].to);
		}
	}
}
void dfs_b(int cur){
	for(int i=headb[cur];~i;i=eb[i].next){
		if(book_b[eb[i].to]==0){
			book_b[eb[i].to]=1;
			dfs_b(eb[i].to);
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
	for(int i=0;i<MAX_N;i++) heada[i]=-1;
	for(int i=0;i<MAX_N;i++) headb[i]=-1;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		addEdge(u,v,1,i);
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		book_a[i]=1;
		book_b[i]=1;
		dfs_a(i);
		dfs_b(i);
		
		for(int j=1;j<=n;j++){
			cnt+=!(book_a[j]||book_b[j]);
			book_a[j]=0;
			book_b[j]=0;
		}
	}
	
	printf("%d",cnt/2);

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

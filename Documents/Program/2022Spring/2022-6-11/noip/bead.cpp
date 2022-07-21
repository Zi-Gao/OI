/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
#define MAX_N 100+10
#define MAX_M 100000+10
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
int cnt,out;
void dfs_a(int cur){
	cnt++;
	if(cnt>(n+1)/2){
		out++;
		return;
	}
	for(int i=heada[cur];~i;i=ea[i].next){
		dfs_a(ea[i].to);
	}
}
void dfs_b(int cur){
	cnt++;
	if(cnt>(n+1)/2){
		out++;
		return;
	}
	for(int i=headb[cur];~i;i=eb[i].next){
		dfs_b(eb[i].to);
	}
}
int main(){
	#ifdef file
	freopen("bead.in", "r", stdin);
	freopen("bead.out", "w", stdout);
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
	
	for(int i=1;i<=n;i++){
		cnt=0;
		book_a[i]=1;
		dfs_a(i);
		memset(book_a,0,sizeof(book_a));
		if(cnt>(n+1)/2){
			goto loop;
		}
		
		cnt=0;
		book_b[i]=1;
		dfs_b(i);
		memset(book_b,0,sizeof(book_b));
		loop:;
	}
	
	printf("%d",out);

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

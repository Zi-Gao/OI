/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file

const int MAX_N=100000+10;
const int MAX_M=MAX_N*2;
const int ST_I=MAX_N;
const int ST_J=19;

struct edge{
	int to,w,next;
	edge(){
		next=-1;
		return;
	}
}tree[MAX_M];

inline int ln(int n){
	return 63-__builtin_clzll(n);
}

struct ST{
	int f[ST_I][ST_J];
	
	void create(int p[],int n){
		int k=ln(n);
		for(register int i=1;i<=n;i++) f[i][0]=p[i];
		
		for(register int j=1;j<=k;j++)
			for(register int i=1;i<=n;i++)
				f[i][j]=f[f[i][j-1]][j-1];
				
		return;
	}
}st;

int head[MAX_N],depths[MAX_N],dis[MAX_N],parents[MAX_N],n,m;

inline int read();
void init();
void addEdge(int u,int v,int w,int nowm);
void count(int u,int p);
int LCA_ST(int u,int v);
//void

int main(){
	#ifdef file
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
	#endif


	init();

	n=read();
	m=n-1;
	int u,v,w;
	char c;
	
	for(register int i=1;i<=m*2;i++){
		u=read();
		v=read();
		w=1;
		addEdge(u,v,w,i++);
		addEdge(v,u,w,i);
//		while(c!='\n')c=
	}
	
	count(1,1);
	st.create(parents,n);
	
	int k=read();
	int lca;
	
	for(register int i=0;i<k;i++){
		u=read();
		v=read();
		lca=LCA_ST(u,v);
		printf("%d\n",(dis[u]+dis[v]-(dis[lca]<<1)));
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int LCA_ST(int u,int v){
	if(depths[u]<depths[v]){
		u^=v;
		v=u^v;
		u=u^v;
	}
	
	while(depths[u]!=depths[v]) u=parents[u];
	
	if(u==v) return u;
	
	int k=ln(depths[u]);
	
	for(register int i=k;i>=0;i--)
		if(st.f[u][i]!=st.f[v][i]){
			u=st.f[u][i];
			v=st.f[v][i];
		}
	
	return st.f[u][0];
}

void count(int u,int p){
	parents[u]=p;
	depths[u]=depths[p]+1;
	for(register int i=head[u];~i;i=tree[i].next)
		if(tree[i].to!=p){
			dis[tree[i].to]=dis[u]+tree[i].w;
			count(tree[i].to,u);
		}
	return;
}

void addEdge(int u,int v,int w,int nowm){
	tree[nowm].to=v;
	tree[nowm].w=w;
	tree[nowm].next=head[u];
	head[u]=nowm;
	return;
}

void init(){
	memset(head,-1,sizeof(head));
	for(register int i=0;i<MAX_N;i++)parents[i]=i;
	return;
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

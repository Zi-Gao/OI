/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file

const int MAX_N=500000+10;
const int ST_I=MAX_N;
const int ST_J=22;

struct edge{
	int to,next;
	edge(){
		next=-1;
		return;
	}
}tree[MAX_N<<1];

inline int ln(int n){
	return 63-__builtin_clzll(n);
}

struct ST{
	int f[ST_I][ST_J];

	void create(int p[],int n){
		int k=ln(n);
		for(int i=1;i<=n;i++) f[i][0]=p[i];

		for(int j=1;j<=k;j++)
			for(int i=1;i<=n;i++)
				f[i][j]=f[f[i][j-1]][j-1];

		return;
	}
}st;

int head[MAX_N],depths[MAX_N],parents[MAX_N],n;

inline int read();
void init();
void addEdge(int u,int v,int nowm);
void count(int u,int p);
int LCA_ST(int u,int v);

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    init();

    int n=read();
    int m=read();
    int head=read();

    int u,v;

    for(register int i=1;i<=((n-1)<<1);++i){
        u=read();
        v=read();
        addEdge(u,v,i);
        addEdge(v,u,++i);
    }

    count(head,head);
    st.create(parents,n);

    for(register int i=0;i<m;++i){
        u=read();
        v=read();
        printf("%d\n",LCA_ST(u,v));
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

	int k=ln(n);

	while(depths[u]>depths[v])
		u=st.f[u][ln(depths[u]-depths[v]-1)];

	if(u==v) return u;

	for(int i=k;i>=0;i--)
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
			count(tree[i].to,u);
		}
	return;
}

void addEdge(int u,int v,int nowm){
	tree[nowm].to=v;
	tree[nowm].next=head[u];
	head[u]=nowm;
	return;
}

void init(){
	memset(head,-1,sizeof(head));
	for(int i=0;i<MAX_N;i++)parents[i]=i;
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
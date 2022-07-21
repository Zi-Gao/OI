/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file

const int MAX_N=40000+10;
const int MAX_QUERY=40000+10;

struct edge{
	int to,w,next;
	edge(){
		next=-1;
		return;
	}
}tree[MAX_N<<1];

struct UFDS{
	int parents[MAX_N];

	UFDS(){
		for(register int i=1;i<MAX_N;++i)
			parents[i]=i;
		return;
	}

	inline int find(int x){
		while(parents[x]!=x)
			x=parents[x];
		return x;
	}

	void clear(){
		for(int i=1;i<MAX_N;i++)
			parents[i]=i;
		return;
	}
}ufds,u2;

struct QUERY{
	int to,next,id;
	QUERY(){
		next=-1;
		return;
	}
}query[MAX_QUERY];

int head[MAX_N],dis[MAX_N],head_query[MAX_QUERY],lca[MAX_QUERY],lca_dis[MAX_QUERY],n,q;
char vis[MAX_N];

inline int read();
void init();
void addEdge(int u,int v,int w,int nowm);
void addQuery(int u,int v,int id,int nowquery);
void LCA_Tarjan(int u);


int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	init();

	n=read();
	int m=read();
	q=read();
	
	int u,v,w;
	char c;
	
	for(register int i=1;i<=(m<<1);++i){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
		addEdge(v,u,w,++i);
		while(c!='\n')c=getchar();
	}
	
	
	
	for(register int i=1;i<=(q<<1);++i){
		u=read();
		v=read();
		addQuery(u,v,(i+1)/2,i);
		addQuery(v,u,(i+1)/2,++i);
	}
	
	
	
	LCA_Tarjan(1);

	for(int i=1;i<=q;i++) printf("%d\n",lca_dis[i]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void LCA_Tarjan(int u){
	vis[u]=1;
	for(register int i=head[u];~i;i=tree[i].next)
		if(!vis[tree[i].to]){
			dis[tree[i].to]=dis[u]+tree[i].w;
			LCA_Tarjan(tree[i].to);
			ufds.parents[tree[i].to]=u;
		}
	
	for(register int i=head_query[u];~i;i=query[i].next)
		if(vis[query[i].to]){
			lca[query[i].id]=ufds.find(query[i].to);
			lca_dis[query[i].id]=dis[u]+dis[query[i].to]-(dis[lca[query[i].id]]<<1);
		}

	return;
}

void addQuery(int u,int v,int id,int nowquery){
	query[nowquery].to=v;
	query[nowquery].id=id;
	query[nowquery].next=head_query[u];
	head_query[u]=nowquery;
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
	memset(head_query,-1,sizeof(head_query));
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

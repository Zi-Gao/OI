#include <cstdio>
#include <cstring>
#define mi(a,b) ((a)<(b)?(a):(b))

#define file
#define MAX_N 430+10
#define MAX_M MAX_N*MAX_N
const int INF=0x3FFFFFFF;

int e[MAX_N][MAX_N],n,m;

void init();
inline int read();
void readGraph();
void Floyd_WarshallMatrix();

int main(){
	#ifdef file
	freopen("floyd.in", "r", stdin);
	freopen("floyd.out", "w", stdout);
	#endif

	init();
	readGraph();

	Floyd_WarshallMatrix();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void Floyd_WarshallMatrix(){
	for(register int k=1;k<=n;++k)
		for(register int i=1;i<=n;++i)
			for(register int j=1;j<=n;++j)
				e[i][j]=mi(e[i][k]+e[k][j],e[i][j]);

	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=n;++j)
			if(e[i][j]==INF) printf("INF ");
			else printf("%d ",e[i][j]);
		putchar('\n');
	}
}

void addEdge(int u,int v,int w,int nowm){
	e[u][v]=w;
	return;
}

void readGraph(){
	n=read();
	m=read();
	int u,v,w;
	for(register int i=1;i<=m;++i){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
	}
	return;
}

void init(){
	for(register int i=0;i<MAX_N;++i){
		for(register int j=0;j<MAX_N;++j){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;
		}
	}
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

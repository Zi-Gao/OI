#include <cstdio>
#include <cstring>

#define file
const int MAX_N=5000+10;
const int MAX_M=MAX_N*MAX_N;
const int INF=0x3FFFFFFF;

int matrix[MAX_N][MAX_N],n,m,s;

int min(int a,int b);
void init();
inline int read();
void readGraph();
void DijkstraMatrix();

int main(){
	#ifdef file
	freopen("dij.in", "r", stdin);
	freopen("dij.out", "w", stdout);
	#endif

	init();
	readGraph();

	DijkstraMatrix();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void DijkstraMatrix(){
	int dis[MAX_N]={0},_min,cur;
	bool book[MAX_N]={0};
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	dis[s]=0;

	for(register int i=1;i<=n;++i){
		_min=INF;
		for(register int j=1;j<=n;++j)
			if(!book[j]&&dis[j]<_min){
				_min=dis[j];
				cur=j;
			}
		book[cur]=1;
		for(register int j=1;j<=n;++j)
			if(!book[j])
				dis[j]=min(dis[cur]+matrix[cur][j],dis[j]);
	}

	for(register int i=1;i<=n;++i)
		if(dis[i]==INF) printf("INF ");
		else printf("%d ",dis[i]);

	return;
}

void readGraph(){
	n=read();
	m=read();
	s=read();
	int u,v,w;
	for(register int i=1;i<=m;++i){
		u=read();
		v=read();
		w=read();
		matrix[u][v]=min(matrix[u][v],w);
	}
	return;
}

void init(){
	for(register int i=0;i<MAX_N;++i){
		for(register int j=0;j<MAX_N;++j){
			if(i==j) matrix[i][j]=0;
			else matrix[i][j]=INF;
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

int min(int a,int b){
	return a<b?a:b;
}

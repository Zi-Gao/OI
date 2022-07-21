#include <cstdio>
#include <cstring>
using namespace std;

//#define file
#define MAX_N 430+10
#define MAX_M MAX_N*MAX_N
const int INF=0x3FFFFFFF;

int e[MAX_N][MAX_N],p[MAX_N][MAX_N],n,m;

int min(int a,int b);
void init();
inline int read();
void readGraph();
void Floyd_WarshallMatrix();
/*
5 8
1 2 1
1 3 4
1 4 6
2 4 2
2 5 4
3 4 1
4 5 1
5 3 6
*/
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
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				p[i][j]=p[k][j];
				if(e[i][j]>e[i][k]+e[k][j]){
					e[i][j]=e[i][k]+e[k][j];
				}
			}


	int nowi=1;
	int nowj=4;
	while(~nowj){
		printf("%d ",nowj);
		nowj=p[nowi][nowj];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)
//			if(e[i][j]==INF) printf("INF ");
//			else printf("%d ",e[i][j]);
//		putchar('\n');
//	}
}

void addEdge(int u,int v,int w,int nowm){
	e[u][v]=w;
	return;
}

void readGraph(){
	n=read();
	m=read();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		p[u][v]=u;
		
		addEdge(u,v,w,i);
	}
	return;
}

void init(){
	for(int i=0;i<MAX_N;i++)
		for(int j=0;j<MAX_N;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;
			p[i][j]=-1;
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

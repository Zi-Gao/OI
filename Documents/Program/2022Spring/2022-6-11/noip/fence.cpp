#include <cstdio>
#include <cstring>
using namespace std;
/*
9
1 2
2 3
3 4
4 2
4 5
2 5
5 6
5 7
4 6
*/
#define file
#define MAX_N 500+10
#define MAX_M 1040
const char INF=127;
int cnt,s,n,m;
char e[MAX_N][MAX_N];
char book[MAX_N];

void init();
inline int read();
void readGraph();
void depthFirstSearchMatrix(int cur);

int main(){
	#ifdef file
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	#endif

	init();
	readGraph();

	book[s]=1;
	depthFirstSearchMatrix(s);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void depthFirstSearchMatrix(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=1;i<=n;i++)
		if(e[cur][i]<INF&&book[i]==0){
			book[i]=1;
			depthFirstSearchMatrix(i);
		}
}

void addEdge(int u,int v,int w){
	e[u][v]=w;
	return;
}

void readGraph(){
//	n=read();
	m=read();
	s=600;
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		if(u>n){
			n=u;
		}
		if(v>n){
			n=v;
		}
		if(u<s){
			s=u;
		}
		if(v<s){
			s=v;
		}
		addEdge(u,v,1);
	}
	return;
}

void init(){
	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
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

#include <cstdio>
#include <cstring>
using namespace std;

#define file
#define MAX_N 110
#define MAX_M MAX_N*MAX_N
const int INF=0x3FFFFFFF;

int e[MAX_N][MAX_N];
int n,m;
int peo[MAX_N];

int min(int a,int b);
void init();
inline int read();
void readGraph();
void Floyd_WarshallMatrix();
/*
5
13 2 3
4 0 0
12 4 5
20 0 0
40 0 0
*/
int main(){
	#ifdef file
	freopen("hospital.in", "r", stdin);
	freopen("hospital.out", "w", stdout);
	#endif

	init();
	readGraph();

	Floyd_WarshallMatrix();
	int cntnow;
	int best=INF;
	
	for(int i=1;i<=n;i++){
		cntnow=0;
		for(int j=1;j<=n;j++)
			cntnow+=e[i][j]*peo[j];
		best=min(cntnow,best);
	}
	
	printf("%d",best);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void Floyd_WarshallMatrix(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);
}

void readGraph(){
	n=read();
	int p,u,v;
	for(int i=1;i<=n;i++){
		p=read();
		u=read();
		v=read();
		peo[i]=p;
		e[i][v]=1;
		e[i][u]=1;
		e[v][i]=1;
		e[u][i]=1;
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

int min(int a,int b){
	return a<b?a:b;
}

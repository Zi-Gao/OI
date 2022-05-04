/***
 * @Author: Zi_Gao
 * @Description: 
 */
/*
DFS/BFS :
5 5
1 2 1
1 3 1
1 5 1
2 4 1
3 5 1
DFS:1 2 4 3 5
BFS:1 2 3 4 5

Floyd/Dijkstra:
4 8
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
Floyd:
0 2 5 4
9 0 3 4
6 8 0 1
5 7 10 0
Dijkstra:
0 2 5 4
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
// #define file
#define MAX_SIZE 10000
const int INF=0x3FFFFFFF;
using namespace std;
int e[MAX_SIZE][MAX_SIZE],e_floyd[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool dfs_book[MAX_SIZE];

void init();
inline int read();
inline void write(int in[MAX_SIZE][MAX_SIZE]);
void readGraph();
void depthFirstSearch(int cur);
void breadthFirstSearch();
void Floyd_Warshall();
void Dijkstra();

int main(){
	#ifdef file
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout); 
	#endif

	init();

	readGraph();

	printf("Depth First Search:\n");
	dfs_book[1]=1;
	depthFirstSearch(1);
	putchar('\n');

	printf("Breadth First Search:\n");
	breadthFirstSearch();
	putchar('\n');

	printf("Floyd-Warshall:\n");
	Floyd_Warshall();
	putchar('\n');

	printf("Dijkstra:\n");
	Dijkstra();
	putchar('\n');

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

/*
 *e_floyd:邻接矩阵
 *book_dij:记录是否访问过
 *dij_dis:记录距离
 *min:记录最小距离
 *u:记录最小距离的点
 *INF:正无穷
 */
void Dijkstra(){
	bool book_dij[MAX_SIZE]={0};
	int dis[MAX_SIZE]={0},_min,u;
	book_dij[MAX_SIZE]=1;

	for(int i=1;i<=n;i++)
		dis[i]=e[1][i];

	for(int i=1;i<n;i++){
		_min=INF;
		for(int j=1;j<=n;j++)
			if(!book_dij[j]&&dis[j]<_min){
				_min=dis[j];
				u=j;
			}
		book_dij[u]=1;
		for(int j=1;j<=n;j++)
			if(!book_dij[j])
				dis[j]=min(dis[u]+e[u][j],dis[j]);
	}

	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
}

/*
 *k:中专点
 *i:起始点
 *j:终止点
 *INF:正无穷
 *e_floyd:邻接矩阵
 */
void Floyd_Warshall(){
	memcpy(e_floyd,e,sizeof(e));

	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e_floyd[i][j]=min(e_floyd[i][k]+e_floyd[k][j],e_floyd[i][j]);
	write(e_floyd);
}

/*
 *cur: 当前的点
 *bfs_book:标记数组
 *INF:正无穷
 *e:邻接矩阵
 *que:队列
 *head:队头
 *tail:队尾
 */
void breadthFirstSearch(){
	bool bfs_book[MAX_SIZE]={0};
	int que[MAX_SIZE]={0},head=0,tail=0,cur=1;

	que[tail++]=cur;
	bfs_book[cur]=1;

	while(head<tail && tail<n){
		cur=que[head];
		for(int i=1;i<=n;i++){
			if(e[cur][i]!=INF && !bfs_book[i]){
				que[tail++]=i;
				bfs_book[i]=1;
			}
			if(tail==n) break;
		}
		head++;
	}

	for(int i=1;i<=n;i++)
		if(bfs_book[i]) printf("%d ",i);
}

/*
 *cur: 当前的点
 *cnt:遍历的点个数
 *INF:正无穷
 *e:邻接矩阵
 *dfs_book:标记数组
 */
void depthFirstSearch(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=1;i<=n;i++)
		if(e[cur][i]<INF&&dfs_book[i]==0){
			dfs_book[i]=1;
			depthFirstSearch(i);
		}
}

void readGraph(){
	n=read();
	m=read();

	int x,y;
	for(int i=1;i<=m;i++){
		x=read();
		y=read();
		e[x][y]=read();
	}
}

void init(){
	for(int i=0;i<MAX_SIZE;i++){
		for(int j=0;j<MAX_SIZE;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;
		}
	}
}

inline void write(int in[MAX_SIZE][MAX_SIZE]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(in[i][j]==INF) printf("INF ");
			else printf("%d ",in[i][j]);
		putchar('\n');
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

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
 */
#include <cstdio>
// #define file
#define MAX_SIZE 10000
const int INF=0x3FFFFFFF;
using namespace std;
inline int read();
int e[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool dfs_book[MAX_SIZE];

void dfs(int cur);
void bfs();

int main(){
	#ifdef file
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout); 
	#endif

	//init
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				e[i][j]=0;
			}else{
				e[i][j]=INF;
			}
		}
	}

	int x,y;
	for(int i=1;i<=m;i++){
		x=read();
		y=read();
		e[x][y]=1;
	}

	// printf("DFS:\n");
	dfs_book[1]=1;
	dfs(1);
	putchar('\n');

	// printf("BFS:\n");
	bfs();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
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
void bfs(){
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

	for(int i=1;i<=n;i++){
		if(bfs_book[i]) printf("%d ",i);
	}
}

/*
 *cur: 当前的点
 *cnt:遍历的点个数
 *INF:正无穷
 *e:邻接矩阵
 *dfs_book:标记数组
 */
void dfs(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=1;i<=n;i++){
		if(e[cur][i]<INF&&dfs_book[i]==0){
			dfs_book[i]=1;
			dfs(i);
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

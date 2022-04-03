/***
 * @Author: Zi_Gao
 * @Description: 
DFS/BFS
5 5
1 2 1
1 3 1
1 5 1
2 4 1
3 5 1
 */
#include <cstdio>
//#define file
#define MAX_SIZE 10
#define INF 0x3FFFFFFF
using namespace std;
inline int read();
int e[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool book[MAX_SIZE];
/*
 *cur: 当前的点
 *cnt:遍历的点个数
 *e:邻接矩阵
 *book:标记数字
 *INF:正无穷
 */ 
void dfs(int cur){//
	printf("%d ",cur);
	++sum;
	if(cnt==n) return;
	for(int i=1;i<=n;i++){
		if(e[cur][i]<INF&&book[i]==0){
			book[i]=1;
			dfs(i);
		}
	}
}
int main(){
	#ifdef file
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
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
	for(int i=1;i<=n;i++){
		x=read();
		y=read();
		e[x][y]=read();
	}
	
	book[1]=1;
	dfs(1);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
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

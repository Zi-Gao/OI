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
 */
#include <cstdio>
#include <cstring>
#define file
const int MAX_SIZE=1000;
const int INF=0x3FFFFFFF;
using namespace std;
inline int read();
int e[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool dfs_book[MAX_SIZE];

void dfs(int cur);

int main(){
	#ifdef file
	freopen("dfs.in", "r", stdin);
	freopen("dfs.out", "w", stdout);
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
		e[x][y]=read();
	}

	dfs_book[1]=1;
	dfs(1);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

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

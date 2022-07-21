/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
#define MAX_N 1010
#define INF 64
using namespace std;
inline int read();
int n,m;
char e_b[MAX_N][MAX_N],e_a[MAX_N][MAX_N];
char book[MAX_N];
char book_b[MAX_N];
void dfs(int cur){
	for(int i=1;i<=n;i++)
		if(e_a[cur][i]<INF&&book[i]==0){
			book[i]=1;
			dfs(i);
		}
}
void dfs_b(int cur){
	for(int i=1;i<=n;i++)
		if(e_b[cur][i]<INF&&book_b[i]==0){
			book_b[i]=1;
			dfs_b(i);
		}
}
int main(){
	#ifdef file
	freopen("rank.in", "r", stdin);
	freopen("rank.out", "w", stdout);
	#endif

	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
			if(i==j) e_a[i][j]=0,e_b[i][j]=0;
			else e_a[i][j]=INF,e_b[i][j]=INF;
		}
	}
	
	n=read();
	m=read();
	int u,v;
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		e_a[u][v]=1;
		e_b[v][u]=1;
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		book[i]=1;
		book_b[i]=1;
		dfs(i);
		dfs_b(i);
		
		for(int j=1;j<=n;j++){
			cnt+=!(book[j]||book_b[j]);
			book[j]=0;
			book_b[j]=0;
		}
	}
	
	printf("%d",cnt/2);

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

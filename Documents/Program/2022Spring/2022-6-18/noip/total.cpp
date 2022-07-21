/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#define file
using namespace std;
inline int read();
const int MAX=20+20;
char arr[MAX][MAX];
int d[4][2]=
{
{0,1},
{0,-1},
{1,0},
{-1,0}
};
int cnt;
void dfs(int x,int y){
	cnt++;
	arr[x][y]=0;
	for(int i=0;i<4;i++){
		if(arr[x+d[i][0]][y+d[i][1]]=='.'){
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}
/*
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
*/
int main(){
	#ifdef file
	freopen("total.in", "r", stdin);
	freopen("total.out", "w", stdout);
	#endif

//	int T=read();
	
	while(1){
	cnt=0;
	int m=read();
	int n=read();
	
	int p,q;
	if(n==0&&m==0){
		break;
	}
	cnt=0;
	
	memset(arr,0,sizeof(arr));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=getchar();
			if(arr[i][j]=='\n'){
				arr[i][j]=getchar();
			}
			if(arr[i][j]=='@'){
				p=i;
				q=j;
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%c",arr[i][j]);
//		}
//		putchar('\n');
//	}
	
	dfs(p,q);
	printf("%d\n",cnt);
	
	}

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

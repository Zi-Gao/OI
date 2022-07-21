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
const int MAX=1000+20;
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
	arr[x][y]=0;
	for(int i=0;i<4;i++){
		if(arr[x+d[i][0]][y+d[i][1]]==1){
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}

int main(){
	#ifdef file
	freopen("puzzle.in", "r", stdin);
	freopen("puzzle.out", "w", stdout);
	#endif

//	int T=read();

	int n=read();
	int m=read();
	cnt=0;
	
	memset(arr,0,sizeof(arr));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=getchar();
			if('0'<=arr[i][j]&&'9'>=arr[i][j]){
				arr[i][j]-='0';
			}else{
				arr[i][j]=getchar()-'0';
			}
		}
	}
	
//	putchar('\n');
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d",arr[i][j]);
//		}
//		putchar('\n');
//	}

	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==1){
				cnt++;
				dfs(i,j);
				
//				putchar('\n');
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=m;j++){
//						printf("%d",arr[i][j]);
//					}
//					putchar('\n');
//				}
//				printf("%d\n",cnt);
			}
		}
	}
	
	printf("%d ",cnt);

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

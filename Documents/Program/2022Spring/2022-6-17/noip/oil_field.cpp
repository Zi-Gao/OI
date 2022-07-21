/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
using namespace std;
inline int read();
const int MAX=100+20;
int arr[MAX][MAX];
int d[8][2]=
{
{0,1},
{0,-1},
{1,0},
{-1,0},
{1,1},
{1,-1},
{-1,1},
{-1,-1},
};
int cnt;
void dfs(int x,int y){
	if(arr[x][y]<=0) return;
	arr[x][y]=0;
	for(int i=0;i<8;i++){
		if(arr[x+d[i][0]][y+d[i][1]]=='@'){
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}

/*
3 5
*@*@*
**@**
*@*@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/

int main(){
	#ifdef file
	freopen("oil_field.in", "r", stdin);
	freopen("oil_field.out", "w", stdout);
	#endif

//	int T=read();
	while(true){

	int n=read();
	int m=read();
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
		}
	}
	
//	putchar('\n');
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%c",arr[i][j]);
//		}
//		putchar('\n');
//	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]=='@'){
				dfs(i,j);
				cnt++;
//				putchar('\n');
//				for(int i=1;i<=n;i++){
//					for(int j=1;j<=m;j++){
//						printf("%c",arr[i][j]);
//					}
//					putchar('\n');
//				}
			}
		}
	}
	
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

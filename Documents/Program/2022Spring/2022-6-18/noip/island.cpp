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
const int MAX=10000+20;
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
	cnt+=arr[x][y];
	arr[x][y]=0;
	for(int i=0;i<4;i++){
		if(arr[x+d[i][0]][y+d[i][1]]>0){
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}

int main(){
	#ifdef file
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
	#endif

//	int T=read();

	int n=read();
	int m=read();
	cnt=0;
	
	memset(arr,0,sizeof(arr));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			arr[i][j]=read();
		}
	}
	
//	putchar('\n');
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d",arr[i][j]);
//		}
//		putchar('\n');
//	}

	int out[MAX]={0};
	int outcnt=0;
	int out_i=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]>0){
				cnt=0;
				dfs(i,j);
				out[outcnt++]=cnt;
				
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
	
	sort(out,out+outcnt);
	
	printf("%d\n",outcnt);
	
	for(int i=0;i<outcnt;i++){
		printf("%d ",out[i]);
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

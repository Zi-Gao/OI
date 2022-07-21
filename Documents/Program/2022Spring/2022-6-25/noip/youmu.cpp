/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
using namespace std;
inline int read();
const int MAX=200+20;
int arr[MAX][MAX];
int d[3][2]=
{
{0,1},
{-1,0},
{1,0},
};
int cnt,n,m;
void dfs(int x,int y,int step){
    if(step==n){
        cnt++;
        if(cnt==998244853){
            cnt=0;
        }
        return;
    }
	arr[x][y]=2;
	for(int i=0;i<3;i++){
		if(arr[x+d[i][0]][y+d[i][1]]==0){
			dfs(x+d[i][0],y+d[i][1],step+1);
		}
	}
    arr[x][y]=0;
}

int main(){
	#ifdef file
	freopen("youmu.in", "r", stdin);
	freopen("youmu.out", "w", stdout);
	#endif

//	int T=read();

	n=read();
	m=read();

	cnt=0;

	memset(arr,0,sizeof(arr));

    int x,y;
    for(int i=0;i<m;i++){
        x=read();
        y=read();
        if(!(x>105||x<-105||y>105||y<0)){
            arr[x+105][y]=1;
        }
    }

	// putchar('\n');
	// for(int i=105-n;i<=n+105;i++){
	// 	for(int j=0;j<=n;j++){
	// 		printf("%d",arr[i][j]);
	// 	}
	// 	putchar('\n');
	// }

    dfs(105,0,0);

    printf("%d",cnt);

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
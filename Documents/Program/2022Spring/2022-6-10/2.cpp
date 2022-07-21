/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();
const int MAX=20;
int arr[MAX][MAX];
int d[4][2]=
{
{0,1},
{0,-1},
{1,0},
{-1,0}
};
int cnt;
void dfs(int x,int y){
	if(arr[x][y]<=0) return;
	arr[x][y]=-arr[x][y];
	for(int i=0;i<4;i++){
		if(arr[x+d[i][0]][y+d[i][1]]>0){
			dfs(x+d[i][0],y+d[i][1]);
		}
	}
}
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int n=10;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=read();
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]>0){
				dfs(i,j);
				cnt++;
			}
		}
	}
	
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

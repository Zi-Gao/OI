/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define file
using namespace std;
inline int read();
const int MAX=100;
int n,m,p,q;
char arr[MAX][MAX];
int d[8][2]=
{
{2,1},
{1,2},
{-1,2},
{-2,1},
{-2,-1},
{-1,-2},
{1,-2},
{2,-1},
};
long long int cnt;
void dfs(int x,int y,int step){
	if(step==n*m){
		cnt++;
		return;
	}
	
	for(int i=0;i<8;i++){
		if(x+d[i][0]>=0&&x+d[i][0]<n&&y+d[i][1]>=0&&y+d[i][1]<m&&arr[x+d[i][0]][y+d[i][1]]==0){
			arr[x+d[i][0]][y+d[i][1]]=1;
			dfs(x+d[i][0],y+d[i][1],step+1);
			arr[x+d[i][0]][y+d[i][1]]=0;
		}
	}
}

int main(){
	#ifdef file
	freopen("check.in", "r", stdin);
	freopen("check.out", "w", stdout);
	#endif


	int T=read();
	
	while(T--){
		n=read();
		m=read();
		q=read();
		p=read();
		
		memset(arr,0,sizeof(arr));
		
	//	putchar('\n');
	//	for(int i=0;i<MAX;i++){
	//		for(int j=0;j<MAX;j++){
	//			printf("%d",arr[i][j]);
	//		}
	//		putchar('\n');
	//	}
		dfs(p,q,1);
		printf("%lld\n",cnt);
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

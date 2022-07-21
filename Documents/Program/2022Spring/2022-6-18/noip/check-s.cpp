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
char arr[MAX][MAX];
int d[3][2]=
{
{-1,0},
{0,1},
{1,0}
};
long long int n,cnt;
void dfs(int x,int y,int step){
	if(step==n){
		cnt++;
		return;
	}
	
	for(int i=0;i<3;i++){
		if(arr[x+d[i][0]][y+d[i][1]]==0){
			arr[x+d[i][0]][y+d[i][1]]=1;
			dfs(x+d[i][0],y+d[i][1],step+1);
			arr[x+d[i][0]][y+d[i][1]]=0;
		}
	}
}

int main(){
//	#ifdef file
	freopen("check.in", "r", stdin);
	freopen("check.out", "w", stdout);
//	#endif

//	int T=read();

//	n=read();
	
	memset(arr,0,sizeof(arr));
	
//	putchar('\n');
//	for(int i=0;i<MAX;i++){
//		for(int j=0;j<MAX;j++){
//			printf("%d",arr[i][j]);
//		}
//		putchar('\n');
//	}


	for(n=0;n<=22;n++){
		cnt=0;
		arr[50][50]=1;
		dfs(50,50,0);
		
		printf("%d,",cnt);
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

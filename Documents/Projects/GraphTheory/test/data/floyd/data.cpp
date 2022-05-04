/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
//#define file
const int MAX_SIZE=100;
const int INF=0x3FFFFFFF;
using namespace std;
inline int read();
int e[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool dfs_book[MAX_SIZE];

inline void write(int in[MAX_SIZE][MAX_SIZE]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(in[i][j]==INF) printf("INF ");
			else printf("%d ",in[i][j]);
		putchar('\n');
	}
}

void Floyd_Warshall(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][k]+e[k][j],e[i][j]);
	write(e);
}

int main(){
	int I=0;
    srand(time(NULL));
	while(I<=9){
	char in[10]={'0'+I,'.','i','n'};
	char out[10]={'0'+I,'.','o','u','t'};
	freopen(in, "w", stdout);

	memset(e,0,sizeof(e));
	memset(dfs_book,0,sizeof(dfs_book));

	cnt=0;

	n=rand()%90+2;
	m=rand()%9000+2;
	printf("%d %d\n",n,m);

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
		x=rand()%(n-1)+1;
		y=rand()%(n-1)+1;
		e[x][y]=rand();
		printf("%d %d %d\n",x,y,e[x][y]);
	}

	freopen(out, "w", stdout);
	// dfs_book[1]=1;
	Floyd_Warshall();
	I++;
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

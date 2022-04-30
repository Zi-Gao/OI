/***
 * @Author: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
//#define file
const int MAX_SIZE=10000;
const int INF=0x3FFFFFFF;
using namespace std;
inline int read();
int e[MAX_SIZE][MAX_SIZE],cnt,n,m;
bool dfs_book[MAX_SIZE];

void bfs();

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

	n=rand()%988+2;
	m=rand()%988+2;
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
	dfs_book[1]=1;
	bfs();
	I++;
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
void bfs(){
	bool bfs_book[MAX_SIZE]={0};
	int que[MAX_SIZE]={0},head=0,tail=0,cur=1;

	que[tail++]=cur;
	bfs_book[cur]=1;

	while(head<tail && tail<n){
		cur=que[head];
		for(int i=1;i<=n;i++){
			if(e[cur][i]!=INF && !bfs_book[i]){
				que[tail++]=i;
				bfs_book[i]=1;
			}
			if(tail==n) break;
		}
		head++;
	}

	for(int i=1;i<=n;i++){
		if(bfs_book[i]) printf("%d ",i);
	}
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

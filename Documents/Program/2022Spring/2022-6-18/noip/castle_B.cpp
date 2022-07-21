/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();

struct c{
	char u,d,l,r,f;
};

c arr[50+20][50+20];

int n,m;
int cnta;

void dfs(int x,int y){
	if(x==0||y==0||x>n||y>m){
		return;
	}
	cnta++;
	arr[x][y].f=1;
	if(arr[x][y].l==0&&arr[x][y-1].f==0){
		dfs(x,y-1);
	}
	if(arr[x][y].r==0&&arr[x][y+1].f==0){
		dfs(x,y+1);
	}
	if(arr[x][y].u==0&&arr[x-1][y].f==0){
		dfs(x-1,y);
	}
	if(arr[x][y].d==0&&arr[x+1][y].f==0){
		dfs(x+1,y);
	}
}

void cldfs(int x,int y){
	if(x==0||y==0||x>n||y>m){
		return;
	}
	arr[x][y].f=0;
	if(arr[x][y].l==0&&arr[x][y-1].f==1){
		dfs(x,y-1);
	}
	if(arr[x][y].r==0&&arr[x][y+1].f==1){
		dfs(x,y+1);
	}
	if(arr[x][y].u==0&&arr[x-1][y].f==1){
		dfs(x-1,y);
	}
	if(arr[x][y].d==0&&arr[x+1][y].f==1){
		dfs(x+1,y);
	}
}

int main(){
	#ifdef file
	freopen("castle_B.in", "r", stdin);
	freopen("castle_B.out", "w", stdout);
	#endif

	m=read();
	n=read();
	
	int t;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			t=read();
			if(t>=8){
				t-=8;
				arr[i][j].d=1;
			}
			if(t>=4){
				t-=4;
				arr[i][j].r=1;
			}
			if(t>=2){
				t-=2;
				arr[i][j].u=1;
			}
			if(t>=1){
				t-=1;
				arr[i][j].l=1;
			}
		}
	}
	
	int num=0;
	int maxa=-1;


	
	int movex,movey,movemaxa=0;
	char moved;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j].f==0){
				dfs(i,j);
				num++;
				
				if(cnta>maxa){
					maxa=cnta;
				}
				cnta=0;
			}
		}
	}
	
//	printf("%d\n%d\n%d\n%d %d %c",num,maxa,movemaxa,movex,movey,moved);
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			arr[i][j].f=0;
	
	for(int j=1;j<=m;j++){
		for(int i=n;i>0;i--){
			if(arr[i][j].f==0){
				
				if(arr[i][j].u==1){
					if(i>1){
						arr[i-1][j].d=0;
					}
					arr[i][j].u=0;
					
					dfs(i,j);
					
					if(cnta>movemaxa){
						movemaxa=cnta;
						movex=i;
						movey=j;
						moved='N';

					}
					cnta=0;

					for(int i2=1;i2<=n;i2++)
						for(int j2=1;j2<=m;j2++)
							arr[i2][j2].f=0;

					if(i>1){
						arr[i-1][j].d=1;
					}
					arr[i][j].u=1;
				}
				if(arr[i][j].r==1){
					if(j<m){
						arr[i][j+1].l=0;
					}
					arr[i][j].r=0;
					
					dfs(i,j);
					
					if(cnta>movemaxa){
						movemaxa=cnta;
						movex=i;
						movey=j;
						moved='E';

					}
					cnta=0;
					
					for(int i2=1;i2<=n;i2++)
						for(int j2=1;j2<=m;j2++)
							arr[i2][j2].f=0;
					
					if(j<m){
						arr[i][j+1].l=1;
					}
					arr[i][j].r=1;
				}

			}
		}
	}
	
	printf("%d\n%d\n%d\n%d %d %c",num,maxa,movemaxa,movex,movey,moved);

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

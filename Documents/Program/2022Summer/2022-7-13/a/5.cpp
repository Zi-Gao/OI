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

char e[100+10][100+10];
char temp[100+10];
struct node{
	char arr[100+10];
	int cnt;
	bool operator < (const node & a) const{
		if(cnt!=a.cnt){
			return cnt>a.cnt;
		}
		return strcmp(arr,a.arr)<0;
	}
}arr[1000000];
int now;
int n,m,_max;

void dfs(int step,int cnt){
	if(step==n+1){
		if(cnt>=_max){
			_max=cnt;
			memcpy(arr[now].arr,temp,sizeof(temp));
			arr[now++].cnt=cnt;
		}
		return;
	}
	
	for(int i=1;i<step;i++)
		if(temp[i]==1&&e[step][i]==1)
			goto loop;
	temp[step]=1;
	dfs(step+1,cnt+1);
	loop:;
	temp[step]=0;
	dfs(step+1,cnt);
}

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	n=read();
	m=read();
	_max=0;
	int u,v;
	
	for(int i=0;i<m;i++){
		u=read();
		v=read();
		e[u][v]=1;
		e[v][u]=1;
	}
	
	dfs(1,0);
	
	sort(arr,arr+now+1);
	
	for(int i=1;i<=n;i++)printf("%d",arr[0].arr[i]);

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

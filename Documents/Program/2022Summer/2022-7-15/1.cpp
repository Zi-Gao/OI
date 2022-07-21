/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file
//using namespace std;

const int MAX_N=10000;
const int ST_I=MAX_N;
const int ST_J=16;

int head[MAX_N],depths[MAX_N],parents[MAX_N],n;
char flag[MAX_N];

inline int read();
void init();
int LCA_book(int u,int v);//暴力--标记法 
//void

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int T=read();
	int m,u,v;
	while(T--){
		init();
		m=read()-1;
		for(int i=1;i<=m;i++){
			u=read();
			v=read();
			parents[v]=u;
		}
		printf("%d\n",LCA_book(read(),read()));
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int LCA_book(int u,int v){
	if(u==v) return u;
	
	memset(flag,0,sizeof(flag));
	
	flag[u]=true;
	while(u!=parents[u]){
		u=parents[u];
		flag[u]=true;
	}
	
	if(flag[v]) return v;
	while(v!=parents[v]){
		v=parents[v];
		if(flag[v]) return v;
	}
	return 0;
}

void init(){
	memset(head,-1,sizeof(head));
	for(int i=0;i<MAX_N;i++)parents[i]=i;
	return;
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

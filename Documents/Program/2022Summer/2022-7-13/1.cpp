/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <queue>
//#define file
using namespace std;
inline int read();

const int max_n=1000+10;
const int max_m=100000+10;

struct node{
	int u,w;
	bool operator < (node a) const{
		return w>a.w;
	}
};

struct edge{
	int v,w,next;
	edge(){
		next=-1;
		return;
	}
}list[max_m],list_b[max_m];
int head[max_n],head_b[max_n];

priority_queue<node> h;
int dis[max_n],dis_b[max_n];
char book[max_n];
/*
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3
*/
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int n=read();
	int m=read();
	int x=read();
	
	int u,v,w;
	
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		list[i].v=v;
		list[i].w=w;
		list[i].next=head[u];
		head[u]=i;
		
		list_b[i].v=u;
		list_b[i].w=w;
		list_b[i].next=head_b[v];
		head_b[v]=i;
	}
	
	int cur,to,cnt=0;
	
	for(int i=0;i<max_n;i++) dis[i]=0x3fffffff;
	book[x]=1;
	h.push((node){x,0});
	dis[x]=0;
	
	while(!h.empty()){
		cur=h.top().u;
		h.pop();
		book[cur]=1;
		for(int i=head[cur];~i;i=list[i].next){
			to=list[i].v;
			if((!book[to])&&(dis[to]>dis[cur]+list[i].w)){
				dis[to]=dis[cur]+list[i].w;
				h.push(node{to,dis[to]});
			}
		}
	}
	
	for(int i=0;i<max_n;i++) dis_b[i]=0x3fffffff;
	memset(book,0,sizeof(book));
	book[x]=1;
	h.push((node){x,0});
	dis_b[x]=0;
	
	while(!h.empty()){
		cur=h.top().u;
		h.pop();
		book[cur]=1;
		for(int i=head_b[cur];~i;i=list_b[i].next){
			to=list_b[i].v;
			if((!book[to])&&(dis_b[to]>dis_b[cur]+list_b[i].w)){
				dis_b[to]=dis_b[cur]+list_b[i].w;
				h.push(node{to,dis[to]});
			}
		}
	}
	
	int max=0;
	for(int i=1;i<=n;i++)
		if(max<dis[i]+dis_b[i])
		 max=dis[i]+dis_b[i];
	
	printf("%d",max);

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

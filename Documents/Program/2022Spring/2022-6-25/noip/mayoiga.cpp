#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 4000000+10
#define MAX_M 4000000+10
const int INF=0x3FFFFFFF;

struct node{
	int v,d;
	bool operator < (const node in) const {
        return d<=in.d;
    }
};

struct edge{
	int from,to,next,w;
	edge(){
		next=-1;
	}
};

#define type_heap <
#define heap_type node
const int HEAP_SIZE = MAX_N;

struct heap{
	heap_type h[HEAP_SIZE];
	int map[MAX_N];
	int tail;

	heap(){
		tail=1;
		return;
	}

	void push(heap_type in){
		if(map[in.v]==0){
			map[in.v]=tail;
			insert(in,tail++);
		}else{
			insert(in,map[in.v]);
		}
		return;
	}

	void pop(){
		map[h[1].v]=-1;
		insert(h[--tail],1);
	}

	void insert(heap_type in,int pos){
		h[pos]=in;
		int next;
		while((pos<<1)<tail){
			next=pos<<1;
			if((next+1<tail)&&(h[next+1] type_heap h[next])) ++next;
			if(h[next] type_heap h[pos]){
				swap(pos,next);
				pos=next;
			}else break;
		}
		while((pos>1)&&(h[pos] type_heap h[pos>>1] )){
			swap(pos,pos>>1);
			pos>>=1;
		}
	}

	heap_type top(){
		return h[1];
	}

	bool empty(){
		return tail==1;
	}

	void swap(int s1,int s2){
		heap_type temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
		map[h[s1].v]=s1;
		map[h[s2].v]=s2;
	}
};

#define file

int head[MAX_N],cnt,n,m,s,d;
edge eList[MAX_M];

inline int read();
void readGraph();
void DijkstraHeapList();

/*
5 7 0 3 
2 0 
0 3 
3 4 
4 1 
0 4 
1 0 
3 2
*/

int main(){
	#ifdef file
	freopen("mayoiga.in", "r", stdin);
	freopen("mayoiga.out", "w", stdout);
	#endif

	readGraph();

	DijkstraHeapList();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
heap h;
int dis[MAX_N];
void DijkstraHeapList(){
	int u,to;
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	h.push((node){s,0});
	dis[s]=0;

	while(!h.empty()){
		u=h.top().v;
		if(h.map[u]==-1){
			h.pop();
			continue;
		}
		h.pop();
		for(int i=head[u];~i;i=eList[i].next){
			to=eList[i].to;
			if((h.map[to]!=-1)&&(dis[to]>dis[u]+eList[i].w)){
				dis[to]=dis[u]+eList[i].w;
				h.push((node){to,dis[to]});
			}
		}
	}

	// for(int i=1;i<=n;++i){
	// 	if(dis[i]==INF) printf("INF ");
	// 	else printf("%d ",dis[i]);
	// }
    printf("%d",dis[d]);
}

void addEdge(int u,int v,int w,int nowm){
	eList[nowm].from=u;
	eList[nowm].to=v;
	eList[nowm].w=w;
	eList[nowm].next=head[u];
	head[u]=nowm;
	return;
}

void readGraph(){
	n=read();
	m=read();
	s=read()+1;
    d=read()+1;
	int u,v;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m*2;i++){
		u=read()+1;
		v=read()+1;
		addEdge(u,v,1,i);
		addEdge(v,u,1,++i);
	}
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
#include <cstdio>
#include <cstring>
using namespace std;

// #define file
const int MAX_N=500+10;
const int MAX_M=5200+10;
const int INF=0x3FFFFFFF;

struct edge{
	int to,next,w;
	edge(){
		next=-1;
	}
};

#define queue_type int
const int QUEUE_SIZE = MAX_N;
struct queue{
	queue_type q[MAX_N];
	int head,tail,num;

	queue(){
		head=0;
		tail=0;
		num=0;
		return;
	}

	void push(queue_type in){
		if(num < QUEUE_SIZE){
			q[tail] = in;
			++tail;
			tail%=QUEUE_SIZE;
			++num;
		}
		return;
	}

	void pop(){
		if(num>0){
			++head;
			--num;
			head%=QUEUE_SIZE;
		}
		return;
	}

	queue_type front(){
		return q[head];
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}
};

int head[MAX_N],cnt,n,m,s,ww;
edge list[MAX_M];

inline int read();
void readGraph();
bool SPFAList();
/*
2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8
*/
int main(){
	#ifdef file
	freopen("spfa.in", "r", stdin);
	freopen("spfa.out", "w", stdout);
	#endif

	int T=read();

	while(T--){
		readGraph();
		if(SPFAList()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

bool SPFAList(){
	queue q;
	int dis[MAX_N],cnt[MAX_N]={0},cur,to;
	bool book[MAX_N]={0};
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	q.push(s);
	dis[s]=0;
	book[s]=1;
	// cnt[s]=1;

	while(!q.empty()){
		cur=q.front();
		q.pop();
		book[cur]=0;

		for(int i=head[cur];~i;i=list[i].next){
			to=list[i].to;
			if(dis[to]>dis[cur]+list[i].w){
				dis[to]=dis[cur]+list[i].w;
				if(!book[to]){
					cnt[to]++;
					if(cnt[to]>=n){
						return true;
					}
					q.push(to);
					book[to]=1;
				}
			}
		}
	}

	return false;
}

void addEdge(int u,int v,int w,int nowm){
	list[nowm].to=v;
	list[nowm].w=w;
	list[nowm].next=head[u];
	head[u]=nowm;
	return;
}

void readGraph(){
	n=read();
	m=read();
	ww=read();
	s=1;
	int u,v,w;
	for(int i=1;i<=m*2+ww;i++)list[i].next=head[i]=-1;
	for(int i=1;i<=m*2;i++){
		u=read();
		v=read();
		w=read();
		addEdge(v,u,w,i++);
		addEdge(u,v,w,i);
	}
	for(int i=m*2+1;i<=m*2+ww;i++){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,-w,i);
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

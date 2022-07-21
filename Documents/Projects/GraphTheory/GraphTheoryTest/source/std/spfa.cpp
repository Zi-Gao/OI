#include <cstdio>
#include <cstring>
using namespace std;

#define file
const int MAX_N=100000+10;
const int MAX_M=200000+10;
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

int head[MAX_N],cnt,n,m,s;
edge list[MAX_M];

inline int read();
void readGraph();
bool SPFAList();

int main(){
	#ifdef file
	freopen("spfa.in", "r", stdin);
	freopen("spfa.out", "w", stdout);
	#endif

	readGraph();

	SPFAList();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

/*
 *list:邻接表
 *q:队列
 *dis:记录距离
 *book:是否在队列中
 *cnt:记录入队此时
 *cur: 当前的点
 *to:去到的点
 *INF:正无穷
 */
bool SPFAList(){
	queue q;
	int dis[MAX_N],cnt[MAX_N]={0},cur,to;
	bool book[MAX_N]={0};
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	q.push(s);
	dis[s]=0;
	book[s]=1;
	cnt[s]=1;

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
						printf("No answer!");
						return false;
					}
					q.push(to);
					book[to]=1;
				}
			}
		}
	}

	for(int i=1;i<=n;++i)
		if(dis[i]==INF) printf("INF ");
		else printf("%d ",dis[i]);

	return true;
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
	s=read();
	int u,v,w;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
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
/***
 * @Author: Zi_Gao
 * @Description: Graph Theory
 * @Samples:
DFS/BFS input:
5 5 1
1 2 1
1 3 1
1 5 1
2 4 1
3 5 1
DFS output:1 2 4 3 5
BFS output:1 2 3 5 4

Floyd/Dijkstra input:
4 8 1
1 2 2
1 3 6
1 4 4
2 3 3
3 1 7
3 4 1
4 1 5
4 3 12
Floyd output:
0 2 5 4
9 0 3 4
6 8 0 1
5 7 10 0
Dijkstra output:
0 2 5 4

Bellman-Ford/SPFA input:
3 3 1
1 2 -1
2 3 -1
3 1 2
Bellman-Ford/SPFA output:
0 -1 -2
 */
#include <cstdio>
#include <cstring>

const int MAX_N=1000;
const int MAX_M=1000;
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
#include "queue.h"
#include "heap.h"
int matrix[MAX_N][MAX_N],head[MAX_N],cnt,s,n,m;
bool book[MAX_N];
edge list[MAX_M];

int min(int a,int b);
void init();
void addEdge(int u,int v,int w,int nowm);
inline int read();
void readGraph();
void depthFirstSearchMatrix(int cur);
void breadthFirstSearchMatrix();
void depthFirstSearchList(int cur);
void breadthFirstSearchList();
void Floyd_WarshallMatrix();
void DijkstraMatrix();
void DijkstraHeapList();
bool Bellman_FordList();
bool SPFAList();

//#define file
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	init();
	readGraph();

	printf("Depth First Search with matrix:\n");
	memset(book,0,sizeof(book));
	book[s]=1;
	depthFirstSearchMatrix(s);
	putchar('\n');

	printf("Breadth First Search with matrix:\n");
	breadthFirstSearchMatrix();
	putchar('\n');

	printf("Depth First Search with with list:\n");
	memset(book,0,sizeof(book));
	book[s]=1;
	depthFirstSearchList(s);
	putchar('\n');

	printf("Breadth First Search with list:\n");
	breadthFirstSearchList();
	putchar('\n');

	printf("Floyd-Warshall:\n");
	Floyd_WarshallMatrix();
	putchar('\n');

	printf("Dijkstra:\n");
	DijkstraMatrix();
	putchar('\n');

	printf("Dijkstra with heap:\n");
	DijkstraHeapList();
	putchar('\n');

	printf("Bellman-Ford:\n");
	Bellman_FordList();
	putchar('\n');

	printf("SPFA:\n");
	SPFAList();
	putchar('\n');

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

/*
 *list:�ڽӱ�
 *q:����
 *dis:��¼����
 *book:�Ƿ��ڶ�����
 *cnt:��¼��Ӵ�ʱ
 *cur: ��ǰ�ĵ�
 *to:ȥ���ĵ�
 *INF:������
 */
bool SPFAList(){
	QUEUE q;
	int dis[MAX_N],cnt[MAX_N]={0},cur,to;
	memset(book,0,sizeof(book));
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

/*
 *list:�ڽӱ�
 *dis:��¼����
 *flag:��¼�Ƿ����ɳڲ���
 *INF:������
 */
bool Bellman_FordList(){
	int dis[MAX_N];
	bool flag;
	for(int i=0;i<MAX_N;i++) dis[i]=INF;
	dis[s]=0;

	for(int i=0;i<=n;i++){
		flag=false;
		for(int e=1;e<=m;e++){
			if(dis[list[e].to]>dis[list[e].from]+list[e].w){
				flag=false;
				dis[list[e].to]=dis[list[e].from]+list[e].w;
			}
		}
		if(!flag) break;
		else if(i==n){
			printf("No answer!");
			return true;
		}
	}

	for(int i=1;i<=n;++i)
		if(dis[i]==INF) printf("INF ");
		else printf("%d ",dis[i]);

	return true;
}

/*
 *h:����ֱ�����м����Ķ�
 *list:�ڽӱ�
 *dis:��¼����
 *cur:��ǰ�ĵ�
 *to:ȥ���ĵ�
 *INF:������
 */
void DijkstraHeapList(){
	HEAP h;
	int dis[MAX_N],cur,to;
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	h.push((node){s,0});
	dis[s]=0;

	while(!h.empty()){
		cur=h.top().v;
		h.pop();
		for(int i=head[cur];~i;i=list[i].next){
			to=list[i].to;
			if((h.book[to]!=-1)&&(dis[to]>dis[cur]+list[i].w)){
				dis[to]=dis[cur]+list[i].w;
				h.push((node){to,dis[to]});
			}
		}
	}

	for(int i=1;i<=n;++i)
		if(dis[i]==INF) printf("INF ");
		else printf("%d ",dis[i]);

	return;
}

/*
 *matrix:�ڽӾ���
 *book:��¼�Ƿ���ʹ�
 *dis:��¼����
 *min:��¼��С����
 *u:��¼��С����ĵ�
 *INF:������
 */
void DijkstraMatrix(){
	int dis[MAX_N]={0},_min,cur;
	memset(book,0,sizeof(book));
	for(int i=0;i<MAX_N;i++)dis[i]=INF;

	dis[s]=0;

	for(int i=1;i<=n;i++){
		_min=INF;
		for(int j=1;j<=n;j++)
			if(!book[j]&&dis[j]<_min){
				_min=dis[j];
				cur=j;
			}
		book[cur]=1;
		for(int j=1;j<=n;j++)
			if(!book[j])
				dis[j]=min(dis[cur]+matrix[cur][j],dis[j]);
	}

	for(int i=1;i<=n;++i)
		if(dis[i]==INF) printf("INF ");
		else printf("%d ",dis[i]);

	return;
}

/*
 *k:��ר��
 *i:��ʼ��
 *j:��ֹ��
 *INF:������
 *matrix:�ڽӾ���
 */
void Floyd_WarshallMatrix(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				matrix[i][j]=min(matrix[i][k]+matrix[k][j],matrix[i][j]);

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(matrix[i][j]==INF) printf("INF ");
			else printf("%d ",matrix[i][j]);
		putchar('\n');
	}

	return;
}

/*
 *cur: ��ǰ�ĵ�
 *list:�ڽӱ�
 *que:����
 *book:�������
 */
void breadthFirstSearchList(){
	QUEUE que;
	int cur=s;
	memset(book,0,sizeof(book));

	que.push(cur);
	book[cur]=1;

	while(!que.empty()){
		cur=que.front();
		for(int i=head[cur];~i;i=list[i].next)
			if(book[list[i].to]==0){
				que.push(list[i].to);
				book[list[i].to]=1;
			}
		printf("%d ",cur);
		que.pop();
	}

	return;
}

/*
 *cur: ��ǰ�ĵ�
 *cnt:�����ĵ����
 *list:�ڽӱ�
 *book:�������
 */
void depthFirstSearchList(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=head[cur];~i;i=list[i].next)
		if(book[list[i].to]==0){
			book[list[i].to]=1;
			depthFirstSearchMatrix(list[i].to);
		}

	return;
}

/*
 *INF:������
 *cur: ��ǰ�ĵ�
 *matrix:�ڽӾ���
 *que:����
 *book:�������
 */
void breadthFirstSearchMatrix(){
	QUEUE que;
	int cur=s;
	memset(book,0,sizeof(book));

	que.push(cur);
	book[cur]=1;

	while(!que.empty()){
		cur=que.front();
		for(int i=1;i<=n;i++){
			if(matrix[cur][i]!=INF&&!book[i]){
				que.push(i);
				book[i]=1;
			}
		}
		printf("%d ",cur);
		que.pop();
	}

	return;
}

/*
 *cur: ��ǰ�ĵ�
 *cnt:�����ĵ����
 *INF:������
 *matrix:�ڽӾ���
 *book:�������
 */
void depthFirstSearchMatrix(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(int i=1;i<=n;i++)
		if(matrix[cur][i]<INF&&book[i]==0){
			book[i]=1;
			depthFirstSearchMatrix(i);
		}

	return;
}

void addEdge(int u,int v,int w,int nowm){
	list[nowm].from=u;
	list[nowm].to=v;
	list[nowm].w=w;
	list[nowm].next=head[u];
	head[u]=nowm;
	matrix[u][v]=w;

	return;
}

void readGraph(){
	n=read();
	m=read();
	s=read();
	int u,v,w;

	for(int i=1;i<=m;i++){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
	}

	return;
}

void init(){
	memset(head,-1,sizeof(head));
	// for(int i=0;i<MAX_M;i++)list[i].next=-1;
	for(int i=0;i<MAX_N;i++)
		for(int j=0;j<MAX_N;j++)
			if(i==j) matrix[i][j]=0;
			else matrix[i][j]=INF;

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

int min(int a,int b){
	return a<b?a:b;
}

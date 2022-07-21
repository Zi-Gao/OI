#include <cstdio>
#include <cstring>
using namespace std;
#define stack_type int
const int maxstack = 10000;
struct stack{
	stack_type _null,s[maxstack];
	int s_top;

	stack(){
		s_top=0;
		memset(s,0,sizeof(s));
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(stack_type in){
		if(s_top < maxstack){
			s[s_top] = in;
			++s_top;
		}
		return;
	}

	void pop(){
		if(s_top > 0){
			--s_top;
		}
		return;
	}

	void pop(int in){
		if(s_top >= in){
			s_top-=in;
		}
		return;
	}

	stack_type top(){
		if(s_top>0){
			return s[s_top-1];
		}else{
			return _null;
		}
	}

	void clear(){
		s_top=0;
	}

	bool empty(){
		if(s_top==0){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return s_top;
	}

	stack_type read(int in){
		if(s_top > in){
			return s[in];
		}else{
			return _null;
		}
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n\n", empty());
	}
};

#define file
#define MAX_N 10+10
#define MAX_M MAX_N*MAX_N
const char INF=127;
int cnt,n,m,out;
char e[MAX_N][MAX_N];
char book[MAX_N];

void init();
inline int read();
void readGraph();
void depthFirstSearchMatrix(int cur);
/*
6
2 3 6
3 4 5 6
3 1 4 6
3 2 3 5
3 2 4 6
4 1 2 3 5 
*/ 
stack s;
int main(){
	#ifdef file
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	#endif

	init();
	readGraph();

	book[1] = 1;
	s.push(1);
	cnt=1;
	depthFirstSearchMatrix(1);
	
	printf("%d",out);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void depthFirstSearchMatrix(int cur){
//	printf("%d ",cur);

	if(cnt==n){
		if(e[1][s.top()]==1){
			for(int i=0;i<n;i++){
				printf("%d ",s.read(i));
			}
			putchar('\n');
			out++;
		}
		return; 
	} 
	for(int i=1;i<=n;i++)
		if(e[cur][i]<INF&&book[i]==0){
			book[i]=1;
			cnt++;
			s.push(i);
			depthFirstSearchMatrix(i);
			book[i]=0;
			cnt--;
			s.pop();
		}
}

void addEdge(int u,int v,int w){
	e[u][v]=w;
	return;
}

void readGraph(){
	n=read();

	int m,u;
	for(int i=1;i<=n;i++){
		m=read();
		for(int j=0;j<m;j++){
			int u=read();
			addEdge(i,u,1);
			addEdge(u,i,1);
		} 
		
	}
	return;
}

void init(){
	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_N;j++){
			if(i==j) e[i][j]=0;
			else e[i][j]=INF;
		}
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

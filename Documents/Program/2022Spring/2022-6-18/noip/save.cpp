/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
inline int read();

struct p{
	int x,y,w;
};

#define queue_type p
const int QUEUE_SIZE = 10000;
struct queue{
	queue_type _null,q[QUEUE_SIZE];
	int head,tail,num;

	queue(){
		head=0;
		tail=0;
		num=0;
		memset(q,0,sizeof(q));
		memset(&_null,0,sizeof(_null));
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
			q[head]=_null;
			++head;
			--num;
			head%=QUEUE_SIZE;
		}
		return;
	}

	queue_type front(){
		if(num<QUEUE_SIZE){
			return q[head];
		}else{
			return _null;
		}
	}
	
	queue_type back(){
		if(num>0){
			return q[0];
		}else{
			return _null;
		}
	}

	void clear(){
		head=0;
		tail=0;
		return;
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return num;
	}

	queue_type read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n", empty());
		printf("head :%d\n",head);
		printf("tail :%d\n\n",tail);
	}
};


#define MAX_N 1000+10


char arr[MAX_N][MAX_N];
int d[4][2]=
{
{0,1},
{0,-1},
{1,0},
{-1,0}
};

int n,sx,sy,fx,fy;

void bfs(){
	queue q;
	int x=sx,y=sy,w=0;
	arr[x][y]=1;
	
	q.push((p){x,y,w});
	
	while(!q.empty()){
		x=q.front().x;
		y=q.front().y;
		w=q.front().w;
		q.pop();
		for(int i=0;i<4;i++){
			if(arr[x+d[i][0]][y+d[i][1]]==0){
				if(x+d[i][0]==fx&&y+d[i][1]==fy){
					printf("%d",w+1);
					return;
				}
				q.push((p){x+d[i][0],y+d[i][1],w+1});
				arr[x+d[i][0]][y+d[i][1]]=1;
			}
		}
	}
}

#define file

int main(){
	#ifdef file
	freopen("save.in", "r", stdin);
	freopen("save.out", "w", stdout);
	#endif
	
	n=read();
	
	memset(arr,1,sizeof(arr));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j]=getchar();
			if(arr[i][j]=='\n'){
				arr[i][j]=getchar();
			}
			arr[i][j]-='0';
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",arr[i][j]);	
//		}
//		putchar('\n');
//	}
	
	sx=read();
	sy=read();
	
	fx=read();
	fy=read();
	
	bfs();

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

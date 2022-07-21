/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file

//**********
//#define STL_queue

#ifdef STL_queue
#include <queue>
#endif

#ifndef STL_queue
#define queue_type int
const int QUEUE_SIZE = 11;
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
		if(tail < QUEUE_SIZE){
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

	void pop(int in){
		if(head+in<=tail){
			head+=in;
			head%=QUEUE_SIZE;
			num-=in;
		}
		return;
	}

	queue_type top(){
		if(num<QUEUE_SIZE){
			return q[head];
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
		return tail-head;
	}

	queue_type read(int in){
		if(head+in<tail){
			return q[head+in];
		}else{
			return _null;
		}
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n", empty());
		printf("head :%d\n",head);
		printf("tail :%d\n\n",tail);
	}
};
#endif
//**********
using namespace std;

inline int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	queue q;

	q.push(0);
	q.push(1);
	
	
	int n=read();
	
	for(int j=0;j<(n-1);j++) putchar(' '); printf(" 1\n");
	
	for(int i=1;i<n;i++){
		for(int j=0;j<(n-i);j++) putchar(' ');
		q.push(0);
		for(int j=0;j<=i;j++){
			int t=q.top();
			q.pop();
			t+=q.top();
			q.push(t);
			printf("%d ",t);
		}
		putchar('\n');
	}
	
//	while(!q.empty()){
//		printf("%d ",q.top());
//		q.pop();
//	}
	
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

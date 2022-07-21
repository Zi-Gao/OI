/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;

#include <cstring>
#define queue_type pair<long long int,long long int>
const int QUEUE_SIZE = 100+5;
struct QUEUE{
	queue_type _null,q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
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
			return q[tail-1];
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

inline long long int read();
/*
6 4
1 -3 5 1 -2 3
*/
#define file
int main(){
	#ifdef file
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);
	#endif

	int n=read();
	int m=read();
	// int arr[]
	QUEUE q;
	long long int best=0;

    pair<long long int,long long int> now;

    now.first=0;
    now.second=0;

    q.push(now);

	for(int i=1;i<=n;i++){
		now.first+=read();
        now.second=i;

        q.pop();
        // printf("%d\n",q.back().first);
        while(now.first<q.back().first&&(!q.empty())){
            q.pop();
        }

        q.push(now);

        best=best>(q.back().first-q.front().first)?best:(q.back().first-q.front().first);
	}

	printf("%lld",best);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

inline long long int read(){
    long long x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

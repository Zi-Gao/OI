/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
//**********
#define type_heap <
#define heap_type int
const int HEAP_SIZE = 2000000;
//					1000000
struct heap{
	heap_type _null,h[HEAP_SIZE];
	int tail;

	heap(){
		tail=1;
		memset(h,0,sizeof(h));
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(heap_type in){
		insert(in,tail++);
	}

	void pop(){
		insert(h[--tail],1);
		h[tail]=_null;
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
		while((pos>>1)&&(h[pos] type_heap h[pos>>1] )){
			swap(pos,pos>>1);
			pos>>=1;
		}
	}

	heap_type top(){
		return h[1];
	}

	void clear(){
//		memset(h,0,sizeof(h));
		tail=1;
	}

	bool empty(){
		if(tail==1){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return tail-1;
	}

	heap_type read(int in){
		return h[in];
	}

	void swap(int s1,int s2){
		heap_type temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n\n", empty());
	}
};
//**********
#define file
using namespace std;
inline int read();
/*
8 3
I 1
I 2
I 3
Q
I 5
Q
I 4
Q
*/
heap h;
int main(){
	#ifdef file
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	#endif

	int i=0;
	int k=0;
	
	while(~scanf("%d %d",&i,&k)){
//	priority_queue<int,vector<int>, greater<int> > h;
	h.clear();
	while(i--){
		
		char op;
		cin >> op;
		if(op=='I'){
			int t=read();
			if((h.size()<k)||(t>h.top())){
				if(h.size()==k){
					h.pop();
				}
				h.push(t);
			}
		}
		if(op=='Q'){
			printf("%d\n",h.top());
		}
	}
	}
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

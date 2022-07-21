/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>

//**********
#define type_heap <
#define heap_type int
const int HEAP_SIZE = 20;

struct heap{
	heap_type _null,h[HEAP_SIZE];
	int tail;

	heap(){
		tail=1;
		memset(h,0,sizeof(h));
		memset(&_null,0,sizeof(_null));
		return;
	}
	
	heap(heap_type* in,int size){
		memcpy(h+1,in,size*sizeof(heap_type));
		tail=size+1;
		for(int i=tail>>1;i;--i)
			insert(h[i],i);
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
		memset(h,0,sizeof(h));
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
int main(){
	#ifdef file
	freopen("average.in", "r", stdin);
	freopen("average.out", "w", stdout);
	#endif
	while(1){
	int n1=read();
	int n2=read();
	int n=read();
	if(n1==0&&n2==0&&n==0) break;
	int nn=n-n1-n2;
	long long cnt=0;
	heap big;
	heap small;
	for(int i=0;i<n;i++){
		int t=read();
		cnt+=t;
		if((big.size()<n2)||(t<-big.top())){
			if(big.size()==n2){
				big.pop();
			}
			big.push(-t);
		}
		if((small.size()<n1)||(t>small.top())){
			if(small.size()==n1){
				small.pop();
			}
			small.push(t);
		}
	}
	while(!small.empty()){
		cnt-=small.top();
		small.pop();
	}
	while(!big.empty()){
		cnt-=-big.top();
		big.pop();
	}
	double out=cnt*1.0/(nn*1.0);
	printf("%.6lf\n",out);
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

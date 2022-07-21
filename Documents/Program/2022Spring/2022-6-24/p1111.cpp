/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;

//#define file

struct node{
	int x,y,t;
	bool operator < (const node in) const {
        return t<=in.t;
    }
};

//**********
#include <cstring>
#define type_heap <
#define heap_type node
const int HEAP_SIZE = 100001;

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

	inline void push(heap_type in){
		insert(in,tail++);
	}

	inline void pop(){
		insert(h[--tail],1);
		h[tail]=_null;
	}

	inline void insert(heap_type in,int pos){
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

	inline heap_type top(){
		return h[1];
	}

	void clear(){
		memset(h,0,sizeof(h));
		tail=1;
	}

	inline bool empty(){
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

struct fa{
	int arr[100001];
	fa(){
		for(int i=1;i<=100000;i++){
			arr[i]=i;
		}
		return;
	}
	
	int find(int x){
		return x==arr[x]?x:(arr[x]=find(arr[x]));
	}
	
	void merge(int i,int j){
		arr[find(i)]=find(j);
		return;
	}
};

inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int n=read();
	int m=read();
	
	heap h;
	fa f;
	
	for(int i=1;i<=m;i++){
		h.push((node){read(),read(),read()});
	}
	
	
	int flag=true;
	while(!h.empty()){
		node aa=h.top();
		f.merge(h.top().x,h.top().y);
		
		int a=f.find(1);
		for(int i=2;i<=n;i++){
			if(f.find(i)!=a){
				goto loop;
			}
		}
		
		
		printf("%d",h.top().t);
		flag=false;
		break;
		
		loop:;
		
		h.pop();
	}
	
	if(flag){
		printf("-1");
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

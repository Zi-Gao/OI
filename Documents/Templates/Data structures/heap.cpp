/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>

//#define file

//**********
#define type_heap <
#define heap_type int
const int HEAP_SIZE = 1000;

struct HEAP{
	heap_type _null,h[HEAP_SIZE];
	int tail;

	HEAP(){
		tail=1;
		return;
	}

	inline void push(heap_type in){
		insert(in,tail++);
	}

	inline void pop(){
		insert(h[--tail],1);
	}

	inline void insert(heap_type in,int pos){
		h[pos]=in;
		register int next;
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

	inline void clear(){
		tail=1;
	}

	inline bool empty(){
		if(tail==1){
			return true;
		}else{
			return false;
		}
	}

	inline int size(){
		return tail-1;
	}

	heap_type read(int in){
		return h[in];
	}

	inline void swap(int s1,int s2){
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
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif



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

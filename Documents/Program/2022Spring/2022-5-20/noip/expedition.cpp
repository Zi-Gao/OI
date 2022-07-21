/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 

//**********
#define type_heap >
#define heap_type int
const int HEAP_SIZE = 10100;
struct p{
	int first,second;
	bool operator <(const p &a) const{
		return second<a.second;//��score��С����������"<",������">"
	}
}arr[10100];
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
		memcpy(h+1,in,size);
		tail=size/sizeof(heap_type)+1;
		for(int i=tail>>1;i;--i)
			insert(i);
		return;
	}

	void push(heap_type in){
		insert(in,tail++);
	}

	void pop(){
		h[1]=h[--tail];
		h[tail]=_null;
		insert(h[1],1);
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
	
	void insert(int pos){
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

	heap_type front(){
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
bool cmp(p a,p b){
	return a.first<b.first;
}
int main(){
	#ifdef file
	freopen("expedition.in", "r", stdin);
	freopen("expedition.out", "w", stdout);
	#endif

	memset(arr,0,sizeof(arr));
	int N=read();
	for(int i=0;i<N;i++){
		arr[i].first=read();//s
		arr[i].second=read();//oil
	}

	int L=read();
	int P=read();
	
	for(int i=0;i<N;i++){
		arr[i].first=L-arr[i].first;
	}
	
	p t;
	t.first=L;
	t.second=0;
	
	arr[N]=t;
	
	sort(arr,arr+N,cmp);

	int cnt=0;
	int nowo=0;
	
	heap h;
//	priority_queue<int> h;
	
	for(int now=P;now<L;){
		while((nowo<N)&&(arr[nowo].first<=now)){
			h.push(arr[nowo++].second);
		}
		if(h.empty()){
			cnt=-1;
			break;
		}
		now+=h.front();
		h.pop();
		cnt++;
	}
	
	printf("%d",cnt);

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

#define type_heap <
#define heap_type node
const int HEAP_SIZE = MAX_N;

struct HEAP{
	heap_type h[HEAP_SIZE];
	int book[MAX_N];
	int tail;

	HEAP(){
		std::memset(book,0,sizeof(book));
		tail=1;
		return;
	}

	void push(heap_type in){
		if(book[in.v]==0){
			book[in.v]=tail;
			insert(in,tail++);
		}else{
			insert(in,book[in.v]);
		}
		return;
	}

	void pop(){
		book[h[1].v]=-1;
		insert(h[--tail],1);
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
		while((pos>1)&&(h[pos] type_heap h[pos>>1] )){
			swap(pos,pos>>1);
			pos>>=1;
		}
	}

	heap_type top(){
		return h[1];
	}

	bool empty(){
		return tail==1;
	}

	void swap(int s1,int s2){
		heap_type temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
		book[h[s1].v]=s1;
		book[h[s2].v]=s2;
	}

	void clear(){
		std::memset(book,0,sizeof(book));
		tail=1;
		return;
	}
};
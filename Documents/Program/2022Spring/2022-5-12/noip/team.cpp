/***
 * @Author: Zi_Gao
 * @Description: 
 *���ڴ�С:
 ****short int �����32767 ��2���ֽ�
 *�������:
 û�б�Ҫ����������¼���е�״̬��
 ****�������� 
 *����STL:
 ****������ 
 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define queue_type int
const int QUEUE_SIZE = 1000;
struct que{
	int _null,q[QUEUE_SIZE];
	int head,tail,num;

	que(){
		head=0;
		tail=0;
		num=0;
		memset(q,0,sizeof(q));
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(int in){
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

	int front(){
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



	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n", empty());
		printf("head :%d\n",head);
		printf("tail :%d\n\n",tail);
	}
};
//**********
struct que1{
	short int _null,q[QUEUE_SIZE];
	int head,tail,num;

	que1(){
		head=0;
		tail=0;
		num=0;
		memset(q,0,sizeof(q));
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(short int in){
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

	short int front(){
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

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n", empty());
		printf("head :%d\n",head);
		printf("tail :%d\n\n",tail);
	}
};
		que qarr[1000];
		que1 h;
inline int read();
#define file
int main(){
	#ifdef file
	freopen("team.in", "r", stdin); 
	freopen("team.out", "w", stdout);
	#endif

	int i=1;
	while(1){
		short int book[999999+1]={0};
		int n=read();
		int intt;
		if(n==0) break;
		printf("Scenario #%d\n",i);
		i++;
		for(int i=0;i<n;i++){
			int cntt=read();
			for(int j=0;j<cntt;j++){
				book[read()]=i;
			}
		}
		memset(&h,0,sizeof(h));
		memset(qarr,0,sizeof(qarr));
		char c=getchar();
		while(c!='S'){

			if(c=='E'){
				intt=read();
				if(qarr[book[intt]].empty()){
					h.push(book[intt]);
				}
				qarr[book[intt]].push(intt);
			}else if(c=='D'){
				printf("%d\n",qarr[h.front()].front());
				qarr[h.front()].pop();
				if(qarr[h.front()].empty()){
					h.pop();
				}
				while(c!='\n'){
					c=getchar();
				}
//				q.front().pop();
			}

			c=getchar();
		}
		putchar('\n');
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

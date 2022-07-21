/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
//********
#define delink_type int
#define max_delink 20
struct node{
	int next,from;
	delink_type data;
	node(){
		next=-1;
		from=-1;
	}
};
struct delink{
	node dl[max_delink];
	int rear,head;
	int now;
	delink(){
		head=-1;
		rear=-1;
		now=0;
	}
	
	void insert(delink_type in){
		dl[now].data=in;
		dl[now].from=rear;
		dl[rear].next=now;
		rear=now;
		if(head==-1){
			head=now;
		}
		++now;
		return;
	}
	
	void insert(delink_type in,int pos){
		if(head==-1&&pos>0) return;
		dl[now].data=in;
		if(pos==0){
			dl[head].from=now;
			dl[now].next=head;
			head=now;
			++now;
			if(rear==-1)rear=head;
			return;
		}
		int find=head;
		while(find!=-1&&--pos) find=dl[find].next;
		if(find!=-1&&dl[find].next!=-1){
			dl[now].from=find;
			dl[now].next=dl[find].next;
			dl[find].next=now;
			dl[dl[find].next].from=now;
			++now;
		}else if(find!=-1){
			dl[now].from=rear;
			dl[rear].next=now;
			rear=now;
			++now;
		}
		return;
	}
	
	void del(){
		if(head==-1) return;
		head=dl[head].next;
	}
	
	int find(delink_type in){
		int pos=head;
		while(pos!=-1&&dl[pos].data!=in){
			pos=dl[pos].next;
		}
		return pos;
	}
	
	void print(){
		int _now=head;
		while(_now!=-1){
			printf("%d ",dl[_now].data);
			_now=dl[_now].next;
		}
	}
};
//********
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	delink l;
//	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.del();
//	l.insert(3,0);
	
	l.print();

//	printf("%d",l.find(4));

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

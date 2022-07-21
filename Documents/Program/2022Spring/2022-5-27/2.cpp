/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
//********
#define link_type int
struct node{
	link_type date;
	node* next;
	node(){
		next=NULL;
	}
};
struct link{
	node* head;
	node* rear;
	link(){
		head=NULL;
	}
	
	void insert(link_type in){
		node* l=new node;
		l->date=in;
		if(head==NULL){
			head=l;
		}else{
			rear->next=l;
		}
		rear=l;

		return;
	}
	
	void insert(link_type in,int pos){
		if(head==NULL&&pos>0) return;
		node* ins=new node;
		if(pos==0){
			ins->next=head;
			if(head==NULL) rear=ins;
			head=ins;
			return;
		}
		node* now=head;
		ins->date=in;
		while(now!=NULL&&--pos) now=now->next;
		if(now!=NULL){
			ins->next=now->next;
			now->next=ins;
			if(ins->next==NULL) rear=ins;
		}
		return;
	}
	
	void del(){
		if(head!=NULL){
			node* l=head;
			head=head->next;
			delete(l);
		}
		return;
	}
	
	void del(int pos){
		if(head==NULL) return;
		node* now=head;
		if(pos==0){
			head=now->next;
			delete(now);
			if(head==NULL) rear==NULL;
			return;
		}
		while(now!=NULL&&--pos) now=now->next;
		if(now!=NULL&&now->next!=NULL){
			node* l=now->next;
			now->next=l->next;
			delete(l);
		}
		if(now->next==NULL){
			rear=now;
		}
		return;
	}
	
	void print(){
		node* now;
		now=head;
		while(now!=NULL){
			printf("%d ",now->date);
			now=now->next;
		}
		return;
	}
	
	bool empty(){
		return head==NULL;
	}
};
//********
inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	link l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(3,4);
	l.print();

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

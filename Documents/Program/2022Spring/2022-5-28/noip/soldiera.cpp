/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <list>
//#define file
using namespace std;
#define link_type int
struct node{
	link_type data;
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
		l->data=in;
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
		ins->data=in;
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
			if(now->next==NULL){
				rear=now;
			}
		}

		return;
	}
	
	int find(link_type in){
		node* now=head;
		int i=0;
		while(now!=NULL&&now->data!=in) now=now->next,i++;
		return i;
	}
	
	void print(){
		node* now;
		now=head;
		while(now!=NULL){
			printf("%d ",now->data);
			now=now->next;
		}
		return;
	}
	
	bool empty(){
		return head==NULL;
	}
};
inline int read();

int main(){
	#ifdef file
	freopen("Doubly_Linked_List.in", "r", stdin);
	freopen("Doubly_Linked_List.out", "w", stdout);
	#endif

	link l;
	int n=read();
	int cnt=0;
	while(n--){
		int p=read();
		for(int i=1;i<=p;i++){
			l.insert(i);
		}
		cnt=p;
		while(cnt>3){
			for (int i=2;i<=p;i*=2){
				l.del(i-1);
				cnt--;
				if(cnt==3){
					goto loop;
				}
			}
			for (int i=3;i<=p;i*=3){
				l.del(i-1);
				cnt--;
				if(cnt==3){
					goto loop;
				}
			}
		}
		loop:;
		l.print();
		
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

/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;

//********
#include <cstring>
#define BST_type int
#define BST_SIZE 500010
struct BSTNode{
	BST_type data;
	int lChild,rChild,p;
	BSTNode(){
		lChild=-1;
		rChild=-1;
		return;
	}
};

struct BST{
	BSTNode bst[BST_SIZE];
	int rear,head,num;

	BST(){
		num=0;
		head=-1;
		rear=-1;
		return;
	}
	
	int search(BST_type key){
		int p=head;
		while(~p){
			if(key==bst[p].data) break;
			if(key<bst[p].data) p=bst[p].lChild;
			else p=bst[p].rChild;
		}
		
		return p;
	}
	
	void ins(BST_type key){
		int p=head;
		while(~p)
			if(key<bst[p].data)
				if(bst[p].lChild==-1){
					bst[p].lChild=rear+1;
					break;
				}
				else p=bst[p].lChild;
			else
				if(bst[p].rChild==-1){
					bst[p].rChild=rear+1;
					break;
				}
				else p=bst[p].rChild;
		bst[++rear].data=key;
		bst[rear].lChild=-1;
		bst[rear].rChild=-1;
		bst[rear].p=p;
		if(num==0) head=rear;
		num++;
	}
	
	void del(BST_type key){
		int p=head,q=head,s;
		while(~p){
			if(key==bst[p].data) break;
			if(key<=bst[p].data){
				q=p;
				p=bst[p].lChild;
			}else{
				q=p;
				p=bst[p].rChild;
			}
		}
		
		if(p==-1){
			return;
		}
		
		num--;
		
		if(bst[p].lChild!=-1&&bst[p].rChild!=-1){
			q=p;
			s=bst[p].lChild;
			while(~bst[p].lChild){
				q=s;
				s=bst[s].rChild;
			}
			bst[q].data=bst[s].data;
			bst[q].rChild=bst[s].lChild;
		}else{
			if(p==head){
				head=p;
				return;
			}
			if(bst[p].rChild==-1) bst[q].rChild=bst[p].lChild;
			else bst[q].rChild=bst[p].rChild;
		}
	}
};
//********
BST bst;
inline int read();
void first(int now){
	if(now==-1) return;
	printf("%d ",bst.bst[now].data);
	first(bst.bst[now].lChild);
	first(bst.bst[now].rChild);
}

void middle(int now){
	if(now==-1) return;
	middle(bst.bst[now].lChild);
	printf("%d ",bst.bst[now].data);
	middle(bst.bst[now].rChild);
}
/*
8 
insert 30 
insert 88 
insert 12 
insert 1 
insert 20 
insert 17 
insert 25 
print
*/
int main(){
	#ifdef file
	freopen("insert_bst.in", "r", stdin);
	freopen("insert_bst.out", "w", stdout);
	#endif

	int n=read();
	int insnum,head=-1;
	char op;
	
	for(int i=0;i<n;i++){
		loop:;
		op=getchar();
		if(op=='\n') goto loop;
		if(op=='i'){
			insnum=read();
			head=0;
			bst.ins(insnum);
		}else{
			middle(head);
			putchar('\n');
			first(head);
			putchar('\n');
			while(op!='\n'&&op!=EOF)op=getchar();
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

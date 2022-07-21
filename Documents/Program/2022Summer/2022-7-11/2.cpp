/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;

//********
#include <cstring>
#define BST_type int
#define BST_SIZE 100
struct BSTNode{
	BST_type data;
	int lChild,rChild;
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
		memset(bst,0,sizeof(bst));
		return;
	}
	
	int search(BST_type key){
		int p=head;
		while(~p){
			if(key==bst[p].data) break;
			if(key<=bst[p].data) p=bst[p].lChild;
			else p=bst[p].rChild;
		}
		
		return p;
	}
	
	void ins(BST_type key){
		int p=head;
		while(~p)
			if(key<=bst[p].data)
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

inline int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	BST bst;
	
	bst.ins(50);
	bst.ins(60);
	bst.ins(30);
	bst.ins(40);
	
	bst.del(40);
	
	printf("%d",bst.search(40));
	
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

/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file

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
	int rear,head,num,s[BST_SIZE];

	BST(){
		num=0;
		head=-1;
        rear=BST_SIZE;
		for(register int i=0;i<BST_SIZE;++i){
            s[i]=i;
        }
		return;
	}

    inline int getMemory(){
        return s[--rear];
    }

    inline void releaseMemory(int address){
        bst[address].lChild=-1;
        bst[address].rChild=-1;
        s[rear++]=address;
        return;
    }

	inline int search(BST_type key){
		int p=head;
		while(~p){
			if(key==bst[p].data) break;
			if(key<=bst[p].data) p=bst[p].lChild;
			else p=bst[p].rChild;
		}

		return p;
	}

	inline void insert(BST_type key){
		register int p=head;
        int address=getMemory();
		while(~p)
			if(key<=bst[p].data)
				if(bst[p].lChild==-1){
					bst[p].lChild=s[address];
					break;
				}
				else p=bst[p].lChild;
			else
				if(bst[p].rChild==-1){
					bst[p].rChild=s[address];
					break;
				}
				else p=bst[p].rChild;
		bst[address].data=key;
		if(num==0) head=s[address];
		num++;

        return;
	}

	inline void del(BST_type key){
		register int p=head,q=head,s;
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
            releaseMemory(s);
		}else{
			if(p==head){
                releaseMemory(q);
				head=p;
				return;
			}
			if(bst[p].rChild==-1) bst[q].rChild=bst[p].lChild;
			else bst[q].rChild=bst[p].rChild;
            releaseMemory(p);
		}

        return;
	}
};
//********

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

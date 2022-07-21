/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;


struct BSTNode{
	int lChild,rChild,p,h,d;
	BSTNode(){
		lChild=-1;
		rChild=-1;
		p=-1;
		h=1;
		d=0;
	}
}tree[10000];
int treeheight,head;

void ins(int id,int left,int right){
	tree[id].lChild=left;
	tree[id].rChild=right;
	
	if(left==-1)left=10000-1;
	if(right==-1)right=10000-1;
	tree[id].h=(tree[left].h>tree[right].h?tree[left].h:tree[right].h)+1;
	int s=id;
	while(~tree[s].p){
		tree[tree[s].p].h=tree[s].h+1>tree[tree[s].p].h?tree[s].h+1:tree[tree[s].p].h;
		s=tree[s].p;
	}
	tree[left].p=id;
	tree[right].p=id;
	return;
}

void print(int id){
	//node 0: parent = 3, sibling = 4, degree = 2, depth = 1, height = 1, internal node
	int node=id;
	int parent=tree[id].p;
	int sibling=-1;
	if(~parent)
		if(tree[parent].lChild==id) sibling=tree[parent].rChild;
		else sibling=tree[parent].lChild;
	int degree=(tree[id].lChild!=-1)+(tree[id].rChild!=-1);
	int depth=tree[id].d;
	int height=tree[id].h-1;
	printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",node,parent,sibling,degree,depth,height);
	if(tree[id].p==-1){
		printf("root\n");
	}else if(degree==0){
		printf("leaf\n");
	}else{
		printf("internal node\n");
	}
	
	return;
}

void countDepth(int now,int depth){
	if(now==-1) return;
	tree[now].d=depth;
	countDepth(tree[now].lChild,depth+1);
	countDepth(tree[now].rChild,depth+1);
}

/*
4
0 -1 -1
1 -1 -1
2 1 0
3 2 -1

9 
0 1 4 
1 2 3 
2 -1 -1 
3 -1 -1 
4 5 8 
5 6 7 
6 -1 -1 
7 -1 -1 
8 -1 -1
*/
inline int read();
int main(){
	#ifdef file
	freopen("bitree.in", "r", stdin);
	freopen("bitree.out", "w", stdout);
	#endif

	tree[10000-1].h=0;
	int n=read();
	for(int i=0;i<n;i++){
		int id=read();
		int l=read();
		int r=read();
		ins(id,l,r);
	}
	
	for(int i=0;i<n;i++)
		if(tree[i].h>treeheight){
			treeheight=tree[i].h;
			head=i;
		}
	
	countDepth(head,0);
	
	for(int i=0;i<n;i++)
		print(i);
	
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

/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
#include <cstring>
#define BST_type int
#define BST_SIZE 100+10
struct BSTNode{
	BST_type data;
	int lChild,rChild;
	BSTNode(){
		lChild=0;
		rChild=0;
		return;
	}
}bst[BST_SIZE];
int x;
bool flag;
int cnt;
void middle(int now){
	if(flag||now==0) return;
	middle(bst[now].lChild);
	cnt++;
	if(bst[now].data==x){
		printf("%d",cnt);
		flag=true;
		return;
	}
	middle(bst[now].rChild);
}
/*
7
15
5 2 3
12 4 5
10 0 0
29 0 0
15 6 7
8 0 0
23 0 0
*/
inline int read();
int main(){
	#ifdef file
	freopen("tree_a.in", "r", stdin);
	freopen("tree_a.out", "w", stdout);
	#endif

	int n=read();
	x=read();
	int data,lChild,rChild;
	
	for(int i=0;i<BST_SIZE;i++) bst[i].lChild=bst[i].rChild=-1;
	
	for(int i=1;i<=n;i++){
		bst[i].data=read();
		bst[i].lChild=read();
		bst[i].rChild=read();
	}
	
	middle(1);
	
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

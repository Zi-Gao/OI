/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
struct node{
	int to,next;
	node(){
		to=-1;
		next=-1;
	}
}arr[100000+10];
int head[100000+10];
int parents[100000+10];
int depths[100000+10];
int m,n;
inline int read();

int findHead(int now){
	if(parents[now]==-1) return now;
	return findHead(parents[now]);
}

void countDepth(int now,int depth){
	if(now==-1) return;
	depths[now]=depth;
	for(int i=head[now];~i;i=arr[i].next){
		countDepth(arr[i].to,depth+1);
	}
}
/*
13 
0 3 1 4 10 
1 2 2 3 
2 0 
3 0 
4 3 5 6 7 
5 0 
6 0 
7 2 8 9 
8 0 
9 0 
10 2 11 12 
11 0 
12 0
*/
int main(){
	#ifdef file
	freopen("r_tree.in", "r", stdin);
	freopen("r_tree.out", "w", stdout);
	#endif

	for(int i=0;i<100000+10;i++) parents[i]=head[i]=-1;

	n=read();
	for(int i=0;i<n;i++){
		int id=read();
		int u=read();
		for(int j=0;j<u;j++){
			arr[m].to=read();
//			arr[m].next=head[id];
//			head[id]=m;
			arr[m].next=m+1;
			parents[arr[m].to]=id;
			if(j==u-1){
				head[id]=m-u+1;
				arr[m].next=-1;
			}else
				arr[m].next=m+1;
			m++;
		}
	}
	
	
	countDepth(findHead(0),0);
	
	for(int i=0;i<n;i++){//node 2: parent = 1, depth = 1, leaf, []
		printf("node %d: parent = %d, depth = %d, ",i,parents[i],depths[i]);
		if(parents[i]==-1){
			printf("root");
		}else if(head[i]==-1){
			printf("leaf");
		}else{
			printf("internal node");
		}
		printf(", [");
		for(int j=head[i];~j;j=arr[j].next)
			if(j==head[i])
				printf("%d",arr[j].to);
			else
				printf(", %d",arr[j].to);
		printf("]\n");
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

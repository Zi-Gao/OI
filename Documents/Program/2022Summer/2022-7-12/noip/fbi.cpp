/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;

struct node{
	int lChild,rChild;
	char type;//type: 0:B 1;1:I 1;2:F 01
	node(){
		lChild=-1;
		rChild=-1;
	}
}tree[2048+9];

int len;

inline int read();
void last(int now){
	if(now==-1) return;
	last(tree[now].lChild);
	last(tree[now].rChild);
	if(tree[now].type==0) putchar('B');
	else if(tree[now].type==1) putchar('I');
	else putchar('F');
}
int main(){
	#ifdef file
	freopen("fbi.in", "r", stdin);
	freopen("fbi.out", "w", stdout);
	#endif
	
	int n=read();
	len=1<<n;
	
	char t;
	
	for(int i=0;i<len;i++){
		t=getchar();
		if(t=='1'){
			tree[i].type=1;
		}
	}
	
	int l=0,r=len,temp;
	
	while(l+1<r){
		for(int i=l;i<r;i+=2){
			if(tree[i].type==0&&tree[i+1].type==0){
				tree[len].type=0;
			}else if(tree[i].type==1&&tree[i+1].type==1){
				tree[len].type=1;
			}else{
				tree[len].type=2;
			}
			tree[len].lChild=i;
			tree[len].rChild=i+1;
//			printf("%d ",tree[len].type);
			len++;
			
		}
		temp=(r-l)>>1;
		l=r;
		r+=temp;
	}
	
	last(len-1);

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

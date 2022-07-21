/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
struct node{
	int to,next;
	char data;
	node(){
		to=-1;
		next=-1;
	}
}list[100000+10];
int head[100000+10];
int m,n;
inline int read();
int main(){
	#ifdef file
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	#endif

	m=1;
	
	char c;
	
	for(int i=0;i<100000+10;i++) head[i]=-1;
	
	while(true){
		int now=1;
		c=getchar();
		while(c!='\n'){
			if(c==EOF){
				goto loop;
			}
			for(int i=head[now];~i;i=list[i].next){
				if(list[i].data==c){
					now=list[i].to;
					goto loop2;
				}
			}
			list[m].to=m+1;
			list[m].data=c;
			list[m].next=head[now];
			head[now]=m;
			now=m+1;
			m++;
			loop2:;
			c=getchar();
		}
	}
	
	loop:;
	printf("%d",m);

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

/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
char last[100+10];
int n;
void readtree(){
	char t=getchar();
	if(t=='.') return;
	readtree();
	printf("%c",t);
	readtree();
	last[n++]=t;
}
int main(){
	#ifdef file
	freopen("tree_b.in", "r", stdin);
	freopen("tree_b.out", "w", stdout);
	#endif

	readtree();
	
	printf("\n%s",last);

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

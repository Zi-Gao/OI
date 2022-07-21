/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
int first[50];
int middle[50];
int n;

void last(int l,int r){
	if(l+1==r){
		printf("%d ",middle[l]);
		return;
	}
	if(l>=r) return;
	for(int i=0;i<n;i++)
		for(int j=l;j<r;j++)
			if(first[i]==middle[j]){
				last(l,j);
				last(j+1,r);
				printf("%d ",middle[j]);
				return;
			}
}
/*
5 
1 2 3 4 5 
3 2 4 1 5

4
1 2 3 4
1 2 3 4
*/
int main(){
	#ifdef file
	freopen("get_tree.in", "r", stdin);
	freopen("get_tree.out", "w", stdout);
	#endif

	n=read();

	for(int i=0;i<n;i++) first[i]=read();
	for(int i=0;i<n;i++) middle[i]=read();
	
	last(0,n);

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

/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file
using namespace std;
inline int read();
int k,n,arr[100];
char book[100];
void dfs(int step,int sum){
	if(step==n){
		return;
	}
	book[step]=1;
	dfs(step+1,sum+arr[step]);
	book[step]=0;
	dfs(step+1,sum);
	if(arr[step]+sum==k){
		for(int i=0;i<n;i++){
			if(book[i]==1){
				printf("%d ",arr[i]);
			}
		}
		printf("%d",arr[step]);
		putchar('\n');
	}
}
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	n=read();
	k=read();
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	
	dfs(0,0);

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

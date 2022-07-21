/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
#define int long long
using namespace std;
inline int read();
int arr[40],n,k;
char book[40];
long long cnt;

void dfs(int step){

    if(step==n){
        long long t=0;
        for(int i=0;i<n;i++){
            if(book[i]==1){
                t+=arr[i];
            }
        }

        if(t==k){
            cnt++;
        }
        return;
    }

    book[step]=1;
    dfs(step+1);
    book[step]=0;
    dfs(step+1);
}

/*
3 0
1 -1 -1
*/

signed main(){
	#ifdef file
	freopen("cherry.in", "r", stdin);
	freopen("cherry.out", "w", stdout);
	#endif

    n=read();
    k=read();

    for(int i=0;i<n;i++){
        arr[i]=read();
    }

    // if(k==0){
    //     cnt++;
    // }

    dfs(0);

    printf("%lld",cnt);

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

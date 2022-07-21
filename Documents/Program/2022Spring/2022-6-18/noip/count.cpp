/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();

long long int cnt;

int arr[1010];

long long dfs(int p){
	if(p==1){
		return 1;
	}
	p>>=1;
	long long out=1;
	for(int i=1;i<=p;i++){
		if(arr[i]==0){
			arr[i]=dfs(i);
		}
		
		out+=arr[i];
		
	}
	return out;
}

int main(){
	#ifdef file
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	#endif
	
	
	int n=read();
	
	long long out=dfs(n);
	printf("%lld",out);

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

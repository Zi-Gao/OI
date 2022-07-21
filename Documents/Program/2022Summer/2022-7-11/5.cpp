/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//#define file
using namespace std;
//#define int long long
inline int read();
unsigned long long tree[60][1000000];
bool cmp(int a,int b){
	return a>b;
}
/*
2
1 1
4
2 2 2 2
10
8 2 4 7 5 1 6 9 3 9
*/
signed main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	int n;
	
	while(~scanf("%lld",&n)){
		int arr[60]={0};
		int cnt=0;
//		memset(tree,0,sizeof(tree));
		for(int i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		sort(arr,arr+n,cmp);
		int now=0;
		for(int i=arr[0];i>=0;i--){
			int j=0;
			for(;j<tree[i+1][1000000-1]/2;j++){
//				printf("%d %d\n",tree[i+1][j*2],tree[i-+1][j*2+1]);
//				printf("%d %d\n",j*2,j*2+1);
				tree[i][j]=tree[i+1][j*2]+tree[i+1][j*2+1];
			}
			
			if(now<n){
				while(arr[now]==i){
					unsigned long long _max=0;
					for(int k=0;tree[i+1][k]>0;k++){
						_max=max(tree[i+1][k],_max);
					}
					tree[i][j++]=max(1ULL,_max);
					now++;
					
				}
				
			}
			tree[i][1000000-1]=j;
		}
//		for(int a=0;a<10;a++){
//			for(int b=0;b<10;b++){
//				printf("%4d",tree[a][b]);
//			}
//			putchar('\n');
//		}
		printf("%lld\n",tree[0][0]);
//		cout << tree[0][0] << '\n';
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

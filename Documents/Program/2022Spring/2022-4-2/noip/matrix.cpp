/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define file
using namespace std;
inline int read();
int mx[110][110];
int smx[110][110];
int arr[110];
int n;
int main(){
	#ifdef file
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	#endif

	n=read();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			mx[i][j]=read();
		}
		smx[i][0]=0;
		for(int k=0;k<n;k++){
			smx[i][k+1]=smx[i][k]+mx[i][k];
		}
	}
	
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			printf("%d ",smx[i][j]);
//		}
//		putchar('\n');
//	}
	
	int out=0xC0000000;
	for(int i=0;i<=n;i++){
//		int out
		for(int j=i+1;j<=n;j++){
			memset(arr,0,sizeof(arr));
			for(int k=0;k<=n;k++){
				arr[k]=smx[k][j]-smx[k][i];
			}
			int best=0xC0000000;
			int ans=0xC0000000;
			for(int k=0;k<n;k++){
				if(arr[k]>arr[k]+ans){
					ans=arr[k];
				}else{
					ans=arr[k]+ans;
				}
				if(best<ans){
					best=ans;
				}
			}
			if(out<best){
				out=best;
			}
		}
	}
	printf("%d",out);

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

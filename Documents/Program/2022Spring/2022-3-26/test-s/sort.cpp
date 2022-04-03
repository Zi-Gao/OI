/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
int arr[4][200000];
int m,n;
int _max,_min,temp;
long long out;
int main(){
	#ifdef file
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	#endif

	m=read();
	n=read();

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			arr[i][j]=read();
		}
	}
	
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",a[i][j]);
//		}
//		putchar('\n');
//	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			_max=-1;
			_min=0x7FFFFFFF;
			temp=0;
			//¼ÆËãarr[k][i]+arr[k][j]
			for(int k=0;k<m;k++){
				temp=arr[k][i]+arr[k][j];
				if(temp<_min){
					_min=temp;
				}
				if(temp>_max){
					_max=temp;
				}
			}
			out+=_max+_min;
//			printf("%d ",_max+_min);
		}
//		putchar('\n');
	}
	
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
